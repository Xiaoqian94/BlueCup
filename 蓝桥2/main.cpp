//https://www.cnblogs.com/-new/p/6662301.html
#include <iostream>
using namespace std;
#define MAXN 1000010
int pre[MAXN];//并查集的集合数组
//数组pre[]记录了每个点的前导点是什么
int Find(int x){
	int p, temp;
	p =x;
	while(x != pre[x])//递归去寻找目标的父亲节点，直到寻找到根节点为止
		x = pre[x];
	while(p != x){//路径压缩
		temp = pre[p];//在改变他的前导点时，存储他的值
		pre[p] = x;
		p = temp; //改变他的前导点为根节点
	}
	return x;
} 

int main(int argc, char *argv[]) {
	int cnt;
	int m,n;
	cin >> m >>n;//输入长和宽
	cnt = m * n;//假设有几个点就有几个集合
	for (int i = 0; i <= n * m; i++){
		pre[i] = i;//初始每个集合的根节点都是自己 
	} 
	int k;
	cin >> k; 
	for(int i = 0; i < k; i++){
		int a, b;
		cin >> a >> b;
		int aa = Find(a);//如果两个点所属的集合不是一个就把它们添加到一个集合中去
		int bb = Find(b);
		if(aa != bb){
			pre[aa] = pre[bb];////我们将ab相连 将a的前导结点设置为b
			cnt--;//每当合成一个集合的时候集合总数就会消失一个 
		}
	}
	cout << cnt;//所以输出最后还有几个集合 
	return 0;
}
