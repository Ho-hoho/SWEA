#include<iostream>
#include <sstream>
using namespace std;
int N;

typedef struct node {
	int num;
	char op[2] ;
	int c1;
	int c2;
}Node;

Node arr[1010];

float solve(int node) {
	if (node[arr].num != 0)
		return arr[node].num;
	
	float a,b;
	a = solve(arr[node].c1);
	b = solve(arr[node].c2);
	switch (arr[node].op[0]) {
		case '+' :
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input.txt", "r", stdin);
	
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int x, y, z;
		char a , b;
		int ans = 1;
		cin >> N;
		for (int i = 0; i <= N; i++) {
			arr[i].num = 0;
			arr[i].op[0] = '\0';
			arr[i].c1 = 0;
			arr[i].c2 = 0;
		}
		for (int i = 1; i <= N; i++) {
			int a; string b;
			cin >> a >> b;
			//cout << a << " " << b << " ";
			if (!b.compare("+") || !b.compare("-") || !b.compare("*") || !b.compare("/")) {
				//cout << "b : " << b << "    ";
				cin >> arr[i].c1 >> arr[i].c2 ;
				//cout << arr[i].c1 << " " << arr[i].c2 << " ";
				strcpy(arr[i].op , b.c_str());
			}
			else {
				stringstream ssInt(b);
				ssInt >> arr[i].num;
			}
			//cout << "\n";
		}
		cout << "#" << test_case << " " << solve(1) << "\n";
	}
	
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
