#ifndef INVERT
#define INVERT

#include<fstream>
#include<iterator>
#include<sstream>
#include<iostream>
#include<vector>
#include<string>
#include "../dependencies/CImg.h" //external image processing library

#define JPG_HEADER_LEN 22
#define JPG_TAIL 2

namespace invertimg{

  template<class Container>
  Container binary_load(std::string const & filePath){

    std::ifstream in(filePath,std::ios::binary);

    if(!in){
      throw std::runtime_error("Could not open file: " + filePath);
    }

    std::noskipws(in);
    return Container(std::istream_iterator<std::uint8_t>(in),
                     std::istream_iterator<std::uint8_t>());

  }


  //dev function for displaying the hex values of image in console
  template<class Container>
  void binary_readhex(Container data){

    std::cout << "Image data in hex: \n\n";

    for(auto it = data.begin(); it!=data.end(); it++){
      //10 rows
      for(int i(0); i < 16; i++){
        std::stringstream stream;
        stream << "0x" << std::hex << (int) *it;
        std::string hexresult(stream.str());
        std::cout << hexresult << " ";
      }
      std::cout << std::endl;
    }

  }

/* Old unfinished low level method
  template<class Container>
  void invert_image(Container &data, const char* imagetype){

    int count = 0;

    for(auto it = data.begin(); it < data.end() - JPG_TAIL; it++){

      //only change hex values when the iterator has passed the file header bits
      if(count > JPG_HEADER_LEN){

        std::stringstream ss;
        uint8_t val = (uint8_t) *it;
        val = ~val; //invert bits
        *it = val;
      }

      count++;
    }

  }
  */


  template<class Container>
  void binary_save(Container && data, std::string const & output){

      std::ofstream out(output, std::ios::binary);

      if(!out){
        throw std::runtime_error("Could not output file: " + output);
      }

      std::copy(data.begin(), data.end(),
                std::ostream_iterator<uint8_t>(out, ""));

  }

  void read(std::string const &);

  bool invert(std::string const &, std::string const &);

}




#endif
