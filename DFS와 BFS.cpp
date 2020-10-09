#include <iostream>
#include <queue>

using namespace std;

//https://www.acmicpc.net/problem/1260

int node, edge, start;
int map[1001][1001] = { 0, };
int visited[1001] = { 0 };
queue<int> q;

void DFS(int start) {
	cout << start << " ";
	visited[start] = 1;

	for (int i = 1; i <=  node; i++) {
		if (map[start][i] == 1 && visited[i] != 1) {
			DFS(i);
		}
	}
}

void BFS(int start) {
	q.push(start);
	visited[start] = 1;

	while (!q.empty()) {
		int n = q.front();
		q.pop();
		cout << n << " ";

		for (int i = 1; i <= node; i++) {
			if (map[n][i] == 1 && visited[i] != 1) {
				q.push(i);
				visited[i] = 1;
			}
		}
	}
}

int main() {
	int a, b;
	cin >> node >> edge >> start;
	
	for (int i = 0; i < edge; i++) {
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	DFS(start);
	cout << endl;

	memset(visited, 0, sizeof(visited));

	BFS(start);
	return 0;
}
