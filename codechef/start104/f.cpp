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
typedef vector<ll> vv;
const ll MAXN=2005,MAXF=MAXN;
ll MOD;
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

int main(){FIN;
	ll n; cin>>n>>MOD;
	factos();
	vv der(n+1); // derrangements
	fore(m,0,n+1){
		auto &res=der[m];
		fore(k,0,m+1)res=(k&1?sub:add)(res,mul(nCr(m,k),fc[m-k]));
	}
	vv pot(n+5); pot[0]=1;
	fore(i,1,SZ(pot))pot[i]=mul(pot[i-1],n);
	vv pot2(n+5); pot2[0]=1;
	fore(i,1,SZ(pot2))pot2[i]=mul(pot2[i-1],2);
	ll ans=0;
	fore(z,1,n+1){
		ll num=mul(mul(fc[n-1],fci[z-1]),mul(pot[n-z],fci[n-z]));
		ll res=mul(num,der[z]);
		cout<<z<<": "<<num<<"*"<<der[z]<<": "<<res<<"\n";
		ans=add(ans,res);
	}
	cerr<<ans<<"\n";
	ans=mul(ans,fpow(2,n));
	cout<<ans<<"\n";
	return 0;
}
