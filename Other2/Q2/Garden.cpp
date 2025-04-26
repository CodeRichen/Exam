#include "Garden.h"
#include <iostream>
#include <string>

using namespace std;

namespace Garden{
    Plant::Plant(string n,float h, string c, string s){
        height = h;
        name = n;
        color = c;
        shape = s;
    }

    void Plant::grow(float h){
        height += h;
    }

    void Plant::bloom(string c){
        color = c;
    }

    void Plant::transform(string s){
        shape = s;
    }

    Plant::Plant(){
        height = 0;
        name = "";
        color = "";
        shape = "";
    }

    Gardener::Gardener(){
        MaxPlant = 10;
    }
    

    Gardener::Gardener(int n){
        MaxPlant = n;
    }

    void Gardener::nurture(Plant* p, string s){
        p->transform(s);
    }

    void Gardener::nurture(Plant& p, float h){
        p.grow(h);
    }

    void Gardener::analyze(Plant p){
        cout<<p.getName()<<" "<<p.getHeight()<<" "<<p.getColor()<<" "<<p.getShape()<<endl;
    }

    void Gardener::addPlant(Plant p){
        if(numPlants < MaxPlant){
            plants[numPlants] = p;
            numPlants++;
        }else{
            cout<<"The garden is full"<<endl;
        }
    }

    Plant* Gardener::findPlant(string n){
        for(int i = 0; i < numPlants; i++){
            if(plants[i].getName() == n){
                return &plants[i];
            }
        }
        return NULL;
    }
}