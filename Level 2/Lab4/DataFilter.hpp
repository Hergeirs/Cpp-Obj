#ifndef DATAFILTERH
#define DATAFILTERH

#include "DataFileReader.hpp"
#include <memory> // for std::unique_ptr
#include <fstream>


template<typename T>
class DataFilter 
{
    public:

        DataFilter(DataFileReader<T> *aReader= new DataFileReader<T>("values.dat","ReadErrors.dat"), T aMin=0.00, T aMax=10.0);
        /* pre: aReader points to an instance of DataFileReader<T>
        for which openFiles() has been succesfully called.
        */
        void run();
        
        const bool getNextValue(T &aValue);
        /* pre: an earlier call to getNextValue() has not returned
        false.
        post: true is returned if aValue holds a value read from
        aReader. If a value could not be read, false
        is returned. If a value is read but is not within
        the interval specified by aMin and aMax parameters
        to the constructor, a range_error exception is
        thrown.
        */
    private:
        const bool rangeOk(T &aValue);
        const T min;
        const T max;
        T sum;
        T amount;        
        T avg;
        T filterAmount;
        std::ofstream rangeErrorFile;
        
        std::unique_ptr<DataFileReader<T>> reader;

        //... necessary members
};

#endif