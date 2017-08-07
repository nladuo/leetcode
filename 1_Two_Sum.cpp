class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            int assumed_j = target - nums[i];
            
            for(int j = 0; j < nums.size(); j++){
                if(i == j) continue;
                if(nums[j] == assumed_j ){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};