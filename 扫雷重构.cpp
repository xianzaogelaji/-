#include<iostream>
#include<vector>
using namespace std;
void zhujiemian() {//主界面
    cout << "********************" << endl;
	cout << "*****1. 初始化 *****" << endl;
	cout << "*****2.开始游戏*****" << endl;
	cout << "*****3.查看存档*****" << endl;
	cout << "*****4.删除存档*****" << endl;
	cout << "*****0.退出游戏*****" << endl;
	cout << "********************" << endl;
}
class map {
private:
public:
	int arr[50][50];
};
int main() {
	zhujiemian();
}