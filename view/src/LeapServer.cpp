#include "LeapServer.hpp"

LeapServer::LeapServer() {
  printf("instance of Leap\n");
  direction = UNDEFINED;
  controller.addListener(*this);
}

LeapServer::~LeapServer() {
  controller.removeListener(*this);
}

void LeapServer::onConnect(const Controller & controller) {
  fprintf(stdout, "Leap connected : %d!\n", controller.isConnected());
}

void LeapServer::onFrame(const Controller & controller) {
  const Frame frame = controller.frame();
  FingerList fingers = frame.fingers().extended();
  Hand hand = frame.hands()[0];

  // Si la main est valide + 5 doigts
  if (hand.isValid() && fingers.count() == 5) {
    Direction tempDirection = findDirection(hand.palmPosition());
    if (tempDirection != direction) {
      fprintf(stdout, "tempDirection : %d\n", tempDirection);
      // MAJ de la direction
      direction = tempDirection;
    }
  } else {
    direction = UNDEFINED;
  }
}

void LeapServer::onDeviceFailure(const Controller &) {
  printf("Failure\n");
}

// Retourne la direction du vecteur de la main
Direction LeapServer::findDirection(const Vector & vector) {
  if (vector.x > 90) { // Droite
    return L;
  } else if (vector.x < -90) { // Gauche
    return R;
  } else if (vector.z < -90) { // Haut
    return FORWARD;
  } else if (vector.z > 90) { // Bas
    return BACKWARD;
  } else {
    return UNDEFINED;
  }
}

Direction LeapServer::getDirection() {
  return this->direction;
}
