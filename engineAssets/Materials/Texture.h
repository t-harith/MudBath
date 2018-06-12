//
//  Texture.h
//  MudBath
//
//  Created by Tejas Harith on 6/11/18.
//  Copyright © 2018 Tejas Harith. All rights reserved.
//

#ifndef Texture_h
#define Texture_h

#ifndef ASSERT_debug
    #define ASSERT_debug
    #define ASSERT(x) if(!x) { __asm__("int $3"); }
#endif

#endif /* Texture_h */

class Texture
{
public:
    Texture()
    {
        ASSERT(false);
    }
};
