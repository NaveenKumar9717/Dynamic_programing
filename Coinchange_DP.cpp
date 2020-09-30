#include<bits/stdc++.h>
using namespace std ;

#define ll long long
int DP[11][1002] ;

int Coin_change_DP(int*denominations, int num, int value) {
	if (DP[num][value] != -1) {
		return DP[num][value] ;
	}
	if (num == 0)
	{
		DP[num][value] = 0 ;
	}
	else if (value == 0) {
		DP[num][0] = 1  ;
	}
	else {
		int way_1 = 0 ;
		int way_2 = 0 ;
		if (value - denominations[0] >= 0)
			way_1 = Coin_change_DP(denominations, num, value - denominations[0]) ;
		if ((num - 1) >= 0 )
			way_2 = Coin_change_DP(denominations + 1, num - 1, value) ;

		DP[num][value] = way_1 + way_2 ;


	}

	return   DP[num][value] ;

}


int main() {
	int n, value ;
	cin >> n ;
	int denominations[n] ;
	for (int i = 0 ; i < n; i++) {
		cin >> denominations[i] ;
	}
	cin >> value ;
	memset(DP, -1, sizeof(DP)) ;
	cout << Coin_change_DP(denominations, n, value) << endl;
}