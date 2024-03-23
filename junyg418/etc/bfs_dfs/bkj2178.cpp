#include <bits/stdc++.h>

using namespace std;

#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)

int x, y;
int maze_map[101][101] = {0, };
int is_passed[101][101] = {0, };
// URDL
int move_x[] = {-1, 0, 1, 0};
int move_y[] = {0, 1, 0, -1};

struct DataSet{
	int x;
	int y;
	int level;
};


int bfs(int f_x, int f_y)
{
	queue<DataSet> q;
	is_passed[0][0] = 1;
	q.push({f_x, f_y, 1});

	while(!q.empty()){
		DataSet current_DataSet = q.front();
		q.pop();
		for (int move_direction=0; move_direction<4; move_direction++){
			int current_x = current_DataSet.x + move_x[move_direction];
			int current_y = current_DataSet.y + move_y[move_direction];

			// 해당 방향에 길이 있는지 확인
			if((0 <= current_x && current_x < x) && (0 <= current_y && current_y < y)
			&& maze_map[current_x][current_y]){
				if(is_passed[current_x][current_y]) continue;
				if(current_x == x-1 && current_y == y-1){
					return current_DataSet.level + 1;
				}
				q.push({current_x, current_y, current_DataSet.level + 1});
				// cout << "push" << "(" << current_x << ", " << current_y << ", " << current_DataSet.level+1 << ")" << endl; // DEBUG
				is_passed[current_x][current_y] = 1;
			}
		}
	}
	return -1;
}

int main()
{
	string input_buffer;
	cin >> x >> y;

	// map 초기화
	for(int x_idx=0; x_idx<x; x_idx++){
		cin >> input_buffer;
		for (int y_idx=0; y_idx<y; y_idx++){
			maze_map[x_idx][y_idx] = input_buffer[y_idx] - '0';
			is_passed[x_idx][y_idx] = 0;
		}
	}

	cout << bfs(0, 0);
}