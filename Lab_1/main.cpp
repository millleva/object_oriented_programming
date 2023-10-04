#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Sample{

  private:
    int N;
    vector<int> content;
    int minElement();
    int maxElement();
    int sumElements();

  public:
    Sample(int n){N = n; content.reserve(n);}; 
    void input();
    void show();
    double mean();
    double dispersion();
    double rozmah();
    double std();
    friend double kohren(Sample s);
};

int Sample::minElement(){
  int minEl = content[0];
      for(auto el : content)
        if(el < minEl) minEl = el;
      return minEl;
}
int Sample::maxElement(){
  int maxEl = content[0];
      for(auto el : content)
        if(el > maxEl) maxEl = el;
      return maxEl;
}
int Sample::sumElements(){
  int sum = 0;
      for(auto el : content) sum += el;
      return sum;
}



void Sample::input(){
  int element;
  cout << "Enter " << N << " integers: " << endl;
  for(int i = 0; i < N; i++){
    cout << "Enter element #" << i << ": ";
    cin >> element;
    content.push_back(element);
  }
}

void Sample::show(){
  cout << "Sample of " << N << " elements: " << endl;
  for(auto el : content){
    cout << el << " ";
  }
  cout << endl;
}

double Sample::mean(){
  return sumElements() / N;
}

double Sample::dispersion(){
  double m = mean();
  double sum = 0;
  for(auto el : content) sum += pow(el - m, 2);
  return sum / N;
}

double Sample::std(){
  return sqrt(dispersion());
}

double Sample::rozmah(){
  return maxElement() - minElement();
}

double kohren(Sample s){
  return (double) s.maxElement() / (double) s.sumElements();
}

int main(){
  int amount;
  cout << "Enter N: ";
  cin >> amount;

  Sample s(amount);
  s.input();
  s.show();
  cout << "Sample mean: " << s.mean() << endl;
  cout << "Sample dispersion: " << s.dispersion() << endl;
  cout << "Sample std: " << s.std() << endl;
  cout << "Sample rozmah: " << s.rozmah() << endl;
  cout << "Sample Kohren: " << kohren(s) << endl;
}