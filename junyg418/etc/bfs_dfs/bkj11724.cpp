// 1차

#include <bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


void bfs(int x, int is_passed[], vector<int> adj_list[]){
    queue<int> q;
    q.push(x);
    is_passed[x] = 1;
    
    while(!q.empty()){
        int temp = q.front();
        q.pop();

        for (auto k : adj_list[temp]){
            if (is_passed[k]) continue;
            q.push(k);
            is_passed[k] = 1;
        }
    }

}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj_list[n];
    int is_passed[n] = {0, };

    int first, sec;
    for (int _=0; _<m; _++){
        cin >> first >> sec;
        adj_list[first-1].push_back(sec-1);
        adj_list[sec-1].push_back(first-1);
    }

    int result = 0;
    int idx = 0;
    for (auto &value : is_passed){
        if (value == 0){
            bfs(idx, is_passed, adj_list);
            result += 1;
        }
        idx += 1;
    }

    cout << result;
}