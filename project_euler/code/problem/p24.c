/* Lexicographic permutations */
/* Myyyura */

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void lexicographic_permutation_enumerate(int p[], int len, int n) {
    int count = 1;
    while (count < n) {
        int i = len - 1;
        for (; p[i - 1] >= p[i]; i--)
            ;
        
        int j = len;
        for (; p[j - 1] <= p[i - 1]; j--)
            ;

        swap(&p[i - 1], &p[j - 1]);
        for (i = i + 1, j = len; i < j; i++, j--) {
            swap(&p[i - 1], &p[j - 1]);
        }

        count++;
    }
}

/* 
    Factorial number system 
    https://en.wikipedia.org/wiki/Factorial_number_system
    
    Seems useful to solve this problem
*/

int main(void) {
    int p[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    lexicographic_permutation_enumerate(p, 10, 1e6);
    for (int i = 0; i < 10; i++) {
        printf("%d", p[i]);
    }
    printf("\n");
    return 0;
}
