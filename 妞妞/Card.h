#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

class Card {
public:
    int suit; 
    int rank; 

    Card(int s, int r);
    void show() const;      
    int getNiuValue() const;// JQK 算 10 點
};

#endif
