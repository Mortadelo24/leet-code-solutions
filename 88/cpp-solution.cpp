class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (nums2.size() < 1) return;
        int index = 0;

        nums1.erase(nums1.end() - n,nums1.end());

        for (int i = 0; i < m + n; i++){
            if (nums1[i] <= nums2[index]) continue;
            nums1.insert(nums1.begin()+i, nums2[index++]);
            i--;
        }

        nums1.insert(nums1.end(), nums2.begin() + index, nums2.end());

    }
};