#ifndef LEAP_SERVER_HPP
#define LEAP_SERVER_HPP

#include "Leap.h"

enum Direction { FORWARD, BACKWARD, R, L, UNDEFINED };

using namespace Leap;

class LeapServer : public Listener {

private:
  Direction direction; // current hand direction
  Direction gesture; // current gesture
  Controller controller;

public:
  LeapServer();
  ~LeapServer();
  virtual void onConnect(const Controller &);
  virtual void onFrame(const Controller &);
  virtual void onDeviceFailure(const Controller &);
  // Retourne la direction du vecteur de la main
  Direction findDirection(const Vector & vector);
  // getter
  Direction getDirection();
  Direction getGesture();
};

#endif // LEAP_SERVER_HPP
