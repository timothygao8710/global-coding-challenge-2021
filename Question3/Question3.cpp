//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

//AC
int portfolio_profit_maximisation(int maxSum, vector<ll> a, vector<ll> b) {
    
    for(int i = 1; i<a.size(); i++) a[i] += a[i-1]; 
    for(int i = 1; i<b.size(); i++) b[i] += b[i-1];
    int ret = upper_bound(b.begin(), b.end(), maxSum) - b.begin();

    for(int i = 0; i<a.size(); i++){
        if(maxSum - a[i] < 0) break;
        auto it = upper_bound(b.begin(), b.end(), maxSum - a[i]);
        ret = max(ret, i + 1 + int(it - b.begin()));
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);

    ll n, m, x;
    cin >> n >> m >> x;

    vector<ll> a(n);//
    vector<ll> b(m);//

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    int result = portfolio_profit_maximisation(x, a, b);
    cout << result;
    return 0;
}