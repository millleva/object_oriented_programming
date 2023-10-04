#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class File{
  private:
    fstream file;

  public:
    File(){}

    friend File& operator>>(File& input, File& output){
      int value;
      while (input.file >> value){
        output.file << value << endl;
      }
      return input;
    }

    void open(const char* filename){
      file.open(filename);
    }

    void close(){
      file.close();
    }
};

int main() {
  File fa, fb, fc;

  fa.open("input.txt");
  fb.open("output.txt");
  fc.open("newoutput.txt");

  //fa >> fb;
  fb >> fc;

  fa.close();
  fb.close();
  fc.close();

    return 0;
}
