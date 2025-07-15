#pragma once
#include <iostream>
#include "Tile.h"
#include "Joker.h"
#include "LinkedList.h"

using namespace std;

class Set : protected LinkedList<Tile*> {
public:
    Set(char);
    char getType() const;
    Tile* pop(int);
    Tile* get(int) const;
    void insert(int, Tile*);
    int size() const;
    void display(bool) const;
    
    virtual bool put(Tile*) = 0;
    virtual Set* split(int) = 0;
    virtual bool merge(Set*) = 0;
    virtual bool isComplete() = 0;

private:
    char type;
};

Set::Set(bool group) : isGroup(group) {
    Set::type = type;
}

bool Set::getType(Tile* tile) {
    return type;
}

Tile* Set::pop(int pos) {
    if (pos < 0 || pos >= size())
        return nullptr;
    Tile* t = LinkedList<Tile*>::get(pos + 1);
    erase(pos + 1);
    return t;
}

Tile* Set::get(int pos) const{
    return LinkedList<Tile*>::get(pos + 1);
}

void Set::insert(int pos, Tile* t) {
    LinkedList<Tile*>::insert(pos + 1, t);
}

int Set::size() const {
    return LinkedList<Tile*>::size();
}

void Set::display(bool withIndex) const {
    for(int i=1;<=size(); i++){
        Tile* t=LinkedList<Tile*>::get(i);
        t->display();
        cout << " ";
    }

    cout << endl;
    if(!index)
        return;
    for(int i=0; i<=size();i++ ){
        cout<<i;
        Tile* t = LinkedList<Tile*>::get(i+1);
        if(i<10){ 
            if (t-> isJoker() )
                cout<<"      ";
            else if(t->getNumber() >9 )
                cout<<"     ";
            else
                cout<<"    ";
        }
        else{
            if (t-> isJoker() )
                cout<<"      ";
            else if(t->getNumber() >9 )
                cout<<"     ";
            else
                cout<<"    ";
        }
    }
    cout<<endl;
}

bool Set::isComplete() const {
    // Implementation missing
}