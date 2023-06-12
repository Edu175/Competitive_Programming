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
const ll MAXN=2e5+5,MAXH=25,INF=5e8;

ll dp[MAXN][MAXH];
ll a[MAXN];
int main(){FIN;
	ifstream cin;   cin.open("casas.in", ios::in);
	ofstream cout; cout.open("casas.out", ios::out);
	ll x,y,n; cin>>x>>y>>n;
	fore(i,0,n)cin>>a[i];
	a[n]=y+1;
	forr(i,0,n+3)fore(h,0,x/2+3){
		ll &res=dp[i][h];
		if(i>=n){res=0;continue;}
		if(i&&a[i-1]+h>=a[i]){res=-INF;continue;}
		res=-INF;
		fore(hi,1,min({x/2+1,a[i]-(i?a[i-1]:0)-h+1,a[i+1]-a[i]})){
			res=max(res,hi*hi*4+dp[i+1][hi]);
		}
	}
	cout<<dp[0][0]<<"\n";
	for(ll i=0,h=0;i<n;){
		ll &res=dp[i][h];
		fore(hi,1,min({x/2+1,a[i]-(i?a[i-1]:0)-h+1,a[i+1]-a[i]})){
			if(res==hi*hi*4+dp[i+1][hi]){
				cout<<hi*2<<"\n";
				i++,h=hi;
				break;
			}
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
