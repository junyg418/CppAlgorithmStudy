// 1차

#include <bits/stdc++.h>

using namespace std;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    int n, prob_cnt;
    cin >> n >> prob_cnt;

    map<string, int>poketmon;
    vector<string> name;
    string temp;
    vector<string> result;
    for (int i=1; i<=n; i++){
        cin >> temp;
        name.push_back(temp);
        poketmon.insert(make_pair(temp, i));
    }

    for (int i=0; i<prob_cnt; i++){
        cin >> temp;
        if(65 <= temp[0] && temp[0] <= 90){
            result.push_back(to_string(poketmon[temp]));
        }
        else{
            result.push_back(name[stoi(temp)-1]);
        }
    }

    for(int i=0; i<prob_cnt; i++){
        cout << result[i]<< '\n';
    }
}