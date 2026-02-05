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
const ll MAXV=1e5+5,MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(ll a, ll b, ll m=MOD){
	if(b<0)return 0;
	ll r=1;
	while(b){if(b&1)r=r*a%m; b>>=1; a=a*a%m;}
	return r;
}
int mu[MAXV] = {0,1};
vector<ll> divs[MAXV];
ll phi[MAXV],cr[MAXV];
void init_all(){
	mset(cr,-1);
	fore(i,1,MAXV){
		if(mu[i])for(int j=i+i;j<MAXV;j+=i){
			mu[j]-=mu[i];
		}
		for(int j=i;j<MAXV;j+=i)divs[j].pb(i);
		phi[i]+=i;
		for(int j=2*i;j<MAXV;j+=i)phi[j]-=phi[i];
		if(i>=2&&cr[i]<0)for(ll j=1ll*i*i;j<MAXV;j+=i)cr[j]=i;
	}
}
map<int,int> fact(int n){
	map<int,int> res;
	while(cr[n]>=0)res[cr[n]]++,n/=cr[n];
	if(n>1)res[n]++;
	return res;
}
ll ord(ll m){ // ord_m(10), (0 if m==1) O(log^2)
	if(m==1)return 0;
	ll x=phi[m];
	for(auto [p,e]:fact(x)){
		while(x%p==0&&fpow(10,x/p,m)==1)x/=p;
	}
	return x;
}
#define addig(a,b) a=add(a,b)
ll cf(ll d, ll x){
	ll res=0;
	while(x%d==0)x/=d,res++;
	return res;
}
ll sac10(ll x){
	while(x%2==0)x/=2;
	while(x%5==0)x/=5;
	return x;
}
int main(){FIN;
	init_all();
	ll n; cin>>n;
	vv a(n),hist(MAXV);
	vector<vv> he(20,vv(20));
	fore(i,0,n){
		cin>>a[i];
		hist[a[i]]++;
		he[cf(2,a[i])][cf(5,a[i])]++;
	}
	vv cm(MAXV);
	fore(i,1,MAXV)for(ll j=i;j<MAXV;j+=i)cm[i]+=hist[j];
	vv sp(MAXV);
	fore(i,1,MAXV)sp[i]=sp[i-1]+hist[i-1];
	auto get_sp=[&](ll x){return x<MAXV?sp[x]:sp.back();};
	// before comma
	ll bef=0;
	for(auto x:a){
		ll cur=get_sp(x);
		ll pot=x;
		fore(j,0,7){
			ll now=get_sp(10*pot)-get_sp(pot);
			now*=(j+1);
			addig(cur,now);
			pot*=10;
		}
		addig(bef,cur);
	}
	// sum |path|
	ll path=0;
	fore(i0,0,20)fore(j0,0,20)
	fore(i1,0,20)fore(j1,0,20){
		ll coef=mul(he[i0][j0],he[i1][j1]);
		ll val=max({0ll,i1-i0,j1-j0});
		ll cur=mul(val,coef);
		addig(path,cur);
	}
	// sum |period|, O(nlog^2n)
	ll prd=0;
	fore(x,1,MAXV){
		ll coef=hist[x],cur=0;
		if(!coef)continue;
		// cout<<"\nx: "<<x<<"\n";
		for(auto d:divs[x]){
			ll cant=0;
			for(auto m:divs[x/d]){
				cant+=mu[m]*cm[d*m];
				// cout<<m<<" m "<<mu[m]*cm[d*m]<<"\n";
			}
			ll val=ord(sac10(x/d));
			ll term=mul(cant,val);
			// cout<<d<<": "<<cant<<" "<<val<<": "<<term<<"\n";
			addig(cur,term);
		}
		cur=mul(cur,coef);
		// cout<<x<<": "<<cur<<"\n";
		addig(prd,cur);
	}
	// cerr<<bef<<" "<<path<<" "<<prd<<"\n";
	ll res=add(bef,add(path,prd));
	res=mul(res,fpow(mul(n,n),MOD-2));
	cout<<res<<"\n";
	return 0;
}