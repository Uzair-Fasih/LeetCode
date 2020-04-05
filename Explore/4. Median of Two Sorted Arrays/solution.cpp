using namespace std;
class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    
    int i_limit = nums1.size();
    int j_limit = nums2.size();
    int sorted_size = i_limit + j_limit;
    int index1 = -1, index2 = -1;
    bool even = false;
    int index = 0;
    
    // Determine the indices of the would be median elements;
    even = sorted_size % 2 == 0;
    index1 = sorted_size / 2;
    if (even) index2 = index1 - 1;
    
    
    int i = 0, j = 0;
    double res = 0;

    while (i < i_limit && j < j_limit) {
      if (nums1[i] < nums2[j]) {
        if (even) {
          if (index == index2 || index == index1) res += nums1[i];
        } else {
          if (index == index1) res += nums1[i];
        }
        i++;
      } else {
        if (even) {
          if (index == index2 || index == index1) res += nums2[j];
        } else {
          if (index == index1) res += nums2[j];
        }
        j++;
      }
      index++;
    }
    
    while (i < i_limit && index <= index1) {
      if (even) {
        if (index == index2 || index == index1) res += nums1[i];
      } else {
        if (index == index1) res += nums1[i];
      }
      i++;
      index++;
    }
    
    
    while (j < j_limit && index <= index1) {
      if (even) {
        if (index == index2 || index == index1) res += nums2[j];
      } else {
        if (index == index1) res += nums2[j];
      }
      j++;
      index++;
    }
    
    
    if (even) {
      if (res > 0) {
        res = (double) res / 2;
      }
    }
    
    return res;
  }
};
