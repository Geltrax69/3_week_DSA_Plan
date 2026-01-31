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

int reverseNumber(int n){
    int rev = 0;
    while(n!=0){
        rev = rev*10 + n%10; //Time Complexity: O(log10N + 1), Space Complexity: O(1)
        n/=10;
    }
    return rev;
}
int reverseNumberOptimal(int n){
    if(n==0) return 0; // Base Case
    return (n%10 * pow(10, countDigitsOptimal(n)-1)) + reverseNumberOptimal(n/10); //Time Complexity: O(log10N + 1), Space Complexity: O(log10N + 1) due to recursive stack
}
int recursiveReverse(int n, int rev = 0){
    if(n==0) return rev; // Base Case
    return recursiveReverse(n/10, rev*10 + n%10); //Time Complexity: O(log10N + 1), Space Complexity: O(log10N + 1) due to recursive stack
}

int palindrome(int n){
    reverseNumber(n) == n ? cout << "Palindrome" : cout << "Not Palindrome"; //Time Complexity: O(log10N + 1), Space Complexity: O(1)
    return reverseNumber(n) == n;
}

int gcdnormal(int a, int b){
    while(b!=0){
        int temp = b;
        b = a%b;
        a = temp;               //Time Complexity: O(log(min(a,b))), Space Complexity: O(1)
    }
    return a;
}
int gcdoptimal(int a, int b){
    if(b==0) return a;         //Time Complexity: O(log(min(a,b))), Space Complexity: O(log(min(a,b))) due to recursive stack
    return gcdoptimal(b, a%b);
}

string nameRecursion(string name,int c,int n){
    if(c==n) return ""; // Base Case
    cout<<name<<" "; 
    return nameRecursion(name,c+1,n); //Time Complexity: O(n), Space Complexity: O(n) due to recursive stack
}




string reverse_String(string s, int l)
{
	if(l==-1) return "";
	cout<<s[l]<<"";
	//pos++;
	return reverse_String(s,l-1);
}

string reverse_String(string s, int start, int end)
{
    if(start>=end) return s; // Base Case
    swap(s[start],s[end]);
    return reverse_String(s,start+1,end-1); //Time Complexity: O(n/2), Space Complexity: O(n/2) due to recursive stack
}

int printfibseries(int n, int a=0, int b=1){
    if(n==0) return 0; // Base Case
    cout<<a<<" ";
    return printfibseries(n-1,b,a+b); //Time Complexity: O(n), Space Complexity: O(n) due to recursive stack
}
int main() {
    // int number;
    // cout << "Enter a number: ";
    // cin >> number;
    // int digitCount = recountDigits(number);
    // cout << "Number of digits in " << number << " is: " << digitCount << endl;
    // cout << "Reversed number is: " << reverseNumber(number) << endl;
    // cout << "Reversed number (Optimal) is: " << reverseNumberOptimal(number) << endl;
    // cout << "Reversed number (Recursive) is: " << recursiveReverse(number) << endl;

    // if (palindrome(number)) {
    //     cout << number << " is a palindrome." << endl;
    // } else {
    //     cout << number << " is not a palindrome." << endl;
    // }
    // int a, b;
    // cout << "Enter two numbers to find GCD: ";
    // cin >> a >> b;
    // cout << "GCD of " << a << " and " << b << " is: " << gcdnormal(a, b) << endl;
    // cout << "GCD of " << a << " and " << b << " (Optimal) is: " << gcdoptimal(a, b) << endl;
    // cout <<"how many times you want to print your name?"<<endl;
    // int n;
    // cin >> n;
    // string name;
    // cout << "Enter your name: ";
    // cin >> name;
    // // cout << "Your name is: ";
    // // nameRecursion(name,0,n);

    // cout <<"string Length is: "<< name.length() << endl;

    // cout << endl;
    // cout << "Reversed string is: ";
    // reverse_String(name,name.length()-1);
    // cout << endl;
    // cout << "Reversed string (in place) is: ";
    // cout << reverse_String(name,0,name.length()-1);
    // cout << endl;

    int n;


    return 0;
}
