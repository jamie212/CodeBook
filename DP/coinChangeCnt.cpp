// Find the number of ways to make a given amount using coins
#include <iostream>
#include <vector>
using namespace std;

int coinChangeCount(vector<int>& coins, int amount) {
    vector<int> count(amount + 1, 0);
    count[0] = 1; // One way to make amount 0
    for (int coin : coins) {
        for (int i = coin; i <= amount; ++i) {
            count[i] += count[i - coin];
        }
    }
    return count[amount];
}
int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    int result = coinChangeCount(coins, amount);
    cout << "Number of ways to make amount " << amount << ": " << result << endl;
    return 0;
}