#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class File{
  private:
    string filename;
  
  public:
  File(string fN){filename = fN;}
  friend File& operator>>(File& input, File& output){
    ifstream in(input.filename);
    ofstream out(output.filename);
    string buf;
    while(getline(in, buf)){
      out << buf << endl;
    }
    in.close();
    out.close();

    return input;
  }

};

int main(){
  File fa("input.txt");
  File fb("output.txt");
  File fc("newoutput.txt");
  
  fa >> fb >> fc;


  return 0;
}