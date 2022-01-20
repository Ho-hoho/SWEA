#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int N;
vector <pair<int,int>> arr;
int visited ;
bool vis[401] = {false};
bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
	return a.second < b.second;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		arr.clear();
		memset(vis,false,sizeof(bool)*401);
		cin >> N;
		for (int i = 0; i < N; i++) {
			int t1, t2;
			cin >> t1 >> t2;
			if (t1 > t2) {
				int tmp = t1;t1 = t2;t2 = tmp;
			}
			arr.push_back( make_pair((t1+1)/2, (t2 + 1) / 2));
		}
		sort(arr.begin(), arr.end());
		int last,cnt=0,check=0;
		while (check < N) { 
			last = -1;
			for (int i = 0; i < N; i++) {
				if((last < arr[i].first) && !vis[i]){
					last = arr[i].second;
					vis[i] = true;
					check++;
				}
			}
			cnt++;
		}
		cout << "#" << test_case << " " << cnt << "\n";
		

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
