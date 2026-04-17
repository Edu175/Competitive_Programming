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
const ll MAXN=16,INF=1e4+5;

struct pt{
	ll x,y;
	pt(ll x, ll y): x(x), y(y){};
	pt(){};
};
ll k,n;
pt a[MAXN];
ll cnt(pt s, pt b){
	return (b.x-s.x+b.y-s.y)*2+8*k;
}
ll vis[MAXN][MAXN][MAXN][MAXN];
ll in(ll u, ll d, ll l, ll r){
	ll &res=vis[u][d][l][r];
	if(res!=-1)return res;
	u=a[u].y,d=a[d].y,l=a[l].x,r=a[r].x;
	res=0;
	fore(i,0,n){
		pt p=a[i];
		if(d<=p.y&&p.y<=u&&l<=p.x&&p.x<=r)res|=1ll<<i;
	}
	return res;
}
ll dp[(1ll<<MAXN)+5];
ll f(ll us){
	ll &res=dp[us];
	if(res!=-1)return res;
	vector<ll>b;
	fore(i,0,n)if(!(us&(1ll<<i)))b.pb(i);
	ll m=SZ(b);
	if(m==0)return res=0;
	res=INF*INF*4;
	fore(_0,0,m)fore(_1,_0,m)fore(_2,0,m)fore(_3,_2,m){
		ll u=a[b[_0]].y,d=a[b[_1]].y,l=a[b[_2]].x,r=a[b[_3]].x;
		if(u<d)swap(u,d);
		if(r<l)swap(l,r);
		ll usi=in(b[_0],b[_1],b[_2],b[_3]);
		ll resi=cnt(pt(l,d),pt(r,u))+f(us|usi);
		res=min(res,resi);
		//cout<<us<<": "<<u<<" "<<l<<" "<<r<<" "<<d<<": "<<usi<<" "<<resi<<"\n";
	}
	//cout<<us<<": "<<res<<"\n";
	return res;
}
int main(){FIN;
	ifstream cin; cin.open("placas.in", ios::in);
	ofstream cout; cout.open("placas.out", ios::out);
	cin>>k>>n;
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	mset(dp,-1);
	mset(vis,-1);
	cout<<f(0)<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

