// Count Digits in a Number
#include <iostream>
using namespace std;
int countDigits(int n){
    int ctr = 0;
    if (n <10) return 1; // Edge case for 0
    while(n!=0){
        n/=10;              //Time Complexity: O(log10N + 1)
        ctr++;
    }
    return ctr;
}

int countDi
int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    int digitCount = countDigits(number);
    cout << "Number of digits in " << number << " is: " << digitCount << endl;
    return 0;
}