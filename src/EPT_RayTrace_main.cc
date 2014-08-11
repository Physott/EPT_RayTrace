#ifndef __CINT__


#include <iostream>

#include "RTFieldMap.h"


using namespace std;


int main(int argc, char *argv[])
{
	cout << "starting EPT ray tracing" << endl;

    if(argc != 2)
    {
        cout << "No fieldmap given." << endl;
        return 0;
    }

    RTFieldMap  field(argv[1]);
}




#endif
