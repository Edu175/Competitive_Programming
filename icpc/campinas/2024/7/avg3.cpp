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

struct frac{
	ll n,d;
	frac(){}
	frac(ll a, ll b): n(a),d(b){
		/*ll g=gcd(n,d);
		n/=g,d/=g;*/
	}
	//frac operator*(ll x){return frac(n*x,d);}
	frac operator*(frac f){return frac(n*f.n,d*f.d);}
	frac operator+(frac f){return frac(n*f.d+f.n*d,d*f.d);}
	frac operator-(frac f){return frac(n*f.d-f.n*d,d*f.d);}
	bool operator<(frac f){return n*f.d<f.n*d;}
	bool operator==(frac f){return n==f.n&&d==f.d;}
	frac avs(){return frac(abs(n),abs(d));}
	void reduce(){
		ll g=gcd(n,d);
		n/=g,d/=g;
	}
	//void prnt(){cout<<n<<"/"<<d<<" ";}
};
ll a[35];
ll n;
frac dp[35][35][35][105][105];
bool vis[35][35][35][105][105];
frac cl;
frac mini(frac a, frac b){
	if((a-cl).avs()==(b-cl).avs()){
		if(b<a)return b;
		return a;
	}
	if((b-cl).avs()<(a-cl).avs())return b;
	return a;
}

frac f(ll i, ll c0, ll c1, ll c2, ll s0, ll s1, ll s2){
	auto &r=dp[c0][c1][c2][s0][s1];
	if(vis[c0][c1][c2][s0][s1])return r;
	vis[c0][c1][c2][s0][s1]=1;
	if(i==n){
		r=frac(0,1);
		r=r+frac(s0,c0);
		r=r+frac(s1,c1);
		r=r+frac(s2,c2);
		r=r*frac(1,3);
		return r;
	}
	frac can0=f(i+1,c0+1,c1,c2,s0+a[i],s1,s2);
	frac can1=f(i+1,c0,c1+1,c2,s0,s1+a[i],s2);
	frac can2=f(i+1,c0,c1,c2+1,s0,s1,s2+a[i]);
	return r=mini(can0,mini(can1,can2));
}

int main(){FIN;
	ll k; cin>>n>>k;
	fore(i,0,n)cin>>a[i];
	cl=frac(k,1);
	frac res=f(0,0,0,0,0,0,0);
	
	cout<<res.n<<"/"<<res.d<<"\n";
	return 0;
}
