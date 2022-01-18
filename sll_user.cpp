#define MAX_NODE 10000

using namespace std;

struct Node {
	int data;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}
/*
void printList() {

	Node* cur = head;
	int idx = 0, ret = 0;
	cout << "LIST : ";
	while (1) {
		if (cur->next == nullptr) break;
		cout << cur->next->data << ' ';
		cur = cur->next;
	}
	cout << '\n';
}
*/
void init()
{
	nodeCnt = 0;
	head = getNode(-1);
}

void addNode2Head(int data)
{
	Node* tmp = getNode(data);
	Node* cur = head;
	if (cur->next == nullptr) cur->next = tmp;
	else {
		tmp->next = cur->next;
		cur->next = tmp;
	}
	//cout << "addNode2Head : " << data << '\n';
	//printList();
}

void addNode2Tail(int data)
{
	Node* cur = head->next;
	Node* tmp = getNode(data);
	if (cur == nullptr)
		cur = tmp;
	else {
		while (1) {
			if (cur->next == nullptr) {
				cur->next = tmp;
				break;
			}
			cur = cur->next;
		}
	}
	//cout << "addNode2Tail : " << data << '\n';
	//printList();
}

void addNode2Num(int data, int num)
{
	Node* cur = head;
	while (--num) {
		if (cur->next == nullptr) break;
		cur = cur->next;
	}
	Node* tmp = getNode(data);
	tmp->next = cur->next;
	cur->next = tmp;
	//cout << "addNode2NUM : " << data << '\n';
	//printList();
}

void removeNode(int data)
{
	Node* cur = head;
	while (1) {
		if (cur->next == nullptr)
			break;
		if (cur->next->data == data) {
			cur->next = cur->next->next;
			break;
		}
		cur = cur->next;
	}
	//cout << "removeNode: " << data << '\n';
	//printList();
}

int getList(int output[MAX_NODE])
{
	Node* cur = head;
	int idx = 0, ret = 0;
	while (1) {
		if (cur->next == nullptr) break;
		output[idx++] = cur->next->data;
		ret++;
		cur = cur->next;
	}
	return ret;
}
