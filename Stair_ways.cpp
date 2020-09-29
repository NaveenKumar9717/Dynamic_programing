#include<bits/stdc++.h>
using namespace std ;
#define ll long long
long staircaseDP(int n)
{
	ll DP[n + 1] ;
	DP[0] = 1 ;
	DP[1] = 1 ;
	DP[2] = 2 ;
	for (int i = 3 ; i <= n; i++) {
		ll x = DP[i - 1] ;
		ll y = DP[i - 2] ;
		ll z = DP[i - 3] ;
		DP[i] = x + y + z ;
	}

	return DP[n] ;
}

int staircase(int n) {
	if (n <= 1) {
		return  1  ;
	}
	int x = 0, y = 0, z = 0 ;

	if (n - 1 >= 0) {
		x = stair(n - 1) ;
	}
	if (n - 2 >= 0) {
		y = stair(n - 2) ;
	}
	if (n - 3 >= 0) {
		z =  stair(n - 3) ;
	}

	return x + y + z ;

}
int main() {
	int n ;
	cin >> n ;
	cout << staircase(n) << endl << staircaseDP(n);
}