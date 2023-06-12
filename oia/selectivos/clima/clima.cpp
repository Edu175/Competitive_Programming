#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=120;
ll h[MAXN][MAXN],c[MAXN][MAXN];
int main(){FIN;
	ifstream cin;   cin.open("clima.in", ios::in);
	ofstream cout; cout.open("clima.out", ios::out);
	ll n; cin>>n;
	pair<ll,ll>a[n];
	fore(i,0,n){
		ll m; cin>>m;
		ll l=100,r=-100;
		fore(j,0,2*m){
			ll x; cin>>x;
			l=min(l,x);
			r=max(r,x);
		}
		l+=50,r+=50;
		h[l][r]++;
		a[i]={l,r};
	}
	fore(l,0,MAXN)fore(r,l,MAXN)fore(s,0,MAXN)fore(e,s,MAXN){
		if(l<=s&&e<=r&&!(l==s&&r==e))c[l][r]+=h[s][e];
	}
	ll maxi=0;
	fore(i,0,n){
		ll l=a[i].fst,r=a[i].snd;
		maxi=max(maxi,c[l][r]);
	}
	fore(i,0,n){
		ll l=a[i].fst,r=a[i].snd;
		if(c[l][r]==maxi)cout<<i+1<<" "<<n-(maxi+h[l][r])<<"\n";
		//cout<<i<<": "<<c[l][r]<<"\n";
	}
	//cout<<maxi<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
