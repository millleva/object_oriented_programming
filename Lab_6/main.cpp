#include <iostream>
#include <string>
#include <cmath>

#define PI 3.14159265

using namespace std;

class Shape{
  protected:
    double centerX;
    double centerY;
    double rotationAngle;
    double scaleFactor;

  public:
    Shape(double x = 0.0, double y = 0.0, double angle = 0.0, double scale = 1.0)
      : centerX(x), centerY(y), rotationAngle(angle), scaleFactor(scale){}

    virtual void showShape() = 0;
    virtual void hideShape() = 0;

    void rotateShape(double degree){
      rotationAngle += degree;
      if(rotationAngle >= 360) rotationAngle -= 360;
    };

    void moveShape(double mX, double mY){
      centerX += mX;
      centerY += mY;
    };


};

class Line : public Shape{
  private:
    double A;
    double B;

    string equation(){
      A = tan(rotationAngle * PI / 180.0);
      B = centerY - A * centerX;
      return "y = " + to_string(A) + "*x + " + to_string(B);
    }

  public:
    Line(double x, double y, double angle, double scale, double A, double B)
      : Shape(x, y, angle, scale), A(A), B(B){}
    
    void showShape() override{
      cout << "Show straight line by equation: " << equation() 
        << " , at (" << centerX << ", " << centerY << "), scale (" 
          << scaleFactor << "), angle (" << rotationAngle << " degrees)" << endl;
    }

    void hideShape() override{
      cout << "Hide straight line by equation: " << equation() 
        << " , at (" << centerX << ", " << centerY << "), scale (" 
          << scaleFactor << "), angle (" << rotationAngle << " degrees)" << endl;
    }
 
};

int main(){

  // Line l1(0, 0, 45, 1, 1, 0);

  // l1.showShape();
  // l1.moveShape(4,4);
  // l1.rotateShape(-15);
  // l1.showShape();
  // l1.hideShape();

  Shape* line = new Line(0, 0, 45, 1, 1, 0);

  line->showShape();
  line->moveShape(4,4);
  line->rotateShape(-15);
  line->showShape();
  line->hideShape();

  return 0;
}