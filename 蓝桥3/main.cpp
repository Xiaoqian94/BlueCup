#include <iostream>
#include<vector>
using namespace std;
#define MAXN 110
#define INF 0x3f3f3f3f;
int graph[MAXN][MAXN];//����ͼ 
int cun[MAXN][MAXN];//�洢�ڼ���������˭˭˭
int cnt[MAXN];//��¼ÿ�����ҵ�����
int res = INF;//�ٶ���Ҫ�����Ľ���
int n, m;//���������Լ���ʶ����ģ
void solve(int id, int num) {//����������id��ʾ��ǰ���ŵ��ǵ�id��ͬѧ
//num��ʾum��ʾ��ǰ�������idͬѧ��ʱʱ���Ѿ����˶��ٸ�����
	 if (num >= res)//�����ǰ�Ľ��ҷ����Ѿ�������ǰ�ķ����ˣ���ô�ͷ�������
	 return;
	 if (id > n) {//���˵id��ͬѧ��id>n˵��ȫ��ͬѧ���������� 
	 	res = num;//���ִ�е���һ��˵��resһ����>num�ģ����и���һ��
		return;//���� 
	 } 
	 for (int i = 0; i < num; i++) {//ɨ��ÿһ���Ѿ����ڵĽ���
	 	int len = cnt[i];//ȡһ�µ�ǰi���ҵ����� 
		int c = 0;//���������ʾ��ǰid��ͬѧ��������ҵ�ͬѧ����ʶ������
		for (int j = 0; j < len; j++) {//ɨ��������ҵ�ÿһ��ͬѧ 
			if (graph[id][cun[i][j]] == 0) {//���û�й�ϵ 
				c++;//��1 
			}
		} 
		if (c == len) {//���ȫ������ʶ 
			cun[i][cnt[i]++] = id;//���idͬѧ�ͽ���������ң�ͬʱ������ҵ�������1
			solve(id+1, num);//��ô������һ������
			cnt[i]--;//�ݹ鷵�غ�����ͬѧ��������ҷ��ߣ��ֵ��¼������ҿ���
		} 
	 }
	 cun[num][cnt[num]++] = id; //���ȫ�����Ҷ�����id��ʶ��ͬѧ,��ô �͸����ͬѧ�¿������� 
	 solve(id+1, num+1);//�ݹ���һ��ͬѧ���ҵ�ǰ������Ŀ+1
	 cnt[num]--; 
} 

int main(int argc, char *argv[]) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;//�����������ʶ�Ļ��Ϳ��Ա�ǳ�1,c++�����鴴�� ��ʱ���Ѿ����ٳ�ʼ��
	}
	solve(1, 0);//������ݸ�����С�Ľ�����Ŀ 
	cout << res;//�������п����е���С�Ĵ� 
}
