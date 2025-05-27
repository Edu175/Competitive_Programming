#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e10;
struct STree{
	ll n,NEUT;
	vv t;
	vector<ll> vals;
	ll oper(ll i, ll j){ // idx of max
		return vals[i]>vals[j]?i:j;
	}
	STree(vv ini):n(SZ(ini)),NEUT(n),t(2*n+5,NEUT),vals(ini){
		vals.pb(-INF);
		// fore(i,0,n)t[n+i]=i;
		// for(ll i=n-1;i>=0;i--)t[i]=oper(t[2*i],t[2*i+1]);
	}
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
ll sq(ll a){return a*a;}
int main(){
    JET
	ll q; cin>>q;
	vector<array<ll,3>>qs(q);
	vector<ii>sa;
	fore(i,0,q){
		ll ty,x,y; cin>>ty>>x>>y;
		sa.pb({x,i});
		qs[i]={ty,x,y};
	}
	sort(ALL(sa));
	vv pos(q);
	fore(i,0,q)pos[sa[i].snd]=i;
	vv vals(q,-INF);
	fore(i,0,q){
		auto [ty,x,y]=qs[i];
		if(ty==1)vals[pos[i]]=x+y;
	}
	STree st(vals);
	fore(i,0,q){
		auto [ty,x,y]=qs[i];
		if(ty==1)vals[pos[i]]=-(x-y);
	}
	auto good=[&](ll i, ll j){ // j circulo
		assert(j<q);
		assert(qs[i][0]==2&&qs[j][0]==1);
		return sq(qs[i][1]-qs[j][1])+sq(qs[i][2]-qs[j][2]) < 
			sq(qs[j][2]);
	};
	STree stNeg(vals);
	auto my_upd=[&](ll i, bool pongo){
		ll v=pongo?pos[i]:q; // NEUT
		st.upd(pos[i],v);
		stNeg.upd(pos[i],v);
	};
	fore(i,0,q){
		auto [ty,x,y]=qs[i];
		if(ty==1)my_upd(i,1);
		else {
			ll ans=-1;
			auto cand=[&](ll j){
				if(good(i,j))ans=j;
			};
			auto doit=[&](ll fg){
				vv volve;
				while(1){
					ll p;
					auto &S=(fg?stNeg:st);
					if(!fg)p=st.query(0,pos[i]);
					else p=stNeg.query(pos[i]+1,q);
					if(p==q)break; // NEUT
					ll ip=sa[p].snd;
					ll bad=S.vals[p]<=(fg?-1:1)*qs[i][1];
					if(bad)break;
					cand(ip);
					my_upd(ip,0);
					volve.pb(ip);
				}
				for(auto i:volve)if(i!=ans)my_upd(i,1);
				volve.clear(); //
			};
			doit(0);
			if(ans==-1)doit(1);
			if(ans!=-1)ans++;
			cout<<ans<<"\n";
		}
	}
	return 0;
}