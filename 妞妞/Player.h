#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Card.h"

class Player {
public:
    std::vector<Card> hand;
    int money;
    int bet;

    Player(int initialMoney = 1000);
    void addCard(Card c);
    void clearHand();
    int calculateNiu();  // 0:沒牛, 1-9:牛幾, 10:牛牛
};

#endif
