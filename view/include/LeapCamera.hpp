#ifndef LEAP_CAMERA_HPP
#define LEAP_CAMERA_HPP

#if __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "LeapServer.hpp"
#include "Camera.h"

class LeapCamera : public LeapServer {

private:
  Camera cam;
public:
  LeapCamera(const Camera &);
  ~LeapCamera();
  void moveCamera(Camera &);
};

#endif // LEAP_CAMERA_HPP
