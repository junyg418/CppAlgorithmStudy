// 1차 성공

#include <bits/stdc++.h>

using namespace std;

int main(){
    int temp;
    int max = -1;
    int idx = -1;
    for (int i=1; i<=9; i++){
        cin >> temp;
        if (temp > max){
            max = temp;
            idx = i;
        }
    }
    cout << max << endl << idx;
}