#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

class Node{
public:
  string content;
  Node *next;
  Node(string s){content = s; next = 0;};
};

class Lstack{
private:
  Node *top;

public:
  Lstack() { top = 0; };
  ~Lstack();
  Lstack(const Lstack& other);
  void push(string content);
  string pop();
  
  void print();
  void input();

  int num();
  bool isEmpty();

  void readFromFile(const string& filename);
  void writeToFile(const string& filename);
};

void Lstack::push(string content){
  Node *n = new Node(content);
  if (!top)
    top = n;
  else{
    n->next = top;
    top = n;
  }
}

istream& insetup(istream& is){
  is.setf(ios::skipws);
  return is;
}

ostream& outsetup(ostream& os){
  os.fill('>');
  os << setw(10);
  return os;
}

void Lstack::print(){
  Node *curr = top;
  while (curr){
    cout << outsetup << curr->content;
    curr = curr->next;
  }
  cout << endl;
}

void Lstack::input(){
  string input;
  cout << "Enter elements to push to stack (enter 'done' to stop): " << endl;
  getline(cin, input);
  stringstream ss(input);
  string element;
  ss >> insetup;
  while (ss >> element && element != "done") {
    push(element);
  }
}



Lstack::~Lstack(){
  if(top){
    Node *curr = top;
    while(curr){
      curr = curr->next;
      delete top;
      top = curr;
    }
  }
}

Lstack::Lstack(const Lstack& other) {
  Node* curr = other.top;
  Node* newTop = nullptr;
  Node* prev = nullptr;

  while (curr) {
    Node* newNode = new Node(curr->content);
    if (!newTop) {
      newTop = newNode;
    } else {
      prev->next = newNode;
    }
    prev = newNode;
    curr = curr->next;
  }

  top = newTop;
}

string Lstack::pop(){
  if(top){
    string value = top->content;
    Node *curr = top->next;
    delete top;
    top = curr;
    return value;
  }
  return "Stack is empty";
}

int Lstack::num(){
  int amount = 0;
  Node *curr = top;
  while(curr){
    amount++;
    curr = curr->next;
  }
  return amount;
}

bool Lstack::isEmpty(){
  return top == 0;
}

void Lstack::readFromFile(const string& filename){
  ifstream file(filename);
  if(file.is_open()){
    string line;
    getline(file, line);
    stringstream ss(line);
    string element;
    ss >> insetup;
    while(ss >> element){
      push(element);
    }
  }
}

void Lstack::writeToFile(const string& filename){
  ofstream file(filename);
  if(file.is_open()){
    Node *curr = top;
    while (curr){
      file << outsetup << curr->content;
      curr = curr->next;
    }
    file.close();
  }
}

int main(){

  Lstack s;
  // s.push("tarelka 1");
  // s.push("tarelka 2");
  // s.push("tarelka 3");
  // s.push("tarelka 4");
  // s.push("tarelka 5");

  s.readFromFile("fileToRead.txt");
  s.writeToFile("fileToWrite.txt");

  // s.input();
  // s.print(); 

  //cout << "Stack contains: " << s.num() << " elements" << endl;

  // while(!s.isEmpty()){
  //   cout << "Took: " << s.pop() << endl;
  //   cout << s.num() << " elements left" << endl;
  // }
  // cout << s.pop() << endl;

  // Lstack copiedS(s);
  // copiedS.print();

  return 0;
}