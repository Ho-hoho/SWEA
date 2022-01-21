#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include <algorithm>

using namespace std;
string arr[20001];
string tmp[20001];
int N;
int cmp(string a, string b) {
	if (a.size() != b.size())
		return a.size() > b.size();
	else
		return a.compare(b) ;
}
void mergesort(int s, int e) {
	if (s >= e) return;

	int m = (s + e) / 2;
	mergesort(s, m);
	mergesort(m + 1, e);
	int i = s, j = m + 1, k = s;
	while (i <= m && j <= e) {
		if (cmp(arr[i], arr[j]) <= 0) {
			tmp[k++] = arr[i++];
		}
		else
			tmp[k++] = arr[j++];
	}
	while (i <= m)
		tmp[k++] = arr[i++];
	while (j <= e)
		tmp[k++] = arr[j++];
	for (int idx = s; idx <= e; idx++) {
		arr[idx] = tmp[idx];
	}

}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{

		cin >> N;
		arr[0] = "\0";
		for (int i = 1; i <= N; i++)
			cin >> arr[i];
		mergesort(1, N);
		cout << "#" << test_case << "\n";

		for (int i = 1; i <= N; i++) {
			if ((arr[i].compare(arr[i - 1])))
				cout << arr[i] << "\n";
		}

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
