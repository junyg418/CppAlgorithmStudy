// 1차 소수점 자리수 때문에 실패
// cout.percision(..) 소수점 자리수 변경해주는 함수
// 2차 성공

#include <bits/stdc++.h>

using namespace std;

int main(){
    double a,b;
    cin >> a >> b;

    cout.precision(10);
    cout << a/b;
}