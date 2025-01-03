#include "CApp.h"

#define SDL_WINDOW_WIDTH 1280
#define SDL_WINDOW_HEIGHT 720
//Default constructor
CApp::CApp(){
    isRunning = true;
    pWindow = NULL;
    pRenderer = NULL;
}

bool CApp::OnInit(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        return false;
    }

    pWindow = SDL_CreateWindow("qbRayTracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SDL_WINDOW_WIDTH, SDL_WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if(pWindow != NULL){
        pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
        m_image.Initialize(SDL_WINDOW_WIDTH, SDL_WINDOW_HEIGHT, pRenderer);

        //create some color variations
        for(int x = 0;x<SDL_WINDOW_WIDTH;x++){
            for(int y = 0;y<SDL_WINDOW_HEIGHT;y++){
                double red = (static_cast<double>(x))/SDL_WINDOW_WIDTH * 255;
                double green = (static_cast<double>(y))/SDL_WINDOW_WIDTH * 255;
                m_image.SetPixel(x, y, red, green, 0);
            }
        }
    }
    else{
        return false;
    }

    return true;
}

int CApp::OnExecute(){
    SDL_Event event;
    if(OnInit() == false){
        return -1;
    }

    while(isRunning){
        while(SDL_PollEvent(&event) != 0){
            OnEvent(&event);
        }

        OnLoop();
        OnRender();
    }
}

void CApp::OnEvent(SDL_Event *event){
    if(event->type == SDL_QUIT){
        isRunning = false;
    }
}

void CApp::OnLoop(){

}

void CApp::OnRender(){
    //Make background color white
    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255); //rgbalpha
    SDL_RenderClear(pRenderer);
    m_image.Display();
    SDL_RenderPresent(pRenderer);
}

void CApp::OnExit(){
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    pWindow = NULL;
    SDL_Quit();
}