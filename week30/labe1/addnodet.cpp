#include <iostream>
#include "cpluspluslabs.h"
#include <string>

void add_node_tail(NODE** data, std::string firstname,std::string lastname, std::string email)
{
  if(*data==nullptr){
    *data = new NODE;
    (*data)->firstname = firstname;
    (*data)->lastname = lastname;
    (*data)->email = email;
    (*data)->next = nullptr;
  }else{
    NODE* temp = *data;
    NODE* newdata = nullptr;
    newdata = new NODE;
    while(temp->next!=nullptr){
      temp = temp->next;
    }
    newdata->firstname = firstname;
    newdata->lastname = lastname;
    newdata->email = email;
    temp->next = newdata;
  }
}
