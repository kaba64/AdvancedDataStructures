#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void csv_import(std::string data[][10], int columns, int *records, std::string filename){
  std::ifstream MyFile;
  std::string writein,temp, line;
  int j;

  MyFile.open(filename);
  if(!MyFile){
    std::cerr << "File could not be opened" <<std::endl;
    exit( EXIT_FAILURE );
  }
  while(MyFile >> temp && (*records)<10){
    std::stringstream s(temp);
    j =0;
    while(getline(s,writein,',')) {
      data[*records][j]=writein;
      j+=1;
    }
    (*records)+=1;
  }
  MyFile.close();
}
