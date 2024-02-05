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
typedef long double ld;
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
	bool operator<(frac f){return n*f.d<f.n*d;}
	void reduce(){
		ll g=gcd(n,d);
		n/=g,d/=g;
	}
	//void prnt(){cout<<n<<"/"<<d<<" ";}
};
const ld EPS=1e-6;
bool equal(ld a, ld b){
	if(abs(a-b)<=EPS)return 1;
	return 0;
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	ll pot=1;
	fore(i,1,n+1)pot*=3;
	ld x=-1,y=0;
	ll mask=0;
	fore(mk,0,pot){
		ll m=mk;
		ll sum[3]={},c[3]={};
		fore(i,0,n)sum[m%3]+=a[i],c[m%3]++,m/=3;
		if(!c[0]||!c[1]||!c[2])continue;
		ld r=0;
		fore(i,0,3)r+=ld(sum[i])/ld(c[i]);
		r/=3.0;
		//cout<<mk<<": ";
		//fore(i,0,3)cout<<sum[i]<<"/"<<c[i]<<"+";
		//cout<<" = "<<r<<" ("<<abs(k-r)<<"): "<<equal(abs(k-r),x)<<" "<<(abs(k-r)<x)<<"\n";
		if(x==-1)mask=mk,x=abs(k-r),y=r;
		else if(equal(abs(k-r),x)){
			if(r<y)mask=mk,x=abs(k-r),y=r;
		}
		else if(abs(k-r)<x)mask=mk,x=abs(k-r),y=r;
	}
	ll m=mask;
	ll sum[3]={},c[3]={};
	fore(i,0,n)sum[m%3]+=a[i],c[m%3]++,m/=3;
	assert(c[0]&&c[1]&&c[2]);
	vector<frac> f(3);
	fore(i,0,3)f[i]=frac(sum[i],c[i]);
	frac r=f[0]+f[1]+f[2];
	r=r*frac(1,3);
	r.reduce();
	cout<<r.n<<"/"<<r.d<<"\n";
	return 0;
}
