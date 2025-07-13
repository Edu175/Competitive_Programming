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
const ll MOD=1e9+7,MAXF=2e6+5;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}
ll nCr(ll n, ll k){ // must call factos before
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}
ll Fc(ll n){
	if(n<0)return 0;
	return fc[n];
}

void acum(vector<ii> &a){
	auto _a=a;
	a.clear();
	sort(ALL(_a));
	for(auto i:_a)if(i.fst>1){
		if(SZ(a)&&a.back().fst==i.fst)a.back().snd+=i.snd;
		else a.pb(i);
	}
}

int main(){FIN;
	factos();
	ll t; cin>>t;
	while(t--){
		ll n,a,b; cin>>n>>a>>b;
		ll k=abs(a-b)-1;
		auto f=[&](ll l, ll r){
			ll res=mul(mul(mul
				(l,nCr(n-k-2,r-1)) ,Fc(n-r-1)) ,fc[r]);
			// cout<<"f "<<l<<" "<<r<<": "<<res<<"\n";
			return res;
		};
		vector<ii> v={{n,1}};
		ll res=0;
		while(SZ(v)){
			vector<ii>vi;
			// cout<<"\nlevel\n";
			// for(auto i:v)cout<<i.fst<<","<<i.snd<<"\n";
			for(auto [z,q]:v){
				ll l=z/2,r=(z+1)/2;
				ll num=add(f(l,r),f(r,l));
				res=add(res,mul(q,num));
				// cout<<z<<" "<<q<<": "<<num<<": "<<mul(num,q)<<"\n";
				vi.pb({l,q});
				vi.pb({r,q});
			}
			swap(v,vi);
			acum(v);
		}
		cout<<res<<"\n";
	}
	return 0;
}
