#ifndef BASE_H_
#define BASE_H_

#include <iostream>


class base{

public:
    virtual void read(std::string inp_filename, std::string outp_filename)=0;
    virtual void write(std::string outp_filename)=0;
    virtual void process()=0;

};

#endif
