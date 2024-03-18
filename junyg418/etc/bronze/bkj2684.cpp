// 1차

#include <bits/stdc++.h>

using namespace std;

void ssolve(string input_data, int *arr){
    string temp;
    string result_set[8] = {
        "TTT",
        "TTH",
        "THT",
        "THH",
        "HTT",
        "HTH",
        "HHT",
        "HHH"
    };

    for (int i=0; i<38; i++){
        temp = input_data.substr(i, 3);

        for (int idx=0; idx<8; idx++){
            if (result_set[idx] == temp){
                arr[idx]++;
                break;
            }
        }
    }
    return ;
}

int main(){
    int n;
    cin >> n;

    int result[8] = {0, };
    string test_case;
    cin.ignore();
    for (int i=0; i<n; i++){
        fill(result, &result[8], 0);
        cin >> test_case;
        ssolve(test_case, result);
        for (auto d : result){
            cout << d << " ";
        }
        cout << '\n';
    }
}