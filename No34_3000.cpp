#include<iostream>
#include <queue>
#include <vector>;
using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);	
	cout.tie(0);
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int ans=0,N,K,mid;
		priority_queue<int, vector<int>, greater<int>> right;
		priority_queue<int, vector<int>, less<int>> left;
		cin >> N >> mid;
		while (N--) {
			int a, b;
			cin >> a >> b;
			mid > a ? left.push(a) : right.push(a);
			mid > b ? left.push(b) : right.push(b);
			while (left.size() > right.size()) {
				right.push(mid);
				mid = left.top();
				left.pop();
			}
			while (left.size() < right.size()) {
				left.push(mid);
				mid = right.top();
				right.pop();
			}
			ans += mid ;
			ans = ans%20171109
		}

		cout <<"#"<<test_case<< " "<< ans<< "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
