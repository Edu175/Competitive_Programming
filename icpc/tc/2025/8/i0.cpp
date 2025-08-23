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
	cut(c);
	return c;
}
ll inv(ll a){return pm(a,MOD-2);}
vv divide(vv a, vv b){
	cut(a);
	cut(b);
	// imp(a) cout<<"/ ";
	// imp(b) cout<<"= "<<endl;
	vv q,r=a;
	ll inve=inv(b.back());
	while(SZ(r)>=SZ(b)){
		q.pb(mul(r.back(),inve));
		if(q.back()) fore(i,0,SZ(b)){
			r[SZ(r)-i-1]=sub(r[SZ(r)-i-1],mul(q.back(),b[SZ(b)-i-1]));
		}
		r.pop_back();
	}
	reverse(ALL(q));
	// imp(q)
	// imp(r)
	assert(r==vv(1,0)||!SZ(r));
	return q;
}

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
	vv pol={1};
	fore(i,0,m)p[i]={1,0},pol=multiply(pol,p[i]);
	
	ll inv=pm(n,MOD-2);
	
	ll res=0;
	// imp(pol)
	
	for(auto [j,i]:all){
		pol=divide(pol,p[i]);
		// cout<<i<<" "<<j<<": ";
		// imp(pol)
		
		ll coef=m/2<SZ(pol)?pol[m/2]:0;
		
		ll cur=mul(coef,inv);
		ll val=mul(x[j],pm(v[i],MOD-2));
		cur=mul(cur,val);
		
		res=add(res,cur);
		
		p[i][0]=sub(p[i][0],inv);
		p[i][1]=add(p[i][1],inv);
		pol=multiply(pol,p[i]);
		
	}
	
	cout<<res<<"\n";
	return 0;
}