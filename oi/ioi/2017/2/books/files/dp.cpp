#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dffyhg:v)cout<<dffyhg<<" ";cout<<"\n";}
using namespace std;
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;
const ll MAXN=1e6+5,K=20,INF=2*MAXN*2;
string cv(ii a){return to_string(a.fst)+","+to_string(a.snd);}

ii oper(ii a, ii b){return {min(a.fst,b.fst),max(a.snd,b.snd)};}
ii st[K][MAXN];
void st_init(vector<ll>a){
	ll n=SZ(a);
	fore(i,0,n)st[0][i]={a[i],a[i]};
	fore(k,1,K)fore(i,0,n)if(i+(1ll<<k)<=n)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
}
ii query(ll s, ll e){
	ll k=63-__builtin_clzll(e-s);
	ii ret=oper(st[k][s],st[k][e-(1ll<<k)]);
	// cout<<"query "<<s<<","<<e-1<<" = "<<cv(ret)<<"\n";
	return ret;
}

const ll N=1005;
ll dp[N][N];
ll n;
ll f(ii ra){
	auto [l,r]=ra;
	ll &res=dp[l][r];
	if(res!=-1)return res;
	if(l==0&&r==n-1)return res=0;
	ii nxt=oper(ra,query(l,r+1));
	// cout<<"f "<<l<<","<<r<<": "<<cv(nxt)<<"\n";
	if(nxt!=ra)return res=f(nxt);
	res=INF;
	if(l)res=min(res,2+f({l-1,r}));
	if(r<n-1)res=min(res,2+f({l,r+1}));
	return res;
}

long long minimum_walk(std::vector<int> A, int S){
	n=SZ(A);
	vector<ll>a;
	fore(i,0,n)a.pb(A[i]);
	ll s=S;
	LL res=0;
	fore(i,0,n)res+=abs(a[i]-i);
	while(SZ(a)&&a.back()==SZ(a)-1)a.pop_back();
	if(!SZ(a))return 0;
	n=SZ(a);
	if(s>=n)res+=2*(s-(n-1)),s=n-1;
	ll pop=-1;
	fore(i,0,n){
		if(a[i]!=i)break;
		pop=i;
	}
	pop++;
	if(s<pop)res+=(pop-s)*2,s=pop;
	vector<ll>_a;
	fore(i,pop,n)_a.pb(a[i]-pop);
	a=_a;
	s-=pop;
	n=SZ(a);
	
	// imp(a);
	
	st_init(a);
	mset(dp,-1);
	res+=f({s,s});
	return res;
}
