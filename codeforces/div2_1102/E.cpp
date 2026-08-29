#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=1e9+7,MAXF=5e6+5;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int b, ll e){
	if(e<0)return 0;
	int r=1;
	for(;e;e>>=1,b=mul(b,b))if(e&1)r=mul(r,b);
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
	factos();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n+2);
		fore(i,1,n+1)cin>>a[i];
		n+=2;
		vv l(n),r(n);
		fore(i,0,n)l[i]=i-1,r[i]=i+1;
		queue<ll> q;
		auto agr_if=[&](ll i){
			if((r[i]-i)*(i-l[i])==a[i])q.push(i);
		};
		fore(i,0,n)agr_if(i);
		vv per(n);
		ll cant=0,bad=0;
		ll res=1;
		while(SZ(q)){
			auto i=q.front(); q.pop();
			ll cl=(i-l[i]);
			ll cr=(r[i]-i);
			if(cr*cl!=a[i]){bad=1;break;}
			cl--,cr--;
			ll cur=nCr(cl+cr,cl);
			// cerr<<i<<": "<<l[i]<<" "<<r[i]<<": "<<cl<<" "<<cr<<": "<<cur<<"\n";
			res=mul(res,cur);
			cant++;
			l[r[i]]=l[i];
			r[l[i]]=r[i];
			agr_if(l[i]);
			agr_if(r[i]);
		}
		if(cant<n-2)bad=1;
		if(bad){
			cout<<"0\n";
			continue;
		}
		cout<<res<<"\n";
	}
	return 0;
}
