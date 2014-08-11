#ifndef __RTFieldMap_h__
#define __RTFieldMap_h__

#include <vector>
#include <iostream>


class   RTFieldMap
{
private:
    std::vector<std::vector<double>>    map;

public:
    RTFieldMap(const char* mapFile);
    ~RTFieldMap();
};





#endif
