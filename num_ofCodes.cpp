#include<bits/stdc++.h>
using namespace std ;
#define ll long long
ll DP[5000] ;
ll all_codes_Dynamic(int *a, int size) {
	if (DP[size] != 0) {
		return 	DP[size] ;
	}
	if (size == 0) {
		DP[0] = 1  ;
		return DP[0] ;
	}
	if (size == 1) {
		DP[1] = 1 ;
		return DP[1] ;
	}

	ll ans = all_codes_Dynamic(a, size - 1) ;
	if (a[size - 2] * 10 + a[size - 1] <= 26) {
		ans += all_codes_Dynamic(a, size - 2) ;
	}

	DP[size] = ans ;
	return DP[size] ;

}

ll all_codes(int*a, int  size) {
	if (size == 0) {
		return 1 ;

	}
	if (size == 1) {
		return  1 ;
	}
	ll ans = all_codes(a, size - 1) ;
	if (a[size - 2] * 10 + a[size - 1] <= 26) {
		ans += all_codes(a, size - 2) ;
	}
	return ans ;

}

int main() {
	int n  ;
	cin >> n ;
	int*number = new int [n] ;
	for (int i = 0 ; i < n ; i++)
	{
		cin >> number[i] ;

	}
	for (int i = 0 ; i < 5000; i++) {
		DP[i] =  0  ;
	}
	cout << all_codes(number, n) << endl;
	cout << all_codes_Dynamic(number, n) << endl;
	return 0 ;
}