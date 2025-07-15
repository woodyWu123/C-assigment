#pragma once
#include <iostream>
using namespace std;

class Tile {
    friend ostream& operator<<(ostream&, const Tile&);

public:
    Tile(char color, int number);
    char getColor() const;
    int getNumber() const;
    virtual int getScore() const;
    virtual bool isJoker() const;
    virtual void display() const;

protected:
    char color;
    int number;
};

Tile::Tile(char color, int number) {
    if (color == 'R' || color == 'B' || color == 'Y' || color == 'K' || color == '-') {
        Tile::color = color;
    }
    else {
        Tile::color = 'R'; // Default to Red if invalid
    }
    Tile::number = (number >= 1 && number <= 13) ? number : 0; // Default to 0 if invalid
}

char Tile::getColor() const {
    return color;
}

int Tile::getNumber() const {
    return number;
}