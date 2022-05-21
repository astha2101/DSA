/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

/*
#include <map>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       map<int,int> m;
       std::pair<std::map<int,int>::iterator,bool> ret;
        for(int i=0;i<nums.size();i++)
        {
            ret = m.insert(std::pair<int,int>(nums[i],0));
            if(ret.second==false)
            {
                return true;
            }
        }
        return false;
        
    }
};

/*
Time complexity : - O(nlogn)
Space complexity :- O(n) {worst case}
*/
