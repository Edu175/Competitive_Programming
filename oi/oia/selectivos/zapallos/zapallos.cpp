#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define forr(i,a,b) for(ll i=b-1,ggdem=a;i>=ggdem;--i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
const ll MAXN=25,MAXM=1205,MAXQ=1005,INF=2e6+5;
ii operator+(ii p, ii q){return {p.fst+q.fst,p.snd+q.snd};}

ii dp[MAXN][MAXM][MAXQ];
ll m[MAXN],n,k,a[MAXN][MAXM];
ii f(ll i, ll j, ll q){
	return dp[i][j][q];
}
ll ans[MAXN];
int main(){FIN;
	ifstream cin;   cin.open("zapallos.in", ios::in);
	ofstream cout; cout.open("zapallos.out", ios::out);
	cin>>n>>k;
	fore(i,0,n){
		cin>>m[i];
		fore(j,0,m[i])cin>>a[i][j];
	}
	forr(i,0,n+3)forr(j,0,m[i]+3)forr(q,0,k+3){
		ii &res=dp[i][j][q];
		if(q>k) res={-INF,INF};
		else if(i>=n)res={0,0};
		else if(j>=m[i])res=f(i+1,0,q);
		else res=max(ii({10-a[i][j],-1})+f(i,j+1,q+1),f(i+1,0,q));
	}
	ii res=f(0,0,0);
	cout<<res.fst<<" "<<-res.snd<<"\n";
	for(ll i=0,j=0,q=0;q<=k&&i<n;){
		ii &res=dp[i][j][q];
		if(res==f(i+1,0,q))ans[i]=j,i++,j=0;
		else j++,q++;
	}
	fore(i,0,n)cout<<ans[i]<<" ";
	cout<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
