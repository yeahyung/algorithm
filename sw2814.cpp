#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int arr[10][10];
int MAX = 0;
int n, m;
bool visited[10];
int main(void) {
	void dfs(int, int);
	void initialize();
	int test_case;
	cin >> test_case;
	for (int test = 1; test <= test_case; test++) {
		cin >> n >> m;
		MAX = 0;
        initialize();
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			arr[x - 1][y - 1] = 1;
			arr[y - 1][x - 1] = 1;
		}
		for (int i = 0; i < n; i++) {

			visited[i] = true;
			dfs(i, 1);
			visited[i] = false;
		}
		cout << "#" << test <<" "<< MAX << "\n";
	}
	return 0;
}
void initialize() {
	for (int i = 0; i < 10; i++) {
        for(int j=0;j<10;j++)
            arr[i][j] = 0;
	}
}
void dfs(int index, int depth) {
	if (depth > MAX)
		MAX = depth;
	for (int i = 0; i < n; i++) {
		if (index != i && arr[index][i] != 0 && visited[i] == false) {

				visited[i] = true;
				dfs(i, depth + 1);
				visited[i] = false;
			
		}
	}
}

