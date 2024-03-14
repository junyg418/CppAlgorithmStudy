// 1차 class 사용하는데 시간 초과 pair로 도전
// 5차 성공
/*
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    입출력간 시간이 너무 오래걸려 시간초과 걸렸었음
*/

#include <bits/stdc++.h>

using namespace std;

// class Data{
//     public:
//         int age;
//         string name;
//         int idx;
//     Data(int age, string name): age(age), name(name){}
// };


bool kkey(pair<int, string> a, pair<int, string> b){
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    // int t_age;
    // string t_name;
    pair<int, string> temp;
    // vector<Data *> arr;
    vector<pair<int, string>> arr;
    for (int i=0; i<n; i++){
        // cin >> t_age >> t_name;
        // arr.push_back(new Data(t_age, t_name));
        cin >> temp.first >> temp.second;
        arr.push_back(temp);
    }

    
    stable_sort(arr.begin(), arr.end(), kkey);

    for (int i=0 ; i<n; i++){
        // cout << arr.at(i)->age << ' ' << arr.at(i)->name << endl;
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }
}