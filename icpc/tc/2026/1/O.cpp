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
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
ii operator-(ii a, ii b){return {a.fst-b.fst,a.snd-b.snd};}
ii operator*(ll t, ii a){return {t*a.fst,t*a.snd};}
ll sq(ll a){return a*a;}
ll norm2(ii a){return sq(a.fst)+sq(a.snd);}

int main(){FIN;
	ll n; cin>>n;
	vector<ii> a(2*n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	if(n==1){
		show(vv(n,1));
		return 0;
	}
	vv sig(2*n); // 0 is +, 1 is -
	ll id=n;
	vv ind={0,1};
	vector<vv> g(2*n);
	fore(i,2,n){
		ind.pb(i);
		ii mn={1e9,1e9}; ii wh={-1,-1}; ll wfg=0;
		fore(wi,0,3)fore(wj,wi+1,3)fore(fg,0,2){
			ii cur=a[ind[wi]]+(fg?-1:1)*a[ind[wj]];
			if(norm2(cur)<norm2(mn))mn=cur,wh={wi,wj},wfg=fg;
		}
		// cerr<<wh.fst<<","<<wh.snd<<" "<<wfg<<"\n";
		assert(wh.fst!=-1);
		sig[ind[wh.snd]]=wfg;
		ll qued=ind[3^wh.fst^wh.snd];
		a[id]=mn;
		g[id]={ind[wh.fst],ind[wh.snd]};
		ind={qued,id++};
	}
	if(norm2(a[ind[0]]-a[ind[1]])<norm2(a[ind[0]]+a[ind[1]])){
		sig[ind[1]]=1;
	}
	vv ans(2*n);
	for(ll i=id-1;i>=0;i--){
		ans[i]^=sig[i];
		for(auto j:g[i])ans[j]^=ans[i];
	}
	assert(norm2(a[ind[0]])<=sq(1e6));
	assert(norm2(a[ind[1]])<=sq(1e6));
	fore(i,0,n)cout<<(ans[i]?"-1 ":"1 ");;cout<<"\n";
	return 0;
}