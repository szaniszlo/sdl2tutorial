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
    SDL_Renderer *renderer;
    int width, height;

private:
    bool success;
    bool quit;
    char errMsg[1024];
    
    SDL_Window *window;
    
};

#endif /* engine_hpp */
