#include <iostream>
#include<vector>
using namespace std;
#define MAXN 110
#define INF 0x3f3f3f3f;
int graph[MAXN][MAXN];//建立图 
int cun[MAXN][MAXN];//存储第几个教室有谁谁谁
int cnt[MAXN];//记录每个教室的人数
int res = INF;//假定需要无穷多的教室
int n, m;//定义人数以及认识的数模
void solve(int id, int num) {//回溯搜索，id表示当前安排的是第id的同学
//num表示um表示当前安排这个id同学的时时候已经用了多少个教室
	 if (num >= res)//如果当前的教室方案已经超过以前的方案了，那么就放弃返回
	 return;
	 if (id > n) {//如果说id的同学的id>n说明全部同学都安排完了 
	 	res = num;//如果执行到这一步说明res一定是>num的，所有更新一下
		return;//返回 
	 } 
	 for (int i = 0; i < num; i++) {//扫描每一个已经存在的教室
	 	int len = cnt[i];//取一下当前i教室的人数 
		int c = 0;//这个变量表示当前id的同学个这个教室的同学不认识的人数
		for (int j = 0; j < len; j++) {//扫描这个教室的每一个同学 
			if (graph[id][cun[i][j]] == 0) {//如果没有关系 
				c++;//加1 
			}
		} 
		if (c == len) {//如果全部不认识 
			cun[i][cnt[i]++] = id;//如果id同学就进入这个教室，同时这个教室的人数加1
			solve(id+1, num);//那么安排下一个教室
			cnt[i]--;//递归返回后把这个同学从这个教室分走，分到下几个教室看看
		} 
	 }
	 cun[num][cnt[num]++] = id; //如果全部教室都存在id认识的同学,那么 就给这个同学新开个教室 
	 solve(id+1, num+1);//递归下一个同学并且当前教室数目+1
	 cnt[num]--; 
} 

int main(int argc, char *argv[]) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;//如果两个人认识的话就可以标记成1,c++在数组创建 的时候已经快速初始化
	}
	solve(1, 0);//进入回溯更新最小的教室数目 
	cout << res;//输入所有可能中的最小的答案 
}
