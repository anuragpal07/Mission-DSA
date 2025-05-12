class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            int n = nums.size();
            unordered_map<int, int> map;
            vector<int> ans;
            for (int &x : nums) map[x]++;
            vector<vector<int>> arr(n + 1);
            for (auto [a, b] : map) arr[b].push_back(a);
            for (int i = n; i > 0; i--) {
                for (int &x : arr[i]) {
                    if (ans.size() == k) return ans;
                    ans.push_back(x);
                }
            }
            return ans;
        }
    };