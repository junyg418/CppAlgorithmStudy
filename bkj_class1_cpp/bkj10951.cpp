// 1차 실패 getline() -> 아무것도 입력 안한다면 \n 이 아닌 \0 을 반환했기에
// 2차 성공

#include <bits/stdc++.h>

using namespace std;

int main(){
    string buffer;
    int a,b;
    while(true){
        cin.clear();
        getline(cin, buffer);

        if (buffer == "\0"){
            break;
        }
        a = buffer.at(0) - 48;
        b = buffer.at(2) - 48;
        cout << a+b << endl;
    }

    
}