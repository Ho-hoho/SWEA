#include <iostream>
#include <algorithm>

using namespace std;
int N, K,ans;
int dp[101][1001],vol[101],cost[101];
void solve() {
	for (int i = 1; i <= N; i++) {
		for (int w = 1; w <= K; w++) {
			if (vol[i] > w) {
				dp[i][w] = dp[i - 1][w];
			}
			else {
				dp[i][w] = max( dp[i - 1][w] , cost[i] + dp[i - 1][w - vol[i]]);
			}
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			int v, c;
			cin >>v >> c;
			vol[i] = v;
			cost[i] = c;
		}
		ans = 0;
		memset(dp, 0, sizeof(dp));
		solve();
		cout << "#" << test_case << " " << dp[N][K]<< "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
