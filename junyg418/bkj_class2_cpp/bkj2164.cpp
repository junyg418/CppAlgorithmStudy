// 1차 성공

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    deque<int>data= deque<int>() ;
    for (int i=1; i<=n; i++){
        data.push_back(i);
    }

    while (data.size() != 1){
        data.pop_front();
        data.push_back(data.at(0));
        data.pop_front();
    }
    cout << data[0];
}