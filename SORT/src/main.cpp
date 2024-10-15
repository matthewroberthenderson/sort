#pragma once
#include <definitions.hpp>
#include <data.hpp>
#include <alg.hpp>

/* We will use this renderer to draw into this window every frame. */
static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;
static SDL_FPoint points[500];

/* This function runs once at startup. */
SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
    int i;

    SDL_SetAppMetadata("Example Renderer Primitives", "1.0", "com.example.renderer-primitives");

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("examples/renderer/primitives", 640, 480, 0, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    /* set up some random points */
    for (i = 0; i < SDL_arraysize(points); i++) {
        points[i].x = (SDL_randf() * 440.0f) + 100.0f;
        points[i].y = (SDL_randf() * 280.0f) + 100.0f;
    }

    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

/* This function runs when a new event (mouse input, keypresses, etc) occurs. */
SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;  /* end the program, reporting success to the OS. */
    }
    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

/* This function runs once per frame, and is the heart of the program. */
SDL_AppResult SDL_AppIterate(void* appstate)
{
    //for glow (some gross transp overdraw but oh well)
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    std::vector<int> arr = data::generate_data(data::gen_type::stochastic,NUM_ELEMENTS);
    SDL_Delay(100);
    alg::sort(alg::tim, renderer, arr);
    SDL_Delay(3000);
    SDL_RenderPresent(renderer);  /* put it all on the screen! */
    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
    /* SDL will clean up the window/renderer for us. */
}
