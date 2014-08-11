#include "RTFieldMap.h"

#include <fstream>

using namespace std;


RTFieldMap::RTFieldMap(const char* mapFile)
{
    ifstream    file;
    file.open(mapFile);
    if(!file.is_open())
    {
        cout << "Could not open field map file " << mapFile << "." << endl;
        return;
    }

    string  str;
    getline(file, str);
    int     maxX;
    int     maxZ;
    double  conversion;
    sscanf(str.c_str(), "%d %d %lf", &maxX, &maxZ, &conversion);
    conversion /=100;
    cout << "Maximum X: " << maxX << "   Maximum Z: " << maxZ << "   Conversion Factor in mm: " << conversion*1000 << endl;
    while(!file.eof())
    {
        getline(file, str);
        //cout << str << endl;
    }

}

RTFieldMap::~RTFieldMap()
{

}
