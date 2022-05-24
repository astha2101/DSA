class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lb=0;
        int rb=nums.size()-1;
        while(lb<=rb)
        {
            int mid=(lb+rb)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            if(nums[mid]<target)
            {
                lb=mid+1;
            }
            else
            {
                rb = mid-1;
            }
        }
        return -1;
        
    }
};
