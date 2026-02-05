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
ll MOD;
const ll MAXF=1e6+5;
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
void factos(ll M){
	fc[0]=1;
	fore(i,1,M)fc[i]=mul(fc[i-1],i);
	fci[M-1]=fpow(fc[M-1],MOD-2);
	for(ll i=M-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}
ll nCr(ll n, ll k){ // must call factos before
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m>>MOD;
		factos(2*n);
		ll p=fpow(m,MOD-2);
		ll dob=0;
		ll tot=fpow(m,n);
		fore(sum,0,n+1)fore(bl,0,2)fore(br,0,2){
			ll rest=n-sum;
			ll bo=(!bl&&!br);
			ll mv=sum+1-bl-br;
			if(mv<=0)continue;
			ll num=mul(mv,nCr(rest+2-1-bo,2));
			ll cur=mul(num,fpow(p,sum));
			dob=add(dob,cur);
			cerr<<"sum "<<sum<<" bl "<<bl<<" br "<<br<<" rest "<<rest<<": "<<num<<": "<<mul(cur,tot)<<"\n";
		}
		cerr<<"dob "<<mul(dob,tot)<<"\n";
		ll same=0,sol=0; // sol is only diff
		fore(mx,0,n+1)fore(b,0,2){
			ll z=!b+2*mx;
			ll slide=n+1-z;
			if(slide<=0||(b&&mx==0))continue;
			ll otr=mx+1 -1-b;
			ll cur=mul(slide,fpow(p,mx));
			sol=add(sol,mul(otr,cur));
			same=add(same,cur);
			cout<<mx<<" "<<b<<": "<<cur<<": "<<mul(mul(otr,cur),tot)<<"\n";
		}
		cerr<<"sol "<<mul(sol,tot)<<"\n";
		cerr<<"same "<<mul(same,tot)<<"\n";
		ll res=add(dob,sol);
		res=mul(res,2);
		res=add(res,same);
		cerr<<mul(res,tot)<<"\n";
		cout<<res<<"\n";
	}
	return 0;
}
