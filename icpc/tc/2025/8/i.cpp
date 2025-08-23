#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(r) {for(auto i:r)cout<<i<<" ";;cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=1e9+7;
ll add(ll a, ll b){a+=b; if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b; if(a<0)a+=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
ll pm(ll n, ll e){
	ll r=1;
	while(e){if(e&1)r=mul(r,n); n=mul(n,n); e>>=1;}
	return r;
}

bool frac(ii a, ii b){return a.fst*b.snd<b.fst*a.snd;}

void cut(vv &r){
	while(SZ(r)>1&&!r.back())r.pop_back();
}
vv multiply(vv a, vv b){
	vv c(SZ(a)+SZ(b)-1);
	fore(i,0,SZ(a))fore(j,0,SZ(b)){
		c[i+j]=add(c[i+j],mul(a[i],b[j]));
	}
	// cut(c);
	return c;
}
// ll inv(ll a){return pm(a,MOD-2);}
vv NEUT={1};
#define oper multiply
struct STree{
	vector<vv>t; ll n;
	STree(ll n):t(2*n+5),n(n){}
	void upd(ll p, vv v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	vv query(ll l, ll r){
		vv res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};
int main(){
	JET
	ll n,m; cin>>n>>m;
	vv x(n);
	fore(i,0,n)cin>>x[i],x[i]*=-1;
	vv v(m);
	fore(i,0,m)cin>>v[i];
	vector<ii>all;
	fore(i,0,n)fore(j,0,m)all.pb({i,j});
	sort(ALL(all),[&](ii a, ii b){
		ii f0={x[a.fst],v[a.snd]};
		ii f1={x[b.fst],v[b.snd]};
		return frac(f0,f1);
	});
	
	vector<vv>p(m);
	STree st(n);
	fore(i,0,m)p[i]={0,1},st.upd(i,p[i]);
	
	ll inv=pm(n,MOD-2);
	
	ll res=0;
	// imp(pol)
	ll prev=0;
	for(auto [j,i]:all){
		// cout<<i<<" "<<j<<": ";
		// imp(pol)
		ll val=mul(x[j],pm(v[i],MOD-2));
		ll dif=sub(val,prev);
		prev=val;
		ll prob=
		ll idx=(m+1)/2;
		ll coef=idx<SZ(pol)?pol[idx]:0;
		
		p[i][0]=add(p[i][0],inv);
		p[i][1]=sub(p[i][1],inv);
		
	}
	
	cout<<res<<"\n";
	return 0;
}