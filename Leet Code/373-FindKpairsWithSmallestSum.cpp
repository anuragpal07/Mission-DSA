class Solution {
    public:
        vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
            int n1 = nums1.size(), n2 = nums2.size();
            vector<vector<int>> R;
            priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>> PQ;
            for (int i=0; i<n1; ++i) {
                for (int j=0; j<n2; ++j) {
                    int num1 = nums1[i], num2 = nums2[j], sum = num1+num2;
                    if (PQ.size()<k) PQ.push({sum,num1,num2});
                    else if (sum < get<0>(PQ.top())) {
                        PQ.pop();
                        PQ.push({sum,num1,num2});
                    } else break;
                }
            }
    
            while (k--) {
                auto top = PQ.top(); PQ.pop();
                int num1 = get<1>(top), num2 = get<2>(top);
                R.push_back({num1,num2});
            }
            return R;
        }
    };