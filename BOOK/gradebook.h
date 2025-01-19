#include<bits/stdc++.h>
using namespace std;
class Gradebook
{
public:
    explicit Gradebook(string course, string instructor);
    void setCourseName(string);
    string getCourseName();
    void setInstructorName(string); 
    string getInstructorName();     
    void displayMessage();

private:
    string courseName;
    string instructorName;          
};