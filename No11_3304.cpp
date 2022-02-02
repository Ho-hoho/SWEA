#include <iostream>
#include <algorithm>

using namespace std;
int dp[1001][1001];
int solve(string s,string t) {
	for (int i = 1; i <= s.size(); i++) {
		for (int j = 1; j <= t.size(); j++) {
			if (s[i-1] == t[j-1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	return dp[s.size()][t.size()];
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string s1, s2;
		cin >> s1 >> s2;
		memset(dp, 0, sizeof(dp));
		cout << "#" << test_case << " " << solve(s1,s2) << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
