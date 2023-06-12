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
const ll MAXN=2005,INF=2*MAXN;

ii a[MAXN];
ll dp[MAXN][MAXN][2];
ll n;
ll f(ll i, ll r, ll b){
	ll &res=dp[i][r][b];
	if(res!=-1)return res;
	if(i==n){
		if(b)return res=INF;
		return res=0;
	}
	res=1+f(i+1,r,b);
	if(!b){
		if(r==n||a[r].snd<a[i].fst)res=min(res,f(i+1,i,1));
	}
	else{
		if(r!=n&&a[r].snd>=a[i].fst){
			ll ri=r; if(a[i].snd>a[r].snd)ri=i;
			res=min(res,f(i+1,ri,0));
		}
	}
	//cout<<i<<" "<<r<<" "<<b<<": "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n+3)fore(j,0,n+3)fore(k,0,2)dp[i][j][k]=-1;
		fore(i,0,n+3)a[i]={0,0};
		fore(i,0,n)cin>>a[i].fst>>a[i].snd;//,a[i].fst++,a[i].snd++;
		sort(a,a+n);
		cout<<f(0,n,0)<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
