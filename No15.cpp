#include<iostream>
#include <cstring>
using namespace std;
int n, p;
int arr[1000001] ;
int last;

int solve() {
	int res = p+1,num=0;
	int s = 1, e = 1;
	while (e <= last) {
		if (arr[e]) {
			num++;
			e++;
			res = max(res, num);
		}
		else {
			if (p == 0) {
				if (arr[s] == 0)
					p++;
				s++;
				num--;
				res = max(res, num);
			}
			else {
				p--;
				num++;
				e++;
				res = max(res, num);
			}
		}
	}
	return res;
}

void init() {
	memset(arr, 0, sizeof(int) * 1000001);
	last = 0;
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> n >> p;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			arr[tmp] = 1;
			last = tmp;
		}
		cout << "#"  << test_case <<" "<< solve() << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
