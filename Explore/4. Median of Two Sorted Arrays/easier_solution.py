using namespace std;
class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int i_limit = nums1.size();
    int j_limit = nums2.size();
    vector<int> sorted;
    int i = 0, j = 0;
    double res = 0;

    while (i < i_limit && j < j_limit) {
      if (nums1[i] < nums2[j]) {
        sorted.push_back(nums1[i++]);
      } else {
        sorted.push_back(nums2[j++]);
      }
    }
    
    while (i < i_limit) {
      sorted.push_back(nums1[i++]);
    }
    
    
    while (j < j_limit) {
      sorted.push_back(nums2[j++]);
    }
    
    int index = sorted.size();
    if (index % 2 == 0) {
      index /= 2;
      res =  (sorted[index] + sorted[index - 1]);
      if (res > 0) {
        res = (double) res / 2;
      }
    } else {
      index /= 2;
      res = sorted[index];
    }
    return res;
  }
};
