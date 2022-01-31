#include <iostream>
#include <cstring>
#define DEV 1000000007

using namespace std;
int dp[10001][16];
string str;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(dp, 0, sizeof(dp));
		cin >> str;
		for (int date = 0; date < str.size(); date++) {
			int admin = 1 << (str[date] - 'A');
			if (date == 0) {
				for (int i = 1; i < 16; i++) {
					if ((i & admin) != 0 && (i & 1) != 0) {
						dp[date][i] = 1;
					}
				}
			}
			else {
				for (int i = 1; i < 16; i++) {
					if (dp[date - 1][i] != 0) {
						for (int j = 1; j <= 15; j++) {
							if ((admin & j) != 0 && (i & j) != 0) {
								dp[date][j] += dp[date - 1][i];
								dp[date][j] %= DEV;

							}
						}
					}
				}
			}
		}
		long long ans=0;
		for (int i = 1; i <= 15; i++) {
			ans += dp[str.size() - 1][i];
			ans %= DEV;
		}
		cout << "#" << test_case << " " << ans << "\n";

	}
	return 0;
}
