#include<iostream>
#include <cstring>
using namespace std;
int N;
char arr[101];

void solve(int node) {
	if (node > N) return;

	solve(node * 2);
	cout << arr[node] ;
	solve(node * 2 + 1);

}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	//cin >> T;
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> N;
		for (int i = 0; i <= 100; i++) {
			arr[i] = '\0';
		}
		for (int i = 1; i <= N; i++) {
			int t1, t2;
			cin >> t1 >> arr[i];
			//cout << t1 << arr[i];
			if ( N %2 == 0 && i == N / 2) cin >> t1;
			else if (i <= N / 2) cin >> t1 >> t2;
		}
		cout << "#" << test_case << " ";
		solve(1);
		cout << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
