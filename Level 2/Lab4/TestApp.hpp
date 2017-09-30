#ifndef TESTAPPH
#define TESTAPPH

#include "DataFilter.hpp"

class TestApp
{
public:
    TestApp();
    ~TestApp();
    
    void run();
private:
    DataFilter<double> filter;
};



#endif //TESTAPPH
