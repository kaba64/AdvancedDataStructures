#include <iostream>
#include <fstream>
#include <string>

void csv_export(std::string data[][10], int records,int columns, std::string filename){
  std::ofstream MyFile;
  std::string writeto;

  MyFile.open(filename);
  for (int i=0;i<records;i++){
    writeto="";
    for (int j=0;j<columns;j++){
      if(j<columns-1){
        writeto += data[i][j]+",";
      }else{
        writeto += data[i][j];
      }
    }
    MyFile<<writeto<<std::endl;
  }
  MyFile.close();
}
