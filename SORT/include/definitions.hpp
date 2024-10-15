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

const int WINDOW_WIDTH = 512;
const int WINDOW_HEIGHT = 512;
const int NUM_ELEMENTS = 150;
const int RECT_WIDTH = WINDOW_WIDTH / NUM_ELEMENTS;
const int RUN = 32; //FOR TIM

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
