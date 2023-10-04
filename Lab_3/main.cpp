#include <iostream>
#include <string>
#include <climits>
#include <vector>

using namespace std;

string vectorToString(vector<string> v) {
  string result = "";
  for (auto el : v) result += el + ',';
  return result;
}

class Human{
  protected:
    string fullName;
    int birthYear;
    char gender;

  public:
    Human(){fullName = ""; birthYear = 0; gender = '-';};
    Human(string fN, int bY, char g){
      fullName = fN;
      birthYear = bY;
      gender = g;
    };
    void inputInfo();
    void printInfo();
};

class LibraryUser : public Human{
  protected:
    int cardNum;
    string issueDate;
    vector<string> books;
    int monthlyFee;
    string status;
  
  public:
    LibraryUser() : Human(){cardNum = 0;issueDate = "";books.push_back("Kobzar");monthlyFee = 0;status = "";};
    LibraryUser(
      string fN, int bY, char g, 
      int cN,
      string iD,
      vector<string> b,
      int mF,
      string s
    ) : Human(fN, bY, g){
      cardNum = cN;
      issueDate = iD;
      books = b;
      monthlyFee = mF;
      status = s;
    };
    void inputInfo();
    void printInfo();
    double getDiscount();
    int getYearlyFee();
    void addBook();

};

void Human::inputInfo(){
  cout << "Enter full name: ";
  getline(cin, fullName);
  cout << "Enter a birth year: ";
  cin >> birthYear;
  cout << "Enter a gender(M/F): ";
  cin >> gender;
}

void Human::printInfo(){
  cout << "Full name: " << fullName << endl;
  cout << "Birth year: " << birthYear << endl;
  cout << "Gender: " << gender << endl;
}

void LibraryUser::inputInfo(){Human::inputInfo();
  // cout << "Enter full name: ";
  // getline(cin, fullName);
  // cout << "Enter a birth year: ";
  // cin >> birthYear;
  // cout << "Enter a gender(M/F): ";
  // cin >> gender;
  cout << "Enter a card number: ";
  cin >> cardNum;
  cin.ignore(INT_MAX, '\n');
  cout << "Enter an issue date: ";
  getline(cin, issueDate);
  
  string bookName;
  cout << "Enter a book name(or 'done', to complete input): ";
  while(cin >> bookName && bookName != "done"){
    books.push_back(bookName);
    cout << "Enter next book name(or 'done', to complete input): ";
  }

  cout << "Enter a monthly fee: ";
  cin >> monthlyFee;
  cin.ignore(INT_MAX, '\n');
  cout << "Status: ";
  getline(cin, status);

}

double LibraryUser::getDiscount(){
  return books.size() * 10.0;
}

int LibraryUser::getYearlyFee(){
  return monthlyFee * 12;
}

void LibraryUser::printInfo(){
  cout << "Full name: " << fullName << endl;
  cout << "Birth year: " << birthYear << endl;
  cout << "Gender: " << gender << endl;
  cout << "Card number: " << cardNum << endl;
  cout << "Issue date: " << issueDate << endl;
  cout << "Books: " << vectorToString(books) << endl;
  cout << "Monthly fee: " << monthlyFee << "$" << endl;
  cout << "Status: " << status << endl;
  cout << "Discount: " << getDiscount() << "%" << endl;
  cout << "Yearly fee: " << getYearlyFee() << "$" << endl;
}


void LibraryUser::addBook(){
  string bookName;
  cout << "Enter book name: ";
  cin >> bookName;
  books.push_back(bookName);
}

int main(){
  Human hum1("Smith Will Williams", 2000, 'M');
  hum1.printInfo();

  // Human hum2;
  // hum2.inputInfo();
  // hum2.printInfo();

  // LibraryUser lib1("Orehova Elena Vladimirovna", 2001, 'F', 1234, "01.01.2019", {"Harry Potter", "Sherlock Holmes", "The Snow Queen"}, 5, "active");
  // lib1.addBook();

  // cout << "Discount: " << lib1.getDiscount() << "%" << endl;
  // cout << "Yearly fee: " << lib1.getYearlyFee() << "$" << endl;
  // lib1.printInfo();

  // LibraryUser lib2;
  // lib2.inputInfo();
  // lib2.printInfo();
}



// cout << "Enter a number of books: ";
  // int numOfBooks;
  // cin >> numOfBooks;
  // cin.ignore(INT_MAX, '\n');
  // for(int i = 0; i < numOfBooks; i++){
  //   cout << "Book " << i+1 << ": ";
  //   cin >> bookName;
  //   books.push_back(bookName);
  // }