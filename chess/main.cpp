#define WIDTH 640
#define HEIGHT 480

#include "../src/window.h"
#include "../src/image.h"
#include "../src/renderer.h"

extern "C" int main(int argc, char** argv)
{
    Window window = Window("Chess", WIDTH, HEIGHT);

    Image img = Image();
    Scene scene = Scene("data/scene.json");
    Renderer *renderer = Renderer::getInstance();

    renderer->render(img, scene);

    img.saveData("out.bmp");

    while(!window.isClosed()){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            if (event.type==SDL_QUIT){
                window.close();
            }
        }
        window.refresh();
    }
    return 0;
}
