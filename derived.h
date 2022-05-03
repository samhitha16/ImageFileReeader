#ifndef DERIVED_H_
#define DERIVED_H_

#include "base.h"
#include <fstream>
#include <string>

class derived : public base{
public:
  void read(std::string inp_filename, std::string outp_filename);
  void write(std::string outp_filename);
  void process();

};



#endif
