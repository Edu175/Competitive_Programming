#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto a:x)cout<<a<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll>  ii;
// vv pr;
const ll MAXV=2e5+5, MOD=998244353;
ll addm(ll a, ll b){a+=b; return a<MOD?a:a-MOD;}
ll mul(ll a, ll b){return a*b%MOD;}
// bool cr[MAXV];
// void init_cr(){
// 	fore(i,2,MAXV)if(!cr[i]){
// 		pr.pb(i);
// 		for(ll j=i*i;j<=MAXV;j+=i){
// 			cr[j]=1;
// 		}
// 	}
// }
// vv divs[MAXV];
// void init_divisores(){
// 	fore(i,1,MAXV)for(ll j=i;j<MAXV;j+=i){
// 		divs[j].pb(i);
// 	}
// }
ll res=0;
vv seq;
vv to(MAXV);
void f(ll v){
	ll cur=1;
	vv ts;
	for(ll i=SZ(seq)-1,j=0;i>=0;i--,j++)cur=mul(cur,max(to[seq[i]]-j,0ll));
	res=addm(res,cur);
	// cerr<<"cand "<<cur<<": ";show(seq)
	for(ll u=2*v;u<MAXV;u+=v){
		seq.pb(u);
		if(to[u]){
			f(u);
		}
		seq.pop_back();
	}
}
int main(){
	JET
	// init_cr();
	// init_divisores();
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n) cin>>a[i];
	for(ll i=n-2; i>=0; i--) a[i]=min(a[i],a[i+1]);
	// show(a)
	fore(v,1,MAXV)to[v]=n-(lower_bound(ALL(a),v)-a.begin());
	f(1);
	// fore(i,1,MAXV)if(to[i])cout<<to[i]<<" ";;cout<<" to\n";
	cout<<res<<"\n";
	
	return 0;
}