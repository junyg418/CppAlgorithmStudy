#include <bits/stdc++.h>

using namespace std;

//int x, y;
int M, N, K;
int cnt = 0;
int input_map[201][201] = { 0, };
int IsCheck[201][201] = { 0, };
int dist[201][201] = { 0, };
int index_X[4] = { -1, 1, 0, 0 };
int index_Y[4] = { 0, 0, -1, 1 };

#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)

int bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	IsCheck[x][y] = 1;
	dist[x][y] = 1;

	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;
		//cnt++;
		//cout << cnt << ": " << a << " " << b << "\n";
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = a + index_X[i];
			int ny = b + index_Y[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;

			if (input_map[nx][ny] == 0)
				continue;

			if (input_map[nx][ny] == 1 && IsCheck[nx][ny] == 0)
			{
				dist[nx][ny] = dist[a][b] + 1;
				q.push(make_pair(nx, ny));
				IsCheck[nx][ny] = 1;
			}
		}
	}

	return dist[N - 1][M - 1];
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			input_map[i][j] = str[j] - '0';
		}
	}

	cout << bfs(0, 0);

	return 0;
}