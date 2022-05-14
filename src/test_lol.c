#include <stdio.h>
#include "s21_sprintf.h"
#include <limits.h>

char mass1[100] = {'\0'}, mass2[100] = {'\0'}; 
char Lmass1[255] = {'\0'}, Lmass2[255] = {'\0'};
int int_test1 = 0, int_test2 = 0;

int main() {
    int_test1 = s21_sprintf(mass1, "%u %lu", UINT_MAX, ULONG_MAX);
    int_test2 = sprintf(mass2, "%u %lu", UINT_MAX, ULONG_MAX);
    printf("%s\n", mass1);

}