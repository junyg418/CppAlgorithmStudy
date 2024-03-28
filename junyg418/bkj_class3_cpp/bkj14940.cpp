// 1차

#include <bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int prob_map[1001][1001] = {0, };
bool is_passed[1001][1001] = {false, };
int length_map[1001][1001] = {0, };

struct DataSet
{
    int x;
    int y;
    int level;
};

int x_lim, y_lim;
// URDL
int move_x[] = {-1, 0, 1, 0};
int move_y[] = {0, 1, 0, -1};

void bfs(const DataSet& start){
    queue<DataSet>q;
    DataSet currnet_data;

    q.push(start);
    length_map[start.x][start.y] = start.level;
    is_passed[start.x][start.y] = true;

    while(!q.empty()){
        currnet_data = q.front();
        q.pop();

        for (int direction=0; direction<4; direction++){
            int current_x = currnet_data.x + move_x[direction];
            int current_y = currnet_data.y + move_y[direction];

            if ((0 <= current_x && current_x < x_lim) && (0 <= current_y && current_y < y_lim)){
                if(is_passed[current_x][current_y]) continue;
                if(!prob_map[current_x][current_y]){
                    length_map[current_x][current_y] = 0;
                    is_passed[current_x][current_y] = true;
                    continue;
                };
                q.push({current_x, current_y, currnet_data.level+1});
                is_passed[current_x][current_y] = true;
                length_map[current_x][current_y] = currnet_data.level + 1;
            }
        }
    }
}

int main(){
    cin >> x_lim >> y_lim;

    DataSet start_pos;    
    int temp;
    for (int x_idx=0; x_idx<x_lim; x_idx++){
        for (int y_idx=0; y_idx<y_lim; y_idx++){
            cin >> temp;
            prob_map[x_idx][y_idx] = temp;
            if (temp == 2) start_pos = {x_idx, y_idx, 0};
        }
    }


    bfs(start_pos);

    // 못간곳 체크
    for (int x_idx=0; x_idx<x_lim; x_idx++){
        for (int y_idx=0; y_idx<y_lim; y_idx++){
            if(!is_passed[x_idx][y_idx] && prob_map[x_idx][y_idx] != 0){
                length_map[x_idx][y_idx] = -1;
            }
            cout << length_map[x_idx][y_idx] << " ";
        }
        cout << "\n";
    }

}