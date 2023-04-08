class Solution {
public:
    void solve(int open,int close,vector<string>&ans,string &output,int n)
    {
        //base case
        if(open == 0 and close == 0)
        {
            ans.push_back(output);
            return;
        }
        //ek case
        
        //include open
        if(open>0)
        {
            output.push_back('(');
            solve(open-1,close,ans,output,n);
            output.pop_back();
        }
        if(close>open)
        {
            output.push_back(')');
            solve(open,close-1,ans,output,n);
            output.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int open = n;
        int close = n;
        vector<string>ans;
        string output;
        solve(open,close,ans,output,n);
        return ans;
    }
};
