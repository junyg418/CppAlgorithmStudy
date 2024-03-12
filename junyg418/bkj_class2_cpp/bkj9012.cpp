// 1차 성공

#include <bits/stdc++.h>

using namespace std;

int main(){
    stack<char> data = stack<char>();
    int n;
    cin >> n;

    string temp;
    bool flag;
    for (int i=0; i<n; i++){
        flag = true;
        cin >> temp;
        for (auto d : temp){
            if (d == '(') data.push('(');
            else {
                if (data.empty()){
                    flag = false;
                    break;
                }
                data.pop();
            }
        }
        if (data.empty() && flag) cout << "YES" << endl;
        else cout << "NO" << endl;

        while (!data.empty()) data.pop();
    }
}