// 1차 성공 암기 필요할듯

#include <bits/stdc++.h>

using namespace std;

int lcm (int a, int b){
    return (a * b) / gcd(a, b);
}

int gcd(int a, int b){
    int r;
    while (b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    int a, b;
    cin >> a >> b;

    cout << gcd(a,b) << endl << lcm(a, b);
}