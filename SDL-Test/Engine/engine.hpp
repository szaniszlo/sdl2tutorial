//
//  engine.hpp
//  SDL-Test
//
//  Created by Stefan Szaniszlo on 03/12/2021.
//

#ifndef engine_hpp
#define engine_hpp

#include <string>
#include "sdl.hpp"


class Engine {
public:
    Engine();
    virtual ~Engine();
  
    virtual bool init(const std::string title, int width, int height);
    
    virtual void clear();
    
    virtual void loop();
    
    virtual void handleEvent(SDL_Event &event);
    
    virtual void render() { }
    
    virtual void update() { }
    
    virtual void errorToConsole();

public:
    SDL_Renderer *renderer = nullptr;
    int width, height = 0;

private:
    bool success = true;
    bool quit = false;
    char errMsg[1024] = "";
    
    SDL_Window *window = nullptr;
    
};

#endif /* engine_hpp */
