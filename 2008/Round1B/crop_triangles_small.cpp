#include <iostream>
#include <vector> 
#include <cstdlib>
#include <algorithm> 
using namespace std;  
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);  
typedef long long ll;  
typedef pair<ll,ll> P;  
bool ok(P &a,P &b,P &c){
	return (((a.first+b.first+c.first)%3 == 0) && ((a.second+b.second+c.second)%3 == 0)); 
}
int main(){
	IOFAST();  
	int N; 
	cin >> N; 
	for (int t = 1; t <= N; t++){
		ll n,A,B,C,D,x0,y0,M;  
		cin >> n >> A >> B >> C >> D >> x0 >> y0 >> M; 
		vector<P> points;   
		ll X = x0, Y = y0;  
		points.push_back(P(X,Y));  
		for (int i = 1; i <= n-1; i++){
			X = (A*X+B)%M; 
			Y = (C*Y+D)%M;  
			points.push_back(P(X,Y));  
		}
		// we brute force for the answer 
		int cnt = 0;  
		for (int i = 0; i < points.size(); i++){
			for (int j = i+1; j < points.size(); j++){
				for (int k = j+1; k < points.size(); k++){
					P a = points[i]; 
					P b = points[j]; 
					P c = points[k];  
					if (ok(a,b,c)) cnt++;  
				}
			}
		}
		cout << "Case #" << t << ": ";  
		cout << cnt << endl; 
	}
	return 0;  
}
