#include<cstdio>
#include <queue>
#include <cstring>
using namespace std;
int dp[101][101];
int mat[101][101];
bool vis[101][101];
int dx[4] = { 1,0,-1,0};
int dy[4] = { 0,-1,0,1};

int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(dp, 0, sizeof(dp));
		memset(mat, 0, sizeof(mat));
		memset(vis, false, sizeof(vis));
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%1d", &dp[i][j]);
				mat[i][j] = dp[i][j];
			}
		}
		queue<pair<int,int>> q;
		q.push({ 1,0 }); q.push({0,1});
		vis[0][0] = true;vis[1][0] = true; vis[0][1] = true;
		while (!q.empty()) {
			int cury = q.front().first;
			int curx = q.front().second;
			//if (curx == N - 1 && cury == N - 1) break;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int newy = cury + dy[i];
				int newx = curx + dx[i];
				if (newy < 0 || newy >= N || newx < 0 || newx >= N)
					continue;
				if (!vis[newy][newx] || dp[newy][newx] >dp[cury][curx] + mat[newy][newx]) {
					vis[newy][newx] = true;
					dp[newy][newx] = dp[cury][curx] + mat[newy][newx];		
					q.push({ newy,newx });
				}
			}
		}
		printf("#%d: %d\n",test_case,dp[N-1][N-1]);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
