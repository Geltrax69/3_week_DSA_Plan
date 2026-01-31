// Count Digits in a Number
#include <iostream>
using namespace std;
int countDigits(int n){
    int ctr = 0;
    if (n == 0) return 1; // Edge case for 0
    while(n!=0){
        n/=10;
        ctr++;
    }
}