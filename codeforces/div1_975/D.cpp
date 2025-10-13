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

struct dat{
	ll sz;
	ii a,b; // even,odd
	// a: mx,c 
	dat():sz(0),a({0,0}),b({0,0}){}
	ll cant()const {return max(a.snd,b.snd);}
	ll full()const {return max(a.fst+a.snd,b.fst+b.snd);}
	ll diff()const {return full()-cant();}
	bool operator<(const dat &d) const {
		return diff()<d.diff();
	}
};
// void acum(ii &a, ll v){a.snd++,a.fst=max(a.fst,v);}
void acum(ii &a, ii b){a.fst=max(a.fst,b.fst),a.snd+=b.snd;}
dat merge(dat l, dat r){
	if(l.sz&1)swap(r.a,r.b);
	acum(l.a,r.a);
	acum(l.b,r.b);
	l.sz+=r.sz;
	return l;
}

const ll MAXN=2e5+5;
int uf[MAXN];
void uf_init(ll n){fore(i,0,n)uf[i]=-1;}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	assert(x!=y);
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		uf_init(n);
		vv a(n);
		vector<ii>sa(n);
		fore(i,0,n){
			cin>>a[i];
			sa[i]={a[i],i};
		}
		sort(ALL(sa));
		reverse(ALL(sa));
		vector<dat> d(n);
		set<pair<dat,ll>>st;
		ll res=0;
		ll sum=0; // de cants
		auto agr=[&](ll x){ // dado que d esta bien
			st.insert({d[x],x});
			sum+=d[x].cant();
			// cout<<"agrego "<<x<<"\n";
			
		};
		auto sac=[&](ll x){
			sum-=d[x].cant();
			// cout<<"saco "<<x<<"\n";
			st.erase({d[x],x});
		};
		auto cand=[&](ll mn){
			auto [d,i]=*st.rbegin();
			ll cur=sum+d.diff()+mn;
			res=max(res,cur);
			// cerr<<"cand "<<mn<<": "<<cur<<"\n";
			// for(auto [d,i]:st)cout<<"["<<i<<":"<<d.cant()<<","<<d.full()<<"] ";;cout<<"\n\n";
		};
		
		vv vis(n);
		auto mer=[&](ll i, ll j){ // i<j
			if(i<0||j>=n)return;
			if(!vis[i]||!vis[j])return;
			// cerr<<"mer "<<i<<" "<<j<<"\n";
			ll x=uf_find(i),y=uf_find(j);
			sac(x); sac(y);
			auto da=merge(d[x],d[y]);
			uf_join(x,y);
			ll p=uf_find(x);
			d[p]=da;
			agr(p);
		};
		for(auto [mn,i]:sa){
			acum(d[i].a,{a[i],1});
			d[i].sz++;
			assert(uf_find(i)==i);
			agr(i);
			
			vis[i]=1;
			mer(i-1,i);
			mer(i,i+1);
			cand(mn);
		}
		cout<<res<<"\n";
	}
	return 0;
}
