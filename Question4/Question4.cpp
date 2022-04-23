//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

//AC
int totalPairs(int n, vector<int>& values) {
    ll ret =0;
    vector<pii> past;
    for(int i=0; i<n; i++){
        while(!past.empty() && past.back().f < values[i]){
            past.pop_back(); ret++;
        }
        ret += !past.empty();
        past.pb(pii(values[i], i));
    }
    return ret;
}

int main(){
   int n;
   cin >> n;
   vector<int> values(n);
   for (int i = 0; i < n; ++i) {
        cin >> values[i];
   }
	int answer = totalPairs(n, values);
    // Do not remove below line
    cout << answer << endl;
    // Do not print anything after this line
        
    return 0;
}
