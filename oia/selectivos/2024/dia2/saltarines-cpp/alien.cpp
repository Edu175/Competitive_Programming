#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto fdkjg:v)cout<<fdkjg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF=1e18,MAXN=305;
ii dp[MAXN][MAXN];
bool vis[MAXN][MAXN];
ll n,k,C,tot;
vector<ll>a,is;
ll lim,lam;
ll db;
string cv(ii a){return to_string(a.fst)+","+to_string(a.snd);}
ii f(ll i, ll _c){
	//cout<<"call "<<i<<" "<<_c<<" "<<s<<"\n";
	auto &res=dp[i][_c];
	if(vis[i][_c])return res;
	vis[i][_c]=1;
	if(i==n+1)return res=(_c==0)?ii({0,0}):ii({INF,0});
	res={INF,0};
	ll c=_c+is[i];
	res=f(i+1,c);
	if(c){
		ii resi=f(i+1,c-1);
		resi.fst+=lam*(i+1)-a[i];
		resi.snd+=i+1;
		res=min(res,resi);
	}
	if(db)cout<<i<<" "<<c<<": "<<cv(res)<<"\n";
	return res;
}
ll wqs(){
	ll l=0,r=1e15;
	while(l<=r){
		lam=(l+r)/2;
		mset(vis,0);
		cerr<<lam<<": "<<cv(f(0,0))<<"\n";
		if(f(0,0).snd>=lim)l=lam+1;
		else r=lam-1;
	}
	lam=r;
	mset(vis,0);
	db=1;
	cerr<<lam<<":\n"<<cv(f(0,0))<<" final\n";
	ii res=f(0,0);
//	assert(res.snd==lim);
	ll ans=res.fst-lam*lim;
	cerr<<ans<<"\n";
	return -ans;
}
long long saltarines(int K, vector<int> &val, vector<int> &p) {
	k=K;
	n=SZ(val);
	ll sum=0;
	a.pb(0);
	fore(i,0,SZ(val)){
		sum+=val[i];
		a.pb(sum);
	}
	imp(a);
	is.resize(n+5);
	ll res=0;
	for(auto i:p)is[i]=1,tot+=i+1,res-=a[i];
	C=SZ(p);
	ll cot=0;
	fore(i,0,C)cot+=n-i+1;
	lim=min(k+tot,cot);
	cout<<lim<<"\n";
//	cout<<lim<<"\n";
//	imp(is);
	res+=wqs();
	return res;
}
