// 1차 성공

#include <bits/stdc++.h>

using namespace std;

bool isdec(const int &data){
    if (data == 1) return false;
    if (data == 2) return true;
    for (int i=2; i<data; i++){
        if (data % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    int result = 0;

    int temp;
    for (int i=0; i<n; i++){
        cin >> temp;
        if (isdec(temp)) result++;
    }
    cout << result;
}