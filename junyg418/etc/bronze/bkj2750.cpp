// 1차

#include <bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main(){
    
    int n;
    cin >> n;
    vector<int> arr;
    int temp;
    for (int i=0; i<n; i++){
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    
    for(auto &k : arr){
        cout << k << '\n';
    }
}