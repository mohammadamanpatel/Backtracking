
    class Solution {
public:
    void combinationSum_util(vector<int>&candidates,int target,vector<int>&v,vector<vector<int>>&ans,int index)
    {
        //base case
        if(target == 0)
        {
            ans.push_back(v);
            return;
        }
        if(target<0)
        {
            return;
        }
        for(int i=index;i<candidates.size();i++)
        {
            if(i>index and candidates[i] == candidates[i-1])  //filhaal waale index se equal nhi hona chahiye means ab jab agli calling hui jo usse pehle check
            {                                                 //hua ki i>index (index current state waala hi hai eg:=> i=3 aur index = 2) && c[i] == c[i-1] to continue mean duplicate 
                                                              //is not allowed
                continue;
            }
            v.push_back(candidates[i]);
            combinationSum_util(candidates,target-candidates[i],v,ans,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       sort(candidates.begin(),candidates.end());
       vector<int>v;
       vector<vector<int>>ans;
       combinationSum_util(candidates,target,v,ans,0);
    //    set<vector<int>>s;
    //    for(auto ele:ans)
    //    {
    //        s.insert(ele);
    //    }
    //    //ab ans clear karenge taaki unduplicate pair daal sake 
    //    ans.clear();
    //    for(auto ele:s)
    //    {
    //        ans.push_back(ele);
    //    }
       return ans; 
    }
};
