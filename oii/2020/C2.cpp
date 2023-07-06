#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=1e9+7;

//all squares should be covered
struct node{
	ll l,r,c,w; // left border, right, border, cantidad, width
	node(l,r){}
	node(vector<vector<ll>>h):h(h),w(1){}
	node():h(4,vector<ll>(4)),w(0){}
};
node oper(node a, node b){
	node r;
	if(a.w==1||b.w==1){
		fore(s,0,4)fore(e,0,4){
			if(!a.h[s][s]||!b.h[e][e])continue;
			ll &res=r.h[s][e];
			res++;
			if(!(s&1)&&!(e&1))r.h[s^1][e^1]++;
			if(!(s&2)&&!(e&2))r.h[s^2][e^2]++;
			if(s==0&&e==0)r.h[3][3]++;
		}
	}
	else{
		fore(l0,0,4)fore(r0,0,4)fore(l1,0,4)fore(r1,0,4){ //O(4**4=256)
			ll &res=r.h[l0][r1];
			res=a.h[l0][r0]*b.h[l1][r1]%MOD;
			ll s=r0,e=l1;
			if(!(s&1)&&!(e&1))res=res*2%MOD;
			if(!(s&2)&&!(e&2))res=res*2%MOD;
		}
	}
	r.w=a.w+b.w;
	return r;
}
node NEUT;

struct STree{
	vector<ll>t; ll n;
	STree(ll n):t(2*n+5,NEUT),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]=node(v);p>1;p>>=1)p^=p&1,t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(ll l, ll r){
		node izq,der;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)izq=oper(izq,t[l++]);
			if(r&1)der=oper(t[--r],der);
		}
		return oper(izq,der);
	}
};
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		
	}
	return 0;
}
