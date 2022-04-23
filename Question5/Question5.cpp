//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

//AC
string solution(string n){
    vector<int> sz;
    int last = -1; int hasOne = 0;
    for(int i = 0; i<(int)(n.length()); i++){
        if(n[i] == '1'){
            sz.pb(i - last - 1); last = i;
            hasOne = 1;
        }
    }
    sz.pb(n.length() - last -1);
    if(sz.size() == 1){
        assert(!hasOne);
        return sz[0]%2 ? "A" : "B";
    }

    sort(sz.begin(), sz.end());    
    if(sz[sz.size()-1]%2 == 0) return "B";
    if(sz[sz.size()-2] >= 1 + (sz[sz.size()-1])/2) return "B";
    return "A";
}
//0000
/*  Do not edit below code */
int main() {
	string  n;
	cin >> n;	
    string answer=solution(n);
	cout << answer << endl;	
}
