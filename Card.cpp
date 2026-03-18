#include "Card.h"

Card::Card(int s, int r) : suit(s), rank(r) {}

void Card::show() const {
    std::string suits[] = {"®ç", "¤ß", "¿j", "±ö"};
    std::string ranks[] = {"", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    std::cout << "[" << suits[suit] << ranks[rank] << "] ";
}

int Card::getNiuValue() const {
    return (rank > 10) ? 10 : rank;
}
