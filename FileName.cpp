#include <iostream>
#include<vector>
#include<cmath>
using namespace std;
template<typename T>
void getMax(T &a, T &b) {
	if (a > b) {
		int tamp = a;
		a = b;
		b = tamp;
	}
}
int main() {
	/*string a, b;
	cin >> a >> b;
	cout <<  a[a.length()-1] + b[b.length()-1] - '0' * 2 << endl;*/
	/**string a, b;
	cin >> a >> b;
	int m = a[a.length() - 1] + b[b.length() - 1] - '0' * 2;
	cout << m;*/
//思考1，偶数分为一组先行
	/*int c, a, b;
	vector<int> arr;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin>> a >> b;
		arr.push_back(a);
		arr.push_back(b);
	}
	for (int j = 1; (j*2-1) < c*2; j++) {
		a = arr[(j - 1) * 2];
		b = arr[(j * 2 - 1)];
		if ((arr[(j - 1) * 2] - arr[(j * 2 - 1)] > 4) && (arr[(j - 1) * 2] - arr[j * 2 - 1] < -4)) {
			cout << "NO" << endl;
		}
		else {
			;
			if (a < b) {
				int tamp = a;
				a = b;
				b = tamp;
			}

				if (!(a % 2 || b % 2)) {
					cout << "NO" << endl;
				}
				else {
					cout << "YES"<< endl;
					for (int i = a - b; i >= 0; i--) {
						cout << b + i << " ";
					}
					cout << endl;
				}
		}
	}
	//遇到大数组时，先从小情况开始。
	//那么问题不在算法的难度，在最基础的构建*/

	/*int a1;
	cin >> a1;
	vector<int> arr;
	int a, b;
	for (int i = 0; i < a1; i++) {
		cin >> a >> b;
		arr.push_back(a);
		arr.push_back(b);
	}
	for (int m = 1; m <= a1; m++) {
		a = arr[2 * (m - 1)];
		b = arr[2 * m - 1];
		getMax(a, b);
		if (b - a > 4 && b - a < -4) {
			cout << "NO" << endl;
		}
		else {
			if (a % 2 == 0 && b % 2 == 0) {
				cout << "NO" << endl;
			}
			else {
				cout << "YES" << endl;
				for (int j = b; j >= a; j--) {
					cout << j << " ";
				}
				cout << endl;
			}
		}
	}*/

	/*vector<int> arr;
	vector<int> e;
	int m;
	cin >> m;
	int a;
	for (int i = 0; i <m ; i++) {
		cin >> a;
		arr.push_back(a);
		e.push_back(1);
	}
	int o;
	cin >> o;
	int a1, a2;
	for (int j = 0; j < o; j++) {
		cin >> a1 >> a2;
		e[a1] = -e[a1];
		if (a2 + 1 > m);
		else {
			e[a2] = -e[a2];
		}
	}
	a = 0;
	int res = 1;
	for (int j2 = 0; j2 < arr.size(); j2++) {
		if (j2 > 0) {
			res *= e[j2-1];
		}
		 a+= arr[j2]*res;
	}
	cout << a;*/
//方法一，时间过长
	/*int a;
	cin >> a;
	int m = 1;
	int o = 0;
	vector<int> arr;
	for (int i = 1; i <= a; i++) {
		if (a % i == 0) {
			if (i - m == 1) {
				o++;
			}
			m = i;
		}
	}
	cout << o;*/
//树状数组
//原理分析1.奇数项为原数组值。2，偶数项则为最末一后零个数
//问题，如何判断一后零个数2，是否生成整个数组
/*int a, b;
cin >> a >> b;
vector<int> arr(a*b,1);
string aon;
for (int i = 0; i < b; i++) {
	cin >> aon;
	for (int j = 0; j < a; j++) {
		if (aon[j] == 'S') {
			arr[i * a + j] = -1;
		}
		else if(aon[j] == '.') {
			arr[i * a + j] = 1;
		}
		else if (aon[j] == '#') {
			arr[i * a + j] = -1;
		}
		else if (aon[j == 'T']) {
			arr[i * a + j] = 2;
		}
		else if (aon[j == 'M']) {
			arr[i * a + j] = -2;
		}
	}
}*/
//差分化
int n = 0;
cin >> n;
int p, times,x,y;
vector<int> arr(n,0);
vector<int> off(n, 1);
for (int i = 0; i < n; i++) {
	cin >> p;
	arr[i] = p;
}
cin >> times;
for (int j = 0; j < times; j++) {
	cin >> x >> y;
	off[x - 1] = -off[x - 1];
	if (y < n) {
		off[y] = -off[y];
	}
}
int no = 1;
p = 0;
for (int k = 0; k < n; k++) {
	no *= off[k];
	p += (arr[k] * no);
}
cout << p;
}


