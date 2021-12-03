//
//  engine.cpp
//  SDL-Test
//
//  Created by Stefan Szaniszlo on 03/12/2021.
//

#include "engine.hpp"

#include <cstdio>
#include <iostream>


Engine::Engine() {
    success = true;
    quit = false;
    
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        sprintf(errMsg, "Error while initialising SDL2: %s", SDL_GetError());
        success = false;
        return;
    }
}

Engine::~Engine() {
    SDL_Quit();
}

bool Engine::init(const std::string title, int width, int height) {
    
    if (!success) return success;
    
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              width, height, SDL_WINDOW_SHOWN);
    if (!window) {
        sprintf(errMsg, "Error while creating window: %s", SDL_GetError());
        success = false;
        return success;
    }
    
    this->width = width;
    this->height = height;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED /*SDL_RENDERER_SOFTWARE*/);
    if(!renderer) {
        sprintf(errMsg, "Error while creating renderer: %s", SDL_GetError());
        success = false;
    }
    
    return success;
}

void Engine::clear() {
    if(renderer) SDL_DestroyRenderer(renderer);
    if(window) SDL_DestroyWindow(window);
}

void Engine::loop() {
    SDL_Event event;
    while(!quit) {
        while(SDL_PollEvent(&event)) {
            handleEvent(event);
        }
        render();
        update();
    }
}

void Engine::handleEvent(SDL_Event &event) {
    if (event.type == SDL_QUIT) {
        quit = true;
    }
}

void Engine::errorToConsole() {
    if (!success) {
        std::cerr << errMsg << std::endl;
    }
}
