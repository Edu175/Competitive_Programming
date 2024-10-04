#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=998244353,MAXF=5e5+5;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
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
ll nCr(ll n, ll k){ //must call factos before
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}
ll solve(vector<ll>a){
	// imp(a);
	ll n=SZ(a)/2;
	ll b=0,c=0,d=0,e=0;
	fore(i,0,2*n){
		if(a[i]==-1)continue;
		if(a[i]<n)e++;
		else d++;
	}
	b=n-d,c=n-e;
	ll r=abs(b-e);
	// cout<<b<<" "<<c<<", "<<d<<" "<<e<<", "<<r<<": ";
	ll res=mul(mul(nCr(b,e),fc[e]),mul(nCr(c,d),fc[d]));
	res=mul(res,mul(fc[r],fc[r]));
	res=mul(res,fpow(2,r));
	return res;
}
int main(){FIN;
	factos();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(2*n),vis(2*n),idx(2*n);
		vector<ll>b;
		fore(i,0,n){
			ll x,y; cin>>x>>y;
			x--;y--;
			if(x!=-1&&y!=-1){
				vis[x]=vis[y]=1;
			}
			else {
				b.pb(x);
				b.pb(y);
			}
		}
		ll cnt=0;
		fore(i,0,2*n)if(!vis[i])idx[i]=cnt++;
		for(auto &i:b)if(i!=-1)i=idx[i];
		cout<<solve(b)<<"\n";
	}
	return 0;
}
