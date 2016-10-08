#ifndef LEAP_SERVER_HPP
#define LEAP_SERVER_HPP

#include "Leap.h"

enum Direction { FORWARD, BACKWARD, R, L, UNDEFINED };

using namespace Leap;

class LeapServer : public Listener {

private:
  Direction direction;
  Controller controller;

public:
  LeapServer() {
    direction = UNDEFINED;
  };
  ~LeapServer() {
    controller.removeListener(*this);
  };
  virtual void onConnect(const Controller &) {
    fprintf(stdout, "Leap connected : %d!\n", controller.isConnected());
  };
  virtual void onFrame(const Controller &) {
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
    }
  };
  // Retourne la direction du vecteur de la main
  Direction findDirection(const Vector & vector) {
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
  };
};

#endif // LEAP_SERVER_HPP
