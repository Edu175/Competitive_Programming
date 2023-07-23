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
const ll MOD=998244353,MAXN=2005;

ll n,m;
ll a[MAXN][MAXN]; 
ll dp[MAXN][MAXN];
int main(){FIN;
	cin>>n>>m;
	char b[n][m];
	fore(i,0,n)fore(j,0,m){
		cin>>b[i][j];
		a[m-1-j][i]=(b[i][j]=='#');
	}
	swap(n,m);
	vector<ll>sp(m+1,1); //[0,i]
	ll mn=m;
	fore(i,0,n){
		cout<<"\n"<<i<<":\n";
		imp(sp);
		cout<<mn<<"\n";
		vector<ll>p(m+1);
		for(ll j=m-1;j>=0;j--){
			ll &res=dp[i][j];
			if(a[i][j])res=(j==m-1?1:dp[i][j+1]); //no pinto
			p[j]=sp[min(mn,j+1)]; //pinto
			res=(res+p[j])%MOD;
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
		//upd mn and sp
		mn=m;
		fore(j,0,m)if(a[i][j])mn=j;
		p[m]=1;
		imp(p);
		sp[0]=p[0];
		fore(j,1,m+1)sp[j]=(sp[j-1]+p[j])%MOD;
	}
	ll res=dp[n-1][0];
	cout<<res<<"\n";
	return 0;
}
