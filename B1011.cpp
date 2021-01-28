#include<iostream>
using namespace std;

int main()
{
	int T;
	int n;
	cin >> T;
	long long* A = new long long[T];
	long long* B = new long long[T];
	long long* C = new long long[T];
	for (n = 0; n < T; ++n)
	{
		cin >> A[n] >> B[n] >> C[n];
	}
	for (n = 0; n < T; ++n)
	{
		if(A[n]+B[n] >C[n])
			cout << "Case #" << n+1 << ": true";
		else
			cout << "Case #" << n+1 << ": false";

		if (n < T-1)
			cout << endl;
	}

	return 0;
}