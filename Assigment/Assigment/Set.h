#pragma once
#include <iostream>
#include "Tile.h"
#include "Joker.h"
#include "LinkedList.h"

using namespace std;

class Set : public LinkedList<Tile*> {
public:
    Set(bool);
    bool put(Tile*);
    Tile* get(int);
    pair<Set, Set> split(int);
    bool merge(const Set&);
    int size() const;
    bool isComplete() const;
    void display(bool) const;
private:
    bool isGroup;
};

Set::Set(bool group) : isGroup(group) {
}

bool Set::put(Tile* tile) {
    // Implementation missing
}

Tile* Set::get(int pos) {
    // Implementation missing
}

pair<Set, Set> Set::split(int pos) {
    // Implementation missing
}

bool Set::merge(const Set& other) {
    // Implementation missing
}

int Set::size() const {
    return LinkedList<Tile*>::size();
}

bool Set::isComplete() const {
    // Implementation missing
}

void Set::display(bool withIndex) const {
    // Implementation missing
}