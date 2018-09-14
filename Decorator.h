#include "image.h"
#include <vector>

#ifndef DECORATOR_H
#define DECORATOR_H

class Decorator: public Image {
protected:
  Image *component;
public:
  Decorator(Image *i);
  virtual ~Decorator();
};

#endif
