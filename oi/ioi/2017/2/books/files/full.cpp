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
ll n;
ii expand(ii ra){
	ii nxt=oper(ra,query(ra.fst,ra.snd+1));
	if(nxt==ra)return ra;
	return expand(nxt);
}
pair<ll,ii> gol(ii ra){
	ll s=1;
	auto [l,r]=ra;
	ii x=expand({l-1,l-1});
	while(x.fst>0&&x.snd<l){
		x=expand({x.fst-1,x.snd});
		s++;
	}
	return {s,x};
}
pair<ll,ii> gor(ii ra){
	ll s=1;
	auto [l,r]=ra;
	ii x=expand({r+1,r+1});
	while(x.snd<n-1&&x.fst>r){
		x=expand({x.fst,x.snd+1});
		s++;
	}
	return {s,x};
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
	
	ii ra=expand({s,s});
	while(ra!=ii({0,n-1})){
		// cout<<cv(ra)<<"\n";
		auto mov=[&](ll b){
			// cout<<"me movi para la "<<(b?"derecha\n":"izquierda\n");
			auto [add,nxt]=(b?gor:gol)(ra);
			res+=add*2;
			ra=oper(ra,nxt);
		};
		if(ra.fst==0)mov(1);
		else if(ra.snd==n-1)mov(0);
		else if(gol(ra).fst<gor(ra).fst)mov(0);
		else(mov(1));
	}
	
	return res;
}
