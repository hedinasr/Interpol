#ifndef _OPENGL_H
#define _OPENGL_H

#if __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//! A appeller juste avant la boucle principale (Main Loop)
void GLInit(GLsizei Width, GLsizei Height);

//! Quand la fenetre est 'resiz�e'
void GLResize(GLsizei Width, GLsizei Height);

//! Pour changer la couleur du Ambiant/Diffus/Speculaire en m�me temps
void GLColor(const float r, const float g, const float b);

//! The main drawing function
void GLDraw(void);

//! Quand une touche est press�e
void keyPressed(unsigned char key, int x, int y);

//! The function called whenever a normal key is pressed
void specialKeyPressed(int key, int x, int y);

//! Load texture and return the GL identifier
enum LOADGLTEXTURE_OPTIONS { LOADGLTEX_EQUAL=0, LOADGLTEX_GREATER=1, LOADGLTEX_LOWER=2};
unsigned int LoadGLTexture(const char* nomfichier,
                           bool isTransparency,
                           const unsigned char R=255,
                           const unsigned char G=255,
                           const unsigned char B=255,
                           int option=LOADGLTEX_EQUAL);

#endif
