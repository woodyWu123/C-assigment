#pragma once
#include <iostream>
#include "LinkList.h"
#include "Sets.h"
#include "Tile.h"
#include "Joker.h"

using namespace std;

class RunSet {

public:
    RunSet();
    bool put(Tile*);
    Set* split(int);
    bool merge(Set*);
    bool isComplete();
};

RunSet::RunSet() : Set('R') {
}

bool RunSet::put(Tile* tile) {
    if (size() == 0) {
        push_back(tile);
        return true;
    }

}
