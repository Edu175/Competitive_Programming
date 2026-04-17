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
const ll MAXV=1e6+5;
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
			if(pa==-1){upp[i]=MAXV-3;continue;}
			upp[i]=upp[pa];
		}
		
		vector<ii> rans;
		fore(i,0,n)if(!a[i])rans.pb({upp[i],low[i]});
		sort(ALL(rans)); reverse(ALL(rans));
		
		// for(auto [r,l]:rans)cout<<r<<","<<l<<" ";;cout<<"\n";
		
		ll m=SZ(rans);
		ll k=count(ALL(a),0)-1;
		vv elem(k);
		vector<ii> ev;
		fore(i,0,k)cin>>elem[i],ev.pb({elem[i],-i-1});
		vv ds(q);
		fore(i,0,q)cin>>ds[i],ev.pb({ds[i],i});
		sort(ALL(ev)); reverse(ALL(ev));
		
		priority_queue<ii> pq;
		vv fi(k,-1),se(k,-1),who(m,-1);
		vv at(q);
		ll po=0;
		fore(i,0,SZ(ev)){
			auto [val,idx]=ev[i];
			while(po<m&&val<rans[po].fst)
				pq.push({rans[po].snd,po}),po++;
			while(SZ(pq)&&pq.top().fst>=val)pq.pop(); // clean
			ll pri=-1;
			if(SZ(pq))pri=pq.top().snd;
			if(idx>=0){
				at[idx]=pri;
				continue;
			}
			idx=-idx-1;
			if(pri==-1){fg=0;break;}
			fi[idx]=pri; who[pri]=idx;
			pq.pop();
			if(SZ(pq))se[idx]=pq.top().snd;
		}
		if(!fg){
			fore(i,0,q)cout<<"NO\n";
			continue;
		}
		
		assert(m==k+1);
		vv to(m);
		fore(i,0,m){
			ll j=who[i];
			if(j==-1)to[i]=-1; // good terminal
			else if(se[j]==-1)to[i]=-2; // bad terminal
			else to[i]=se[j];
		}
		// fore(i,0,k)cout<<elem[i]<<": "<<fi[i]<<" "<<se[i]<<" elem\n";
		vv mem(m,-1);
		auto good=[&](ll x, auto &&good)-> ll {
			auto &res=mem[x];
			if(res!=-1)return res;
			ll p=to[x];
			if(p==-1)return res=1;
			if(p==-2)return res=0;
			return res=good(p,good);
		};
		
		fore(i,0,q){
			ll j=at[i];
			if(j!=-1&&good(j,good))cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	return 0;
}
