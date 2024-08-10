#include <iostream>
using namespace std;

// Desired interface (Target)
class Rectangle {
  public:
    virtual void draw() = 0;
};

// Legacy component (Adaptee)
class LegacyRectangle {
    private:
        int x1_;
        int y1_;
        int x2_;
        int y2_;
    public:
        LegacyRectangle(int x1, int y1, int x2, int y2) {
            x1_ = x1;
            y1_ = y1;
            x2_ = x2;
            y2_ = y2;
            cout << "LegacyRectangle(x1,y1,x2,y2)\n";
        }
        void oldDraw() {
            cout << "LegacyRectangle:  oldDraw(). \n";
        }
};

// Adapter wrapper
class RectangleAdapter: public Rectangle, private LegacyRectangle {
  public:
    RectangleAdapter(int x, int y, int w, int h):
      LegacyRectangle(x, y, x + w, y + h) {
         cout << "RectangleAdapter(x,y,x+w,x+h)\n";
      }
    
    void draw() {
        cout << "RectangleAdapter: draw().\n"; 
        oldDraw();
    }
};

int main()
{
  int x = 20, y = 50, w = 300, h = 200;
  Rectangle *r = new RectangleAdapter(x,y,w,h);
  r->draw();
}