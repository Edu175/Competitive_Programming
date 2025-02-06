#include<bits/stdc++.h>
#define fore(i,a,b) for( ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll INF=2e9;

typedef ii node;
node oper(node a, node b){return {a.fst+b.fst,a.snd+b.snd};}
node inv(node a, node b){return {a.fst-b.fst,a.snd-b.snd};}
node NEUT = {0,0};
struct STree{
	vector<node> st; vv L,R; ll n,rt;
	STree(ll n):st(1,NEUT),L(1,0),R(1,0),n(n),rt(0){}
	ll new_node(node v, ll l, ll r){
		ll ks=SZ(st);
		st.pb(v),L.pb(l),R.pb(r);
		return ks;
	}
	ll upd(ll k, ll s, ll e, ll p, node v){
		ll ks=new_node(st[k],L[k],R[k]);
		if(s+1==e){st[ks]=oper(st[ks],v);return ks;}
		ll m=(s+e)/2,ps;
		if(p<m)ps=upd(L[ks],s,m,p,v),L[ks]=ps;
		else ps=upd(R[ks],m,e,p,v),R[ks]=ps;
		st[ks]=oper(st[L[ks]],st[R[ks]]);
		return ks;
	}
	node query(ll k, ll s, ll e, ll a, ll b){
		if(a<=s&&e<=b) return st[k];
		if(e<=a || b<=s) return NEUT;
		ll m=(s+e)/2;
		return oper(query(L[k],s,m,a,b),query(R[k],m,e,a,b));
	}
	ll upd(ll k, ll p, node v) {return rt=upd(k,0,n,p,v);}
	ll upd(ll p, node v){return rt=upd(rt,p,v);}
	node query(ll k, ll a, ll b){return query(k,0,n,a,b);}
	
	ll get(ll h, ll k, ll q, ll s, ll e){
		if(e-s==1){
			ll cant=st[k].snd-st[h].snd;
			ll sum=st[k].fst-st[h].fst;
			// assert(cant<=1);
			return cant?min(q,cant)*(sum/cant):0;
		}
		ll rhs=st[R[k]].snd-st[R[h]].snd;
		ll sum=st[R[k]].fst-st[R[h]].fst;
		ll m=(s+e)/2;
		if(rhs<=q)return sum+get(L[h],L[k],q-rhs,s,m);
		return get(R[h],R[k],q,m,e);
	}
	ll get(ll h, ll k, ll q){return get(h,k,q,0,n);}
};

int main(){
	JET
	ll n,k,q; cin>>n>>k>>q;
	vv a(n),po(n),sp(n+1);
	fore(i,0,n)cin>>a[i];
	fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
	fore(i,0,n)po[i]=max(0ll,a[n-1-i]-a[i]);
	// for(auto i:po)cout<<i<<" ";;cout<<"\n";
	vv rts={0};
	STree st(INF);
	fore(i,0,n)rts.pb(st.upd(po[i],{po[i],1}));
	
	ll prev=0,m0=(n-1)/2,m1=(n)/2; // if odd same
	// cout<<m0<<" "<<m1<<"\n";
	while(q--){
		ll l,r; cin>>l>>r;
		l^=prev; r^=prev;
		ll res=0;
		// cout<<"query "<<l<<" "<<r<<"\n";
		if(l<=m0&&m1<=r){
			ll dl=m0-l,dr=r-m1;
			// cout<<dl<<" "<<dr<<"\n";
			if(dr>dl){
				res+=sp[m1+dl+1]-sp[l];
				l=m1+dl+1;
			}
			else {
				res+=sp[r+1]-sp[m0-dr];
				r=m0-dr-1;
			}
		}
		
		r++;
		// cout<<res<<": "<<l<<" "<<r<<" : "; cout<<endl;
		if(r==l){cout<<res<<"\n";prev=res;continue;}
		res+=sp[r]-sp[l];
		ll sum=st.get(rts[l],rts[r],k);
		// cout<<"get "<<l<<" "<<r<<" "<<k<<": "<<sum<<"\n";
		res+=sum;
		cout<<res<<"\n";
		prev=res;
		// cout<<endl;
	}
	return 0;
}