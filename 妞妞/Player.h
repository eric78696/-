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
    int calculateNiu(); // 0:¨S¤û, 1-9:¤û´X, 10:¤û¤û
};

#endif
