#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n,m; cin>>n>>m;
	vector<vector<char>> a(n,vector<char>(m));
	fore(i,0,n)fore(j,0,m)cin>>a[i][j];
	a[n-1][m-1]='U';
	vector<vector<char>> dp(n,vector<char>(m));
	for(ll i=n-1;i>=0;i--)for(ll j=m-1;j>=0;j--){
		if(a[i][j]=='U'){dp[i][j]='U';continue;}
		auto &res=dp[i][j];
		res='L';
		fore(k,1,max(n,m)){
			if(i+k<n&&dp[i+k][j]!='.')res='.';
			if(j+k<m&&dp[i][j+k]!='.')res='.';
		}
	}
	fore(i,0,n){
		fore(j,0,m)cout<<dp[i][j];
		cout<<"\n";
	}
	return 0;
}