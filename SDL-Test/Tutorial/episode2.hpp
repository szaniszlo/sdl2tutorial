//
//  episode2.hpp
//  SDL-Test
//
//  Created by Stefan Szaniszlo on 03/12/2021.
//

#ifndef episode2_hpp
#define episode2_hpp

#include "engine.hpp"


class Episode2: public Engine {
public:
    virtual void render() override;
    virtual void draw();

private:
    int direction = 1;
    unsigned char gradient = 0x00;
};

#endif /* episode2_hpp */
