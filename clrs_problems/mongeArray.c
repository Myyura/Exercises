/* 
   An m * n array of real numbers is a Monge array if for all i, j, k, and l
   such that 1 <= i <= k <= m and 1 <= j <= l <= n, we have

   A[i][j] + A[k][l] <= A[i][l] + A[k][j],

   We calculate the leftmost minimum element in each row of an m * n Monge array
   A. 
*/

/* 
   Test case:
     10, 17, 13, 28, 23,
     17, 22, 16, 29, 23,
     24, 28, 22, 34, 24,
     11, 13,  6, 17,  7,
     45, 44, 32, 37, 23,
     36, 33, 19, 21,  6,
     75, 66, 51, 53, 34,

   The index of column containing the leftmost minimum element of each row :
      1, 3, 3, 3, 5, 5, 5
*/

#include <limits.h>

#define MAX_M 100
#define MAX_N 100

int pow2 (
    int y
    )
{
    int temp = 1;
    for(int i = 0; i < y; i++) {
        temp = temp << 1;
    }

    return temp;
}

// lm_min[i] is the index of column containing the leftmost minimum element of row i.
// c couters recursions.
void calc_lm_min_of_monge_array (
    double A[MAX_M][MAX_N],
    int m,
    int n,
    int lm_min[],
    int c
    )
{
    if(m != 0) {
        calc_lm_min_of_monge_array(A, m / 2, n, lm_min, c + 1);
        int lambda = pow2(c);
        for(int i = 1; i <= m; i += 2) {
            int left = i == 1 ? 1 : lm_min[(i - 1) * lambda];
            int right = i == m ? n : lm_min[(i + 1) * lambda];
            int min = INT_MAX;
            for(int j = left; j <= right; j++) {
                if(A[i * lambda][j] < min) {
                    min = A[i * lambda][j];
                    lm_min[i * lambda] = j;
                }
            }
        }
    }
}
