// 1차 성공

#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    if (a > b){
        cout << '>';
    }
    else if(a < b){
        cout << '<';
    }
    else{
        cout << "==";
    }
}