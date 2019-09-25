#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int MAX = 1;
char arr[100][100];
int main(void) {
	void paliS(int, int, int);
	void paliG(int, int, int);
	void check(int, int);
	int n;
	for (int test = 1; test <= 10; test++) {
		cin >> n;
		MAX = 1;
		for(int i=0;i<100;i++){
			for (int j = 0; j < 100; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				check(i, j);
		cout << "#" << test << " " << MAX << "\n";
	}
	return 0;
}

void paliS(int x, int y, int length) {
	bool pos = false;
	for (int i = x; i < x + length / 2; i++) {
		if (arr[i][y] != arr[2 * x + length - i - 1][y]) {
			pos = true;
			return;
		}
	}
	if (pos == false){
		if(length>MAX)
            MAX = length;
    }
}

void paliG(int x, int y, int length) {
	bool pos = false;
	for (int i = y; i < y + length / 2; i++) {
		if (arr[x][i] != arr[x][2 * y + length - i - 1]) {
			pos = true;
			return;
		}
	}
if (pos == false){
		if(length>MAX)
            MAX = length;
    }
}

void check(int x, int y) {
	for (int length = 2; length <= 100 - y; length++) {
		paliG(x, y, length);
	}
	for (int length = 2; length <= 100 - x; length++) {
		paliS(x, y, length);
	}
}

