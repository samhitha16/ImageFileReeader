#include "derived.h"
#include <fstream>
#include <string>

struct RGB {
    int R,B,G;
};

std::ifstream& operator>>(std::ifstream &in,RGB& rgb){
    in >> rgb.R;
    in >> rgb.G;
    in >> rgb.B;
    return in;
};

std::ostream& operator<<(std::ostream &out,RGB& rgb){
      out << rgb.R << " ";
      out << rgb.G << " ";
      out << rgb.B << std::endl;
      return out;
};

std::ofstream& operator<<(std::ofstream &out,RGB& rgb){
  out << rgb.B << " ";
  out << rgb.R << " ";
  out << rgb.G << " ";
  return out;
};

void derived::read(std::string inp_filename, std::string outp_filename){
  int k = 0;
  int x;
  int y;
  std::string line[5];
  std::ofstream MyFile(outp_filename);
  std::string delim = " ";
  //std::string filename = ;
  std::ifstream file(inp_filename);
  if(file.is_open()) {

      for (int i=0;i<2;i++) {
        std::getline(file,line[i]);
      }
      MyFile<<line[0]<<std::endl;
      if(line[1].substr(0,1).compare("#") == 0){
        MyFile<<line[1]<<std::endl;
        for(int j = 2; j<5; j++){
          file>>line[j];
        }
        MyFile<<line[2]<<" "<<line[3]<<std::endl;
        MyFile<<line[4]<<std::endl;
      }
      else{
        file>>line[4];
        MyFile<<line[1]<<std::endl;
        MyFile<<line[4]<<std::endl;
        auto start = 0U;
        auto end = line[1].find(delim);
        line[2] = line[1].substr(start, end - start);
        start = end + delim.length();
        end = line[1].find(delim,start);
        line[3] = line[1].substr(start, end - start);
      }

      if(line[0].compare("P3") == 0){
        x = std::stoi(line[2]);
        y = std::stoi(line[3]);
        RGB rgb;
        for (int i=1;i<(x*y)+1;i++) {
            file >> rgb;
            k = i % 4;
            if(k == 1){
              MyFile<<"\n";
              MyFile << rgb;
            }
            else{
              MyFile << rgb;
            }
        }
      }
      file.close();
      MyFile.close();
  }
}

void derived::write(std::string outp_filename){

}

void derived::process(){

}
