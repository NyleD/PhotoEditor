#include "Decorator.h"

#ifndef SEPIA_H
#define SEPIA_H

class Sepia: public Decorator {
public:
  Sepia(Image *i);
  void render(PPM &ppm) override;
};

#endif
