#include <iostream>
using namespace std;

int main() {
	int num;
	int arr[100001];
	int part_max;
	int max;

	cin >> num;

	for (int i = 0; i < num; i++)
		cin >> arr[i];

	part_max = arr[0];
	max = part_max;

	for (int i = 1; i < num; i++) {
		if (arr[i] < part_max + arr[i]) 
			part_max = part_max + arr[i];
		else
			part_max = arr[i];
		if (max < part_max)
			max = part_max;
	}

	cout << max;

	return 0;
}
