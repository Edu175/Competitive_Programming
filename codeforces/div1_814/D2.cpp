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
const ll INF=1e9;;
#define maxig(a,b) a=max(a,b)
#define minig(a,b) a=min(a,b)
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		vv p(n),pos(n);
		fore(i,0,n)cin>>p[i],p[i]--,pos[p[i]]=i;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		
		vv fa(n,-1);
		set<ll> st;
		for(ll x=n-1;x>=0;x--){
			ll i=pos[x];
			auto it=st.insert(i).fst;
			ll l=-1,r=-1;
			if(next(it)!=st.end())r=*next(it);
			if(it!=st.begin())l=*prev(it);
			ll to=l;
			if(l==-1||(r!=-1&&p[r]<p[l]))to=r;
			fa[i]=to;
		}
		
		vv upp(n),low(n);
		fore(x,0,n){
			ll i=pos[x];
			if(a[i])low[i]=a[i];
			if(fa[i]!=-1)maxig(low[fa[i]],low[i]);
		}
		ll fg=1;
		for(ll x=n-1;x>=0;x--){
			ll i=pos[x],pa=fa[i];
			if(pa!=-1&&a[pa]&&a[i])fg&=a[pa]>a[i];
			if(a[i]){upp[i]=a[i];continue;}
			if(pa==-1){upp[i]=INF;continue;}
			upp[i]=upp[pa];
		}
		
		vector<ii> rans;
		fore(i,0,n)if(!a[i])rans.pb({low[i],upp[i]}),fg&=low[i]<=upp[i];
		
		// for(auto [r,l]:rans)cout<<r<<","<<l<<" ";;cout<<"\n";
		
		ll m=SZ(rans);
		ll k=count(ALL(a),0)-1;
		vv elem(k);
		fore(i,0,k)cin>>elem[i];
		auto greedy=[&](ll neg){ // last d that works, first that I need
			if(neg){
				for(auto &i:elem)i=-i;
				for(auto &[l,r]:rans)l=-l,r=-r,swap(l,r);
			}
			sort(ALL(elem));
			sort(ALL(rans));
			ll res=0; ll did=0;
			ll po=0;
			priority_queue<ll> pq;
			elem.pb(INF+5);
			for(auto val:elem){
				while(po<m&&rans[po].fst<val)pq.push(-rans[po++].snd);
				while(SZ(pq)&&-pq.top()<=val){
					if(!did)res=-pq.top(),did=1;
					else {fg=0;break;}
					pq.pop();
				}
				if(val>=INF)break;
				if(!SZ(pq))fg=0;
				else pq.pop();
			}
			elem.pop_back();
			if(neg)res=-res;
			return res;
		};
		ll R=greedy(0),L=greedy(1);
		// cerr<<L<<","<<R<<"\n";
		fore(i,0,q){
			ll d; cin>>d;
			if(fg&&L<=d&&d<=R)cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	return 0;
}
