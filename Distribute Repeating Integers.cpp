class Solution {
public:
    bool canDistribute_util(vector<int>&quantity,vector<int>&countArray,int ithCustomer)
    {
        //base case
        if(ithCustomer == quantity.size())
        {
            return true;
        }

        for(int i=0;i<countArray.size();i++)
        {
            if(countArray[i]>=quantity[ithCustomer])
            {
               countArray[i]-=quantity[ithCustomer];
               if(canDistribute_util(quantity,countArray,ithCustomer+1))
               {
                   return true;
               }
               countArray[i]+=quantity[ithCustomer]; //backtrack 
            }
        }
        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int>countmap;
        for(auto number:nums)
        {
           countmap[number]++;
        }
        vector<int>countArray;
        for(auto iterating:countmap)
        {
            countArray.push_back(iterating.second); //.second for frequency
        }
        //agar quantity array ko sort kar dia jaaye to false waali chize pehle hi handle 
        //ho jayegi
        sort(quantity.rbegin(),quantity.rend());
        return canDistribute_util(quantity,countArray,0);
    }
};
