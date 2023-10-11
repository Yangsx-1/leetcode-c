class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int index1 = 0, index2 = 0;
        int first = 0, second = 0;
        int mid = (nums1.size() + nums2.size()) / 2;
        for (int i = 0; i <= mid; ++i){
            first = second;
            if (index1 < nums1.size() && index2 < nums2.size()){
               if (nums1[index1] <= nums2[index2]) {
                    second = nums1[index1];
                    index1++;
                } else {
                    second = nums2[index2];
                    index2++;
                }
            } else if (index1 == nums1.size()) {
                second = nums2[index2];
                index2++;
            } else if (index2 == nums2.size()){
                second = nums1[index1];
                index1++;
            }
        }
        double r = (nums1.size() + nums2.size()) % 2 == 0 ? (first + second) / 2.0 : second;
        return r;
    }
};