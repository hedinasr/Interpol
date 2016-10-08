#include <unistd.h>

#include "LeapCamera.hpp"

LeapCamera::LeapCamera() {}

LeapCamera::~LeapCamera() {}

void LeapCamera::moveCamera(Camera& camera) {
  /* avoid thrashing this procedure */
  usleep(100);

  switch (this->getDirection()) {
  case 0:
    printf("FRONT\n");
    camTranslate(camera, FRONT);
    break;

  case 1:
    printf("BACK\n");
    camTranslate(camera, BACK);
    break;

  case 2:
    printf("LEFT\n");
    camTranslate(camera, LEFT);
    break;

  case 3:
    printf("RIGHT\n");
    camTranslate(camera, RIGHT);
    break;
  default:
    break;
  }
}
