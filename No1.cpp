#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

int N;


int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		int res = 0;
		for (int i = 1;; i++) {
			int check = N * i;
			while (check > 0) {
				int tmp = check % 10;
				res = res | (1 << tmp);
				check /= 10;
			}

			if (res == 1023) {
				cout << "#" << test_case << ' ' << i * N<< '\n';
				break;
			}

		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
