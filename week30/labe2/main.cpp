#include <iostream>
#include "cpluspluslabs.h"
#include <string>

void add_node_head(NODE** data, std::string firstname, std::string lastname, std::string email);

auto main() -> int
{
  NODE* data = nullptr;
  add_node_head(&data,"aspen","olmsted","aspeno@aol.com");
  add_node_head(&data,"sally","jones","sally@aol.com");
  if(data->firstname == "sally")
    std::cout<<(data->next)->firstname<<std::endl;
}

void add_node_head(NODE** data, std::string firstname,std::string lastname, std::string email)
{
  if(*data==nullptr){
    *data = new NODE;
    (*data)->firstname = firstname;
    (*data)->lastname = lastname;
    (*data)->email = email;
    (*data)->next = nullptr;
  }else{
    NODE* newdata = nullptr;
    newdata = new NODE;
    
    newdata->firstname = firstname;
    newdata->lastname = lastname;
    newdata->email = email;
    newdata->next = *data;
    *data = newdata;
  }
  
}
