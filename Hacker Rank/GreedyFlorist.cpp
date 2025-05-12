#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;

    vector<int> friends(k, 1);
    vector<int> flowers;
    for (int i = 0; i < n; ++i) {
        int f;
        cin >> f;
        flowers.push_back(f);
    }

    sort(begin(flowers), end(flowers));

    int total = 0;
    while (n --> 0) {
        total += flowers[n] * friends[0];
        ++friends[0];
        make_heap(begin(friends), end(friends), greater<int>());
    }
    cout << total << endl;
}