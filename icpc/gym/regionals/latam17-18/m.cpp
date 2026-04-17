#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#pragma GCC optimize("Ofast") // may lead to precision errors

#pragma GCC optimize("O3,unroll-loops")
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int mul(LL a, LL b){return a*b%MOD;}
int fpow(int a, LL b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
#define bint LL
struct Hash{
	bint MOD=1e9+7,P=1777771,PI=420604794;
	vector<bint>pi,h;
	Hash(){}
	Hash(vv s){
		assert((P*PI)%MOD==1);
		pi.resize(SZ(s)+1),h.resize(SZ(s)+1);
		pi[0]=1,h[0]=0;
		bint p=1;
		fore(i,1,SZ(s)+1){
			h[i]=(h[i-1]+s[i-1]*p)%MOD;
			pi[i]=(pi[i-1]*PI)%MOD;
			p=(p*P)%MOD;
		}
	}
	int get(ll s, ll e){
		return ((h[e]-h[s]+MOD)*pi[s])%MOD;
	}
};
const ll MAXN=1e5+5;
vv a[MAXN];
ll p[MAXN];
Hash h[MAXN];
struct coso{ll x;};
bool operator<(coso _i, coso _j){
	auto i=_i.x,j=_j.x;
	ll n=SZ(a[i]),m=SZ(a[j]);
	ll l=0,r=min(n-p[i],m-p[j]);
	assert(r>0);
	while(l<=r){
		ll d=(l+r)/2;
		if(h[i].get(p[i],p[i]+d)==h[j].get(p[j],p[j]+d))l=d+1;
		else r=d-1;
	}
	l--;
	// cout<<"less "<<i<<" "<<j<<": "<<p[i]<<" "<<p[j]<<": "<<n<<" "<<m<<": "<<l<<endl;
	// prefix is bad
	if(l+p[j]==m)return 0;
	if(l+p[i]==n)return 1;
	//done
	return a[j][l+p[j]]<a[i][l+p[i]];
}
int main(){ET;
	ll n; cin>>n;
	ll sum=0;
	priority_queue<coso>pq;
	fore(i,0,n){
		ll m; cin>>m;
		a[i].resize(m);
		fore(j,0,m)cin>>a[i][j];
		// reverse(ALL(a[i]));
		sum+=m;
	}
	fore(i,0,n){
		h[i]=Hash(a[i]);
		pq.push({i});
	}
	ll res=0;
	for(ll d=sum;d;d--){
		auto _i=pq.top(); pq.pop(); auto i=_i.x;
		ll v=a[i][p[i]];
		p[i]++;
		if(p[i]!=SZ(a[i]))pq.push({i});
		res=add(res,mul(v,fpow(365,d)));
	}
	cout<<res<<"\n";
}