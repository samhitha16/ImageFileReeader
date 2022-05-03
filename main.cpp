#include"derived.h"
#include<iostream>
#include<string>

int main(int argc, char *argv[]){
  base* bptr;
  derived d;
  bptr = &d;
  //std::string input1;
  //std::string input2;
  //std::cin>>input1;
  //std::cin>>input2;
  int n = argc;
  bptr->read(argv[n-2], argv[n - 1]);
}
