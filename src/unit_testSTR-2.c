#include <check.h>
#include "s21_string.h"
#include <string.h>
#include <limits.h>

char mass1[100] = {'\0'}, mass2[100] = {'\0'}; 
char Lmass1[255] = {'\0'}, Lmass2[255] = {'\0'};
int int_test1 = 0, int_test2 = 0;

int n = 2100, n1 = 0, n2 = -21;
long int lg = 12345678912345, lg1 = -12345678912345;
short sh = 123, sh1 = -123;
float f = 21.21, f1 = -21.21;

char char_test1 = 'T', char_test2 = 'Z';
wchar_t str_test[10] = {'h', 'e', 'l', 'l', 'o'};

void free_array(char *arr1, char *arr2) {
    int Legth1 = sizeof(arr1);
    int Legth2 = sizeof(arr2);
    if(Legth1 < Legth2) Legth1 = Legth2;

    for (int i = 0; i < Legth1; i++) {
        arr1[i] = '\0';
        arr2[i] = '\0';
    }
}

START_TEST(sprintfTest_s_string) {
    
    int count = 0;

    s21_sprintf(mass1, "%s", "Hello");
    sprintf(mass2, "%s", "Hello");
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "%.1s", "Hello");
    sprintf(mass2, "%.1s", "Hello");
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "%7s", "Hello");
    sprintf(mass2, "%7s", "Hello");
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "%-10s", "Hello");
    sprintf(mass2, "%-10s", "Hello");
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "qwerty %s qwe", "qwerty");
    sprintf(mass2, "qwerty %s qwe", "qwerty");
    ck_assert_str_eq(mass1, mass2);
    free_array(mass1, mass2);

    int_test1 = s21_sprintf(Lmass1, "%s", "");
    int_test2 = sprintf(Lmass2, "%s", "");
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);  

    int_test1 = s21_sprintf(Lmass1, "%23s", "aboba");
    int_test2 = sprintf(Lmass2, "%23s", "aboba");
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);  

    // int_test1 = s21_sprintf(Lmass1, "%-15s", "helloworld");
    // int_test2 = sprintf(Lmass2, "%-15s", "helloworld");
    // ck_assert_str_eq(Lmass1, Lmass2);
    // ck_assert_int_eq(int_test1, int_test2); count++;
    // int_test1 = 0;
    // int_test2 = 0;
    // free_array(Lmass1, Lmass2);  

    int_test1 = s21_sprintf(Lmass1, "%10.s", "ABOBA");
    int_test2 = sprintf(Lmass2, "%10.s", "ABOBA");
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);  

    int_test1 = s21_sprintf(Lmass1, "%15.2s", "ABOBBAAA");
    int_test2 = sprintf(Lmass2, "%15.2s", "ABOBBAAA");
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);  


    int_test1 = s21_sprintf(Lmass1, "%15ls", str_test);
    int_test2 = sprintf(Lmass2, "%15ls", str_test);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%15.3ls", str_test);
    int_test2 = sprintf(Lmass2, "%15.3ls", str_test);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%s %10s", "hello", "hello");
    int_test2 = sprintf(Lmass2, "%s %10s", "hello", "hello");
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%.s %.3s %.10s", "hello", "hello", "hello");
    int_test2 = sprintf(Lmass2, "%.s %.3s %.10s", "hello", "hello", "hello");
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%-10s %-3s", "hello", "hello");
    int_test2 = sprintf(Lmass2, "%-10s %-3s", "hello", "hello");
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%ls %10ls", L"hello", L"hello");
    int_test2 = sprintf(Lmass2, "%ls %10ls", L"hello", L"hello");
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%-10ls", L"hello");
    int_test2 = sprintf(Lmass2, "%-10ls", L"hello");
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%-3ls", L"hello");
    int_test2 = sprintf(Lmass2, "%-3ls", L"hello");
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%.ls", L"hello");
    int_test2 = sprintf(Lmass2, "%.ls", L"hello");
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%.3ls", L"hello");
    int_test2 = sprintf(Lmass2,"%.3ls", L"hello");
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%.10ls", L"hello");
    int_test2 = sprintf(Lmass2,"%.10ls", L"hello");
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);


    printf("TestSpecifier 's' = %d tests\n", count);

}
END_TEST

START_TEST(sprintfTest_c_string) {
    
    int count = 0;

    s21_sprintf(Lmass1, "%10c", 'a');
    sprintf(Lmass2, "%10c", 'a');
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    s21_sprintf(Lmass1, "%-10c", 'e');
    sprintf(Lmass2, "%-10c", 'e');
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    s21_sprintf(Lmass1, "%c hello %c", '\0', '\0');
    sprintf(Lmass2, "%c hello %c", '\0', '\0');
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);
    
    s21_sprintf(Lmass1, "%25c", 'f');
    sprintf(Lmass2, "%25c", 'f');
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    s21_sprintf(Lmass1, "%-30c", 'R');
    sprintf(Lmass2, "%-30c", 'R');
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    s21_sprintf(Lmass1, "%25c", 'Q');
    sprintf(Lmass2, "%25c", 'Q');
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);   
    

    s21_sprintf(Lmass1, "%2c", 'L');
    sprintf(Lmass2, "%2c", 'L');
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);


    s21_sprintf(Lmass1, "%lc", char_test1);
    sprintf(Lmass2, "%lc", char_test1);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    s21_sprintf(Lmass1, "%c", CHAR_MAX);
    sprintf(Lmass2, "%c", CHAR_MAX);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    s21_sprintf(Lmass1, "%c", CHAR_MIN);
    sprintf(Lmass2, "%c", CHAR_MIN);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    s21_sprintf(Lmass1, "%c", UCHAR_MAX);
    sprintf(Lmass2, "%c", UCHAR_MAX);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    s21_sprintf(Lmass1, "%c %c %c", CHAR_MAX, CHAR_MIN, UCHAR_MAX);
    sprintf(Lmass2, "%c %c %c", CHAR_MAX, CHAR_MIN, UCHAR_MAX);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    s21_sprintf(Lmass1, "%-50lc", char_test2);
    sprintf(Lmass2, "%-50lc", char_test2);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    s21_sprintf(Lmass1, "%c", '!');
    sprintf(Lmass2, "%c", '!');
    ck_assert_str_eq(Lmass1, Lmass2); count++;
    free_array(Lmass1, Lmass2);

    s21_sprintf(Lmass1, "%10c", 'a');
    sprintf(Lmass2, "%10c", 'a');
    ck_assert_str_eq(Lmass1, Lmass2); count++;
    free_array(Lmass1, Lmass2);

    s21_sprintf(Lmass1, "%-10c", 'b');
    sprintf(Lmass2, "%-10c", 'b');
    ck_assert_str_eq(Lmass1, Lmass2); count++;
    free_array(Lmass1, Lmass2);

    s21_sprintf(Lmass1, "%c %10c %-10c", '!', 'a', 'b');
    sprintf(Lmass2, "%c %10c %-10c", '!', 'a', 'b');
    ck_assert_str_eq(Lmass1, Lmass2); count++;
    free_array(Lmass1, Lmass2);

    s21_sprintf(mass1, "%1c %c", 'H', 'z');
    sprintf(mass2, "%1c %c", 'H', 'z');
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "%10c %2c", 'H', 'z');
    sprintf(mass2, "%10c %2c", 'H', 'z');
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "%-1c %-c", 'H', 'z');
    sprintf(mass2, "%-1c %-c", 'H', 'z');
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "abc %3c abc", '*');
    sprintf(mass2, "abc %3c abc", '*');
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "abc %-3c abc", '*');
    sprintf(mass2, "abc %-3c abc", '*');
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "qwerty %c %-5c %15c", '$', '/', '!');
    sprintf(mass2, "qwerty %c %-5c %15c", '$', '/', '!');
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    printf("TestSpecifier 'c' = %d tests\n", count);

}
END_TEST

// START_TEST(sprintfTest_f_string) {
//     int count = 0;

//     s21_sprintf(mass1, "abc %+.4f abc", 166.087);
//     sprintf(mass2, "abc %+.4f abc", 166.087);
//     ck_assert_str_eq(mass1, mass2); count++;
//     free_array(mass1, mass2);

//     s21_sprintf(mass1, "abc %-12.3f abc", 166.87);
//     sprintf(mass2, "abc %-12.3f abc", 166.87);
//     ck_assert_str_eq(mass1, mass2); count++;
//     free_array(mass1, mass2);

//     s21_sprintf(mass1, "abc %f abc", -166.87);
//     sprintf(mass2, "abc %f abc", -166.87);
//     ck_assert_str_eq(mass1, mass2); count++;
//     free_array(mass1, mass2);

//     s21_sprintf(mass1, "%f", 100000.3);
//     sprintf(mass2, "%f", 100000.3);
//     ck_assert_str_eq(mass1, mass2); count++;
//     free_array(mass1, mass2);

//     s21_sprintf(mass1, "%0f", 100000.4);
//     sprintf(mass2, "%0f", 100000.4);
//     ck_assert_str_eq(mass1, mass2); count++;
//     free_array(mass1, mass2);

//     s21_sprintf(mass1, "%f", -100000.4);
//     sprintf(mass2, "%f", -100000.4);
//     ck_assert_str_eq(mass1, mass2); count++;
//     free_array(mass1, mass2);

//     s21_sprintf(mass1, "%+f %+f", -100000.4, 1000.231);
//     sprintf(mass2, "%+f %+f", -100000.4, 1000.231);
//     ck_assert_str_eq(mass1, mass2); count++;
//     free_array(mass1, mass2);

//     s21_sprintf(mass1, "%-20f", 100000.4);
//     sprintf(mass2, "%-20f", 100000.4);
//     ck_assert_str_eq(mass1, mass2); count++;
//     free_array(mass1, mass2);


//     s21_sprintf(mass1, "abc %.lf", 58787.878958);
//     sprintf(mass2, "abc %.lf", 58787.878958);
//     ck_assert_str_eq(mass1, mass2); count++;
//     free_array(mass1, mass2);

//     s21_sprintf(mass1, "abc %.10f", 587.00089);
//     sprintf(mass2, "abc %.10f", 587.00089);
//     ck_assert_str_eq(mass1, mass2); count++;
//     free_array(mass1, mass2);

//     s21_sprintf(mass1, "%-+20f", 100000.4);
//     sprintf(mass2, "%-+20f", 100000.4);
//     ck_assert_str_eq(mass1, mass2); count++;
//     free_array(mass1, mass2);

//     s21_sprintf(mass1, "%-20f", -100000.4);
//     sprintf(mass2, "%-20f", -100000.4);
//     ck_assert_str_eq(mass1, mass2); count++;
//     free_array(mass1, mass2);

//     s21_sprintf(mass1, "%+20f", 100000.4);
//     sprintf(mass2, "%+20f", 100000.4);
//     ck_assert_str_eq(mass1, mass2); count++;
//     free_array(mass1, mass2);

//     s21_sprintf(mass1, "%+20f", -100000.4);
//     sprintf(mass2, "%+20f", -100000.4);
//     ck_assert_str_eq(mass1, mass2); count++;
//     free_array(mass1, mass2);
    
//     float key = 10000;
//     s21_sprintf(mass1, "%+20f", key);
//     sprintf(mass2, "%+20f", key);
//     ck_assert_str_eq(mass1, mass2); count++;
//     free_array(mass1, mass2);

//     int_test1 = s21_sprintf(Lmass1, "%+-10.5f", 2546.4324);
//     int_test2 = sprintf(Lmass2, "%+-10.5f", 2546.4324);
//     ck_assert_str_eq(Lmass1, Lmass2);
//     ck_assert_int_eq(int_test1, int_test2); count++;
//     int_test1 = 0;
//     int_test2 = 0;
//     free_array(Lmass1, Lmass2);

//     int_test1 = s21_sprintf(Lmass1, "%+10.2f", 3452.4325);
//     int_test2 = sprintf(Lmass2, "%+10.2f", 3452.4325);
//     ck_assert_str_eq(Lmass1, Lmass2);
//     ck_assert_int_eq(int_test1, int_test2); count++;
//     int_test1 = 0;
//     int_test2 = 0;
//     free_array(Lmass1, Lmass2);

//     int_test1 = s21_sprintf(Lmass1, "%15.16f", 5678.43256);
//     int_test2 = sprintf(Lmass2, "%15.16f", 5678.43256);
//     ck_assert_str_eq(Lmass1, Lmass2);
//     ck_assert_int_eq(int_test1, int_test2); count++;
//     int_test1 = 0;
//     int_test2 = 0;
//     free_array(Lmass1, Lmass2);


//     int_test1 = s21_sprintf(Lmass1, "%25.f", 4325678.43242);
//     int_test2 = sprintf(Lmass2, "%25.f", 4325678.43242);
//     ck_assert_str_eq(Lmass1, Lmass2);
//     ck_assert_int_eq(int_test1, int_test2); count++;
//     int_test1 = 0;
//     int_test2 = 0;
//     free_array(Lmass1, Lmass2);

//     int_test1 = s21_sprintf(Lmass1, "%f %f", (double)UINT_MAX, (double)ULONG_MAX);  // FAIL
//     int_test2 = sprintf(Lmass2, "%f %f", (double)UINT_MAX, (double)ULONG_MAX);
//     ck_assert_str_eq(Lmass1, Lmass2);
//     ck_assert_int_eq(int_test1, int_test2); count++;
//     int_test1 = 0;
//     int_test2 = 0;
//     free_array(Lmass1, Lmass2);

//     int_test1 = s21_sprintf(Lmass1, "%f", (double)INT_MAX);
//     int_test2 = sprintf(Lmass2, "%f", (double)INT_MAX);
//     ck_assert_str_eq(Lmass1, Lmass2);
//     ck_assert_int_eq(int_test1, int_test2); count++;
//     int_test1 = 0;
//     int_test2 = 0;
//     free_array(Lmass1, Lmass2);

//     int_test1 = s21_sprintf(Lmass1, "%f", (double)INT_MIN);
//     int_test2 = sprintf(Lmass2, "%f", (double)INT_MIN);
//     ck_assert_str_eq(Lmass1, Lmass2);
//     ck_assert_int_eq(int_test1, int_test2); count++;
//     int_test1 = 0;
//     int_test2 = 0;
//     free_array(Lmass1, Lmass2);

//     int_test1 = s21_sprintf(Lmass1, "%f", (double)SHRT_MAX);
//     int_test2 = sprintf(Lmass2, "%f", (double)SHRT_MAX);
//     ck_assert_str_eq(Lmass1, Lmass2);
//     ck_assert_int_eq(int_test1, int_test2); count++;
//     int_test1 = 0;
//     int_test2 = 0;
//     free_array(Lmass1, Lmass2);

//     int_test1 = s21_sprintf(Lmass1, "%f", (double)SHRT_MIN);
//     int_test2 = sprintf(Lmass2, "%f", (double)SHRT_MIN);
//     ck_assert_str_eq(Lmass1, Lmass2);
//     ck_assert_int_eq(int_test1, int_test2); count++;
//     int_test1 = 0;
//     int_test2 = 0;
//     free_array(Lmass1, Lmass2);

//     int_test1 = s21_sprintf(Lmass1, "%f", (double)LONG_MIN);
//     int_test2 = sprintf(Lmass2, "%f", (double)LONG_MIN);
//     ck_assert_str_eq(Lmass1, Lmass2);
//     ck_assert_int_eq(int_test1, int_test2); count++;
//     int_test1 = 0;
//     int_test2 = 0;
//     free_array(Lmass1, Lmass2);

//     int_test1 = s21_sprintf(Lmass1, "%f", (double)USHRT_MAX);
//     int_test2 = sprintf(Lmass2, "%f", (double)USHRT_MAX);
//     ck_assert_str_eq(Lmass1, Lmass2);
//     ck_assert_int_eq(int_test1, int_test2); count++;
//     int_test1 = 0;
//     int_test2 = 0;
//     free_array(Lmass1, Lmass2);

//     int_test1 = s21_sprintf(Lmass1, "%f", (double)LONG_MAX);
//     int_test2 = sprintf(Lmass2, "%f", (double)LONG_MAX);
//     ck_assert_str_eq(Lmass1, Lmass2);
//     ck_assert_int_eq(int_test1, int_test2); count++;
//     int_test1 = 0;
//     int_test2 = 0;
//     free_array(Lmass1, Lmass2);

//     printf("TestSpecifier 'f' = %d tests\n", count);

// }
// END_TEST

START_TEST(sprintfTest_d_string) {
    int count = 0;

    s21_sprintf(Lmass1, "%-10d", 21);
    sprintf(Lmass2, "%-10d", 21);
    ck_assert_str_eq(Lmass1, Lmass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "abc %d abc", -166);
    sprintf(mass2, "abc %d abc", -166);
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "%d%%\n", 4);
    sprintf(mass2, "%d%%\n", 4);
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "%.10d%%\n", 4);
    sprintf(mass2, "%.10d%%\n", 4);
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "%-+10d%%\n", 4);
    sprintf(mass2, "%-+10d%%\n", 4);
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "%-10d%%\n", -4);
    sprintf(mass2, "%-10d%%\n", -4);
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "%+10d%%\n", 4);
    sprintf(mass2, "%+10d%%\n", 4);
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "%.2d", 4);
    sprintf(mass2, "%.2d", 4);
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "%+10d%%\n", -4);
    sprintf(mass2, "%+10d%%\n", -4);
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    int_test1 = s21_sprintf(Lmass1, "%-+.5d %-+10.5d", 21, 10);
    int_test2 = sprintf(Lmass2, "%-+.5d %-+10.5d", 21, 10);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);


    int_test1 = s21_sprintf(Lmass1, "% -10d %-10d %-10d", 21, 55, -55);
    int_test2 = sprintf(Lmass2, "% -10d %-10d %-10d", 21, 55, -55);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%.10d %.10d", n, n2);
    int_test2 = sprintf(Lmass2, "%.10d %.10d", n, n2);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%2.2d %.d % d %.0d", -21, char_test1, 21, -42);
    int_test2 = sprintf(Lmass2, "%2.2d %.d % d %.0d", -21, char_test1, 21, -42);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%hd %hd", sh, sh1);
    int_test2 = sprintf(Lmass2, "%hd %hd", sh, sh1);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%ld %ld", lg, lg1);
    int_test2 = sprintf(Lmass2, "%ld %ld", lg, lg1);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%10ld", lg1);
    int_test2 = sprintf(Lmass2, "%10ld", lg1);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    s21_sprintf(mass1, "%+10.5d%%\n", -4);
    sprintf(mass2, "%+10.5d%%\n", -4);
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    long int var_long = 100;
    s21_sprintf(mass1, "%ld%%\n", var_long);
    sprintf(mass2, "%ld%%\n", var_long);
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    short var_short = 123;
    s21_sprintf(mass1, "%hd%%\n", var_short);
    sprintf(mass2, "%hd%%\n", var_short);
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "abc %ld", 58787878958);
    sprintf(mass2, "abc %ld", 58787878958);
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "abc %d", 87878958);
    sprintf(mass2, "abc %d", 87878958);
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "abc %lld", (long long int)88888858787878958);
    sprintf(mass2, "abc %lld", (long long int)88888858787878958);
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "abc %hd", 87878958);
    sprintf(mass2, "abc %hd", 87878958);
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    int_test1 = s21_sprintf(Lmass1, "%d%d", INT_MIN, INT_MAX);
    int_test2 = sprintf(Lmass2, "%d%d", INT_MIN, INT_MAX);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%d%d", SHRT_MAX, SHRT_MIN);
    int_test2 = sprintf(Lmass2, "%d%d", SHRT_MAX, SHRT_MIN);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%d %d", SHRT_MIN, USHRT_MAX);
    int_test2 = sprintf(Lmass2, "%d %d", SHRT_MIN, USHRT_MAX);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%ld", LONG_MAX);
    int_test2 = sprintf(Lmass2, "%ld", LONG_MAX);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%ld", LONG_MIN + 1);  // 
    int_test2 = sprintf(Lmass2, "%ld", LONG_MIN + 1);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%-25.10d", 253);
    int_test2 = sprintf(Lmass2, "%-25.10d", 253);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%-30.2d", 335);
    int_test2 = sprintf(Lmass2, "%-30.2d", 335);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%10.12d", 1234);
    int_test2 = sprintf(Lmass2, "%10.12d", 1234);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%11d", 34);
    int_test2 = sprintf(Lmass2, "%11d", 34);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%+10.2ld", 456789l);
    int_test2 = sprintf(Lmass2, "%+10.2ld", 456789l);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    printf("TestSpecifier 'd' = %d tests\n", count);

}
END_TEST

START_TEST(sprintfTest_u_string) {
    int count = 0;

    s21_sprintf(mass1, "abc %u abc", 166);
    sprintf(mass2, "abc %u abc", 166);
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "%2.5u%%\n", 4); 
    sprintf(mass2, "%2.5u%%\n", 4);
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "%2.5u%%\n", -4);
    sprintf(mass2, "%2.5u%%\n", -4);
    ck_assert_str_eq(mass1, mass2);
    free_array(mass1, mass2);

    s21_sprintf(mass1, "%10.5u%%\n", 4);
    sprintf(mass2, "%10.5u%%\n", 4);
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "%-10u%%\n", 421);
    sprintf(mass2, "%-10u%%\n", 421);
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    short unsigned key_h = 421;
    s21_sprintf(mass1, "%-10hu%%\n", key_h);
    sprintf(mass2, "%-10hu%%\n", key_h);
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    long unsigned key_l = 421;
    s21_sprintf(mass1, "%-10lu%%\n", key_l);
    sprintf(mass2, "%-10lu%%\n", key_l);
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "abc %hu", 17);
    sprintf(mass2, "abc %hu", 17);
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "abc %lu", 17123121);
    sprintf(mass2, "abc %lu", (long unsigned int)17123121);
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    int_test1 = s21_sprintf(Lmass1, "%u", 4321u);
    int_test2 = sprintf(Lmass2, "%u", 4321u);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%15u", 34567u);
    int_test2 = sprintf(Lmass2, "%15u", 34567u);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%-20u", 2342u);
    int_test2 = sprintf(Lmass2, "%-20u", 2342u);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);


    int_test1 = s21_sprintf(Lmass1, "%-15.10u", 234542u);
    int_test2 = sprintf(Lmass2, "%-15.10u", 234542u);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);


    int_test1 = s21_sprintf(Lmass1, "%-20.12lu", lg);
    int_test2 = sprintf(Lmass2, "%-20.12lu", lg);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%19hu", sh);
    int_test2 = sprintf(Lmass2, "%19hu", sh);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(Lmass1, "%u", UINT_MAX);
    int_test2 = sprintf(Lmass2, "%u", UINT_MAX);
    ck_assert_str_eq(Lmass1, Lmass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(Lmass1, Lmass2);

    int_test1 = s21_sprintf(mass1, "%lu", ULONG_MAX + 2);
    int_test2 = sprintf(mass2, "%lu", ULONG_MAX + 2);
    ck_assert_str_eq(mass1, mass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(mass1, mass2);

    int_test1 = s21_sprintf(mass1, "%u %lu", UINT_MAX, ULONG_MAX);
    int_test2 = sprintf(mass2, "%u %lu", UINT_MAX, ULONG_MAX);
    ck_assert_str_eq(mass1, mass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0;
    free_array(mass1, mass2);

    printf("TestSpecifier 'u' = %d tests\n", count);
}
END_TEST



START_TEST(sprintfTest_i_string) {
    int count = 0;

    s21_sprintf(mass1, "abc %-20i abc", 5); 
    sprintf(mass2, "abc %-20i abc", 5);
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "abc %.20i abc", 1234567890); 
    sprintf(mass2, "abc %.20i abc", 1234567890);
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "abc % 5i abc", 5);
    sprintf(mass2, "abc % 5i abc", 5);
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    s21_sprintf(mass1, "abc %3i abc", 5);
    sprintf(mass2, "abc %3i abc", 5);
    ck_assert_str_eq(mass1, mass2); count++;
    free_array(mass1, mass2);

    int_test1 = s21_sprintf(mass1, "abc %+i abc", 5);
    int_test2 = sprintf(mass2, "abc %+i abc", 5);
    ck_assert_str_eq(mass1, mass2);
    ck_assert_int_eq(int_test1, int_test2); count++;
    int_test1 = 0;
    int_test2 = 0; 
    free_array(mass1, mass2);

    int_test1 = s21_sprintf(mass1, "abc %-.i abc", n);
    int_test2 = sprintf(mass2, "abc %-.i abc", n);
    ck_assert_str_eq(mass1, mass2);
    ck_assert_int_eq(int_test1, int_test2);count++;
    int_test1 = 0;
    int_test2 = 0; 
    free_array(mass1, mass2);

    
    int_test1 = s21_sprintf(mass1, "abc %-+i abc", n2);
    int_test2 = sprintf(mass2, "abc %-+i abc", n2);
    ck_assert_str_eq(mass1, mass2);
    ck_assert_int_eq(int_test1, int_test2);count++;
    int_test1 = 0;  
    int_test2 = 0; 
    free_array(mass1, mass2);


    printf("TestSpecifier 'i' = %d tests\n", count);
}
END_TEST


//=======================================================================

int main(void) {
    Suite *suite = suite_create("Core");
    TCase * take_case = tcase_create("Core");
    SRunner *source_runner = srunner_create(suite);
    int errors = 1;

//===================== sprintf===========================
    suite_add_tcase(suite, take_case);
    tcase_add_test(take_case, sprintfTest_c_string);
    tcase_add_test(take_case, sprintfTest_d_string);
    tcase_add_test(take_case, sprintfTest_i_string);
    // tcase_add_test(take_case, sprintfTest_f_string);
    tcase_add_test(take_case, sprintfTest_s_string);
    tcase_add_test(take_case, sprintfTest_u_string);

//=======================================================
    
    srunner_run_all(source_runner, CK_ENV);
    errors = srunner_ntests_failed(source_runner);
    srunner_free(source_runner);

    return errors == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
