#include<iostream>

using namespace std;
int N;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input.txt", "r", stdin);
	
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int x, y, z;
		char a , b;
		int ans = 1;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> x >> a;
			if (N % 2 == 0 &&  i == N / 2) {
				cin >> y;
				if ('0' <= a && a <= '9') ans = 0;
			}
			else if (i <= N / 2) {
				cin >> y >> z;
				if ('0' <= a && a <= '9') ans = 0;
			}
			else {
				if ('0' <= a && a <= '9') continue;
				else ans = 0;
			}
		}
		cout << "#" << test_case << " " << ans << "\n";
	}
	
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
