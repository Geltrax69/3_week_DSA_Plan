#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v ;
    cout <<"Enter the Size: ";
    int n ;
    cin >> n ;
    for (int i=0;i<n;i++){
        int x;

        cin>>x;
        v.push_back(x);
    }
    swap(v[0],v[n-1]);
    
    for (int i=0;i<n;i++){
        cout << v[i] << " ";
    }
    return 0;
}