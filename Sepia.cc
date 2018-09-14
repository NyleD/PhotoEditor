#include "Sepia.h"

using namespace std;

Sepia::Sepia(Image *i): Decorator{i} {}

void Sepia::render(PPM &ppm) {

  component->render(ppm);

  const int width = ppm.getWidth();
  const int height = ppm.getHeight();
  vector<Pixel> &pixels = ppm.getPixels();
  vector<Pixel> newPixels; // Filtered values of pixels stored

newPixels.reserve(height * width);

for(int k = 0; k < (height * width); k++) {
	newPixels[k] = pixels[k];
}

int size = pixels.size();

 for(int i = 0; i < size; ++i) {

Pixel &p = pixels[i];
Pixel &np = newPixels[i];

      // Get new values for pixel
      np.r = p.r *.393 + p.g * .769 + p.b * .189;
      np.g = p.r *.349 + p.g * .686 + p.b * .168;
      np.b = p.r *.272 + p.g * .534 + p.b * .131;

      // values above exceed 255, then set them to the maximum value of 255
      if(np.r > 255){
        np.r = 255;
      }
      if(np.g > 255){
        np.g = 255;
      }
      if(np.b > 255){
        np.b = 255;
      }
}

// Add filtered values back to pixels 
for(int k = 0; k < (height * width); k++) {
        pixels[k] = newPixels[k];
}




}
