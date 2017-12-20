#include <cstdio>
#include "../src/scene.h"
#include "../src/image.h"
#include "../src/renderer.h"

extern "C" int main(int argc, char** argv)
{
    FILE* log = freopen("log.txt", "w", stdout);

    Scene scene = Scene("data/scene.json");
    printf("Successfully loaded scene!\nname : \"%s\"\ndesc : \"%s\"\n",
           scene.getName(), scene.getDescription());

    Image img = Image();

    Renderer *renderer = Renderer::getInstance();
    renderer->render(img, scene);

    img.saveData("demo.bmp");

    fclose(log);
    return 0;

}
