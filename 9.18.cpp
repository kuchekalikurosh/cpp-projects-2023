#include <iostream>

using namespace std;

class ComboLock {
    public:
        ComboLock();
        void setCombo(int one, int two, int three);
        void reset();
        void turn_left(int ticks);
        void turn_right(int ticks);
        void open();
    private:
        int dial;
        int combo1;
        int combo2;
        int combo3;
        bool check1;
        bool check2;
        bool check3;
        bool isOpen;
};

ComboLock::ComboLock() {
    dial = 0;
    combo1 = 0;
    combo2 = 0;
    combo3 = 0;
}

void ComboLock::setCombo(int one, int two, int three) {
    combo1 = one;
    combo2 = two;
    combo3 = three;
}

void ComboLock::reset() {
    dial = 0;
    check1 = false;
    check2 = false;
    check3 = false;
    isOpen = false;
}

void ComboLock::turn_left(int ticks) {
    dial = dial - ticks;
    if(dial < 0) {
        dial = dial + 40;
    } else if (dial > 39) {
        dial = 0;
    }

    if(dial == combo2 & check1 == true) {
        check2 = true;
    }
}

void ComboLock::turn_right(int ticks) {
    dial = dial + ticks;
    if(dial < 0) {
        dial = 39;
    } else if (dial > 39) {
        dial = dial - 40;
    }

    if(dial == combo1) {
        check1 = true;
    }

    if(dial == combo3 & check1 == true & check2 == true) {
        check3 = true;
    }
}

void ComboLock::open() {
    if(check1 == true & check2 == true & check3 == true) {
        isOpen = true;
    }

    if(isOpen == true) {
        cout << "Lock is Open!" << endl;
    } else {
        cout << "Still locked!" << endl;
    }
}

int main() {
    ComboLock newlock;
    newlock.setCombo(8, 23, 2);
    newlock.reset();
    newlock.turn_right(8);
    newlock.turn_left(25);
    newlock.turn_right(19);
    newlock.open();
    return 0;
}