#include "invert.h"

const char* PNG = "PNG";
const char* JPG = "JPG";

using namespace cimg_library;

void invertimg::read(std::string const & file){

  auto data = invertimg::binary_load<std::vector<uint8_t>>(file);
  invertimg::binary_readhex(data);

}

bool invertimg::invert(std::string const & filePath,
                       std::string const & output){

  const int MAX_RGB = 0xff;
  const char* fp = filePath.c_str();
  const char* out = output.c_str();
  CImg<unsigned char> img(fp);

  for(int y = 0; y < img.height(); y++){

    for(int x = 0; x < img.width(); x++){

      int R = (int) img(x,y,0);
      int G = (int) img(x,y,1);
      int B = (int) img(x,y,2);

      img(x,y,0) = MAX_RGB - R;
      img(x,y,1) = MAX_RGB - B;
      img(x,y,2) = MAX_RGB - G;

    }

  }

  try{

    img.save(out);

  }catch(std::exception & e){

    return false;

  }

  return true;

}
