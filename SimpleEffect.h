//
//  SimpleEffect.h
//  Ders 7
//
//  Created by Gurel Erceis on 4/15/13.
//  Copyright (c) 2013 Yogurt3D. All rights reserved.
//

#ifndef Ders_7_SimpleEffect_h
#define Ders_7_SimpleEffect_h
#include "Effect.h"
#include "SOIL.h"

GLint LoadGLTexture(const char *filename)
{
    GLuint _texture;
    
    _texture = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture 
	(
     filename,
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT 
     );
    
    // check for an error during the load process 
    if(_texture == 0)
    {
	    printf( "SOIL loading error: '%s'\n", SOIL_last_result() );
    }
	
    return _texture;
}

class SimpleEffect: public Effect{
public:
    SimpleEffect(int* screen_width, int* screen_height):Effect("effect_simple.frag",screen_width, screen_height){
        UniformOffset = glGetUniformLocation(programID, "offset");
        if (UniformOffset == -1) {
            fprintf(stderr, "Could not bind attribute %s\n", "offset");
        } 
    }
    virtual void draw(){
		glEnable(GL_TEXTURE_1D);
		UniformRamp = LoadGLTexture("Sample.jpg");
		glBindTexture(GL_TEXTURE_1D, UniformRamp);
		glBindTexture(GL_TEXTURE_2D, fbo_texture);
		Effect::draw();
    }
private:
    GLuint UniformOffset;
};

#endif
