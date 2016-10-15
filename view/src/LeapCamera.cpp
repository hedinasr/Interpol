#include <unistd.h>
#include <vector>

#include "LeapCamera.hpp"

LeapCamera::LeapCamera() {}

LeapCamera::~LeapCamera() {}

void LeapCamera::moveCamera(Camera& camera) {
  /* avoid thrashing this procedure */
  //usleep(100);
  printf("queue size : %d\n", this->rotations.size());
  // Rotation
  // TODO affiné la rotation

  while(!this->rotations.empty()) {
    camStartMove(camera, CAMERA_ROTATION, camera.mx, camera.my);
    if(this->rotations.front() == 1)
      {
        camMove(camera, camera.mx - 1, camera.my);
        this->rotations.pop();
      }
    if(this->rotations.front() == 2)
      {
        camMove(camera, camera.mx + 1, camera.my);
        this->rotations.pop();
      }
  }

  // Translation
  switch (this->getDirection()) {
  case 0:
    //printf("FRONT\n");
    camTranslate(camera, FRONT);
    break;

  case 1:
    //printf("BACK\n");
    camTranslate(camera, BACK);
    break;

  case 2:
    //printf("LEFT\n");
    camTranslate(camera, LEFT);
    break;

  case 3:
    //printf("RIGHT\n");
    camTranslate(camera, RIGHT);
    break;
  default:
    break;
  }
}
