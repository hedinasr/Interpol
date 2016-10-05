#ifndef _SCENE_H
#define _SCENE_H

#include "Animation.h"
#include "Image.h"
#include "Paving.hpp"

//! The structure Scene stores all texture Id or images used by the sceneDraw fonction
struct Scene
{
  Animation anim;
	Image terrain;
  unsigned int tex_papillon;
	unsigned int tex_terrain;
  unsigned int tex_arbre;
  unsigned int tex_eau;
  unsigned int tex_cube;
};

//! Dessine les arbres
void draw_arbre();

//! Dessine un terrain
void terraindraw(const Image & im, const Scene & sc);

//! Dessine les normales en chaque points du terrain
void terrainNormal(const Image & im, const int i, const int j);

//! Init a Scene
void sceneInit(Scene& sc);

//! Draw the scene
void sceneDraw(const Scene& sc, int dim, const std::vector<std::vector<float> >& matrix);

//! Draw a cube
void draw_cube();

//! Draw a cylinder
void draw_cylinder();

//! Draw a cone
void draw_cone();

//! Draw a sphere
void draw_sphere();

//! Draw the X,Y,Z axes
void draw_axes();

//! Draw a grid in the XZ plane
void draw_grid();

//! Draw a 2-simplex
void draw_simplex(const Simplex<2> &simplex);

//! Draw a 3-simplex
void draw_simplex(const Simplex<3> &simplex);

//! Draw a 4-simplex
void draw_simplex(const Simplex<4> &simplex);

#endif
