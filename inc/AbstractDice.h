#ifndef ABSTRACTDICE_H
#define ABSTRACTDICE_H

class AbstractDice {
public:
    virtual unsigned roll()=0;
    virtual ~AbstractDice()=0;  
};

#endif