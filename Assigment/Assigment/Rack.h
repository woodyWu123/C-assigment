#pragma once
#include <iostream>
#include "Tile.h"
#include "Joker.h"
#include "LinkedList.h"

using namespace std;

class Rack : public LinkedList<Tile*> {
public:
    Rack();
    int size() const;
    Tile* pop(int pos);
    void put(Tile*);
    void insert(int, Tile*);
    int getPoints() const;
    void display() const;
};

Rack::Rack() {
}

int Rack::size() const {
    return LinkedList<Tile*>::size();
}

Tile* Rack::pop(int pos) {
    if (pos < 0 || pos >= size()) {
        return nullptr;
    }
    Tile* t = LinkedList<Tile*>::get(pos + 1);
    erase(pos + 1);
    return t;
}

void Rack::put(Tile* t) {
    push_back(t);
}

void Rack::insert(int pos, Tile* t) {
   LinkedList<Tile*>::insert(pos+1, t)
}

int Rack::getPoints() const {
    int sum = 0;
    for (int i = 0; i < size(); i++) {
        Tile* t = LinkedList<Tile*>::get(i + 1);
        sum += t->getScore;
    }
    return sum;
}

void Rack::display() const {
    for (int i = 0; i < size(); i++) {
        Tile* t = LinkedList<Tile*>::get(i);
        t->display();
        cout << " ";
    }
    cout << endl;
    for (int i = 0; i < size(); i++) {
        cout << i;
        Tile* t = LinkedList<Tile*>::get(i + 1);
        if (i < 10) {
            if (t->isJoker() || t->getNumber() > 9)
                cout << "   ";
            else
                cout << "  ";
        }

        else {
            if (t->isJoker() || t->getNumber() > 9)
                cout << "   ";
            else
                cout << "  ";
        }
    }
    cout << endl;
}