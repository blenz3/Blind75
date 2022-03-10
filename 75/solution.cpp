class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (auto num : nums) {
            map[num]++;
        }
        
        int maxGroupSize = 0;
        unordered_map<int, vector<int>> countToValues;
        for (auto kv : map) {
            countToValues[kv.second].push_back(kv.first);
            maxGroupSize = max(maxGroupSize, kv.second);
        }
        
        std::vector<int> out;
        while (out.size() < k) {
            auto currentGroup = countToValues[maxGroupSize];
            for (int i = 0; out.size() < k && i < currentGroup.size(); i++) {
                out.push_back(currentGroup[i]);
            }
        
            // get the next max group size
            int newMaxGroupSize = 0;
            for (auto kv : countToValues) {
                if (kv.first < maxGroupSize)
                    newMaxGroupSize = max(newMaxGroupSize, kv.first);
            }
            
            maxGroupSize = newMaxGroupSize;
        }
        
        return out;
            
#if 0    
        // now that we have the counts let's use max heap
        priority_queue<pair<int, int>> pq;
        for (auto kv : map) {
            pq.push(make_pair(kv.second, kv.first));
        }
        
        // grab the k top elements
        vector<int> out;
        for (int i = 0; i < k; ++i) {
            out.push_back(pq.top().second);
            pq.pop();
        }
#endif        

        return out;
    }
};
