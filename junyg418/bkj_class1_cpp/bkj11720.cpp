// 1차 ++ getline(cin, 입력버퍼, 입력종료문자);
// cin.ignore(streamsize<길이>, 없앨 문자);
// 정답
#include <bits/stdc++.h>

using namespace std;

int main(){
    int len, sum=0;
    string k;
    cin >> len;
    cin.ignore();

    getline(cin, k, '\n');

    for(auto data : k){
        sum += data-48;  
    }
    cout << sum;
}