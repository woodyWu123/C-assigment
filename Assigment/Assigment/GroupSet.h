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
    
           // R      B      Y      K
bool color[]={false, false, false ,false};
    for (int i=0; i<size(); i++){
        Tile* t=get(i);
        if (t->getColor() == 'R')
            color[0]=true;
        else if (t->getColor() == 'B')
            color[1]=true;
        else if (t->getColor() == 'Y')
            color[2]=true;
        else
            color[3]=true;
    }
    Tile* ref=get(0);
    int number = ref->getNumber();

    if(tile->getNumber() != number)
        return false;

    else if(tile->getColor() == 'R'&& !color[0] ){
        LinkedList<Tile*>::push_back(tile);
        return true;
    }
    else if(tile->getColor() == 'B'&& !color[1] ){
        LinkedList<Tile*>::push_back(tile);
        return true;
    }
    else if(tile->getColor() == 'Y'&& !color[2] ){
        LinkedList<Tile*>::push_back(tile);
        return true;
    }
    else if(tile->getColor() == 'K'&& !color[3] ){
        LinkedList<Tile*>::push_back(tile);
        return true;
    }
    else
        return false;
}

Set* GroupSet::split(int pos){
    if(pos>=size() )
        return nullptr;
    GroupSet* gs= new GroupSet();
    int n=size()-pos;
    for(int i=0;i<n;i++){
        Tile* t =Set::pop(pos);
        gs->put(t);
    }
    return gs;
}

//Not Yet(1:21:44)
bool GroupSet::merge(Set* s){
    Tile* ref=get(0);

                   // R      B      Y      K
    bool color[]={false, false, false ,false};
        for (int i=0; i<size(); i++){
            Tile* t=get(i);
            if (t->getColor() == 'R')
                color[0]=true;
            else if (t->getColor() == 'B')
                color[1]=true;
            else if (t->getColor() == 'Y')
                color[2]=true;
            else
                color[3]=true;
        }

    for(int i-0; i<size();i++ ){
        
        Tile* t= s->get(i);

        if(tile->getColor() == 'R'&& !color[0] || t->getNumber() !=ref->getNumber() ) 
            return false;
        
        else if(tile->getColor() == 'B'&& !color[1] || t->getNumber() !=ref->getNumber() )
            return false;
        
        else if(tile->getColor() == 'Y'&& !color[2] || t->getNumber() !=ref->getNumber() )
            return false;
        
        else if(tile->getColor() == 'K'&& !color[3] || t->getNumber() !=ref->getNumber() )
            return false;
        

    }


}