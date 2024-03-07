// 1차 성공 하하

#include <bits/stdc++.h>

using namespace std;

int self_num(const int &n){
    int sum_v = 0;
    int ja = 10;
    int temp;
    int before_data = 0;
    while (true){
        temp = n % ja;
        sum_v += (temp - before_data)/(ja/10);
        if (n == temp) {
            break;
        }
        before_data = temp;
        ja *= 10;
    }
    return sum_v + n;
}

int main(){
    int arr[10001] ={0,};
    int result;

    for (int i=1; i<10000; i++){
        result = self_num(i);
        while(true){
            if (result > 10000) break;
            arr[result] = 1;
            result = self_num(result);
        }
    }

    for (int i=1; i<10000; i++){
        if (arr[i] == 0) cout << i << endl;
    }
}