#include "Decorator.h"

#ifndef ROTATE_H
#define ROTATE_H

class Rotate: public Decorator {
public:
  Rotate(Image *i);
  void render(PPM &ppm) override;

};

#endif
