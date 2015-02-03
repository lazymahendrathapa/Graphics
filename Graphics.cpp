#include "Object.h"
#include "Matrix.h"
#include "Vector.h"
#include "Graphics.h"


int main(){
    Vec3 camera(25,25,25);
    Vec3 LookTo(0,0,0);
    Object3d obj;
    obj.LoadObject("sphere.obj");

    Screen S(1024,600);
    SDL_Event event;

    while (1)
    {
        obj.drawWire(&S,camera,LookTo);
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_KEYDOWN:
                switch (event.key.keysym.sym){
                    case SDLK_a:
                        camera.x -= 1;
                        break;
                    //Triggered for keydown
                    case SDLK_s:
                        camera.y -= 1;
                        break;
                    case SDLK_d:
                        camera.x += 1;
                        break;
                    case SDLK_w:
                        camera.y += 1;
                        break;
                    case SDLK_z:
                        camera.z += 1;
                        break;
                    case SDLK_x:
                        camera.z -= 1;
                        break;
                    case SDLK_ESCAPE:
                           return 0;
                }
            }
        }
    }
}

void Screen::setpixel(Vec3 P,Color c)
{
    int *pixmem32;
    int colour;

    int width = screen->w;
    int height = screen->h;

    //Check for boundaries
    int x = P.x;
    int y = P.y;


    if (!(x>=0 && x <= width && y >=0 && y<=height)) return;

    if (P.z > Zbuffer[height*x + y])
        return;
    else
        Zbuffer[height*x + y] = P.z;

    colour = SDL_MapRGB ( screen->format,c.r,c.g,c.b);
    pixmem32 = (int*) screen->pixels+y*screen->pitch/4+x;
    *pixmem32 = colour;

}

void Screen::line(Vec3 P1, Vec3 P2,Color c){

    int x1 = P1.x; int y1 = P1.y;
    int x2 = P2.x; int y2 = P2.y;

    int delta_x(x2 - x1);
    // if x1 == x2, then it does not matter what we set here
    signed char const ix((delta_x > 0) - (delta_x < 0));
    delta_x = ABS(delta_x) << 1;

    int delta_y(y2 - y1);
    // if y1 == y2, then it does not matter what we set here
    signed char const iy((delta_y > 0) - (delta_y < 0));
    delta_y = ABS(delta_y) << 1;

    setpixel(x1, y1,P1.z,c);

    if (delta_x >= delta_y)
    {
        // error may go below zero
        int error(delta_y - (delta_x >> 1));

        while (x1 != x2)
        {
            if ((error >= 0) && (error || (ix > 0)))
            {
                error -= delta_x;
                y1 += iy;
            }
            // else do nothing

            error += delta_y;
            x1 += ix;

            setpixel(x1, y1,P1.z,c);
        }
    }
    else
    {
        // error may go below zero
        int error(delta_x - (delta_y >> 1));

        while (y1 != y2)
        {
            if ((error >= 0) && (error || (iy > 0)))
            {
                error -= delta_y;
                x1 += ix;
            }
            // else do nothing

            error += delta_x;
            y1 += iy;

            setpixel(x1, y1,P1.z,c);
        }
    }
}

bool Screen::WaitQuit()
{
    SDL_Event event;
    bool keypress = false;

    while (!keypress)
    {
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            //If the cross on the top is pressed it is triggered
            case SDL_QUIT:
                keypress = true;
                break;
            //Triggered for keydown
            case SDL_KEYDOWN:
                keypress = true;
                break;
            }
        }
    }
    return true; //wait ends
}

