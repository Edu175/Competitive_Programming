#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,szokput=b;i<szokput;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<endl;}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;
ll MOD;
ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=mul(res,b);
		b=mul(b,b); e>>=1;
	}
	return res;
}
ll pot(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res*=b;
		b*=b; e>>=1;
	}
	return res;
}
struct info{
	ll i,g,val;
};
vector<info> posl[MAXN],posr[MAXN];
int main(){FIN;
	ll n,q; cin>>n>>q>>MOD;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	auto lam=[&](vector<info>* pos){
		for(ll i=n-1;i>=0;i--){
			auto &v=pos[i];
			if(i<n-1)v=pos[i+1];
			v.insert(v.begin(),{i,0});
			vector<ii>u;
			fore(j,0,SZ(v)){
				v[j].snd=gcd(v[j].snd,a[i]);
				if(!SZ(u)||v[j].snd!=u.back().snd)u.pb(v[j]);
			}
			v=u;
			// v.pb({n,-1});
		}
	};
	vector<ll>sp(n+1,1);
	fore(i,1,n+1){
		sp[i]=mul(sp[i-1],a[i-1]);
	}
	imp(sp);
	while(q--){
		ll l,r; cin>>l>>r; l--;
		ll res=1;
		fore(i,0,sz)res=mul(res,fpow(ps[i],st[i].query(l,r)));
		cout<<"\n"<<res<<"\n";
		res=mul(res,sp[r]);
		res=mul(res,inv(sp[l]));
		
		ll gs=1;
		auto &v=dif[l];
		fore(i,0,SZ(v)){
			ll idx=v[i].fst;
			if(idx>=r)break;
			ll nxt=i==SZ(v)-1?n:v[i+1].fst;
			nxt=min(nxt,r);
			gs=mul(gs,fpow(v[i].snd,nxt-idx));
		}
		res=mul(res,inv(gs));
		cout<<res<<"\n";
	}
	return 0;
}