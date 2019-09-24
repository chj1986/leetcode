class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                if(nums.at(i)+nums.at(j)==target)
                {
                    ret.push_back(i);
                    ret.push_back(j);
                }
            }
        }
        return ret;
    }
};
