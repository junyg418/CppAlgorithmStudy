// 1차

#include <bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main(){
    int computer_cnt;
    int n;
    cin >> computer_cnt;
    cin >> n;

    vector<int> adj_list[computer_cnt+1];
    int is_passed[computer_cnt+1] = {0, };

    int first, sec;
    for (int _=0; _<n; _++){
        cin >> first >> sec;
        adj_list[first].push_back(sec);
        adj_list[sec].push_back(first);
    }

    queue<int> q;
    int virus_computer = 0;
    
    q.push(1);
    is_passed[1] = 1;
    while(!q.empty()){
        int currnet_computer = q.front();
        q.pop();

        for (auto com : adj_list[currnet_computer]){
            if(!is_passed[com]) { // 방문하지 않았다면
                q.push(com);
                is_passed[com] = 1;
                virus_computer += 1;
            }
        }
    }
    cout << virus_computer;
}