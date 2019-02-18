#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	long long i, a, b, t, n;
	cin >> a >> b >> n;
	a = a % b;
	while(n-10 > 0){
		a *= 1e10;
		a %= b;
		n -= 10;
 	}
	for (i = 0; i < n + 2; i++) {
		a *= 10;
		if (i >= n -1) cout << a / b;
		a %= b;
	} 
	
	return 0;
}
