/**
 * Median of Two Sorted Arrays  
 * Myyura
 */

int min(int a, int b) {
    return a < b ? a : b;
}

/*
 *  Find kth number in merged array of two sorted array A and B.
 *  Suppose that A and B are sorted in ascending order and let C be the merged
 *  array of A and B that is also sorted in ascending order.
 *  Also we suppose that arrays start from index 1. 
 *
 *  Basic idea: If A[k / 2] < B[k / 2], then all members in A[1 ... k / 2]
 *              are smaller than (or equal to) C[k].
 */
int findKthOfMergedTwoArrays(int *a, int an, int *b, int bn, int k) {
    if (bn > an) {
        return findKthOfMergedTwoArrays(b, bn, a, an, k);
    } 
    
    if (bn == 0) {
        return a[k - 1];
    }

    if (k == 1) {
        return min(a[0], b[0]);
    }

    int pb = min(k / 2, bn);
    int pa = k - pb;

    if (a[pa - 1] > b[pb - 1]) {
        return findKthOfMergedTwoArrays(a, an, b + pb, bn - pb, k - pb);
    } else if (a[pa - 1] < b[pb - 1]) {
        return findKthOfMergedTwoArrays(a + pa, an - pa, b, bn, k - pa);
    }
    // a[pa - 1] == b[pa - 1]
    return a[pa - 1];
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int n = nums1Size + nums2Size;
    int median1 = 
        findKthOfMergedTwoArrays(nums1, nums1Size, nums2, nums2Size, n / 2 + 1);
    int median2 = 
        n % 2 == 0 ? findKthOfMergedTwoArrays(nums1, nums1Size, nums2, nums2Size, n / 2) : median1;
        
    return ((double)median1 + (double)median2) / 2.0;
}