#ifndef DUMMYBASECLASSH
#define DUMMYBASECLASSH

class DummyBaseClass
{
public:
    DummyBaseClass()=default;
    virtual ~DummyBaseClass(){};
    virtual void run(){}; //only public function of TestApp template function.
private:
    
};


#endif //DUMMYBASECLASSH
