// 1차

#include <bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

struct DataSet{
    int x;
    int y;
    int level;
};
int x_limit, y_limit;
int box_map[1001][1001] = {-1, };
bool is_passed[1001][1001] = {false, };

// URDL
int move_x[] = {-1, 0, 1, 0};
int move_y[] = {0, 1, 0, -1};


int bfs(const vector<DataSet>&start_pos){
    queue<DataSet>q;
    int max_level = 0;

    for (auto d : start_pos){
        q.push(d);
        is_passed[d.x][d.y] = true;
    }

    DataSet current_tomato;
    while (!q.empty()){
        current_tomato = q.front();
        q.pop();
        max_level = current_tomato.level;
        
        for (int move_direction=0; move_direction<4; move_direction++){
            int current_x = current_tomato.x + move_x[move_direction];
            int current_y = current_tomato.y + move_y[move_direction];
            
            if((0 <= current_x && current_x < x_limit) && (0 <= current_y && current_y < y_limit)
            && box_map[current_x][current_y]==0){
                if(is_passed[current_x][current_y]) continue;

                q.push({current_x, current_y, current_tomato.level+1});
                box_map[current_x][current_y] = 1;
                is_passed[current_x][current_y] = true;
            }
        }
    }
    return max_level;
}

int main(){
    cin >> y_limit >> x_limit;

    string buffer;
    vector<DataSet> start_pos;

    int current_data;
    for (int x_idx=0; x_idx<x_limit; x_idx++){
        for (int y_idx=0; y_idx<y_limit; y_idx++){
            cin >> current_data;
            if (current_data == 1){
                start_pos.push_back({x_idx, y_idx, 0});
            }
            box_map[x_idx][y_idx] = current_data;
        }
    }

    int result = bfs(start_pos);
    bool flag = false;
    for (int i = 0; i < x_limit; i++) {
        for (int j = 0; j < y_limit; j++) {
            if (box_map[i][j] == 0 && !is_passed[i][j]) {
                flag = true;
                break;
            }
        }
        if (flag) break;
    }

    if(flag){
        cout << "-1";
    }
    else{
        cout << result;
    }
}