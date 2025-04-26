#include "Garden.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    int maxPlant;
    cin>>maxPlant;
    Garden::Gardener g1(maxPlant);
    string command;
    while (cin>>command)
    {
        if(command == "add"){
            string name, color, shape;
            float height;
            cin>>name>>height>>color>>shape;
            Garden::Plant p1(name, height, color, shape);
            g1.addPlant(p1);
        }
        else if(command == "nurtureH"){
            string name;
            float height;
            cin>>name>>height;
            Garden::Plant* p1 = g1.findPlant(name);
            g1.nurture(*p1, height);
        }else if(command == "nurtureS"){
            string name, shape;
            cin>>name>>shape;
            Garden::Plant* p1 = g1.findPlant(name);
            g1.nurture(p1, shape);
        }
        else if(command == "analyze"){
            string name;
            cin>>name;
            Garden::Plant* p1 = g1.findPlant(name);
            g1.analyze(*p1);
        }else if(command == "end"){
            break;
        }else if(command == "bloom"){
            string name, color;
            cin>>name>>color;
            Garden::Plant* p1 = g1.findPlant(name);
            p1->bloom(color);
        }else if(command == "transform"){
            string name, shape;
            cin>>name>>shape;
            Garden::Plant* p1 = g1.findPlant(name);
            p1->transform(shape);
        }else if(command == "grow"){
            string name;
            float height;
            cin>>name>>height;
            Garden::Plant* p1 = g1.findPlant(name);
            
            p1->grow(height);
        }
    }
    
}