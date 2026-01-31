// Count Digits in a Number
#include <iostream>
using namespace std;
int countDigits(int n){
    int ctr = 0;
    if (n <10) return 1; // Edge case for 0
    while(n!=0){
        n/=10;              //Time Complexity: O(log10N + 1), Space Complexity: O(1)
        ctr++;
    }
    return ctr;
}

int countDigitsOptimal(int n){
    if (n == 0) return 1; // Edge case for 0
    return (int)log10(n)+1;           //Time Complexity: O(1) , Space Complexity: O(1)
}
int recountDigits(int n){
    if(n==0) return 0; // Base Case
    return 1 + recountDigits(n/10);   //Time Complexity: O(log10N + 1), Space Complexity: O(log10N + 1) due to recursive stack
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    int digitCount = countDigitsOptimal(number);
    cout << "Number of digits in " << number << " is: " << digitCount << endl;
    return 0;
}