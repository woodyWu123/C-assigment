#pragma once
#include <iostream>
#include "Title.h"
#include "Joker.h"
#include "Set.h"
#include "LinkedList.h"

using namespace std;

class GroupSet : public Set {
public:
    GroupSet();
    bool put(Tile*);
    Set* split(int);
    bool merge(Set*);
    bool isComplete();
};

Sets::GroupSet() : Set('G') {
}

bool GroupSet()::put(Tile* tile) {
    if (size() == 0) {
        push_back(tile);
        return true;
    }
    
       
}