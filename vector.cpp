#include <iostream>
#include <vector>
using namespace std;

void loop(vector<int>& v)
{
    for(auto it : v){
        cout << it << " ";
    }
    cout << endl;
}

void basic()
{
    vector<int> v = {1,2,3,4,5};
    loop(v);
    // push an element to the end
    v.push_back(6);
    cout << "After push_back(6): ";
    loop(v);

    // remove the last element
    v.pop_back();
    cout << "After pop_back(): ";
    loop(v);

    // insert an element at the beginning
    v.insert(v.begin(), 0);
    cout << "After insert(0) at beginning: ";
    loop(v);

    // erase the second element
    v.erase(v.begin());
    cout << "After erase second element: ";
    loop(v);

    // size of the vector
    cout << "Size of vector: " << v.size() << endl;
    
}

int main(){

    basic();

    return 0;
}