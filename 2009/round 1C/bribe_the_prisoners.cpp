#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <algorithm>
#include <map> 
using namespace std; 
typedef pair<int,int> pii; 
const int INF = (int)2e9; 
int N; 
int P,Q;   
int q[111]; 
map<pii,int> dp; 
int solve(int a,int b){
	pii p = pii(a,b); 
	if (dp.find(p) != dp.end()) return dp[p]; 
	int ret = 0; 
	for (int i = 1; i <= Q; i++){
		if (q[i] >= a && q[i] <= b){
			int temp = b-a + solve(a,q[i]-1) + solve(q[i]+1,b); 
			if (ret == 0 || ret > temp){
				ret = temp;  
			}
		}
	}
	return dp[p] = ret; 
}	
int main(){
	cin >> N; 
	for (int i = 1; i <= N; i++){
		dp.clear(); 
		cin >> P >> Q; 
		for (int j = 1; j <= Q; j++){
			cin >> q[j]; 
		}
		int ans = solve(1,P); 
		cout << "Case #" << i << ": " << ans << endl; 
	}
	return 0; 
}
