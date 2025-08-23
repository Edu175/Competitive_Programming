#include<bits/stdc++.h> 
#define fore(i,a,b) for(ll i=a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MOD=1e9+7,P=5782344;
ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}

ii __cv(ii a){
	auto [x,y]=a;
	return {x-2*y,x+2*y};
}
ii cv(ii a){
	auto [x,y]=__cv(a);
	return {-x,-y};
}

struct STree{
	vector<vector<ii>> t; ll n;
	STree(ll n):t(2*n+5),n(n){}
	void upd(ll p, ii v){
		for(p+=n;p>0;p>>=1)t[p].pb(v);
	}
	void sortit(){
		fore(i,0,2*n+3)sort(ALL(t[i]));
	}
	ll query(ll rx, ll ry){ // )
		// rx++;
		vv all;
		auto agr=[&](vector<ii> &v){
			for(auto [y,i]:v){
				if(y>=ry)break;
				all.pb(i);
			}
		};
		for(ll r=rx+n,l=n;l<r;l>>=1,r>>=1){
			if(l&1)agr(t[l++]);
			if(r&1)agr(t[--r]);
		}
		sort(ALL(all));
		ll pot=1,res=0;
		fore(j,0,SZ(all)){
			// cerr<<j<<"\n";
			res=add(res,mul(add(all[j],1),pot));
			pot=mul(pot,P);
		}
		return res;
	}
};

int main(){
	JET
	ll n,q; cin>>n>>q;
	vector<ii>a(n);
	
	vv vals;
	
	fore(i,0,n){
		ii p; cin>>p.fst>>p.snd;
		p=cv(p);
		vals.pb(p.fst);
		vals.pb(p.snd);
		a[i]=p;
	}
	sort(ALL(vals));
	vals.resize(unique(ALL(vals))-vals.begin());
	ll m=SZ(vals)+5;
	auto get_idx=[&](ll x){
		return lower_bound(ALL(vals),x)-vals.begin();
	};
	STree st(m);
	fore(idx,0,n){
		auto &i=a[idx];
		i.fst=get_idx(i.fst);
		i.snd=get_idx(i.snd);
		st.upd(i.fst,{i.snd,idx});
	}
	st.sortit();
	ll p=0;
	while(q--){
		ll a,b; cin>>a>>b;
		ii par;
		par.fst=-1-(p+a)%MOD;
		par.snd=(p+b)%MOD;
		par=cv(par);
		par.fst++;
		par.snd++;
		par.fst=get_idx(par.fst);
		par.snd=get_idx(par.snd);
		p=st.query(par.fst,par.snd);
		cout<<p<<"\n";
	}
	return 0;
}