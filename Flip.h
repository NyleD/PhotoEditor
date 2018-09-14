#include <utility>
#include "Decorator.h"

#ifndef FLIP_H
#define FLIP_H

class Flip: public Decorator {
public:

  Flip(Image *i);

  void render(PPM &ppm) override;

};

#endif
