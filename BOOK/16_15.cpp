#include<bits/stdc++.h>
#include "gradebook.h"
using namespace std;
int main()
{
	Gradebook gradebook("CS101", "Dr.MIKU");
	gradebook.displayMessage();

	gradebook.setInstructorName("Prof. MIKU");
	gradebook.displayMessage();
}

