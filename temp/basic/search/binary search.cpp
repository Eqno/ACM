#include <vector>
using namespace std;

class Solution {
public:
    int leftSearch(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size()-1;
        while (l <= r)
        {
            int m = (l + r) >> 1;
            if (nums[m] >= target) r = m - 1;
            else l = m + 1;
        }
        if (l<nums.size() && nums[l]==target) return l;
        return -1;
    }
    int rightSearch(vector<int> &nums, int target) 
    {
        int l = 0, r = nums.size()-1;
        while (l <= r)
        {
            int m = (l + r) >> 1;
            if (nums[m] > target) r = m - 1;
            else l = m + 1;
        }
        if (r>=0 && nums[r]==target) return r;
        return -1;
    }
    int binarySearch(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size()-1;
        while (l <= r)
        {
            int m = (l + r) >> 1;
            if (nums[m] == target) return m;
            if (nums[m] > target) r = m-1;
            else l = m + 1;
        }
    }  
    vector<int> searchRange(vector<int>& nums, int target) {
        return {leftSearch(nums, target), rightSearch(nums, target)};
    }
};