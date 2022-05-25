#include <iostream>
using namespace std;
#include <string>

 
class AbstractWindow 
{
public:
  virtual void draw() = 0;
  virtual string getDescription() = 0;
};
 
class Window : public AbstractWindow 
{
public:
  void draw() {
    cout << "draw window";
  }
  string getDescription() {
	  return "simple window\n";
  }
};

class Decorator : public AbstractWindow 
{
protected:
	AbstractWindow *_decoratedWindow; 
 
public:
	Decorator (AbstractWindow *decoratedWindow): _decoratedWindow(decoratedWindow) {}
};

class Vertical : public Decorator 
{
private:
	void drawVerticalScrollBar() {
        cout << "draw the vertical scrollbar"; 
    }
public:
	Vertical (AbstractWindow *decoratedWindow): Decorator(decoratedWindow) {}
 
	void draw() {
        drawVerticalScrollBar();
        _decoratedWindow->draw();
    }
 
    string getDescription() {
        return _decoratedWindow->getDescription() + "with vertical scrollbars\n";
    }

};

class Horizontal : public Decorator 
{
private:
	void drawHorizontalScrollBar() {
        cout << "draw the horizontal scrollbar";
    }
public:
	Horizontal (AbstractWindow *decoratedWindow): Decorator(decoratedWindow) {}
 
	void draw() {
        drawHorizontalScrollBar();
        _decoratedWindow->draw();
    }
 
    string getDescription() {
        return _decoratedWindow->getDescription() + "with horizontal scrollbars\n";
	}
};

int main()
{
  AbstractWindow *simple = new Window();
  cout << simple -> getDescription() << endl;

  AbstractWindow *horiz = new Horizontal ( new Window());
  cout << horiz -> getDescription() << endl;

  AbstractWindow *vert = new Vertical ( new Window());
  cout << vert -> getDescription() << endl;

  AbstractWindow *decoratedWindow = new Horizontal (
                new Vertical(new Window()));
  cout << decoratedWindow -> getDescription() << endl;

  return 0;
}