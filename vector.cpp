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
    v.erase(v.begin()+1);
    cout << "After erase second element: ";
    loop(v);

    // size of the vector
    cout << "Size of vector: " << v.size() << endl;

    //Print the front and the back element
    cout << "Front element: " << v.front() << endl;
    cout << "Back element: " << v.back() << endl;

    //Add multiple elements sing emplace_back
    v.emplace_back(7);
    v.emplace_back(8);
    cout << "After emplace_back(7) and emplace_back(8): ";
    loop(v);
    
    //Add multiple elements using emplace
    v.emplace(v.begin() + 2, 9);
    cout << "After emplace(9) at index 2: ";
    loop(v);

    //erase th

}

int main(){

    basic();

    return 0;
}