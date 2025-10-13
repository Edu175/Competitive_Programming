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
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll MAXF=1e6+5;
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}
const ll haf=(MOD+1)/2;

ll n;
vv a,b;
ll res=0;
void f(){
	if(SZ(b)==n){
		ll good=b.back()>0;
		vv t(n);
		fore(i,1,n)t[b[i]]+=i;
		good&=t==b;
		// if(b==vv({0,1,2})){
		// 	cout<<n<<":\n";
		// 	cout<<"aca: ";
		// 	imp(b);
		// 	imp(t);
		// 	cout<<good<<"\n";
		// }
		if(good){
			res++;
			imp(b)
			// imp(t)
			// cout
		}
		return;
	}
	ll i=SZ(b);
	ll e=(!i?n*n+2:n);
	fore(v,0,e){
		if(a[i]!=-1&&a[i]!=v)continue;
		b.pb(v);
		f();
		b.pop_back();
	}
}

int main(){FIN;
	factos();
	ll t; cin>>t;
	while(t--){
		cin>>n; n++;
		a=vv(n);
		fore(i,0,n)cin>>a[i];
		res=0;
		b.clear();
		f();
		cout<<res<<"\n";
	}
	return 0;
}
