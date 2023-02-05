#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "cpluspluslabs.h"

void csv_import2(NODE** data, std::string filename)
{
  std::ifstream MyFile;
  std::string writein[3],temp;
  int j;
  MyFile.open(filename);
  if(!MyFile){
    std::cerr << "File could not be opened" <<std::endl;
    exit( EXIT_FAILURE );
  }
  while(MyFile >> temp){
    j=0;
    std::stringstream s(temp);
    while(getline(s,writein[j],',')){
	j++;
    }
    if(*data==nullptr){
      *data = new NODE;
      (*data)->firstname = writein[0];
      (*data)->lastname = writein[1];
      (*data)->email = writein[2];
      (*data)->next = nullptr;
    }else{
      NODE* temp = *data;
      NODE* newdata = nullptr;
      newdata = new NODE;
      while(temp->next!=nullptr){
	temp = temp->next;
      }
      newdata->firstname = writein[0];
      newdata->lastname = writein[1];
      newdata->email = writein[2];
      temp->next = newdata;
    }
  }
  MyFile.close();
}
