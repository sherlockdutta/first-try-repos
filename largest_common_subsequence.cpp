#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
int max(int a,int b){
	if(a > b){
		return a;
	}
	return b;
}
int lcs(vector< vector<int> > &dp,string S1,string S2,int SS1,int SS2){
	if(SS1 == 0  || SS2 == 0){
		return 0;
	}
	if(dp[SS1-1][SS2-1] != -1){
		return dp[SS1-1][SS2-1];
	}
	else if(S1[SS1-1] == S2[SS2-1]){
		return dp[SS1-1][SS2-1] = 1 + lcs(dp,S1,S2,SS1-1,SS2-1);
	}
	else {
		return dp[SS1-1][SS2-1] = max(lcs(dp,S1,S2,SS1-1,SS2),lcs(dp,S1,S2,SS1,SS2-1));
	}
}
int main(){
	cout<<"Enter two Strings"<<endl;
	string S1,S2;
	cin>>S1>>S2;
	int SS1 = S1.size();
	int SS2 = S2.size();
	int i,j;
	vector< vector<int> > dp(SS1, vector<int>(SS2,-1));
	int n = lcs(dp,S1,S2,SS1,SS2);
	cout<<n<<endl;
	return 0;
}