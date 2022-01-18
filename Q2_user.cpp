#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define COUPLE  0
#define PARENT  1
#define CHILD   2

int mstrcmp(const char a[], const char b[])
{
	int i;
	for (i = 0; a[i] != '\0'; ++i) if (a[i] != b[i]) return a[i] - b[i];
	return a[i] - b[i];
}

void mstrcpy(char dest[], const char src[])
{
	int i = 0;
	while (src[i] != '\0') { dest[i] = src[i]; i++; }
	dest[i] = src[i];
}

int mstrlen(const char a[])
{
	int i;
	for (i = 0; a[i] != '\0'; ++i);
	return i;
}

typedef struct node {
	char name[20];
	int sex;
	int couple=0;
	int parent[2] = { 0 };
}NODE;

vector<NODE> list;
int adj[201][201];

void check_list() {
	for (int i = 1; i < list.size(); i++) {
		cout << list[i].name << ' ' << list[i].sex << " [COUPLE] " << list[list[i].couple].name << " [PARENT] "
			<< list[list[i].parent[0]].name << ' ' << list[list[i].parent[1]].name ;
		for (int j = 1; j < list.size(); j++) {
			if (adj[i][j] == CHILD)
				cout << " [CHILD] " << list[j].name << ' ';

			if(adj[i][j] == PARENT)
				cout << " [PARENT ADJ] " << list[j].name << ' ';
		}
		cout << '\n';
	}
	cout << "\n\n\n";
}

int find_list_index(char name[]) {
	for (int i = 1; i <= 200; i++) {
		if (i == list.size() ) break;
		if (!mstrcmp(list[i].name, name)){
			return i;
		}
	}
}

void init(char initialMemberName[], int initialMemberSex)
{
	list.clear();
	for (int i = 0; i < 201; i++) {
		memset(adj[i], -1, sizeof(int) * 200);
	}
	NODE tmp;
	mstrcpy(tmp.name, "NULL");
	tmp.sex = 0;
	list.push_back(tmp);
	mstrcpy(tmp.name, initialMemberName);
	tmp.sex = initialMemberSex;
	list.push_back(tmp);

	//find_list(initialMemberName);
	//cout << "FOUND " << find_list(list.back().name).name << ' ' << find_list(list.back().name).sex << '\n';
	

}

bool addMember(char newMemberName[], int newMemberSex, int relationship, char existingMemberName[])
{
	bool ret=true;
	int idx =-1, newidx = -1,pidx1,pidx2;
	NODE tmp;
	switch (relationship) {
	case 0:
		 idx = find_list_index(existingMemberName);
		if (list[idx].couple || list[idx].sex == newMemberSex) {
			ret = false;
			break;
		}
		// couple update
		
		mstrcpy(tmp.name, newMemberName);
		tmp.sex = newMemberSex;
		list.push_back(tmp);
		newidx = list.size() - 1;
		list[idx].couple = newidx;
		list[newidx].couple = idx;
		
		//child update
		for (int i = 1; i < list.size(); i++) {
			if (adj[idx][i] == CHILD) {
				adj[newidx][i] = CHILD;
				adj[i][newidx] = PARENT;
				list[i].parent[newMemberSex] = newidx;
			}
			if (adj[newidx][i] == CHILD) {
				adj[idx][i] = CHILD;
				adj[i][idx] = PARENT;
				list[i].parent[list[idx].sex] = idx;
			}
		}
		break;

	case 1:
		idx = find_list_index(existingMemberName);
		if (list[idx].parent[newMemberSex]) { // A 예외
			ret = false;
			break;
		}
		mstrcpy(tmp.name, newMemberName);
		tmp.sex = newMemberSex;
		list.push_back(tmp);
		newidx = list.size() - 1;
		//새 구성원이 기존 구성원의 부모가 되고, 이 기존 구성원은 새 구성원의 자식이 된다.
		list[idx].parent[newMemberSex] = newidx;
		adj[newidx][idx] = CHILD;
		adj[idx][newidx] = PARENT;
		
		if (list[idx].parent[ newMemberSex ^ 1 ]) { //기존 구성원에게 새 구성원과 성별이 다른 부모가 있다면
			//그 기존의 부모는 새 구성원과 서로 배우자가 된다.
			pidx1 = list[idx].parent[newMemberSex ^ 1];
			pidx2 = list[idx].parent[newMemberSex ];
			
			list[pidx1].couple = pidx2;
			list[pidx2].couple = pidx1;
			//기존의 부모의 자식이 모두 새 구성원의 자식으로도 추가되며, 그 자식에게도 새 구성원이 부모로 추가된다.
			for (int i = 0; i < newidx; i++) {
				if (adj[pidx1][i] == CHILD) {
					adj[pidx2][i] = CHILD;
					adj[i][pidx2] = PARENT;
					list[i].parent[ list[pidx2].sex ] = pidx2;
				}
				if (adj[pidx2][i] == CHILD) {
					adj[pidx1][i] = CHILD;
					adj[i][pidx1] = PARENT;
					list[i].parent[list[pidx1].sex] = pidx1;
				}
			}

		}

		break;

	case 2:
		idx = find_list_index(existingMemberName);
		mstrcpy(tmp.name, newMemberName);
		tmp.sex = newMemberSex;
		list.push_back(tmp);
		newidx = list.size() - 1;
		//새 구성원이 기존 구성원의 자식이 되고, 이 기존 구성원은 새 구성원의 부모가 된다.
		list[newidx].parent[list[idx].sex] = idx;
		adj[newidx][idx] = PARENT;
		adj[idx][newidx] = CHILD;
		if (list[idx].couple) {
			idx = list[idx].couple;
			list[newidx].parent[list[idx].sex] = idx;
			adj[newidx][idx] = PARENT;
			adj[idx][newidx] = CHILD;
		}
		break;
	}
	//check_list();
	return ret;
}

int getDistance(char nameA[], char nameB[])
{
	int ret = 0, idx, cflag, qidx,dist=0;
	queue<int> q, newq;
	int visited[201] = { 0 };
	idx = find_list_index(nameA);
	cflag = list[idx].couple;
	q.push(idx);
	visited[idx] = 1;
	visited[cflag] = 1;
	if (!mstrcmp(list[list[idx].couple].name, nameB)) {
		//cout << "ans : 0\n" ;
		return 0;
	}
	while (++dist) {
		newq = queue<int>();
		while (!q.empty()) {
			qidx = q.front(); q.pop();
			//cout << "CHECKING " << list[qidx].name << "\n";
			for (int i = 1; i < list.size(); i++) {
				if (!visited[i]) {
					if (adj[qidx][i] == CHILD || adj[qidx][i] == PARENT) {
						if (!mstrcmp(list[i].name, nameB)) {
							return dist;
						}
						newq.push(i);
						visited[i] = 1;
						if (list[i].couple && !visited[list[i].couple]) {
							if (!mstrcmp(list[list[i].couple].name, nameB)) {
								return dist;
							}
							newq.push(list[i].couple);
							visited[list[i].couple] = 1;
						}
					}
					cflag = list[qidx].couple;
					if (cflag) {
						if (adj[cflag][i] == PARENT) {
							if (!mstrcmp(list[i].name, nameB)) {
								return dist;
							}
							newq.push(i);
							visited[i] = 1;
						}
					}
				}
			}
		}
		if (newq.empty()) break;
		q = newq;
	}
	ret = 0;

	return ret;
}

int countMember(char name[], int dist)
{
	int ret = 0, idx, cflag, qidx;
	queue<int> q, newq;
	int visited[201] = { 0 };
	idx = find_list_index(name);
	cflag = list[idx].couple;
	int orgdist = dist;
	if (dist == 0) {
		if (cflag)
			ret = 1;
	}
	else {
		q.push(idx);
		visited[idx] = 1;
		visited[cflag] = 1;		
		while (dist--) {
			newq = queue<int>();
			while (!q.empty()) {
				qidx = q.front(); q.pop();
				for (int i = 1; i < list.size(); i++) {
					if (!visited[i]) {

						if (adj[qidx][i] == CHILD || adj[qidx][i] == PARENT) {
							newq.push(i);
							visited[i] = 1;
							if (list[i].couple && !visited[list[i].couple]) {
								newq.push(list[i].couple);
								visited[list[i].couple] = 1;
							}
						}
						cflag = list[qidx].couple;
						if (cflag) {
							if (adj[cflag][i] == PARENT) {
								newq.push(i);
								visited[i] = 1;
							}
						}
					}
				}
			}
			q = newq;
		}
		ret = newq.size();
	}
	return ret;
}
