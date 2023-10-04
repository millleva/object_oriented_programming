#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Exception{
  private:
    string message;

  public:
    Exception(string msg){message = msg;}
    void what(){
      cerr << message << endl;
    }
};

class IOException : public Exception{
  public:
    IOException(string msg) : Exception(msg){}; 
};
class MathException : public Exception{
  public:
    MathException(string msg) : Exception(msg){};
};
class MemoryException : public Exception{
  public:
    MemoryException(string msg) : Exception(msg){};

    void* operator new(size_t size){
      throw MemoryException("Failed to allocate memory");
    }
    void operator delete(void* memory){
      
    }
    
};

class File{
  private:
    string filename;
  
  public:
  File(string fN){filename = fN;}
  friend File& operator>>(File& input, File& output){
    ifstream in(input.filename);
    if(in.fail()) throw IOException("Failed to open " + input.filename);
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

int divide(int x, int y){
  if(y == 0) throw MathException("Dividing by 0");
  return x / y;
}

int* allocateArray(long long int size){
  int* array = new (nothrow) int[size];
  if (array == nullptr) throw MemoryException("Array size is too big");
  return array;
}

int main(){
  File fa("input1.txt");
  File fb("output.txt");
  File fc("newoutput.txt");
  
  try{
    fa >> fb >> fc;
  }
  catch(IOException e){
    e.what();
  }
  
  try{
    cout << divide(15, 3) << "; " << divide(6, 0) << endl;
  }
  catch(MathException e){
    e.what();
  }

  try{
    allocateArray(1000000000000);
  }
  catch(MemoryException e){
    e.what();
  }

  try{
    MemoryException* exception = new MemoryException("Test");
    delete exception;
  }
  catch(MemoryException e){
    e.what();
  }
  
  return 0;
}