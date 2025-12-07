//LeetCode349
//Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       std::unordered_set<int> s1(nums1.begin(), nums1.end());
       std::unordered_set<int> resSet;
        for (int num : nums2) {
            if (s1.count(num)) {
                resSet.insert(num);
            }
        }
        std::vector<int> result(resSet.begin(), resSet.end());
        return std::vector<int>(resSet.begin(), resSet.end());;
    }


//LeetCode350
//Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.


    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> counts;
        for (int num : nums1) {
        counts[num]++;
    }
    vector<int> result;
     for (int num : nums2) {
            if (counts[num] > 0) {
                result.push_back(num);
                counts[num]--;
            }
        }

        return result;
    }
