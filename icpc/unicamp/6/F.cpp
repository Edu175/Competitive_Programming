#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		char a[n][m];
		fore(i,0,n)fore(j,0,m)cin>>a[i][j];
		ll dp[n][m];
		for(ll i=n-1;i>=0;i--)for(ll j=m-1;j>=0;j--){
			dp[i][j]=0;
			if(a[i][j]=='#')continue;
			if(i==n-1&&j==m-1){dp[i][j]=1;continue;}
			if(i<n-1)dp[i][j]|=dp[i+1][j];
			if(j<m-1)dp[i][j]|=dp[i][j+1];
		}
		if(!dp[0][0]){
			cout<<"NO\n";
			continue;
		}
		string mov,row(n,'N'),col(m,'N');
		if(a[0][0]=='@')row[0]='Y';
		ll i=0,j=0;
		//cout<<n-1<<" "<<m-1<<"\n";
		while(i!=n-1||j!=m-1){
			if(i<n-1&&dp[i+1][j]){
				mov.pb('D');
				if((a[i+1][j]=='@')^(col[j]=='Y'))row[i+1]='Y';
				i++;
			}
			else {
				mov.pb('R');
				if((a[i][j+1]=='@')^(row[i]=='Y'))col[j+1]='Y';
				j++;
			}
			//cout<<i<<" "<<j<<"\n";
		}
		cout<<"YES\n"<<row<<"\n"<<col<<"\n"<<mov<<"\n";
	}
	return 0;
}
