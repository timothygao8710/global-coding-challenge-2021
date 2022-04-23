
using namespace std;
#include <string>
#include <iostream>
//AC
int solution(int n){
    return 2*(n/3) + (n%3 != 0);
}

/*  Do not edit below code */
int main() {
	int n;
	cin >> n;	
    int answer=solution(n);
	cout << answer << endl;	
}
