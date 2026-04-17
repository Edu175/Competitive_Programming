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
const ll MAXF=5e5+5;
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
	factos();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		set<ll> ban;
		fore(i,0,n)cin>>a[i],ban.insert(a[i]);
		ll p=n;
		ll l=p-1;
		ll bad=0;
		set<ll> put;
		ll free=0;
		ll res=1;
		fore(i,0,n){
			if(a[i]>p){
				bad=1;
				break;
			}
			if(a[i]==p){
				while(ban.count(l))l--;
				if(l<0){bad=1;break;}
				put.insert(l--);
				free++;
			}
			if(a[i]<p){
				ll now=n-p+1+free;
				res=mul(res,now);
				--p;
				ll used=0;
				while(put.count(p))p--,used++;
				if(p!=a[i]){bad=1;break;}
				ll cur=mul(nCr(free,used),fc[used]);
				// cout<<i<<": ";
				// cerr<<free<<" "<<used<<": "<<cur<<"\n";
				free-=used;
				res=mul(res,cur);
			}
		}
		ll rest=0;
		while(l>=0){
			rest+=!ban.count(l--);
		}
		res=mul(res,mul(nCr(rest+free,free),fc[free]));
		if(bad){
			cout<<"0\n";
			continue;
		}
		cout<<res<<"\n";
	}
	return 0;
}
