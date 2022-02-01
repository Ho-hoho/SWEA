#include<iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

Node node[3010];
int node_cnt;
Node* head;
int N, M, L;

Node* getNode(int x) {
	node[node_cnt].data = x;
	node[node_cnt].next = NULL;
	return &node[node_cnt++];
}

void init() {
	node_cnt = 0;
	head = getNode(-1);
}

void func_I(int x, int y) {
	Node* cur = head;
	for (int i = 0; i < x; i++)
		cur = cur->next;
	Node* tmp = getNode(y);

	tmp->next = cur->next;
	cur->next = tmp;
}
void func_D(int x) {
	Node* cur = head;
	for (int i = 0; i < x; i++)
		cur = cur->next;
	cur->next = cur->next->next;
}
void func_C(int x, int y) {
	Node* cur = head;
	for (int i = 0; i <= x; i++)
		cur = cur->next;
	cur->data = y;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> N >> M >> L;
		Node* cur = head;
		for (int i = 0; i < N; i++) {
			int tmp;
			cin >> tmp;
			cur->next = getNode(tmp);
			cur = cur->next;
		}
		for (int i = 0; i < M; i++) {
			char c; int t1, t2;
			cin >> c;
			switch (c) {
			case 'I':
				cin >> t1 >> t2;
				func_I(t1, t2);
				N++;
				break;
			case 'D' :
				cin >> t1;
				func_D(t1);
				N--;
				break;
			case 'C' :
				cin >> t1 >> t2;
				func_C(t1, t2);
				break;
			}
		}
		int idx ;
		cur = head;
		if ( N - 1 < L ) 
			cout << "#" << test_case << " " << -1 << "\n";
		else {
			for (idx = 0; idx <= L; idx++) {
				cur = cur->next;
			}
			cout << "#" << test_case << " " << cur->data << "\n";
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
