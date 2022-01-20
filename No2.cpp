#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N, M;
	bool flag ;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		flag = true;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			if (!(M & 1)) {
				flag = false;
			}
			M = M >> 1;
		}
		cout << "#" << test_case << ' ';
		if (flag)
			cout << "ON\n";
		else
			cout << "OFF\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
