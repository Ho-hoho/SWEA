#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
int ans[8][2] = { 0 };
int money;
void solve() {
	ans[0][0] = 50000;	ans[1][0] = 10000;
	ans[2][0] = 5000;	ans[3][0] = 1000;
	ans[4][0] = 500;	ans[5][0] = 100;
	ans[6][0] = 50;		ans[7][0] = 10;

	for (int i = 0; i < 8; i++) {
		cout <<  money / ans[i][0] << ' ';
		money = money % ans[i][0];
	}
	
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("1970_input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case << "\n";
		cin >> money;
		solve();
		cout << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
