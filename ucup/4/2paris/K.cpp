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
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
typedef ii node;
ll inv(ll a){return fpow(a,MOD-2);}
node oper(node a, node b){
	a.fst+=b.fst;
	a.snd=mul(a.snd,b.snd);
	return a;
}
node rang(node a, node b){ // left, right
	b.fst-=a.fst;
	b.snd=mul(b.snd,inv(a.snd));
	return b;
}
node NEUT={0,1};
struct STree{ //persistent
	vector<node>st;
	vv L,R; ll n,rt;
	STree(ll n): st(1,NEUT),L(1,0),R(1,0),n(n),rt(0){}
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
	// node query(ll k, ll s, ll e, ll a, ll b){
	// 	if(a<=s&&e<=b)return st[k];
	// 	if(e<=a||b<=s)return NEUT;
	// 	ll m=(s+e)/2;
	// 	return oper(query(L[k],s,m,a,b),query(R[k],m,e,a,b));
	// }
	// node query(ll k, ll a, ll b){return query(k,0,n,a,b);}
	
	vv rts={0};
	ll upd(ll k, ll p, node v){return rt=upd(k,0,n,p,v);} // update on root k (first root is 0)
	ll upd(ll p, node v){ // update on last root
		ll cur=upd(rt,p,v);
		rts.pb(cur);
		return cur;
	}
	
	ll get(ll l, ll r, ll v){ // k,x
		ll s=0,e=n;
		ll k=rts[l], x=rts[r];
		node all=rang(st[k],st[x]);
		if(all.fst<=v)return 1;
		// busco primera pos que al agregarlo sea >v
		ll prod=1; // de la parte derecha
		while(1){
			if(e-s==1){
				node cur=rang(st[k],st[x]);
				assert(cur.fst>v);
				ll u=cur.snd-v;
				assert(u>=1);
				// cout<<"hoja "<<prod<<" "<<v<<" "<<s<<"\n";
				// cout<<cur.fst<<","<<cur.snd<<"\n";
				prod=mul(prod,u);
				break;
			}
			ll m=(s+e)/2;
			node gol=rang(st[L[k]],st[L[x]]);
			node gor=rang(st[R[k]],st[R[x]]);
			if(gol.fst<=v){ // voy para la derecha
				v-=gol.fst;
				s=m;
				k=R[k]; x=R[x];
			}
			else { // voy para la izquierda
				prod=mul(prod,gor.snd);
				e=m;
				k=L[k]; x=L[x];
			}
		}
		return prod;
	}
};

int main(){FIN;
	ll n,q; cin>>n>>q;
	vector<ll> a(n);
	vector<ii> sa;
	fore(i,0,n)cin>>a[i],sa.pb({a[i],i});
	vv pos(n);
	sort(ALL(sa));
	fore(i,0,n)pos[sa[i].snd]=i;
	
	STree st(n);
	fore(i,0,n)st.upd(pos[i],{a[i]-1,a[i]});
	
	while(q--){
		ll l,r,v; cin>>l>>r>>v; l--;
		ll res=st.get(l,r,v);
		cout<<res<<"\n";
	}
	return 0;
}
