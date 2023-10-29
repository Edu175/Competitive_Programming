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
const ll MAXN=103;

ll dp[MAXN][MAXN][MAXN];
ll a[MAXN];
ll n,k,d;

ll f(ll i, ll s, ll m){
	ll &res=dp[i][s][m];
	if(res!=-5)return res;
	if(i==n){
		if(m==k&&s==0)return res=0;
		else return res=-1;
	}
	ll b=f(i+1,(s+a[i])%d,m+1);
	res=f(i+1,s,m);
	//cout<<i<<" "<<s<<" "<<m<<": "<<res<<" "<<b<<","<<a[i]<<" = ";
	if(b!=-1&&b+a[i]>res)res=b+a[i];
	//cout<<res<<"\n";
	return res;
}

int main(){FIN;
	fore(i,0,MAXN){
		fore(j,0,MAXN){
			fore(l,0,MAXN){
				dp[i][j][l]=-5;
			}
		}
	}
	cin>>n>>k>>d;
	fore(i,0,n)cin>>a[i];
	cout<<f(0,0,0)<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
