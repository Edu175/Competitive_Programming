#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,tap=b;i<tap;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;
const ll MAXV=1e9+5;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<
ii,
null_type,
less<ii>,
rb_tree_tag,
tree_order_statistics_node_update>
indexed_set;

//LL cv(ll a, ll b){return (a<<30)^b};
ll qidx=0;
struct MSTree{ //lazy creation
	vector<indexed_set>mst; vector<ll> L,R; ll n;
	MSTree (ll n):mst(1),L(1,-1),R(1,-1),n(n){}
	MSTree(){}
	ll new_node(){
		ll ks=SZ(L);
		mst.pb({});
		L.pb(-1),R.pb(-1);
		return ks;
	}
	void upd(ll k, ll s, ll e, ll i, ll j, ll v){
		if(v==1)mst[k].insert({j,qidx++});
		if(v==-1)
			mst[k].erase(mst[k].find_by_order(mst[k].order_of_key({j,-1})));
		if(s+1==e)return;
		ll m=(s+e)/2;
		if(i<m){
			if(L[k]==-1){ll ls=new_node(); L[k]=ls;}
			upd(L[k],s,m,i,j,v);
		}
		else {
			if(R[k]==-1){ll rs=new_node(); R[k]=rs;}
			upd(R[k],m,e,i,j,v);
		}
	}
	ll query(ll k, ll s, ll e, ll i0, ll i1, ll j0, ll j1){
		if(k==-1||i1<=s||e<=i0)return 0;
		if(i0<=s&&e<=i1){
			return mst[k].order_of_key({j1,-1})-mst[k].order_of_key({j0,-1});
		}
		ll m=(s+e)/2;
		return query(L[k],s,m,i0,i1,j0,j1)+query(R[k],m,e,i0,i1,j0,j1);
	}
	void upd(ll i, ll j, ll v){upd(0,0,n,i,j,v);}
	ll query(ll i0, ll i1, ll j0, ll j1){return query(0,0,n,i0,i1,j0,j1);}
};
const ll MAXN=2e5+5;
ii a[MAXN];
ll h2;
MSTree mst(MAXV);
ii calc(ll s0, ll e0, ll s1, ll e1){
	ll des=mst.query(0,e0,s0+1,s1+1);
	ll apa=mst.query(e0,e1,s1+1,h2+1);
	return {des,apa};
}

int main(){FIN;
	ll n,q,h1,bas; cin>>n>>q>>h1>>h2>>bas;
	fore(i,0,n){
		ll l,r; cin>>l>>r;
		cin>>bas>>bas;
		a[i]={l,r};
		mst.upd(l,r,1);
	}
	ll s=0,e=h1;
	while(q--){
		char c; cin>>c;
		ll apa=0,des=0;
		if(c=='A'){
			ll id,l,r; cin>>id>>l>>r>>bas>>bas; id--;
			a[id]={l,r};
			mst.upd(l,r,1);
			if(l<e&&r>s)apa++;
		}
		else if(c=='D'){
			ll id; cin>>id; id--;
			ll l=a[id].fst,r=a[id].snd;
			if(l<e&&r>s)des++;
			mst.upd(l,r,-1);
		}
		else {
			ll si,ei; cin>>si; ei=si+h1;
			if(s<si){
				ii res=calc(s,e,si,ei);
				apa=res.snd;
				des=res.fst;
			}
			else {
				ii res=calc(si,ei,s,e);
				apa=res.fst;
				des=res.snd;
			}
			s=si,e=ei;
		}
		cout<<apa<<" "<<des<<"\n";
	}
	return 0;
}
