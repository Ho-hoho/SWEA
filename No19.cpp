#include<iostream>
#include <vector>
#include <algorithm>

#define MAX 987654321
using namespace std;

int N;
int arr[14][14];
vector<pair<int, int>> proc;
int dx[4] = { 1,0, -1,0 }; // {down,right,up,left};
int dy[4] = { 0,-1,0,1 };
int max_proc = 0;
int res = MAX;
int coLine(int x, int y, int dir) {
	int orgX = x, orgY = y;
	while (x != 0 && x != N + 1 && y != 0 && y != N + 1) {
		x += dx[dir]; y += dy[dir];
		if (arr[x][y] == 1 || arr[x][y] == 3)
			return 0;
	}
	x = orgX; y = orgY;
	while (x != 0 && x != N + 1 && y != 0 && y != N + 1) {
		x += dx[dir]; y += dy[dir];
		arr[x][y] = 3;
	}
	return 1;

}

void disLine(int x, int y, int dir) {
	while (x != 0 && x != N + 1 && y != 0 && y != N + 1) {
		x += dx[dir]; y += dy[dir];
		arr[x][y] = 0;
	}
}

int dfs(int cnt, int num) {
	if (cnt == proc.size()) {
		if (max_proc < num) {
			int line_num = 0;
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (arr[i][j] == 3)
						line_num++;
				}
			}
			res = line_num;
			max_proc = num;
			return line_num;
		}
		else if (max_proc == num) {
			int line_num = 0;
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (arr[i][j] == 3)
						line_num++;
					if (line_num > res) return MAX;
				}
			}
			max_proc = num;
			return line_num;
		}
		else return MAX;
	}


	int curX = proc[cnt].first, curY = proc[cnt].second;
	for (int i = 0; i < 4; i++) {

		int done = coLine(curX, curY, i);
		if (done) {
			res = min(res, dfs(cnt + 1, num + done));
			disLine(curX, curY, i);

		}
	}
	if(max_proc < N - cnt + num)
		res = min(res, dfs(cnt + 1, num));
	return res;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		proc.clear(); max_proc = 0; res = MAX;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			arr[i][0] = 2;	arr[0][i] = 2;
			arr[i][N + 1] = 2;	arr[N + 1][i] = 2;
			for (int j = 1; j <= N; j++) {
				cin >> arr[i][j];
				if (arr[i][j])
					proc.push_back(make_pair(i, j));
			}
		}
		cout << "#" << test_case << " " << dfs(0, 0) << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
