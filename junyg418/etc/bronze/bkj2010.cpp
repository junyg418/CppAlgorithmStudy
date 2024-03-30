// 1차

#include <bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main(){
    int n = 0;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++){
        int a = 0;
        cin >> a;
        sum += a-1;
    }
    cout << sum+1 << '\n';
}