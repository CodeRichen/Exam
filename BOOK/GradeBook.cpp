#include<bits/stdc++.h>
#include "gradebook.h"

using namespace std;

Gradebook::Gradebook(string course, string instructor)
{
    setCourseName(course);
    setInstructorName(instructor);
}
void Gradebook::setCourseName(string name)
{
    if (name.length()<=25)
    courseName = name;
    if (name.length()>25)
    {
        courseName =name.substr(0,25);
        cout << "Name \"" << name << "\" exceeds maximum length (25).\n"<< "Limiting courseName to first 25 characters.\n" << endl; 
    }
}
string Gradebook::getCourseName()
    {
        return courseName;
    }
void Gradebook::setInstructorName(string name)
{
    instructorName = name;
}
string Gradebook::getInstructorName()
{
    return instructorName;
}

void Gradebook::displayMessage()
{
    cout << "Welcome to " << getCourseName() << " Gradebook" << endl;
    cout << "This course is presented by: " << getInstructorName() << endl;
}

