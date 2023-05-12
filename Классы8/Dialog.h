#pragma once
#include "Vector.h"
#include "TEvent.h"
#include "Student.h"
class Dialog :
    public Vector
{
protected:
    int EndState;
public:
    Dialog();
    virtual ~Dialog();
    virtual void GetEvent(TEvent& event);
    virtual int Execute();
    virtual void HandleEvent(TEvent&);
    virtual void ClearEvent(TEvent&);
    int Valid();
    void EndExec();
};

