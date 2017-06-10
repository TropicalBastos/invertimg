#include "invert.h"

using namespace cimg_library;

const char* PNG = "PNG";
const char* JPG = "JPG";

void invertimg::invert(const std::string& filePath, const std::string& fileOutput){
    /*
    int len = filePath.length();
    const char* fp = (const char*) filePath.c_str();
    const char* fs = (const char*) fileOutput.c_str();
    CImg<unsigned char> original(fp);


    CImg<unsigned char> resultImg(original.width(),original.height());



    //CImg<unsigned char> inverted = original.invert();
    //inverted.save(fs);
    */
  }

void invertimg::read(std::string const & file){
  auto data = invertimg::binary_load<std::vector<uint8_t>>(file);
  invertimg::binary_readhex(data);
}
