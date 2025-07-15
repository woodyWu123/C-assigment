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

    Tile* ref1 =get(0);
    char color =ref1->getColor();
    int number=ref1->getNumber();

    if(tile->getColor() ==color && tile->getNumber() == number - 1 ){
        push_fornt(tile);
        return true;
    }

    Tile* ref2 =get(size() -1 );
    char color =ref2->getColor();
    int number=ref2->getNumber();

    if(tile->getColor() ==color && tile->getNumber() == number + 1 ){
        push_back(tile);
        return true;
    }
    return false;
}

Set* RunSet::split(int pos) {
    if(pos>= size() )
        return nullptr;
    RunSet* rs =new RunSet();
    int n=size()- pos;
    for(int i=0; i<n;i++){
        Tile* t=Set::pop(pos);
        rs->put(t);
    }
    return rs;
}

bool RunSet::merge(Set* s){
    Tile* ref =get(size() -1);
    char color =ref->getColor();
    int number=ref->getNumber();

    for(int i=0; i<n;i++){
        Tile* t=Set::pop(pos);
        rs->put(t);
    }

}