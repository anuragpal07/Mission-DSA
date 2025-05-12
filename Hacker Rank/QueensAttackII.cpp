#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    set<pair<int, int>> obstacleSet;
    for (auto &obs : obstacles) {
        obstacleSet.insert({obs[0], obs[1]});
    }

    int directions[8][2] = {
        {-1, 0}, {1, 0},   // vertical (up, down)
        {0, -1}, {0, 1},   // horizontal (left, right)
        {-1, -1}, {-1, 1}, // diagonal up-left, up-right
        {1, -1}, {1, 1}    // diagonal down-left, down-right
    };

    int totalMoves = 0;

    for (int i = 0; i < 8; i++) {
        int dr = directions[i][0];
        int dc = directions[i][1];
        int r = r_q + dr;
        int c = c_q + dc;

        while (r >= 1 && r <= n && c >= 1 && c <= n && obstacleSet.count({r, c}) == 0) {
            totalMoves++;
            r += dr;
            c += dc;
        }
    }

    return totalMoves;
}

int main() {
    int n, k;
    cin >> n >> k;

    int r_q, c_q;
    cin >> r_q >> c_q;

    vector<vector<int>> obstacles(k, vector<int>(2));
    for (int i = 0; i < k; i++) {
        cin >> obstacles[i][0] >> obstacles[i][1];
    }

    cout << queensAttack(n, k, r_q, c_q, obstacles) << endl;

    return 0;
}
