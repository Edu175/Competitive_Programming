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
const ll MAXN=1e5+5;

ll n,k;
ll a[MAXN];
ll dp[MAXN][2][2];

ll f(ll i, ll h, ll y){
	ll &res=dp[i][h][y];
	if(res!=-1)return res;
	if(i==n)return res=0;
	ll go0=(a[i]%(a[i-1]+k*h))+f(i+1,0,(h==1||y)),go1=-1;
	if(!y)go1=((a[i]+k)%(a[i-1]+k*h))+f(i+1,1,y);
	//cout<<i<<" "<<h<<" "<<y<<": "<<go0<<" ";
	/*if(go1!=-1)cout<<go1;
	else cout<<"-";*/
	res=max(go0,go1);
	//cout<<": "<<res<<"\n";
	return res;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>k;
		fore(i,0,n)cin>>a[i];
		fore(i,0,n+3)fore(j,0,2)fore(h,0,2)dp[i][j][h]=-1;
		cout<<max(f(1,1,0),f(1,0,0))<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
