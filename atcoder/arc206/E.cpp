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
const ll INF=1e18;
ll sum(ii a){return a.fst+a.snd;}
ll get(vv u, vv d, vv l, vv r){
	sort(ALL(l)); sort(ALL(r));
	ll fij=l[0]+l[1]+r[0]+r[1];
	ll n=SZ(u);
	vv mns(n+1,INF);
	for(ll i=n-1;i>=0;i--){
		mns[i]=min(mns[i+1],d[i]);
	}
	vector<ii> mnp(n+1,{INF,INF}); // de d
	fore(i,0,n){
		auto &cur=mnp[i+1];
		cur=mnp[i];
		ii cand={d[i],mns[i+1]};
		if(sum(cand)<sum(cur))cur=cand;
	}
	ll res=INF,mn=INF;
	fore(i,0,n){
		ll p=min(i+2,n);
		ll cur=mn+u[i]+sum(mnp[p]);
		res=min(res,cur);
		mn=min(mn,u[i]);
	}
	return res+fij;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv u(n-2),d=u,l=u,r=u;
		fore(i,0,n-2)cin>>u[i];
		fore(i,0,n-2)cin>>d[i];
		fore(i,0,n-2)cin>>l[i];
		fore(i,0,n-2)cin>>r[i];
		ll res0=get(u,d,l,r);
		reverse(ALL(l));
		reverse(ALL(r));
		ll res1=get(l,r,u,d);
		ll res=min(res0,res1);
		cout<<res<<"\n";
	}
	return 0;
}
