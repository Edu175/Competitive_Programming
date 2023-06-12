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
const ll MAXN=505,INF=2*MAXN;

ll a[MAXN];
ll dp[2][MAXN][MAXN];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)cin>>a[i];
		ll w=0;
		for(ll i=n;i>=0;i--){
			w^=1;
			fore(r,0,n+1)fore(k,0,n+1){
				ll &res=dp[w][r][k];
				if(i==n){res=0;continue;}
				res=-INF;
				ll s=(!i||a[i-1]==r);
				//cout<<i<<" "<<r<<" "<<k<<": ";
				//cout<<"["<<r<<"]["<<k-s<<"] ";
				if(k-s>=0)res=dp[w^1][r][k-s];
				//cout<<dp[w^1][r][k-s]<<" ";
				//else cout<<"- ";
				//cout<<"["<<a[i]<<"]["<<k<<"] ";
				if(a[i]>r)res=max(res,dp[w^1][a[i]][k]+1);
				//cout<<dp[w^1][a[i]][k]+1<<": ";
				//else cout<<"-: ";
				//cout<<res<<"\n";
			}
		}
		//cout<<w<<"\n";
		fore(i,1,n+1)cout<<n-dp[w][0][i]<<" ";
		cout<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
