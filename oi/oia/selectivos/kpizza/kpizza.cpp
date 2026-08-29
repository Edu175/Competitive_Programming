#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int morder(int i); // Puede llamar a esta funcion en su implementacion de kpizza

ll lgt(ll n){
	assert(n);
	if(n==1)return 0;
	return __lg(n-1)+1;
}

int kpizza(int N) {
	ll n=N;
	vv divs;
	fore(i,1,n+1)if(n%i==0)divs.pb(i);
	vector<array<ll,3>> all; // [l,r) -> m for r-l>1
	vv rs(n+1,-1); // [i, rs[i])
	vv vals(n+1);
	fore(i,1,n+1){
		ll p=lower_bound(ALL(divs),i)-divs.begin();
		ll cant=SZ(divs)-p;
		vals[i]=lgt(cant);
		rs[i]=i+1;
	}
	vv le(n+2,-1); // inverse of rs
	fore(i,1,n+1)le[rs[i]]=i;
	priority_queue<array<ll,3>> pq;
	auto get_val=[&](ll l){
		return 1+max(vals[l],vals[rs[l]]);
	};
	auto agr=[&](ll l){ // a merge of l and rs[l]
		ll r=rs[l];
		if(r==-1||r>n)return;
		ll val=get_val(l);
		pq.push({-val,l,r});
	};
	fore(i,1,n+1)agr(i);
	while(SZ(pq)){
		auto [val,l,r]=pq.top(); pq.pop(); val=-val;
		if(rs[l]!=r||val!=get_val(l))continue;
		ll ri=rs[r];
		all.pb({l,ri,r});
		rs[r]=-1; le[r]=-1;
		vals[l]=val;
		rs[l]=ri; le[ri]=l;
		agr(l);
		if(le[l]!=-1)agr(le[l]);
	}
	assert(rs[1]==n+1);
	assert(count(ALL(rs),-1)==n);
	// cerr<<"worst case in theory: "<<vals[1]+1<<"\n";
	sort(ALL(all));
	auto getm=[&](ll l, ll r){
		array<ll,3> key={l,r,-1};
		auto ptr=lower_bound(ALL(all),key);
		assert(ptr!=all.end()&&(*ptr)[0]==l&&(*ptr)[1]==r);
		return (*ptr)[2];
	};
	ll rt=morder(0);
	ll l=1,r=n+1;
	while(r-l>1){
		ll m=getm(l,r);
		if(morder(m-1)==rt)l=m;
		else r=m;
	}
	ll z=l;
	ll lo=lower_bound(ALL(divs),z)-divs.begin(),hi=SZ(divs);
	while(hi-lo>1){
		ll mid=(lo+hi)/2;
		if(morder(n-(divs[mid]-z))==rt)lo=mid;
		else hi=mid;
	}
	ll res=divs[lo];
	return n/res;
}
