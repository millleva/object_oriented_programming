#include <iostream>
#include <string>

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
  int num();
  bool isEmpty();
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

void Lstack::print(){
  Node *curr = top;
  while (curr){
    cout << " -> " << curr->content;
    curr = curr->next;
  }
  cout << endl;
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

int main(){

  Lstack s;
  s.push("tarelka 1");
  s.push("tarelka 2");
  s.push("tarelka 3");
  s.push("tarelka 4");
  s.push("tarelka 5");
  s.print(); 
  cout << "Stack contains: " << s.num() << " elements" << endl;

  while(!s.isEmpty()){
    cout << "Took: " << s.pop() << endl;
    cout << s.num() << " elements left" << endl;
  }
  cout << s.pop() << endl;

  // Lstack copiedS(s);
  // copiedS.print();

  return 0;
}






  // Lstack::Lstack(const Lstack &obj){
  //   top = new Node;
  //   *top = *obj.top;
  //   Node *objCurr = obj.top;
  //   Node *curr = top;
  //   while(objCurr){
  //     curr->next = objCurr->next;
  //     curr = curr->next;
  //     objCurr = objCurr->next;
  //   }
  // }

  // Node(){
  //   content = "";
  //   next = 0;
  // }

  //Lstack(const Lstack &obj);