#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e5+5,INF=MAXN*5;

ll n;
char a[MAXN][2];
ll val(char a, char b, char c){
	string s;
	s.pb(a);
	s.pb(b);
	s.pb(c);
	if(count(ALL(s),'A')>=2)return 1;
	return 0;
}
vector<vector<vv>> piezas={
	{{1,0},
	 {1,0},
	 {1,0}},
	 
	 {{0,1},
	  {0,1},
	  {0,1}},
	 
	 {{1,1},
	  {1,0},
	  {0,0}},
	 
	 {{1,1},
	  {0,1},
	  {0,0}},
	  
	  {{0,1},
	   {1,1},
	   {0,0}},
	  
	  {{1,0},
	   {1,1},
	   {0,0}},
	 };
vector<ll>mks;
ll value(ll s, ll k){
	auto p=piezas[k];
	string S;
	fore(i,0,3)fore(j,0,2)if(p[i][j]){
		if(s+i>=n)return -INF;
		S.pb(a[s+i][j]);
	}
	if(count(ALL(S),'A')>=2)return 1;
	return 0;
}
const ll MAXMK=1<<6;
ll dp[MAXN][MAXMK];
ll vis[MAXN][MAXMK];
ll f(ll i, ll mk){
	ll &res=dp[i][mk];
	if(vis[i][mk])return res;
	vis[i][mk]=1;
	if(i==n)return res=mk==0?0:-INF;
	if((mk&3)==3){
		res=f(i+1,mk>>2);
		// cout<<i<<" "<<mk<<": "<<res<<" avanzo\n";
		return res;
	}
	res=-INF;
	fore(k,0,SZ(piezas))if(!(mk&mks[k])){
		ll resi=value(i,k)+f(i,mk|mks[k]);
		// cout<<i<<" "<<mk<<" prueba pieza "<<k<<": "<<resi<<"\n";;
		res=max(res,resi);
	}
	// cout<<i<<" "<<mk<<": "<<res<<"\n";
	return res;
}

int main(){FIN;
	fore(k,0,SZ(piezas)){
		ll mk=0;
		fore(i,0,3)fore(j,0,2)mk+=ll(piezas[k][i][j])<<(2*i+j);
		mks.pb(mk);
	}
	// imp(mks);
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(h,0,2)fore(i,0,n)cin>>a[i][h];
		fore(i,0,n+3){
			fore(j,0,MAXMK)vis[i][j]=0;
		}
		ll res=f(0,0);
		cout<<res<<"\n";
	}
	return 0;
}
