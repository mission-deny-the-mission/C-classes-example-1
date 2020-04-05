#include <iostream>

class demoClass {
private:
    std::string text;
    int number;


public:

    // this is called a constructor, which is a special method run when the class is first initialized
    demoClass(std::string text, int number) {
        // a method can call other methods in the same class
        // even if they are private
        setText(text);
        setNumber(number);
    }

    // These functions are called getters and setters
    // They are used to see and update private attributes of a class


    // set functions can be used to check values assigned to a attribute of a class for validity
    // this one makes sure that any text set cannot contain numbers
    void setText(std::string text) {
        bool containsDigit = false;
        for (int i = 0; i < text.length(); i++) {
            if (isdigit(text[i])) { containsDigit = true; }
        }
        if (containsDigit) {
            throw 0;
        } else {
            this->text = text;
        }
    }

    // this makes any number set to the class positive
    void setNumber(int number) {
        if (number >= 0) {
            this->number = number;
        } else {
            this->number = - number;
        }
    }

    // these just return the values of their respective attributes
    std::string getText () {
        return text;
    }

    int getNumber () {
        return number;
    }
};

// This method is so I can output my class using std::cout
// for more info see this stack overflow page:
// https://stackoverflow.com/questions/2981836/how-can-i-use-cout-myclass

// it does this by changing how the << operator works for this class using method overloading/overiding
// method overloading is where multiple methods or operators have the same name and are selected by the compiler
// based on the arguments they are being called with
std::ostream& operator<<(std::ostream& os, demoClass obj)
{
    os << "Text: " << obj.getText() << "\nNumber:" << obj.getNumber();
    return os;
}

int main() {
    demoClass one("hello", 14);
    std::cout << one << std::endl;

    one.setNumber(-5);
    std::cout << one << std::endl;

    try {
        one.setText("hello 21");
    } catch (int exceptionNo) {
        std::cout << "Could not set text" << std::endl;
    }

    one.setText("hello there");
    std::cout << one << std::endl;

    return 0;
}
