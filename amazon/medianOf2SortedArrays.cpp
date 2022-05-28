class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) findMedianSortedArrays(nums2,nums1);
        int low,high,n1,n2,c1,c2;
        int l1,l2,r1,r2;
        n1=nums1.size();
        n2=nums2.size();
        low=0;
        high=nums1.size();
        while(low<=high)
        {
            c1= (low+high)/2;
            c2=((n1+n2+1)/2)-c1;
            l1 = c1 == 0 ? INT_MIN : nums1[c1-1];
            l2 = c2 == 0 ? INT_MIN : nums2[c2-1];
            r1 = c1 == n1 ? INT_MAX : nums1[c1];
            r2 = c2 == n2 ? INT_MAX : nums2[c2];
            if(l1<=r2 && l2<=r1)
                {
                    if((n1+n2) % 2 == 0)
                    {
                        return (max(l1,l2) + min(r1,r2))/ 2.0;
                    }
                    else
                    {
                        return max(l1,l2);
                    }
            }
            if(l1>r2)
                {
                    high = c1-1;
                }
            else
                {
                    low = c1+1;
                }
        }
        return 0.0;
    }
};

/*
Time complexity : O(log(m+n))
*/
