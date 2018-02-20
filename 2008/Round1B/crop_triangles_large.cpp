#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm> 
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
typedef long long ll; 
typedef pair<ll,ll> P;  
int main(){
	IOFAST();  
	int N; 
	cin >> N; 
	for (int t = 1; t <= N; t++){
		ll n,A,B,C,D,x0,y0,M;  
		cin >> n >> A >> B >> C >> D >> x0 >> y0 >> M; 
		ll bucket[9];  
		memset(bucket,0,sizeof(bucket)); 
		ll X = x0, Y = y0; 
		for (int i = 0; i < n; i++){
			bucket[(X%3)*3+(Y%3)]++; // can have values from 0 to 8
			X = (A*X+B)%M; 
			Y = (C*Y+D)%M;  
		}
		ll ret = 0; 
		// select three points from the same bucket  
		for (int i = 0; i < 9; i++){
			ret += bucket[i]*(bucket[i]-1)*(bucket[i]-2)/6;  
		}
		// select from three different buckets  
		for (int i = 0; i < 9; i++){
			for (int j = i+1; j < 9; j++){
				for (int k = j+1; k < 9; k++){
					if ((((i/3) + (j/3) + (k/3))%3 == 0) && (((i%3) + (j%3) + (k%3))%3 == 0)){
						ret += bucket[i]*bucket[j]*bucket[k];  
					}
				}
			}
		}
		cout << "Case #" << t << ": ";  
		cout << ret << endl; 
	}
	return 0; 
}
