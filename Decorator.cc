#include "Decorator.h"


  Decorator::Decorator(Image *i): component{i} {}
  Decorator::~Decorator() {
    delete component;
  }
