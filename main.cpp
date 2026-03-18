#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include "Player.h"

using namespace std;

int main() {
    srand(time(0));
    Player user(1000); // 玩家初始籌碼
    Player dealer;     // 莊家
    vector<Card> deck;

    cout << "=== 妞妞對決系統 (OOP) ===" << endl;

    while (user.money > 0) {
        cout << "\n[目前餘額]: $" << user.money << endl;
        cout << "請輸入下注金額 (輸入 0 結束): ";
        cin >> user.bet;

        if (user.bet <= 0) break;
        if (user.bet > user.money) {
            cout << "【錯誤】餘額不足！" << endl;
            continue;
        }

        // 初始化牌堆並洗牌
        deck.clear();
        for (int s = 0; s < 4; s++) {
            for (int r = 1; r <= 13; r++) {
                deck.push_back(Card(s, r));
            }
        }
        random_shuffle(deck.begin(), deck.end());

        user.clearHand();
        dealer.clearHand();

        // 發牌 (一人五張)
        for (int i = 0; i < 5; i++) {
            user.addCard(deck.back()); deck.pop_back();
            dealer.addCard(deck.back()); deck.pop_back();
        }

        // --- 顯示玩家結果 ---
        cout << "你的手牌: ";
        for (int i = 0; i < (int)user.hand.size(); i++) {
            user.hand[i].show();
        }
        int uP = user.calculateNiu();
        cout << " -> ";
        if (uP == 10) cout << "【牛牛】";
        else if (uP == 0) cout << "【沒牛】";
        else cout << "【牛 " << uP << "】";
        cout << endl;

        // --- 顯示莊家結果 ---
        cout << "莊家手牌: ";
        for (int i = 0; i < (int)dealer.hand.size(); i++) {
            dealer.hand[i].show();
        }
        int dP = dealer.calculateNiu();
        cout << " -> ";
        if (dP == 10) cout << "【牛牛】";
        else if (dP == 0) cout << "【沒牛】";
        else cout << "【牛 " << dP << "】";
        cout << endl;

        // --- 勝負判定 ---
        if (uP > dP) {
            cout << ">>> 你贏了！獲得 $" << user.bet << endl;
            user.money += user.bet;
        } else {
            cout << ">>> 莊家贏了！失去 $" << user.bet << endl;
            user.money -= user.bet;
        }
    }

    cout << "\n遊戲結束。最終帶走餘額: $" << user.money << endl;
    return 0;
}
