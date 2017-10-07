#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>

int mod(int a, int b)
{
    if (a<b)
        return a;
    else
        return a-(a/b)*b;
}

int pow(int root,int exp)
{
    int res=1;
    for(int i=0; i<exp;++i)
    {
        res*=root;
    }
    return res;
}

void printExpMod(int n=7)
{
    std::cout << std::endl;
    std::cout  << "a" << std::setw(2) << '|';    
    for (int i=1;i<n;++i)
        std::cout  << "a" << i << std::setw(2) << '|';
    
    std::cout << std::endl;
    for (int m=1;m<n;++m)
    {
        std::cout << std::left << std::setw(2) << m << '|';
        for(int i=1;i<n;++i)
        {
            std::cout << std::setw(2) << std::right << mod(pow(m,i),n) << std::setw(2) << '|';
        }
        std::cout << std::endl;
    }    
}

std::vector<std::vector<int>> getExpMod(int n=7)
{
    std::vector<std::vector<int>> retur;
    std::vector<int> line;

    for (int m=1;m<n;++m)
    {
        for(int i=1;i<n;++i)
        {
            line.push_back(mod(pow(m,i),n));
        }
        retur.push_back(line);
        line.clear();
    } 
    return retur; 
}


std::vector<int> getPrimRoots(int n)
{
    std::vector<int> retur;

    int counter =0;
    for (auto & line: getExpMod(n))
    {
        ++counter;
        std::sort(line.begin(),line.end());
        if (std::unique(line.begin(),line.end())==line.end())
            retur.push_back(counter);
    }
    return retur;
}

void printPrimRoots(int n)
{
    std::vector<int> primitiveRoots = getPrimRoots(n);
    if(primitiveRoots.size()!=0)
    {
        std::cout << "Primitive roots of " << n << " are: ";
        for (auto i: primitiveRoots)
        {
            std::cout << i << ',';
        }    
        std::cout << std::endl;
    }
    else
    {
        std::cout << n << " has no primitive roots!" << std::endl;
    }
    
    
}

int main(int argc, char *argv[])
{
    printPrimRoots(std::stoi(argv[1]));

    for (int i =0;i<500;++i)
    {
        printPrimRoots(i);
        
    }
}