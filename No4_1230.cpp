#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node node[6000];
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

void func_I(int x, int y,vector<int> s) {
	Node* cur = head;
	Node* prev = cur;
	for (int i = 0; i < x; i++) {
		prev = cur;
		cur = cur->next;
	}
	Node* next_tmp = cur->next;
	for (int i = 0; i < y; i++) {
		Node* tmp = getNode(s[i]);
		cur->next = tmp;
		cur = cur->next;
	}
	cur->next = next_tmp;
}
void func_D(int x,int y) {
	Node* cur = head;
	for (int i = 0; i < x; i++)
		cur = cur->next;
	Node* next_node = cur;
	for (int i = 0; i < y; i++)
		next_node = next_node->next;
	cur->next = next_node->next;
}
void func_A(int y, vector<int> s) {
	Node* cur = head;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	for (int i = 0; i < y; i++) {
		Node* tmp = getNode(s[i]);
		cur->next = tmp;
		cur = cur->next;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	vector<int> vec;
	freopen("input.txt", "r", stdin);

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		init();
		cin >> N;
		Node* cur = head;
		for (int i = 0; i < N; i++) {
			int tmp;
			cin >> tmp;
			cur->next = getNode(tmp);
			cur = cur->next;
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			char c; int t1, t2, t3;
			cin >> c;
			switch (c) {
			case 'I':
				vec.clear();
				cin >> t1 >> t2;
				for (int i = 0; i < t2; i++) {
					cin >> t3;
					vec.push_back(t3);
				}
				func_I(t1, t2, vec);
				N++;
				break;
			case 'D':
				cin >> t1 >> t2;
				func_D(t1, t2);
				N--;
				break;
			case 'A':
				vec.clear();
				cin >> t2 ;
				for (int i = 0; i < t2; i++) {
					cin >> t3;
					vec.push_back(t3);
				}
				func_A(t2, vec);
				break;
			}
		}
		int idx;
		cur = head;
		cout << "#" << test_case << " ";
		for (idx = 0; idx < 10; idx++) {
			cur = cur->next;
			cout << cur->data << " ";
		}
		cout << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
