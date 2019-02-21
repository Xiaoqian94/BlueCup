#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 100010;
vector<int> arr[10];
int ok[MAX] = {0};//记录在环上的点
int n;
int tag = 0;//发现环时 变为1
int record;//记录形成环的那几个点，用来消除起点与该点之间的0；

//dfs搜环 
void dfs(int x, int y) {
	ok[x] = 1;
	for (int i = 0; i < arr[x].size(); i++) {
		if (arr[x][i] == y) continue;
		if (ok[arr[x][i]]) {
			tag = 1;
			record = arr[x][i];
			return;
		} else {
			dfs(arr[x][i], x);
		}
		if (tag ==1) return;
	}
	ok[x] = 0;
} 

//将不在环上的点消0 
void re(int x){
	ok[x] = 0;
	for (int i = 0; i < arr[x].size(); i++) {
		if (arr[x][i] == record) {
			return;
		}
		if (ok[arr[x][i]]) {
			re(arr[x][i]);
		}
	}
}

int main(int argc, char *argv[]) {
	int a, b;
	cin >> n;
	for (int i = 0; i <n; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	dfs(1, 0);
	if (record != 1) {
		re(1);
	}
	for (int i = 1; i <=n; i++) {
		if (ok[i])
			cout << i <<" ";
	}
	return 0;
}
