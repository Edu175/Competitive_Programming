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
const ll INF=4e18;
// Li-Chao Tree with given queries' x-coordinates
struct LiChao{ // for minimum (for maximum just change the sign of lines)
	vv xs; ll n; vector<ii> st;
	LiChao(vv xs):xs(xs),n(SZ(xs)),st(4*n+5,{0,INF}){}
	ll eval(ii l, ll x){return l.fst*x+l.snd;}
	void add(ii l){
		l.fst*=-1,l.snd*=-1;
		ll k=1,s=0,e=n;
		while(1){
			ll m=(s+e)/2;
			auto &v=st[k];
			if(eval(l,xs[m])<eval(v,xs[m]))swap(v,l);
			if(e-s==1)break;
			k*=2;
			if(l.fst<v.fst)s=m,k++;
			else e=m;
		}
	}
	ll eval(ll i){
		ll k=1,s=0,e=n,x=xs[i];
		ll res=eval(st[k],x);
		while(e-s>1){
			ll m=(s+e)/2;
			k*=2;
			if(i<m)e=m;
			else s=m,k++;
			res=min(res,eval(st[k],x));
		}
		return -res;
	}
};

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,D,s; cin>>n>>D>>s; s--; D++;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		map<ll,vv> mp;
		vv whe(n-1);
		fore(i,0,n-1){
			ll t; cin>>t;
			whe[i]=t;
		}
		vector<ii> sted_a; fore(i,0,n)sted_a.pb({a[i],i});
		vv pos_a(n);
		sort(ALL(sted_a));
		fore(i,0,n)pos_a[sted_a[i].snd]=i;
		vv xs; for(auto i:sted_a)xs.pb(i.fst);
		vv t(n);
		ll l=s,r=s,tim=1;
		while(l>0||r<n-1){
			ll tl=1e12,tr=1e12;
			if(l>0)tl=whe[l-1];
			if(r<n-1)tr=whe[r];
			if(tim<min(tl,tr))tim=min(tl,tr);
			if(tim>=tl)t[--l]=tim;
			if(tim>=tr)t[++r]=tim;
			tim++;
		}
		assert(t[s]==0);
		LiChao LL(xs),LR(xs),RL(xs),RR(xs);
		ll LLp=0,LRp=0,RLp=n-1,RRp=n-1;
		vector<ii> sted; fore(i,0,n)sted.pb({t[i],i});
		sort(ALL(sted)); reverse(ALL(sted));
		vv dp(n);
		vv sp(n+1);
		fore(i,0,n)sp[i+1]=sp[i]+a[i];
		auto incL=[&](ll tm, LiChao &L, ll &p, ll e){
			while(p<e&&t[p]+p>=tm)L.add({t[p]+p,dp[p]-sp[p+1]}),p++;
		};
		auto incR=[&](ll tm, LiChao &R, ll &p, ll e){
			while(p>e&&t[p]-p>=tm)R.add({t[p]-p,dp[p]+sp[p]}),p--;
		};
		auto izq=[&](auto &L, ll i){
			return -(t[i]+i)*a[i]+sp[i+1]+L.eval(pos_a[i]);
		};
		auto der=[&](auto &R, ll i){
			return -(t[i]-i)*a[i]-sp[i]+R.eval(pos_a[i]);
		};
		for(auto [ti,i]:sted){
			auto &res=dp[i]; res=-INF;
			if(ti<=D){
				res=(D-ti)*a[i];
			}
			if(i<=s){ // im in L
				incL(ti+i,LL,LLp,i);
				incR(ti-i,RL,RLp,s);
				ll curL=izq(LL,i);
				ll curR=der(RL,i);
				res=max({res,curL,curR});
			}
			if(i>=s){ // im in R
				incL(ti+i,LR,LRp,s);
				incR(ti-i,RR,RRp,i);
				ll curL=izq(LR,i);
				ll curR=der(RR,i);
				res=max({res,curL,curR});
			}
			// cout<<i<<" "<<ti<<": "<<res<<"\n";
		}
		ll res=dp[s];
		res-=a[s];
		cout<<res<<"\n";
	}
	return 0;
}
