#include <cstdio>
#include "../src/window.h"
#include "../src/scene.h"

#include "../src/vector.h"

#define WIDTH 640
#define HEIGHT 480

int main()
{
    Window window = Window(WIDTH, HEIGHT);

    Vector v0 = Vector(4, 4, 4);
    Vector v1 = Vector(4, 4, 4);

    Vector v2 = v0 / v1;

    v0 *= 3;
    v0 /= 2;

    printf("%f %f %f\n", v0.x, v0.y, v0.z);

    Scene scene = Scene("data\\scene.xml");
    printf("successfully loaded scene: %s\n%s%s\n", scene.getTitle(), "author is: ", scene.getAuthor());

    return 0;
}
