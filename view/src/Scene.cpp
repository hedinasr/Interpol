#include "Scene.h"

#include <iostream>
#include <time.h>

#include "opengl.h"

void draw_axes() {
  glLineWidth(5);
  glBegin(GL_LINES);

  glColor3f(1.f, 0.f, 0.f);
  glVertex3f(0.f, 0.f, 0.f);
  glVertex3f(1.f, 0.f, 0.f);

  glColor3f(0.f, 1.f, 0.f);
  glVertex3f(0.f, 0.f, 0.f);
  glVertex3f(0.f, 1.f, 0.f);

  glColor3f(0.f, 0.f, 1.f);
  glVertex3f(0.f, 0.f, 0.f);
  glVertex3f(0.f, 0.f, 1.f);

  glEnd();
}

void draw_grid() {
  int i;
  glLineWidth(1);
  glColor3f(1.f, 1.f, 1.f);

  glPushMatrix();
  glTranslatef(-5, 0, -5);

  glBegin(GL_LINES);

  for (i = 0; i <= 10; ++i) {
    glVertex3f(i, 0, 0);
    glVertex3f(i, 0, 10);
  }

  for (i = 0; i <= 10; ++i) {
    glVertex3f(0, 0, i);
    glVertex3f(10, 0, i);
  }

  glEnd();
  glPopMatrix();
}

void draw_quad() {
  glBegin(GL_TRIANGLE_STRIP);

  glNormal3f(0, 0, 1);
  glTexCoord2f(0, 0);
  glVertex3f(-0.5, 0, 0);

  glNormal3f(0, 0, 0);
  glTexCoord2f(1, 0);
  glVertex3f(0.5, 0, 0);

  glNormal3f(0, 1, 1);
  glTexCoord2f(0, 1);
  glVertex3f(-0.5, 1, 0);

  glNormal3f(0, 1, 0);
  glTexCoord2f(1, 1);
  glVertex3f(0.5, 1, 0);

  glEnd();
}

void sceneInit(Scene &sc) {}

// 2D
void draw_simplex(const Simplex<2> &simplex) {
  for (int i = 0; i < simplex.getSize(); i++) {
    glBegin(GL_LINES);
    glVertex2f(simplex[i].at(0), simplex[i].at(1));
    glVertex2f(simplex[(i + 1) % (simplex.getSize())].at(0),
               simplex[(i + 1) % (simplex.getSize())].at(1));
    glEnd();
  }
}

// 3D
void draw_simplex(const Simplex<3> &simplex) {
  for (int i = 0; i < simplex.getSize(); i++) {
    glBegin(GL_LINES);
    glVertex3f(simplex[i].at(0), simplex[i].at(1), simplex[i].at(2));
    glVertex3f(simplex[(i + 1) % simplex.getSize()].at(0),
               simplex[(i + 1) % simplex.getSize()].at(1),
               simplex[(i + 1) % simplex.getSize()].at(2));
    glEnd();
  }
}

// 4D
void draw_simplex(const Simplex<4> &simplex) {
  for (int i = 0; i < simplex.getSize(); i++) {
    glBegin(GL_LINES);
    glVertex4f(simplex[i].at(0), simplex[i].at(1), simplex[i].at(2), simplex[i].at(3));
    glVertex4f(simplex[(i + 1) % simplex.getSize()].at(0),
               simplex[(i + 1) % simplex.getSize()].at(1),
               simplex[(i + 1) % simplex.getSize()].at(2),
               simplex[(i + 1) % simplex.getSize()].at(3));
    glEnd();
  }
}

void sceneDraw(const Scene &sc, int dim,
               const std::vector<std::vector<float>> &matrix) {
  glPushMatrix();
  glScalef(0.1f, 0.1f, 0.1f);
  switch (dim) {
  case 1: { // 1D
    std::vector<Point<1>> v_points;
    for (size_t i = 0; i < matrix.size(); i++) {
      // recupère toutes les coordonnées (sauf la dernière)
      std::vector<float> _matrix(matrix[i].begin(), matrix[i].end() - 1);
      // on ajoute la valeur (dernier élément du vector)
      v_points.push_back(Point<1>(_matrix, matrix[i].back()));
    }
    Paving<1> pav(v_points);
    pav.init();
    break;
  }
  case 2: { // 2D
    std::vector<Point<2>> v_points;
    for (size_t i = 0; i < matrix.size(); i++) {
      std::vector<float> _matrix(matrix[i].begin(), matrix[i].end() - 1);
      v_points.push_back(Point<2>(_matrix, matrix[i].back()));
    }
    Paving<2> pav(v_points);
    pav.init();
    for (unsigned i = 0; i < pav.multiplex.size(); i++)
      draw_simplex(pav.multiplex[i]);
    break;
  }
  case 3: { // 3D
    std::vector<Point<3>> v_points;
    for (size_t i = 0; i < matrix.size(); i++) {
      std::vector<float> _matrix(matrix[i].begin(), matrix[i].end() - 1);
      v_points.push_back(Point<3>(_matrix, matrix[i].back()));
    }
    Paving<3> pav(v_points);
    pav.init();
    for (unsigned i = 0; i < pav.multiplex.size(); i++)
      draw_simplex(pav.multiplex[i]);
    break;
  }
  case 4: { // 4D
    std::vector<Point<4>> v_points;
    for (size_t i = 0; i < matrix.size(); i++) {
      std::vector<float> _matrix(matrix[i].begin(), matrix[i].end() - 1);
      v_points.push_back(Point<4>(_matrix, matrix[i].back()));
    }
    Paving<4> pav(v_points);
    pav.init();
    for (unsigned i = 0; i < pav.multiplex.size(); i++)
      draw_simplex(pav.multiplex[i]);
    break;
  }
  }

  glPopMatrix();
}
