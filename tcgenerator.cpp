#include"bits/stdc++.h"
using namespace std;

int main(void)
{
	srand(time(0));
	const int size = 500;
	vector<int> arr(size);

	for(int i=0; i<size; i++)
	{
		int tmp;
		
		do
			tmp =rand()%size;
		while(arr[tmp]);
		arr[tmp] = i+1;
	}

	for(auto i : arr)
		printf("%d ", i);
}