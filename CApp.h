#ifndef CAPP_H
#define CAPP_H

#include <SDL2/SDL.h>
#include "qbImage.hpp"

class CApp
{
    public:
        CApp();

        int OnExecute();
        bool OnInit();
        void OnEvent(SDL_Event *event);
        void OnLoop();
        void OnRender();
        void OnExit();
    
    private:
        //SDL2 stuff
        bool isRunning;
        qbImage m_image;
        SDL_Window *pWindow;
        SDL_Renderer *pRenderer;
};

#endif