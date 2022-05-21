/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

*/
#include<map>
#include<math.h>
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> m;
        pair<map<int,int>::iterator,bool> ret;
        for(int i=0;i<nums.size();i++)
        {
            ret = m.insert(pair<int,int>(nums[i],i));
            if(ret.second == false)
            {
                int diff = abs(i-ret.first->second);
                if(diff<=k) return true;
                ret.first->second = i;
            }
        }
        return false;
        
    }
};
