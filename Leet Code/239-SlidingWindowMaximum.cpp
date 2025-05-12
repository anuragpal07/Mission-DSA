class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            deque<int> windowIndices; 
            vector<int> maxValues;    
            for (int i = 0; i < nums.size(); ++i) {
                if (!windowIndices.empty() && i - k >= windowIndices.front()) {
                    windowIndices.pop_front();
                }
                while (!windowIndices.empty() && nums[windowIndices.back()] <= nums[i]) {
                    windowIndices.pop_back();
                }
                windowIndices.push_back(i);
                if (i >= k - 1) {
                    maxValues.emplace_back(nums[windowIndices.front()]);
                }
            }
            return maxValues;
        }
    }; 