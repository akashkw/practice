// Copyright 2018 Akash Kwatra

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

// 25
// family of drink
// Test out subclasses, abstract classes, interfaces, and virtual functions
// Creates a drink bar, populates with drinks, prints their descriptions

class IBeverage {
 public:
    virtual void drink() = 0;
    virtual void print_description() = 0;
};

class SoftDrink : public IBeverage {
    int calories;
 public:
    explicit SoftDrink(int cals) : calories(cals) {}
    void check_calories() {
        cout << "This drink has " << calories << " calories" << endl;
    }
    virtual void describe_can() = 0;
    virtual void print_description() {
        drink();
        check_calories();
        describe_can();
        cout << endl;
    }
};

class HardDrink : public IBeverage {
    int alcohol_content;
 public:
    explicit HardDrink(int alc) : alcohol_content(alc) {}
    void check_alcohol() {
        cout << "This drink is " << alcohol_content << "% alcohol" << endl;
    }
    virtual void take_snapstagram_pic() = 0;
    virtual void print_description() {
        drink();
        check_alcohol();
        take_snapstagram_pic();
        cout << endl;
    }
};

class CokeZero : public SoftDrink {
 public:
    CokeZero() : SoftDrink(0) {}
    virtual void describe_can() {
        cout << "It's black with a cool modern design" << endl;
    }
    virtual void drink() {
        cout << "MMMM, Coke Zero, tastes like delicious chemicals" << endl;
    }
};

class CocaCola : public SoftDrink {
 public:
    CocaCola() : SoftDrink(150) {}
    virtual void describe_can() {
        cout << "It's red with that classic logo" << endl;
    }
    virtual void drink() {
        cout << "MMMM, Coca Cola, tastes like acidic sugar" << endl;
    }
};

class JackDaniels : public HardDrink {
    int alcohol_content;
 public:
    JackDaniels() : HardDrink(40) {}
    virtual void take_snapstagram_pic() {
        cout << "Looks like dehydrated amber piss... *snaps pic*" << endl;
    }
    virtual void drink() {
        cout << "DAMN, Jack Daniels, got a nice burn to it" << endl;
    }
};

class Mojito : public HardDrink {
    int alcohol_content;
 public:
    Mojito() : HardDrink(10) {}
    virtual void take_snapstagram_pic() {
        cout << "Looks fresh, green, and tropical! *snaps pic*" << endl;
    }
    virtual void drink() {
        cout << "MMMM, Mojitos, nice and fruity with a hint of mint" << endl;
    }
};

int main() {
    cout << endl << "25 - family of drink" << endl << endl;

    vector<IBeverage*> drink_bar;

    drink_bar.push_back(new CokeZero());
    drink_bar.push_back(new CocaCola());
    drink_bar.push_back(new JackDaniels());
    drink_bar.push_back(new Mojito());

    for (auto const &my_drink : drink_bar) {
        my_drink->print_description();
    }
    return 0;
}

