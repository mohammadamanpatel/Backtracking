class Solution {
public:
    void solve(string &output,vector<string>&ans,string &digits,int i,vector<string>&map)
    {
        //base case
        if(i>=digits.length())
        {
            ans.push_back(output);
            return;
        }

        //ek case
        int digit = digits[i] - '0';
        string value = map[digit];
        for(int j=0;j<value.length();j++)
        {
            char ch = value[j];
            //include char ko
            output.push_back(ch);
            solve(output,ans,digits,i+1,map);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string output = "";
        vector<string>ans;
        if(digits.length()==0)
        {
            return ans;
        }
        vector<string>map(10);
        map[2] = "abc";
        map[3] = "def";
        map[4] = "ghi";
        map[5] = "jkl";
        map[6] = "mno";
        map[7] = "pqrs";
        map[8] = "tuv";
        map[9] = "wxyz"; 
        int i = 0;
        solve(output,ans,digits,i,map);
        return ans;
    }
};
