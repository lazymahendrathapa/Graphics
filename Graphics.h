#ifndef GRAPHICS_H_
#define GRAPHICS_H_


#include <SDL/SDL.h>
#include <math.h>
#include "Vector.h"

#define round(a) ((int) (a+0.5))
#define ABS(a) ((a<0)? a*-1 : a)

class Color{
    public:
        int r,g,b,a;
    public: Color(){}
            Color(int rr, int gg, int bb, int aa=255):r(rr),g(gg),b(bb),a(aa){}

};

class Screen{
    SDL_Surface* screen;
    float *Zbuffer;
    public:
        Screen(int width = 1024,int height=600){
            SDL_Init(SDL_INIT_EVERYTHING);
            screen = SDL_SetVideoMode(width,height,32,SDL_SWSURFACE);
            Zbuffer = new float[(width*height)]();
        }

        void setpixel(Vec3 P,Color c);
        void setpixel(int x,int y,int z,  Color c){
            Vec3 temp(x,y,z);
            setpixel(temp,c);
        }
        void line(Vec3 P1,Vec3 P2,Color c);
        bool WaitQuit();

        void refresh(){
            SDL_Flip(screen);
        }

        void clrscr(){
            SDL_Rect R;
            R.x =0; R.y =0;
            R.h = screen->h; R.w = screen->w;
            SDL_FillRect(screen,&R,0);
        
        }

        void resetZ()
        {
           delete[] Zbuffer;
           Zbuffer = new float[(screen->w)*(screen->h)]();
        }
        ~Screen()
        {
           
         if(screen)
         {
           SDL_FreeSurface(screen);
           screen = NULL;
         }
                SDL_Quit();
                delete[] Zbuffer;
        }
};



#endif // GRAPHICS_H_

