#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long candies(int n, vector<int> ratings) {
    vector<long> candies(n, 1);

    // Left to Right pass
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Right to Left pass
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    // Sum all candies
    long totalCandies = 0;
    for (int i = 0; i < n; i++) {
        totalCandies += candies[i];
    }

    return totalCandies;
}

int main() {
    int n;
    cin >> n;
    vector<int> ratings(n);
    for (int i = 0; i < n; i++) {
        cin >> ratings[i];
    }

    cout << candies(n, ratings) << endl;
    return 0;
}
