#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
	int arr[7] = { 0 };
	for (int i = 0; i < 7; i++) {
		cin >> arr[i];
	}
	sort(begin(arr), end(arr));
	int a = arr[0], b = arr[1], c = arr[6] - a - b;
	cout << a << ' ' << b << ' ' << c << '\n';
}


