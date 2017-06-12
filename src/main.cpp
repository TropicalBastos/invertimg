#include<string>
#include<regex>
#include<iostream>
#include<fstream>
#include<vector>
#include<typeinfo>
#include "invert.h"

#define USAGE "Usage: invertimg [filePath] [fileOutput]"
#define FILETYPE "Current file types supported: png, jpg"
#define PNG "PNG"
#define JPG "JPG"
#define JPEG "JPG"
#define ERROR "\033[1;31merror: \033[0m"

using namespace std;

typedef struct ImageData{
  const char* imageType;
  bool compatible;
} IMAGEDATA;

bool fileExists(string filePath){
  cout << "Checking file ..." << endl;
  ifstream file(filePath);
  return file.good();
}

bool isCompatibleFileType(const string& filePath, IMAGEDATA& imagedata){

  bool isCompatible = false;
  regex pngR(".*[.]png$");
  regex jpgR(".*[.]jpg$");

  if(regex_match(filePath,pngR)){

    imagedata.imageType = PNG;
    imagedata.compatible = true;
    return true;

  }else if(regex_match(filePath, jpgR)){

    imagedata.imageType = JPG;
    imagedata.compatible = true;
    return true;

  }else{

    return false;

  }
}

void invertimage(const string& filePath, const string& fileOutput){

}

int main(int argc, char** argv){

  IMAGEDATA id;

  if(argc < 3){
    cerr << ERROR << "Not enough arguments specified, aborting." << endl;
    cout << USAGE << endl;
    return 0;
  }

  if(argc > 3){
    cerr << ERROR << "Too many arguments specified" << endl << USAGE
     << endl;
     return 0;
  }

  const string imageFile(argv[1]);
  const string output(argv[2]);


  if(!fileExists(imageFile)){
      cerr << ERROR << "File at path " << argv[1] << " does not exist" << endl;
      return 0;
  }

  if(!isCompatibleFileType(imageFile, id) ||
     !isCompatibleFileType(output, id)){

      cerr << ERROR << "Incorrect file type specified: " << imageFile << endl <<
      FILETYPE << endl << USAGE << endl;
      return 0;

  }

  cout << "Correct file type, proceeding..." << endl;

  if(!invertimg::invert(imageFile, output)){

    cerr << "Error: could not write file, check arguments and file type"
    << endl;

    return 0;

  }

  cout << "Image file inverted successfully!\n";

  return 0;
}
