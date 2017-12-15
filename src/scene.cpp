#include "scene.h"
#include <tinyxml2.h>

using namespace tinyxml2;

#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if ((a_eResult) != XML_SUCCESS) { printf("Error: %i\n", a_eResult); exit(a_eResult); }
#endif

Scene::Scene(const char *file)
{
    XMLDocument doc;
    XMLError result = doc.LoadFile(file);
    XMLCheckResult(result);

    XMLNode *root = doc.FirstChild();
    if (root == nullptr) exit(XML_ERROR_FILE_READ_ERROR);

    XMLElement *scene = root->FirstChildElement("scene");
    if (scene == nullptr) exit(XML_ERROR_PARSING_ELEMENT);

    title = scene->Attribute("title");
    author = scene->Attribute("author");
    if (title == nullptr) exit(XML_ERROR_PARSING_ATTRIBUTE);
}

Scene::~Scene()
{

}