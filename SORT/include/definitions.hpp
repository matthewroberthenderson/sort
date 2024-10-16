#pragma once
#define SDL_MAIN_USE_CALLBACKS 1  /* use the callbacks instead of main() */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <definitions.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800; 
const int ELEMENT_SCALE = WINDOW_WIDTH / 150;
const int NUM_ELEMENTS = WINDOW_WIDTH / ELEMENT_SCALE;
const int RUN = NUM_ELEMENTS / 10; //FOR TIM

namespace alg
{
    enum sort_alg
    {
        quick,
        bubble,
        tim
    };
}
namespace data
{
    enum gen_type
    {
        stochastic,
        backward,
        signalsine
    };



}
