// finished in 2024.1.28
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int insert_index = nums1.size() - 1;
        int id1 = m - 1, id2 = n - 1;
        while (id1 >= 0 && id2 >= 0) {
            if (nums1[id1] >= nums2[id2]) {
                nums1[insert_index] = nums1[id1];
                --id1;
            } else {
                nums1[insert_index] = nums2[id2];
                --id2;
            }
            --insert_index;
        }
        if (id2 >= 0) {
            while (id2 >= 0) {
                nums1[insert_index] = nums2[id2];
                --id2;
                --insert_index;
            }
        }
    }
};