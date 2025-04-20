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
typedef ll node;
struct STree{
	int n,ty; node NEUT; vector<node>t;
	#define oper(a,b) ty?max(a,b):min(a,b)
	STree(int N, int ty):n(2<<__lg(N)),ty(ty),NEUT(ty?0:n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
	int find(int k, int s, int e, int a, int b, int x){
		if(e<=a||b<=s) return -1; // -1 es que no lo encontre
		// push(k,s,e); para lazy
		int m = (s+e)/2;
		bool bad=t[k]>=x; // bad es que no lo va a encontrar en este subarbol
		if(bad&&(a<=s&&e<=b))return -1;
		if(e-s==1)return s;
		int res=find(2*k,s,m,a,b,x);
		if(res==-1)res=find(2*k+1,m,e,a,b,x);
		return res; // cuando lo encuentra devuelve algo != -1
	}
	int find(int a, int b, int x){return find(1,0,n,a,b,x);}
};

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n),b(n),p(n,-1),pa(n,-1);
		fore(i,0,n)cin>>a[i],a[i]--,pa[a[i]]=i;
		fore(i,0,n){
			cin>>b[i],b[i]--;
			if(b[i]!=-1)p[b[i]]=i;
		}
		STree st0(n,0),st1(n,1);
		vv l(n),r(n); // [,)
		for(ll i=n-1;i>=0;i--){
			ll x=a[i];
			r[i]=min(n,st0.query(x,n));
			if(p[x]!=-1)st0.upd(x,p[x]);
		}
		ll fg=1;
		fore(i,0,n){
			ll x=a[i];
			l[i]=st1.query(0,x),fg&=l[i]<r[i];
			if(p[x]!=-1)st1.upd(x,p[x]);
		}
		// fore(i,0,n){
		// 	cout<<i<<": "<<l[i]<<","<<r[i]<<" "<<p[a[i]]<<"\n";
		// }
		if(!fg){
			cout<<"-1\n";
			continue;
		}
		set<ll>st;
		ll t=0;
		multiset<ii>ms;
		vector<ll> h[n+1];
		auto cand=[&](ll i){ms.insert({r[i],i});};
		auto add=[&](ll i){
			if(l[i]<=t)cand(i);
			else h[l[i]].pb(i);
		};
		
		STree de(n,0); // descenso
		fore(i,0,n)if(p[a[i]]==-1)de.upd(i,a[i]);
		// fore(i,0,n)cout<<de.t[i+de.n]<<" ";;cout<<"\n";
		auto esc=[&](ll from){
			// cout<<"esc "<<from<<": ";
			while(1){
				ll j=de.find(from+1,n,from==-1?de.NEUT:a[from]);
				if(j==-1||st.count(j))break;
				from=j;
				st.insert(j);
				add(j);
				// cout<<j<<" ";
			}
			// cout<<"\n";
		};
		esc(-1);
		while(t<n){
			for(auto i:h[t])cand(i);
			if(b[t]==-1){
				// cout<<"pongo en "<<t<<":\n";
				// imp(st)
				if(!SZ(ms)){fg=0;break;}
				ll i=ms.begin()->snd; ms.erase(ms.begin());
				b[t]=a[i];
				de.upd(i,de.NEUT);
				fg&=t<r[i];
				// if(!fg)cout<<"fail\n";
				ll from=-1;
				auto it=st.lower_bound(i); assert(*it==i);
				if(it!=st.begin())from=*prev(it);
				// cout<<i<<"\n\n";
				esc(from);
				st.erase(it);
			}
			t++;
		}
		fore(i,0,n)if(b[i]!=-1)p[b[i]]=i;
		fore(x,0,n){
			ll i=pa[x];
			fg&=l[i]<=p[x]&&p[x]<r[i];
		}
		if(!fg)cout<<"-1\n";
		else {
			for(auto i:b)cout<<i+1<<" ";
			cout<<"\n";
		}
	}
	return 0;
}
