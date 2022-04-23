//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second
 //AC
int securitiesBuying(int z,int security_value[], int N)
{
    int no_of_stocks=0;//
    vector<pii> nums(N);
    for(int i = 0; i<N; i++){
        nums[i].f = security_value[i]; nums[i].s = i+1;
    }
    sort(nums.begin(), nums.end());
    for(int i = 0; i<N; i++){
        while(z - nums[i].f >= 0 && nums[i].s > 0){
            no_of_stocks++; nums[i].s--; z -= nums[i].f;
        }
    }
    return no_of_stocks;
}
 
int main(){
 
int z;
cin>>z;
vector<int> input_data;
string buffer;
int data;
getline(cin, buffer);
getline(cin, buffer);
istringstream iss(buffer);
 
 
while (iss >> data)
    input_data.push_back(data);
 
int n= input_data.size();
 
 
 int security_value[n];
    for (int i = 0; i < n; i++) {
        security_value[i] = input_data[i];
    }
 
 
 
int no_of_stocks_purchased = securitiesBuying(z,security_value,n);
cout << no_of_stocks_purchased;
 
 
 
}
 
 
