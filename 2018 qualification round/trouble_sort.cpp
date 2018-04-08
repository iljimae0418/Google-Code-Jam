#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;  
int main(){
	int t; 
	cin >> t; 
	for (int test = 1; test <= t; test++){
		int n; 
		cin >> n; 
		vector<int> a(n),b,c; // b contains even index sublist, c contains odd index sublist 
		for (int i = 0; i < n; i++){
			cin >> a[i];  
			if (i%2 == 0) b.push_back(a[i]); 
			else if (i%2 == 1) c.push_back(a[i]); 
		}
		sort(b.begin(),b.end()); 
		sort(c.begin(),c.end()); 
		int cnt_b = 0, cnt_c = 0; 
		for (int i = 0; i < n; i++){
			if (i%2 == 0) a[i] = b[cnt_b++]; 
			else a[i] = c[cnt_c++];  
		}
		cout << "Case #" << test << ": "; 
		bool canSort = true; 
		for (int i = 0; i < n-1; i++){
			if (a[i] > a[i+1]){
				canSort = false;  
				cout << i << endl; 
				break; 
			}
		}
		if (canSort) cout << "OK" << endl; 
	}	
	return 0; 
}
