#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void)
{
	int T, a, sum1 = 0, sum2 = 0, sisa1, sisa2;
	vector<int> N;
	
	cin >> T;
	
	for(int i = 0; i < T; i++)
	{
		cin >> a;
		N.push_back(a);
	}
	
	for(int i = 0; i < T; i++)
	{
		while(N[i] > 0)
		{
			sisa1 = N[i] % 10;
			sum1 = sum1 + sisa1;
			N[i] = N[i] / 10;
		}
		
		if(sum1 >= 10)
		{
			for(int j = 1; j <= sizeof(sum1); j++)
			{
				sisa2 = sum1 % 10;
				sum2 = sum2 + sisa2;
				sum1 = sum1 / 10;	
			}
			cout << sum2 << '\n';
			sum2 = 0;
		}
		
		else
		{
			cout << sum1 << '\n';
			sum1 = 0;	
		}
	}
	
	return 0;
}