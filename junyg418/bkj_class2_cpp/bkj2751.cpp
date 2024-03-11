// 1차 time over

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    // array<int, 1000001> data = {0, };
    int * data = new int[1000001];

    for (int i=0; i<n; i++){
        cin >> data[i];
    }
    sort(data, data+n);
    
    for (int i=0; i<n; i++){
        cout << data[i] << '\n';
    }
}