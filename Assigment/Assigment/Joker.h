#pragma once
#include <iostream>
#include "Tile.h"
using namespace std;

class Joker : public Tile {
    friend ostream& operator<<(ostream&, const Joker&);

public:
    Joker();
    void clear();
    void setColor(char);
    void setNumber(int);
    virtual int getScore() const;
    virtual bool isJoker() const;
    virtual void display() const;
};

Joker::Joker() : Tile('-', 0) {
}

void Joker::clear() {
    color = '-';
    number = 0;
}

void Joker::setColor(char color) {
    Tile::color = color;
}

void Joker::setNumber(int number) {
    Tile::number = number;
}

bool Joker::isJoker() const {
    return true;
    // return dynamic_cast<const Joker*>(this) != nullptr;
}

int Joker::getScore() const {
    if (number == 0) // on rack or pool (use when game end)
        return 30;
    return 0;
}

void Joker::display() const {
    if (color == '-') {
        cout << ":-)";
    }
    else {
        cout << "[" << color << number << "]";
    }
}
