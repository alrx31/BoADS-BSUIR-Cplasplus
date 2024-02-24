#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "enter a size";

	int n;

	cin >> n;

	int *a = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

	}	

	int sum = 0;




	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}

	for (int j = 0; j <n; j++)
	{
		cout << "\t" << a[j];
	}


	cout << endl<< sum << endl;
	delete []a;
}