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
const ll MAXN=16,INF=1e10+5;

struct pt{
	ll x,y;
	pt(ll x, ll y): x(x), y(y){};
	pt(){};
};
ll k,n,g;
pt a[MAXN];
ll tle=0,db=0;
ll cnt(vector<ll>&c){
	//imp(c);
	db++;
	return 0;
	vector<ll> oc[g];
	fore(i,0,SZ(c))oc[c[i]].pb(i);
	ll res=0;
	fore(i,0,g){
		//cout<<i<<": ";
		pt s=pt(INF,INF),b=pt(0,0);
		for(auto j:oc[i]){
			//cout<<j<<" ("<<a[j].x<<","<<a[j].y<<") ";
			s.x=min(s.x,a[j].x),s.y=min(s.y,a[j].y);
			b.x=max(b.x,a[j].x),b.y=max(b.y,a[j].y);
		}
		//cout<<"| "<<s.x<<","<<s.y<<" "<<b.x<<","<<b.y<<" = "<<(b.x-s.x+b.y-s.y)*2+8*k<<"\n";
		res+=(b.x-s.x+b.y-s.y)*2+8*k;
	}
	//cout<<res<<"\n";
	return res;
}
ll f(ll i, vector<ll>&c){
	tle++;
	ll res=INF;
	if(i==n)return res=cnt(c);
	fore(j,0,g){
		vector<ll>ci=c; ci.pb(j);
		res=min(res,f(i+1,ci));
	}
	cout<<tle<<" "<<db<<"\n";
	return res;
}

int main(){//FIN;
	ifstream cin; cin.open("placas.in", ios::in);
	//ofstream cout; cout.open("placas.out", ios::out);
	cin>>k>>n;
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	ll pot[n+1][n+1];
	fore(i,1,n+1){
		pot[i][0]=1;
		fore(j,1,n-i+1)pot[i][j]=pot[i][j-1]*i;
	}
	ll res=INF;
	fore(h,1,n+1){
		vector<ll>c;
		fore(i,0,h)c.pb(i);
		g=h;
		fore(mk,0,pot[h][n-h]){
			vector<ll>ci=c;
			fore()
		}
		ll resi=f(h,c);
		cout<<h<<": "<<resi<<"\n";
		res=min(res,resi);
	}
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

