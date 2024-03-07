// 1차 성공

#include <bits/stdc++.h>

using namespace std;

int main(){
    int len;
    cin >> len;

    int data[len];       
    for (int i=0; i<len; i++){
        cin >> data[i];
    }
    
    int min = *min_element(data, data + len);
    int max = *max_element(data, data + len);
    cout << min << ' ' << max;
}