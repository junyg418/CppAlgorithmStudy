// 1차 성공

#include <bits/stdc++.h>

using namespace std;

int main(){
    string temp;
    string result;
    while (true){
        getline(cin, temp, '\n');
        result = "yes";

        if (temp == "0") break;

        int len = temp.length();
        for (int i=0; i<len/2; i++){
            if (temp.at(i) != temp.at(len-1-i)){
                result = "no";
                break;
            }
        }
        cout << result << endl;
    }
}