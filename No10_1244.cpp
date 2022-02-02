#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;
int ans ;
bool vis[1000001][11];
void solve(string s, int k) {
	int i;
	stringstream ss(s);
	ss >> i;
	if (vis[i][k]) return;
	vis[i][k] = true;
	if (k == 0) {
		if (i > ans) ans = i;
		return;
	}
	int max_idx =0;
	int l = s.length();
	for (int i = 0; i < l; i++) {
		for (int j = i+1; j < l; j++) {
			//if (s[j] >= s[i]) {
				swap(s[i], s[j]);
				solve(s, k - 1);
				swap(s[i], s[j]);
			//}
		}
	}
	return ;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string s;
		int k;
		ans = 0;
		memset(vis, false, sizeof(vis));
		cin >> s;
		cin >> k;
		solve(s, k);
		cout <<	"#" <<test_case << " " << ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
