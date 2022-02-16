#include<iostream>
#include<unordered_map>

using namespace std;
int N, M;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		unordered_map <string, int> um;
		string s;
		int res = 0;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> s;
			um[s]++;
		}
		for (int i = 0; i < M; ++i) {
			cin >> s;
			if (um.count(s))
				res++;
		}
		cout << "#" << test_case << " " << res << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
