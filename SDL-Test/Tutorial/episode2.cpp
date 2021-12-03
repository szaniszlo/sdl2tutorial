//
//  episode2.cpp
//  SDL-Test
//
//  Created by Stefan Szaniszlo on 03/12/2021.
//

#include "episode2.hpp"


void Episode2::render() {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);
    SDL_RenderSetViewport(renderer, nullptr);
    SDL_RenderClear(renderer);
    
    draw();
    
    SDL_RenderPresent(renderer);
}

void Episode2::draw() {
    
    // vertical green lines
    SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, SDL_ALPHA_OPAQUE);
    for (int w = 200; w < width; w += 200) {
        SDL_RenderDrawLine(renderer, w, 0, w, height);
    }
    
    // red rectangle
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, SDL_ALPHA_OPAQUE);
    SDL_Rect rect = {50, 50, 100, 100};
    SDL_RenderDrawRect(renderer, &rect);
    
    // blue filled rectangle
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, SDL_ALPHA_OPAQUE);
    rect = {250, 50, 100, 100};
    SDL_RenderFillRect(renderer, &rect);
    
    // black points
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
    SDL_Point points[] = {
        {150, 50}, {25, 75}, {120, 150}, {150, 125}
    };
    rect = {400, 0, 200, 200};
    SDL_RenderSetViewport(renderer, &rect);
    SDL_RenderDrawPoints(renderer, points, 4);
    
    // black lines
    rect = {600, 0, 200, 200};
    SDL_RenderSetViewport(renderer, &rect);
    SDL_RenderDrawLines(renderer, points, 4);
}
