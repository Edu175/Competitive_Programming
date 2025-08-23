#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

#define oper max
ll NEUT=-1;

struct STree{
	vector<ll>t; ll n;
	STree(ll n):t(2*n+5),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	ll query(ll l, ll r){
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};

int main(){
	JET
	ll n; cin>>n;
	vv h(n+1);
	ll mx=0;
	fore(i,1,n+1)cin>>h[i],mx=max(mx,h[i]);
	ll q; cin>>q;
	vv L(q),R(q),W(q),lo(q),hi(q);
	auto mid=[&](ll idx){
		return lo[idx]+hi[idx]/2;
	};
	vector<array<ll,3>> ev;
	fore(idx,0,q){
		ll l,r,w; cin>>l>>r>>w; r++; // indexado desde 1
		L[idx]=l;
		R[idx]=r;
		W[idx]=w;
		lo[idx]=0,hi[idx]=mx+5;
		ev.pb({mid(idx),0,idx});
	}
	// ll sigo=1;
	while(SZ(ev)){
		// cout<<"\n\nlevel\n";
		fore(i,1,n+1)ev.pb({h[i],1,i});
		sort(ALL(ev));
		// sigo=0;
		STree seg(n+5); // asignar
		set<ll>st={0,n+1};
		seg.upd(0,n);
		vector<array<ll,3>>prox;
		for(auto [t,ty,idx]:ev){
			if(ty==1){
				// cout<<"idx: "<<idx<<""<<endl;
				// cout<<"st: ";
				// for(auto i:st)cout<<i<<" ";;cout<<endl;
				auto it=st.lower_bound(idx);
				assert(*it!=idx);
				ll s=*prev(it);
				ll e=*(it);
				seg.upd(s,idx-s-1);
				seg.upd(idx,e-idx-1);
				st.insert(idx);
				// cout<<"upd "<<t<<" "<<idx<<"\n";
			}
			else {
				ll l=L[idx],r=R[idx],w=W[idx];
				auto &Lo=lo[idx];
				auto &Hi=hi[idx];
				ll e=*prev(st.upper_bound(r));
				ll s=*(st.lower_bound(l));
				ll cur=0;
				if(s>=r)cur=r-l;
				else {
					cur=max({s-l,r-e-1,seg.query(s,e)});
				}
				// cout<<"query "<<t<<" "<<idx<<" "<<w<<": "<<cur<<"\n";
				if(cur>=w)Lo=t+1;
				else Hi=t-1;
				if(Lo<=Hi){
					// sigo=1;
					prox.pb({(Lo+Hi)/2,0,idx});
				}
			}
		}
		swap(ev,prox);
	}
	fore(i,0,q)cout<<hi[i]<<"\n";
	return 0;
}


