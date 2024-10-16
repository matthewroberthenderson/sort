#pragma once
#include <iostream>

namespace vis
{
    struct col
    {
        int r = 0;
        int b = 0;
        int g = 0;
    };

    void arrow(SDL_Renderer *renderer, int x, int y, int width, int height, col color)
    {
        int bl = 4;  // blur range
        int ga = 10; // glow amount;
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, ga);

        for (int i = 4; i > 0; --i)
        {
            for (int j = 4; j > 0; --j)
            {
                // this is just for lines glow
                SDL_RenderLine(renderer, (x - sin(i) * bl) + width, (y - cos(j) * bl) + height, (x - sin(i) * bl), (y - cos(j) * bl) + height);
                SDL_RenderLine(renderer, (x - sin(i) * bl), (y - cos(j) * bl), (x - sin(i) * bl), (y - cos(j) * bl) + height);
                SDL_RenderLine(renderer, (x + sin(i) * bl) + width, (y + cos(j) * bl), (x + sin(i) * bl) + width, (y + cos(j) * bl) + height);
                SDL_RenderLine(renderer, (x - sin(i) * bl) + width, (y - cos(j) * bl), (x - sin(i) * bl), (y - cos(j) * bl));
            }
        }

        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
        SDL_RenderLine(renderer, x + width, y + height, x, y + height);
        SDL_RenderLine(renderer, x, y, x, y + height);
        SDL_RenderLine(renderer, x + width, y, x + width, y + height);
        SDL_RenderLine(renderer, x + width,
                       y, x, y);
    }

    void renderArray(SDL_Renderer *renderer, const std::vector<int> &arr, const std::vector<int> &highlights)
    {
        SDL_SetRenderDrawColor(renderer, 0, 121, 140, 255); // Black background
        SDL_RenderClear(renderer);

        col color;
        for (int i = 0; i < arr.size(); i++)
        {
            // Check if current exists in highlights vector
            if (std::find(highlights.begin(), highlights.end(), i) != highlights.end())
            {
                color.r = 209;
                color.g = 73;
                color.b = 91;

                //(renderer, 255, 0, 0, 255); // red
            }
            else
            {
                color.r = 237;
                color.g = 174;
                color.b = 73;
                // SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); //green
            }


            arrow(renderer, i * ELEMENT_SCALE, (WINDOW_HEIGHT/2) - (arr[i] / 2.0), ELEMENT_SCALE, arr[i], color);
        }

        SDL_RenderPresent(renderer);
    }
}
