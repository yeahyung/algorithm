#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int arr[401][401];
int main(void) {
	int x = 1, y = 1, jump = 2;
	int index = 1,test_case;
	while (index <= 50000) {
		//printf("%d %d %d\n",x,y,index);
		arr[x][y] = index;
		index++;
		if (x == 1) {
			x = jump;
			jump++;
			y = 1;
		}
		else {
			x--;
			y++;
		}
	}
	cin >> test_case;
	for (int test = 1; test <= test_case; test++) {
		int p, q,px,py,qx,qy;
		cin >> p >> q;
		for (int i = 1; i <= 200; i++) {
			for (int j = 1; j <= 200; j++) {
				if (arr[i][j] == p) {
					px = i; py = j;
				}
				if (arr[i][j] == q) {
					qx = i; qy = j;
				}
			}
		}
		printf("#%d %d\n", test, arr[px + qx][py + qy]);
	
	}
	return 0;
}


