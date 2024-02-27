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
	frac avs(){return frac(abs(n),abs(d));}
	void reduce(){
		ll g=gcd(n,d);
		n/=g,d/=g;
	}
	void prnt(){cout<<n<<"/"<<d<<" ";}
};

int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	ll pot[n+1]; pot[0]=1;
	fore(i,1,n+1)pot[i]=pot[i-1]*3;
	frac cl(k,1),res;
	ll did=0;
	fore(mk,0,pot[n]){
		ll m=mk;
		ll sum[3]={},c[3]={};
		fore(i,0,n)sum[m%3]+=a[i],c[m%3]++,m/=3;
		if(!sum[0]||!sum[1]||!sum[2])continue;
		vector<frac> f(3);
		fore(i,0,3)f[i]=frac(sum[i],c[i]);
		frac r=f[0]+f[1]+f[2];
		
		r=r*frac(1,3);
		cout<<mk<<": "<<sum[0]<<" "<<sum[1]<<" "<<sum[2]<<": ";
		f[0].prnt(); f[1].prnt(); f[2].prnt(); cout<<"= "; 
		(f[0]+f[1]).prnt(); (f[0]+f[1]+f[2]).prnt(); r.prnt();
		cout<<"\n"; (r-cl).avs().prnt(); cout<<"\n";
		if(!did||(r-cl).avs()<(res-cl).avs())res=r;
		did=1;
	}
	res.reduce();
	cout<<res.n<<"/"<<res.d<<"\n";
	return 0;
}
