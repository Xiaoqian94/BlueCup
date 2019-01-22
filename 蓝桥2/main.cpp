//https://www.cnblogs.com/-new/p/6662301.html
#include <iostream>
using namespace std;
#define MAXN 1000010
int pre[MAXN];//���鼯�ļ�������
//����pre[]��¼��ÿ�����ǰ������ʲô
int Find(int x){
	int p, temp;
	p =x;
	while(x != pre[x])//�ݹ�ȥѰ��Ŀ��ĸ��׽ڵ㣬ֱ��Ѱ�ҵ����ڵ�Ϊֹ
		x = pre[x];
	while(p != x){//·��ѹ��
		temp = pre[p];//�ڸı�����ǰ����ʱ���洢����ֵ
		pre[p] = x;
		p = temp; //�ı�����ǰ����Ϊ���ڵ�
	}
	return x;
} 

int main(int argc, char *argv[]) {
	int cnt;
	int m,n;
	cin >> m >>n;//���볤�Ϳ�
	cnt = m * n;//�����м�������м�������
	for (int i = 0; i <= n * m; i++){
		pre[i] = i;//��ʼÿ�����ϵĸ��ڵ㶼���Լ� 
	} 
	int k;
	cin >> k; 
	for(int i = 0; i < k; i++){
		int a, b;
		cin >> a >> b;
		int aa = Find(a);//��������������ļ��ϲ���һ���Ͱ�������ӵ�һ��������ȥ
		int bb = Find(b);
		if(aa != bb){
			pre[aa] = pre[bb];////���ǽ�ab���� ��a��ǰ���������Ϊb
			cnt--;//ÿ���ϳ�һ�����ϵ�ʱ�򼯺������ͻ���ʧһ�� 
		}
	}
	cout << cnt;//�����������м������� 
	return 0;
}
