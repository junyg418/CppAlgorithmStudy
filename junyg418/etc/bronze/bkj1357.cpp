// 1차

#include <bits/stdc++.h>

using namespace std;


int Rev(int x){
    string tp = to_string(x);
    reverse(tp.begin(), tp.end());
    return stoi(tp);
}

int main(){
    int x, y;
    cin >> x >> y;
    
    int tp = Rev(x) + Rev(y);
    cout << Rev(tp);
}