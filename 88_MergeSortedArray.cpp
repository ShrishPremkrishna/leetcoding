/* 
Problem: 88. Merge Sorted Array
Link: https://leetcode.com/problems/merge-sorted-array?envType=study-plan-v2&envId=top-interview-150

Notes: I get two non decreasing arrays and their sizes. I need to combine them both into a nondecreasing array. 
Need to edit the first array directly. The first array has the extra space for the seconc array at the end. Goal is o(n+m)

Tags: Arrays, Sorting 

"Show me the simplest improvement in time/space complexity without rewriting my entire solution."

Takeaway: Traverse arrays/vectors backward so that when you replace elements, it doesn't shift elements and add extra complexity.
*/

#include "includes.hpp"

// Arguably better but not o(n+m) and uses an inbuilt sort algo
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.erase(nums1.begin() + (m), nums1.begin() + (m+n));
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
    }
};

// Uses takeaway and refactors
// three pointers to go through the two arrays. Simple, unintuitive, smart ?
class Solution2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;

        int nums2Last = n-1;
        int nums1Last = m-1;
        int last = n+m-1;

        while (nums2Last >= 0 && nums1Last >= 0){
            if (nums1[nums1Last] > nums2[nums2Last]){
                nums1[last] = nums1[nums1Last];
                last--;
                nums1Last--;
            } else {
                nums1[last] = nums2[nums2Last];
                last--;
                nums2Last--;
            }
        }

        while (nums2Last >= 0) {
            nums1[last] = nums2[nums2Last];
            nums2Last--;
            last--;
        }
    }
};

int main() {
    Solution sol;
    return 0;
}

