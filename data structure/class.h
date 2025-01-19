#include<iostream>
using namespace std;

class Plant {
public:
    void insert(const string& key, float value, string color, string shape);
    void changecolor(const string& key, string color);
    void grow(const string& key, float value);
    void changeshape(const string& key, string shape);
    void get(const string& key) const;
private:
    string key;
    string color;
    string shape;
    float value;
};