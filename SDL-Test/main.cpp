//
//  main.cpp
//  SDL-Test
//
//  Created by Stefan Szaniszlo on 02/12/2021.
//
//
//  Following the SDL2 tutorial playlist at https://www.youtube.com/playlist?list=PLJ-vQubfi2yEfPCqb1lr9GX2Kc1NhU4du
//

#include <cstdio>
#include <iostream>

#include <SDL2/SDL.h>

#include "Tutorial/episode2.hpp"

int main(int argc, const char **argv) {

    Engine *engine = new Episode2();
    
    if (!engine->init("SDL Test", 800, 200)) {
        engine->errorToConsole();
        engine->clear();
        delete engine;
        return 1;
    }

    engine->loop();
    engine->clear();
    
    delete engine;
    std::cout << "Exiting!" << std::endl;
    return 0;
}
