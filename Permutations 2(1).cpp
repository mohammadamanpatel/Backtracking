class Solution {
public:
    void permutations(vector<int>&nums,vector<vector<int>>&ans,int index)
    {
        //base case
        if(index==nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for(int i=index;i<nums.size();i++)
        {
            swap(nums[i],nums[index]);
            permutations(nums,ans,index+1);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        permutations(nums,ans,0);
        set<vector<int>>s;
        for(auto e:ans)
        {
            s.insert(e);
        }
        ans.clear();
        for(auto e:s)
        {
            ans.push_back(e);
        }
        return ans;
    }
};
