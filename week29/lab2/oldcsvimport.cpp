#include <iostream>
#include <fstream>
#include <string>

void csv_import(std::string data[][10], int columns, int *records, std::string filename){
  std::ifstream MyFile;
  std::string writein,temp;

  MyFile.open(filename);
  if(!MyFile){
    std::cerr << "File could not be opened" <<std::endl;
    exit( EXIT_FAILURE );
  }
  while(getline(MyFile,data[*records][0],',') && (*records)<10){
    for(int j=1;j<columns;j++){
      if(j<columns-1){
        getline(MyFile,data[*records][j],',');
      }else{
        getline(MyFile,data[*records][j],'\n');
      }
    }
    (*records)+=1;
  }
  MyFile.close();
}
