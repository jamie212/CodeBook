// Find the minimum number of coins needed to make a given amount
#include <iostream>
#include <vector>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
    vector<int> count(amount + 1, amount + 1);
    count[0] = 0;
    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i >= coin) {
                count[i] = min(count[i], count[i - coin] + 1);
            }
        }
    }
    return count[amount] == amount + 1 ? -1 : count[amount];
}
int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int result = coinChange(coins, amount);
    if (result != -1) {
        cout << "Minimum number of coins: " << result << endl;
    } else {
        cout << "Cannot change!" << endl;
    }
    return 0;
}