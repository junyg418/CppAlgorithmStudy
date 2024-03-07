// 1차 성공

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int k=0; k<i; k++)
            cout << '*';
        cout << endl;
    }
}