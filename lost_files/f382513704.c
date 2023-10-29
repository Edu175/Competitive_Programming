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
const ll MOD=998244353;

typedef vector<vector<ll>> Matrix;
Matrix ones(ll n){
	Matrix r(n,vector<ll>(n));
	fore(i,0,n)r[i][i]=1;
	return r;
}
Matrix operator*(Matrix a, Matrix b){	//no conmutativa
	ll n=SZ(a),m=SZ(b[0]),z=SZ(a[0]);
	Matrix r(n,vector<ll>(m));
	fore(i,0,n)fore(j,0,m)fore(k,0,z)r[i][j]=(r[i][j]+a[i][k]*b[k][j])%MOD;
	return r;
}
Matrix be(Matrix b, ll e){	//b tiene que ser cuadrada
	Matrix r=ones(SZ(b));
	while(e){if(e&1ll)r=r*b; b=b*b; e/=2;}
	return r;
}
string cv(ll x, ll sz){
	string s;
	fore(i,0,sz){
		if(x&(1ll<<i))s.pb('b');
		else s.pb('a');
	}
	return s;
}
set<string>st;
bool valid(string s){//O(sz²)
	ll flag=1;
	fore(l,0,SZ(s))fore(r,l+1,SZ(s)+1){
		string p;
		fore(i,l,r)p.pb(s[i]);
		if(st.count(p))flag=0;
	}
	return flag;
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		string s; cin>>s; st.insert(s);
	}
	if(n<6){
		ll res=0;
		fore(i,0,1ll<<n){
			res+=valid(cv(i,n));
		}
		cout<<res<<"\n";
		return 0;
	}
	Matrix g(64,vector<ll>(64));
	fore(i,0,64)fore(j,0,64){
		string s=cv(i,6); s+=cv(j,6);
		g[i][j]=valid(s);
	}
	g=be(g,n/6-1);
	ll res=0;
	fore(j,0,64){
		ll sum=0;
		fore(i,0,64)sum=(sum+g[i][j])%MOD;
		ll val=0;
		fore(k,0,1ll<<(n%6)){
			string s=cv(j,6),t=cv(k,n%6);
			for(auto i:t)s.pb(i);
			val+=valid(s);
		}
		res=(res+sum*val)%MOD;
	}
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
