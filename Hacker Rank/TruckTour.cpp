#include <iostream>
#include <vector>
using namespace std;

int truckTour(vector<pair<int, int>> petrolpumps) {
    int total_petrol = 0;
    int total_distance = 0;
    int start_index = 0;
    int current_petrol = 0;

    for (int i = 0; i < petrolpumps.size(); i++) {
        int petrol = petrolpumps[i].first;
        int distance = petrolpumps[i].second;

        total_petrol += petrol;
        total_distance += distance;

        current_petrol += petrol - distance;
        
        // If current_petrol becomes negative, start from next pump
        if (current_petrol < 0) {
            start_index = i + 1;
            current_petrol = 0;
        }
    }

    // If total petrol is less than total distance, not possible
    if (total_petrol < total_distance) {
        return -1;
    }

    return start_index;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> petrolpumps(n);

    for (int i = 0; i < n; i++) {
        int petrol, distance;
        cin >> petrol >> distance;
        petrolpumps[i] = {petrol, distance};
    }

    cout << truckTour(petrolpumps) << endl;
    return 0;
}
