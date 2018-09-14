#include "Flip.h"

using namespace std;

  Flip::Flip(Image *i): Decorator{i} {}

  void Flip::render(PPM &ppm) {

  component->render(ppm);

  const int width = ppm.getWidth();
  const int height = ppm.getHeight();
  vector<Pixel> &pixels = ppm.getPixels();


   int w = 0;
   int h = 0;
   int swapWIndex;
   int nr;
   int nb;
   int ng;

   for(h = 0; h < height; h++) {

     for(w = 0; (h * width + w) < ((h * width) + (width - 1 - w)); w++) {

	swapWIndex = (h * width) + (width - 1 - w);

// Get pixels current Index
       nr = pixels[h * width + w].r;
       ng = pixels[h * width + w].g;
       nb = pixels[h * width + w].b;

// Add SwapIndex pixels to current pixels
       pixels[h * width + w].r = pixels[swapWIndex].r;
       pixels[h * width + w].g = pixels[swapWIndex].g;
       pixels[h * width + w].b = pixels[swapWIndex].b;

// Add current pixels to SwapIndex 
       pixels[swapWIndex].r = nr;
       pixels[swapWIndex].g = ng;
       pixels[swapWIndex].b = nb;


     }
   }
  }
