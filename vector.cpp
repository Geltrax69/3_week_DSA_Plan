#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <map>
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

    //erase a range of elements
    v.erase(v.begin() + 3, v.begin() + 5);
    cout << "After erase elements from index 3 to 4: ";
    loop(v);

}

void swap_elements()
{
    //swapping two vectors
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {4,5,6};

    cout << "Before swap:" << endl;
    cout << "v1: ";
    loop(v1);
    cout << "v2: ";
    loop(v2);

    v1.swap(v2);

    cout << "After swap:" << endl;
    cout << "v1: ";
    loop(v1);
    cout << "v2: ";
    loop(v2);

    //swap elemets within a vector
    vector<int> v3 = {1,2,3,4,5};
    cout << "Before swapping elements within v3: ";
    loop(v3);
    swap(v3[1], v3[3]);
    cout << "After swapping elements at index 1 and 3 within v3: ";
    loop(v3);

    //Sorting a vector
    vector<int> v4 = {5,2,8,1,4};
    cout << "Before sorting v4: ";
    loop(v4);
    sort(v4.begin(), v4.end());
    cout << "After sorting v4: ";
    loop(v4);

    reverse(v4.begin(), v4.end());
    cout << "After reversing v4: ";
    loop(v4);
}

void find_element()
{
    vector<int> v = {1,2,3,4,5};
    int t = 6;
    auto it = find(v.begin(), v.end(), t);
    if(it != v.end()){
        cout << "Element " << t << " found at index " << distance(v.begin(), it) << endl;
    }else{
        cout << "Element " << t << " not found" << endl;    
    }

    

}

void unordert_learning()
{
    unordered_set<int> s;
    for(int i =0; i<10; i++){
        s.insert(i);
    }
    for(auto it : s){
        cout << it << " ";
    }
    cout << endl;

    // check if an element exists
    int t = 11;
    if(s.find(t) !=s.end()) cout << t << " Found" << endl;
    else cout << t << " Not Found" << endl;

    // erase an element
    s.erase(5);
    cout << "After erasing 5: ";
    for(auto it : s){
        cout << it << " ";
    }
    cout << endl;

    cout << "Size of unordered_set: " << s.size() << endl;

}

void set_learning()
{
    set <int> s;
    for(int i =1; i<=10; i++){
        s.insert(i);
    }
    for(auto it : s){
        cout << it << " "; 
    }
    cout << endl;
    cout<<s.count(52)<<endl; // check if element exists

    if(s.find(5) != s.end()) cout << "5 Found" << endl;
    else cout << "5 Not Found" << endl;
    cout << "Size of set: " << s.size() << endl;
    s.erase(5);
    cout << "After erasing 5: ";
    for(auto it : s){
        cout << it << " ";
    }
    cout << endl;
}

void map_elements()
{
    //map<object_type,object_type> variable_name;
    map<int,int> mp;
    //insertion
    for(int i=1;i<=5;i++){
        mp.insert({i,i*10});
    }
    for(auto it:mp){
        cout<<it.first<<" "<<it.second<<endl;
    }

    //find the element
    int t=3;
    auto it=mp.find(t);
    if(it!=mp.end()){
        cout<<"Element "<<t<<" found with value "<<it->second<<endl;
    }else{
        cout<<"Element "<<t<<" not found"<<endl;
    }

    cout<<endl;
}

int main(){

    //basic();
    //swap_elements();
    //find_element();
    //unordert_learning();
    //set_learning();
    //map_elements();
    return 0;

}