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
const ll INF=1e6;
#define oper min
#define NEUT INF
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
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
};

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		// cout<<"\n";
		ll n; cin>>n;
		vv a(n),b(n),p(n,-1);
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,n){
			cin>>b[i],b[i]--;
			if(b[i]!=-1)p[b[i]]=i;
		}
		STree st(n);
		
		vv pos(n);
		vector<ii> sa;
		ll fg=1;
		for(ll i=n-1;i>=0;i--){
			ll x=a[i];
			pos[x]=min(n,st.query(x,st.n))-1;
			if(p[x]!=-1){
				fg&=p[x]<=pos[x];
				pos[x]=p[x];
			}
			st.upd(x,pos[x]);
			fg&=pos[x]>=0;
			if(p[x]==-1)sa.pb({pos[x],x});
		}
		cerr<<fg<<": ";
		sort(ALL(sa));
		ll w=0;
		for(auto [jhd,x]:sa){
			while(b[w]!=-1)w++;
			b[w]=x;
			fg&=w<=pos[x];
		}
		cerr<<fg<<": ";
		auto check=[&](){
			cout<<"check ";
			for(auto i:b)cout<<i+1<<" ";
			cout<<"\n";
			vv pos(n);
			fore(i,0,n)pos[b[i]]=i;
			ll fg=1;
			STree st(n);
			for(ll i=n-1;i>=0;i--){
				ll x=a[i];
				fg&=pos[x]<st.query(x,st.n);
				st.upd(x,pos[x]);
			}
			return fg;
		};
		fg&=check();
		if(fg==0)cout<<"-1\n";
		else {
			for(auto i:b)cout<<i+1<<" ";
			cout<<"\n";
		}
		auto check2=[&](){ // cuadratico
			set<ii>inva,invb;
			fore(i,0,n)fore(j,i+1,n)if(a[i]<a[j])inva.insert({a[i],a[j]});
			fore(i,0,n)fore(j,i+1,n)if(b[i]<b[j])invb.insert({b[i],b[j]});
			ll fg=1;
			imp(a)
			imp(b)
			for(auto i:inva){
				fg&=invb.count(i);
				if(!invb.count(i))cout<<"fail "<<i.fst<<","<<i.snd<<"\n";
			}
			if(fg)cout<<"Yes\n";
			else cout<<"No\n";
		};
		check2();
	}
	return 0;
}
