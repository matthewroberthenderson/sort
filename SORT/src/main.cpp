#pragma once
#include <definitions.hpp>
#include <data.hpp>
#include <alg.hpp>



/* We will use this renderer to draw into this window every frame. */
static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;
static SDL_FPoint points[500];


SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{

    SDL_SetAppMetadata("Sorting Playground SDL3 Visualisation", "1.0", "com.matthewhenderson.sorting");

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("Sorting Playground SDL3 Visualisation", fint(WINDOW_WIDTH), fint(WINDOW_HEIGHT), 0, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }


    return SDL_APP_CONTINUE;  
}


SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;  
    }
    return SDL_APP_CONTINUE;  
}


SDL_AppResult SDL_AppIterate(void* appstate)
{
    //for glow (some gross transp overdraw but oh well)
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    
    //run sorting visualisation
    std::vector<int> arr = data::generate_data(data::gen_type::signalsine, fint(NUM_ELEMENTS));
    SDL_Delay(100);
    alg::sort(alg::bubble, renderer, arr);

    SDL_Delay(3000);
    SDL_RenderPresent(renderer); 
    return SDL_APP_CONTINUE;  
}


void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
   
}
