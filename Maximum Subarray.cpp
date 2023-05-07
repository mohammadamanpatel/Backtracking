class Solution {
public:
    int maxSubArrayUtil(vector<int>&nums,int start,int end)
    {
        int mid = (start+end) >> 1;
        if(start == end)
        {
            return nums[start];
        }
        int MaxLeftSubArraySum = INT_MIN;
        int MaxRightSubArraySum = INT_MIN;
        int leftSum = maxSubArrayUtil(nums,start,mid);
        int rightSum = maxSubArrayUtil(nums,mid+1,end);
        int leftborderSum = 0;
        int rightborderSum = 0;
        for(int i = mid;i>=start;i--)
        {
            leftborderSum+=nums[i];
            if(leftborderSum>MaxLeftSubArraySum)
            {
                MaxLeftSubArraySum = leftborderSum;
            }
        }
        for(int i=mid+1;i<=end;i++)
        {
            rightborderSum+=nums[i];
            if(rightborderSum>MaxRightSubArraySum)
            {
                MaxRightSubArraySum = rightborderSum;
            }
        }
        int crossSum = MaxLeftSubArraySum + MaxRightSubArraySum;
        return max(leftSum,max(rightSum,crossSum));
    }
    int maxSubArray(vector<int>& nums) {
        return maxSubArrayUtil(nums,0,nums.size()-1);
    }
};
