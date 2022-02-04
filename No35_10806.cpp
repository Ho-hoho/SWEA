#include<iostream>
#include <queue>
#include <cstring>

using namespace std;

int A[11],N,K;

struct set {
	int x;
	int d;
	int cnt;
};
bool operator<(set a, set b) {
	return (a.x+a.d) < (b.x+b.d);
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> A[i];
		cin >> K;
		int i;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push(make_pair(0, K));
		while (pq.top().second) {
			pair<int, int> cur = pq.top();
			pq.pop();
			pq.push(make_pair(cur.first + cur.second, 0));
			for (i = 0; i < N; i++) {
				pq.push(make_pair(cur.first + cur.second % A[i], cur.second / A[i]));
			}
		}
		
		cout << "#" << test_case << " " << pq.top().first << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
