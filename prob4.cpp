/*
There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/

//TODO: Problem is tough. Need to give some time.

#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::endl;

double findMedian(vector<int>& nums1, vector<int>& nums2, int s1, int e1, int s2, int e2)
{
	double med1, med2;
	if(e1 <= s1 && e2 <= s2) {
		med1 = (nums1[s1] + nums1[e1])/2;	
		med2 = (nums2[s2] + nums2[e2])/2;
	}

	int mid1 = (s1 + e1)/2;
	int mid2 = (s2 + e2)/2;	
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {   
	int size1 = nums1.size();
	int size2 = nums2.size();
	
	return findMedian(nums1, nums2, 0, size1, 0, size2);
}


int main() 
{

	return 0;
}
