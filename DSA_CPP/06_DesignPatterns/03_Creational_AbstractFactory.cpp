// https://www.bogotobogo.com/DesignPatterns/abstractfactorymethod.php

#include <iostream>
using namespace std;

// Product type 1
class Button {
    public:
        virtual void paint() = 0;
};

class WinButton : public Button {
    public:
        void paint() {
            cout << "Windows Button" << endl;
        }
};

class MacButton : public Button {
    public:
        void paint() {
            cout << "Mac Button" << endl;
        }
};

// ---------------------------------------------------
// Added later
class iPhoneButton : public Button {
    public:
        void paint() {
            cout << "iPhone Button" << endl;
        }
};
// ---------------------------------------------------


// Product type 2
class ScrollBar {
    public:
        virtual void paint() = 0;
};

class WinScrollBar : public ScrollBar {
    public:
        void paint() {
            cout << "Windows Scrollbar" << endl;
        }
};

class MacScrollBar : public ScrollBar {
    public:
        void paint() {
            cout << "Mac Scrollbar" << endl;
        }
};

// ---------------------------------------------------
// Added later
class iPhoneScrollBar : public ScrollBar {
    public:
        void paint() {
            cout << "iPhone Scrollbar" << endl;
        }
};
// ---------------------------------------------------


// Abstract Factory
class GUIFactory {
    public:
        virtual Button* createButton() = 0;
        virtual ScrollBar* createScrollbar() = 0;
};

// Concrete Factory
class WinFactory : public GUIFactory {
    public:
        Button* createButton() {
            return new WinButton;
        }

        ScrollBar* createScrollbar() {
            return new WinScrollBar;
        }
};

// Concrete Factory
class MacFactory : public GUIFactory {
    public:
        Button* createButton() {
            return new MacButton;
        }

        ScrollBar* createScrollbar() {
            return new MacScrollBar;
        }
};

// ---------------------------------------------------
// Added later
class iPhoneFactory : public GUIFactory {
    public:
        Button* createButton() {
            return new iPhoneButton;
        }

        ScrollBar* createScrollbar() {
            return new iPhoneScrollBar;
        }
};
// ---------------------------------------------------

int main () {
    GUIFactory* guiFactory;
    Button* btn;
    ScrollBar* sb;

    guiFactory = new MacFactory;
    btn = guiFactory->createButton();
    btn->paint();
    sb = guiFactory->createScrollbar();
    sb->paint();

    guiFactory = new WinFactory;
    btn = guiFactory->createButton();
    btn->paint();
    sb = guiFactory->createScrollbar();
    sb->paint();

    // Which part of the code should be modified if we want to add iPhone look-and-feel?

    guiFactory = new iPhoneFactory;
    btn = guiFactory->createButton();
    btn->paint();
    sb = guiFactory->createScrollbar();
    sb->paint();
}