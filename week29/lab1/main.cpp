#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void csv_import(std::string data[][10], int columns, int *records, std::string filename){
  std::ifstream MyFile;
  std::string writein,temp;
  
  MyFile.open(filename);
  for (int i=0;i<(*records);i++){
    getline(MyFile,writein);
    std::stringstream ss(writein);
    for(int j=0;j<3;j++){
      getline(ss,temp,',');
      data[i][j]= temp;
    }
  }
  MyFile.close();
}

int main(){
  int records=3;
  std::string data[10][10];
  csv_import(data,3,&records,"customers.csv");
  
  return 0;
}
