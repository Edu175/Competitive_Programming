#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a) cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
#define addig(a,b) a=add(a,b)
ll fpow(ll b, ll e){
	ll res=1;
	for(;e;e>>=1,b=mul(b,b))if(e&1)res=mul(res,b);
	return res;
}
ll inv(ll a){return fpow(a,MOD-2);}

int main(){
    JET
	ll n,k,t; cin>>n>>k>>t;
	map<vv,ll> dp;
	dp[vv(n,1)]=1;
	vv fc(n+1,1); fore(i,1,SZ(fc))fc[i]=mul(fc[i-1],i);
	vv fci(n+1,1); fore(i,1,SZ(fci))fci[i]=mul(fci[i-1],inv(i));
	
	// dp[{4}]=1;
	fore(_,0,k){
		map<vv,ll> prox;
		for(auto [a,now]:dp){
			fore(i,0,SZ(a)){
				fore(c,1,a[i]){
					auto b=a; b[i]=c; b.pb(a[i]-c);
					sort(ALL(b));
					addig(prox[b],mul(now,a[i]));
				}
				fore(j,i+1,SZ(a)){
					auto b=a; b.erase(b.begin()+j);
					b[i]=a[i]+a[j];
					ll coef=mul(2,mul(a[i],a[j]));
					sort(ALL(b));
					addig(prox[b],mul(now,coef));
				}
			}
		}
		swap(dp,prox);
		for(auto &i:dp)i.snd=mul(i.snd,(MOD+1)/2);
		// cout<<"vuelta "<<_<<"\n";
		// for(auto [a,b]:dp)cout<<a<<": "<<b<<"\n";
	}
	// return 0;
	while(t--){
		vv a(n); fore(i,0,n)cin>>a[i],a[i]--;
		vv zs;
		vv vis(n);
		fore(x,0,n)if(!vis[x]){
			ll z=0;
			for(ll y=x;!vis[y];y=a[y])vis[y]=1,z++;
			zs.pb(z);
		}
		sort(ALL(zs));
		ll coef=fc[n];
		for(auto z:zs)coef=mul(coef,fci[z]);
		coef=mul(coef,fci[SZ(zs)]);
		// cerr<<"coef "<<coef<<"\n";
		for(auto z:zs)coef=mul(coef,fc[z-1]);
		// cerr<<"coef "<<coef<<"\n";
		ll res=dp[zs];
		res=mul(res,inv(coef)); // every same partition permutation is counted in dp, there are coef of them
		
		// cerr<<"query "<<a<<": "<<zs<<": ";
		cout<<res<<"\n";
	}
    return 0;
}
