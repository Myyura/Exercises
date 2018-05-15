/* Counting Sundays */

#include <stdio.h>

int is_leap(int year) {  
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))  
        return 1;  
    return 0;  
}

int count_sundays_on_1st_of_month(void) {
    int month[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},  
                        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};  

    int day = 367;
    int count = 0;
    for (int i = 1901; i <= 2000; i++) {
        int leap = is_leap(i);
        for (int j = 0; j < 12; j++) {
            day += month[leap][j];
            count += (day % 7 == 0);
        }
    }

    return count;
}
  
int main(void) {
    printf("%d\n", count_sundays_on_1st_of_month());
    return 0;  
}  
