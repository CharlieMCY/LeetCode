#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int sum =  nums1Size + nums2Size;
    double midnum = 0;
    if (sum % 2 == 1) {
    	int i = 0, j = 0, k = 0;
    	int mid = (sum - 1) / 2;
    	while (i < nums1Size && j < nums2Size) {
    		if (nums1[i] < nums2[j]) {
    			midnum = nums1[i++];
    			if (k++ == mid) goto loop;
			} else {
				midnum = nums2[j++];
				if (k++ == mid) goto loop;
			}
		} 
    	while (i < nums1Size) {
    		midnum = nums1[i++];
    		if (k++ == mid) goto loop;
		}
		while (j < nums2Size) {
    		midnum = nums2[j++];
    		if (k++ == mid) goto loop;
		}
	} else {
		int i = 0, j = 0, k = 0;
		int mid = sum / 2;
		int left = 0, right = 0;
		while (i < nums1Size && j < nums2Size) {
    		if (nums1[i] < nums2[j]) {
    			left = right;
    			right = nums1[i++];
    			if (k++ == mid) 
				{
					midnum = (right + left) / 2.0;
					goto loop;
				}
			} else {
				left = right;
    			right = nums2[j++];
				if (k++ == mid)
				{
					midnum = (right + left) / 2.0;
					goto loop;
				}
			}
		}
		while (i < nums1Size) {
			left = right;
    		right = nums1[i++];
    		if (k++ == mid)
    		{
				midnum = (right + left) / 2.0;
				goto loop;
			}
		}
		while (j < nums2Size) {
			left = right;
    		right = nums2[j++];
    		if (k++ == mid)
    		{
				midnum = (right + left) / 2.0;
				goto loop;
			}
		}
	}
	loop:return midnum;
}

int nums1[] = {1,3,5,6};
int nums2[] = {2,4};

int main() {
	double res = findMedianSortedArrays(nums1, 4, nums2, 2);
	printf("%lf", res);
	return 0;
}
