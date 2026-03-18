#include "Player.h"
#include <algorithm>

Player::Player(int initialMoney) : money(initialMoney), bet(0) {}

void Player::addCard(Card c) {
    hand.push_back(c);
}

void Player::clearHand() {
    hand.clear();
}

int Player::calculateNiu() {
    int totalSum = 0;
    for (int i = 0; i < 5; i++) totalSum += hand[i].getNiuValue();

    int maxNiu = -1; 
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                int threeSum = hand[i].getNiuValue() + hand[j].getNiuValue() + hand[k].getNiuValue();
                if (threeSum % 10 == 0) {
                    int rest = (totalSum - threeSum) % 10;
                    if (rest == 0) rest = 10;
                    if (rest > maxNiu) maxNiu = rest;
                }
            }
        }
    }
    return (maxNiu == -1) ? 0 : maxNiu;
}
