#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int arr[10][10];
int MAX = 0;
int n, m, k;
bool visited[10];
int level[10];
int main(void) {
	int test_case;
	cin >> test_case;
	for (int test = 1; test <= test_case; test++) {
		cin >> n >> m >> k;
		vector<int> timeList;
		for (int i = 0; i < n; i++)
		{
			int tempTime;
			cin >> tempTime;
			timeList.push_back(tempTime);
		}
		sort(timeList.begin(), timeList.end());
		int index=0,total = 0, time = 0;
		time += m;
		total += k;
		while (index < n) {
			if (total == 0) {
				time += m; total += k;
			}
			if (timeList[index] < time) {
				printf("#%d Impossible\n", test);
				break;
			}
			else {
				total--;
				index++;
			}
		}
		if(index==n)
			printf("#%d Possible\n", test);
	}
	return 0;
}


