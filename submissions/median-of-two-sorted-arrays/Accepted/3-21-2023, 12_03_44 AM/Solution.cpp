// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector <int> ans;
        int n1=nums1.size(),n2=nums2.size();
        int i=0,j=0;

        while(i!=n1 && j!=n2){
            if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }

        while(i!=n1){
            ans.push_back(nums1[i]);
            i++;
        }

        while(j!=n2){
            ans.push_back(nums2[j]);
            j++;
        }

        int n=ans.size();
        double a;
        if(n&1){
            int m=n/2;
            a=ans[m];
        }
        else{
            int m1=n/2;
            int m2=n/2-1;
            a=(ans[m1]+ans[m2])/(2*1.0);
        }
        
        return a;
    }
};