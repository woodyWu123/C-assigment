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

    for(int i=0; i< s->size();i++){
        Tile* t=s->get(i);
        if(t->getColor() != color || t->getNumber() != number + i+1 )
            return false;
    }

    while (s->size() >0 ){
        Tile* t = s->pop(0);
        put(t);
    }
    return true;
}

bool RunSet::isComplete() {
    Tile* ref;
    if(size() > 0 )
        ref=get(0);
    else
        return false;

    char color = ref->getColor();
    int  number=ref->getNumber();
    for(int i=1; i<size();i++){
        Tile* t= get(i);
        if(t->getColor() !=color || t->getNumber() != number + i )
            return false;
    }

    if(size() >= 3)
        return true;
    return true;

}