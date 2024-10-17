#pragma once
#define fint(x) static_cast<int>(x)
#define SDL_MAIN_USE_CALLBACKS 1  /* use the callbacks instead of main() */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <definitions.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 800; 
const float ELEMENT_SCALE = WINDOW_WIDTH / 150;
const float NUM_ELEMENTS = WINDOW_WIDTH / ELEMENT_SCALE;
const int RUN = int(NUM_ELEMENTS / 10); //FOR TIM


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
