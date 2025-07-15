#pragma once

#include <ctime>
#include <cmath>
#include <iostream>
#include "Tile.h"
#include "Joker.h"
#include "LinkedList.h"

using namespace std;

class Pool : public LinkedList<Tile*> {
public:
    Pool();
    void shuffle();
    void display() const;
    int size() const;
    Tile* draw();
    void put(Tile*);
};

Pool::Pool() {
    srand(time(NULL));
    char color[] = { 'R', 'B', 'Y', 'K' };
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 13; j++) {
            for (int k = 0; k < 2; k++) { // 2 sets
                Tile* t = new Tile(color[i], j);
                push_back(t);
            }
        }
    }
    push_back(new Joker());
    push_back(new Joker());
}

void Pool::shuffle() {
    for (int i = 0; i < 500; i++) {
        int num = rand() % size();
        Tile* t = get(num + 1);
        erase(num + 1);
        push_back(t);
    }
}

void Pool::display() const {
    for (int i = 0; i < size(); i++) {
        Tile* t = get(i + 1);
        t->display();
        cout << " ";
    }
}

int Pool::size() const {
    return LinkedList<Tile*>::size();
}

Tile* Pool::draw() {
    if (size() == 0)
        retrn nullptr;
    int num = rand() % size();
    Tile* t = get(num + 1);
    erase(num + 1);
    return t;
}

void Pool::put(Tile*) {
    push_back(t);
}