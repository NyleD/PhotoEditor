#include "Rotate.h"

using namespace std;

Rotate::Rotate(Image *i): Decorator{i} {}

void Rotate::render(PPM &ppm) {

component->render(ppm);

int &width = ppm.getWidth();
int &height = ppm.getHeight();
vector<Pixel> &pixels = ppm.getPixels();


 vector<Pixel> newPixels;


newPixels.reserve(height * width);


 for(int j = 0; j < height; j++) {
   for(int i = 0; i < width; i++) {
  // Add Rotated Pixel to NewPixel
   newPixels[i * height + j] = pixels[width *(height - j - 1) + i];
   }
 }

// Add all Rotated newPixels back to pixels
for(int k = 0; k < (height * width); k++){
pixels[k] = newPixels[k];
}

// Adjust Rotated Height and Width
 int temp = width;
 width = height;
 height = temp;

}
