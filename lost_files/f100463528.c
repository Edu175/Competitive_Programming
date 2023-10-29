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
const ll MAXN=501,INF=1e9+5;

ll n,l,k;
ll a[MAXN],v[MAXN];
ll dp[5][MAXN][MAXN];

int main(){FIN;
	cin>>n>>l>>k;
	fore(i,0,n)cin>>a[i];
	a[n]=l;
	fore(i,0,n)cin>>v[i];
	ll w=0;
	for(ll i=n-1;i>=0;i--){
		fore(s,0,i+1){
			fore(c,0,k+1){
				ll &res=dp[w][s][c];
				ll d=a[i+1]-a[i];
				res=v[i]*d+dp[w^1][i][c];
				if(c<k)res=min(res,v[s]*d+dp[w^1][s][c+1]);
			}
		}
		w^=1;
	}
	cout<<dp[w^1][0][0]<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

