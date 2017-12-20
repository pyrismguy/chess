#include <fstream>

#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/error/en.h>

using namespace rapidjson;

#include "scene.h"
#include "ray.h"

Scene::Scene(const char *file) {
    std::ifstream ifs(file);
    IStreamWrapper isw(ifs);

    Document doc;
    ParseResult ok = doc.ParseStream(isw);

    if (!ok) {
        printf("JSON parse error: %s (%u)",
                GetParseError_En(ok.Code()), ok.Offset());
        exit(1);
    }

    assert(doc.HasMember("name") && doc.HasMember("desc"));
    assert(doc["name"].IsString() && doc["desc"].IsString());

    name = new char[NAME_LENGTH + 1];
    desc = new char[DESC_LENGTH + 1];

    memcpy(name, doc["name"].GetString(), NAME_LENGTH);
    memcpy(desc, doc["desc"].GetString(), DESC_LENGTH);

    name[NAME_LENGTH] = 0;
    desc[DESC_LENGTH] = 0;


    const Value& objects = doc["objects"];
    assert(objects.IsArray());

    unsigned int objIdx = 0;
    for (Value::ConstValueIterator itr = objects.Begin(); itr != objects.End(); ++itr)
    {
        if (itr->FindMember("type")->value == "PerspectiveCamera")
        {
            const Value &transform = itr->FindMember("transform")->value,
                        &forward = itr->FindMember("forward")->value,
                        &up = itr->FindMember("up")->value,
                        &fieldOfView = itr->FindMember("fov")->value;

            assert(transform.IsArray());
            assert(forward.IsArray() && transform.IsArray());
            assert(fieldOfView.IsFloat());

            glm::vec3 pos = glm::vec3(transform[0][0].GetFloat(), transform[0][1].GetFloat(), transform[0][2].GetFloat());
            Transform t = Transform();
            t.setPos(pos);

            glm::vec3 f = glm::vec3(forward[0].GetFloat(), forward[1].GetFloat(), forward[2].GetFloat());
            glm::vec3 u = glm::vec3(up[0].GetFloat(), up[1].GetFloat(), up[2].GetFloat());

            float fov = fieldOfView.GetFloat();

            this->objects.push_back(new PerspectiveCamera(t, f, u, fov, 1.0));

            // if camera is main
            if (itr->FindMember("main")->value.GetBool()){
                mainCamIdx = objIdx;
            }
        }
        ++objIdx;
    }

    // Using a reference for consecutive access is handy and faster.
    const Value& shapes = doc["shapes"];
    assert(shapes.IsArray());

    for (Value::ConstValueIterator itr = shapes.Begin(); itr != shapes.End(); ++itr)
    {
        if (itr->FindMember("type")->value == "Sphere")
        {
            const Value &center = itr->FindMember("center")->value;
            const Value &radius = itr->FindMember("radius")->value;

            assert(center.IsArray() && radius.IsFloat());
            assert(center.GetArray().Size() == 3);

            glm::vec3 c = glm::vec3(center[0].GetFloat(), center[1].GetFloat(), center[2].GetFloat());
            float r = radius.GetFloat();

            this->shapes.push_back(new Sphere(c, r));
        }
    }
}

Scene::~Scene() {
    delete [] desc;
    delete [] name;
}

