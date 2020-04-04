using namespace std;
    
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hashmap;
        int complement, i = 0, length = nums.size();
        
        for (; i < length; i++) {
            complement = target - nums[i];
            if (hashmap.find(complement) != hashmap.end()) break;
            hashmap[nums[i]] = i;
        }
        
        vector<int> solution = { hashmap[complement], i };
        return solution;
    }
};