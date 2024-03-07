// 1차 성공

#include <bits/stdc++.h>

using namespace std;

int main(){
    int testcase;
    int again;
    string data;
    cin >> testcase;
    for (int t=0; t<testcase; t++){
        cin >> again >> data;
        for(auto d : data){
            string k = string(again, d);
            cout << k;
        }
        cout << endl;
    }
}