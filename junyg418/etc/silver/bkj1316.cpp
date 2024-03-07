// 1차 실패
/*
if (input_data.at(idx-1) == c) {
    alpha[c-97] = 1;
    전 데이터와 같았다면 alpha 배열에 기록을 안하는 오류가 있었음이 아님.
if (input_data.at(idx-1) == c) {
    idx++ 
    와 같이 idx를 갱신해주지 않아서 오류가 났던거였음 
*/
//... 5차 성공

#include <bits/stdc++.h>

using namespace std;

int main(){
    int result = 0;
    int test_case, fin=0;
    string input_data;

    cin >> test_case;
    cin.ignore();
    for (int n=0; n<test_case; n++){
        int alpha[26] = {0,};
        fin = 0;
        int idx = 0;
        getline(cin, input_data, '\n');
        for(auto c: input_data){
            if (alpha[c-97] == 1) {
                if (input_data.at(idx-1) == c) {
                    idx++;
                    continue;
                }
                fin = 1;
                break; 
            }
            alpha[c-97] = 1;
            idx++;
        }
        if (fin == 0) result++;
    }
    cout << result;
}