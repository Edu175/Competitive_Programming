#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef long long LL;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXV=1e6+5,MAXN=2e5+5,MOD=1e9+7;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(LL a, LL b){return a*b%MOD;}
ll fpow(ll b, ll e){
	ll r=1;
	while(e){
		if(e&1)r=mul(r,b);
		b=mul(b,b),e>>=1;
	}
	return r;
}
ll cr[MAXV];
void init_sieve(){
	mset(cr,-1);
	fore(i,2,MAXV)if(cr[i]==-1)
		for(LL j=1ll*i*i;j<MAXV;j+=i)cr[j]=i;
}
vector<ii> fact(ll x){
	vector<ii>r;
	while(x>1){
		ll c=0,p=cr[x]==-1?x:cr[x];
		while(x%p==0)x/=p,c++;
		r.pb({p,c});
	}
	return r;
}
vector<ii>fac[MAXN];
ll a[MAXN];
vector<vector<ll>> num[MAXN];
vector<vector<ll>> inv[MAXN];
ll res=1,oc[MAXV]; // oc of primes

void add(ll i){
	fore(j,0,SZ(fac[i])){
		auto [p,k]=fac[i][j];
		if(oc[p])res=mul(res,num[i][j][0]);
		else res=mul(res,num[i][j][1]);
		oc[p]+=k;
	}
}
void remove(ll i){
	fore(j,0,SZ(fac[i])){
		auto [p,k]=fac[i][j];
		if(oc[p]-k>0)res=mul(res,inv[i][j][0]);
		else res=mul(res,inv[i][j][1]);
		oc[p]-=k;
	}
}
ll get_ans(){
	return res;
}
ll n,sq,nq;
struct qu{int l,r,id; LL ord;};
const int HOLG=18,HON=1<<HOLG;
LL hilbertOrder(int x, int y){
	LL rx,ry,s,d=0;
	for(s=HON/2;s>0;s/=2){
		rx=(x&s)>0,ry=(y&s)>0;
		d+=s*s*((3*rx)^ry);
		if(!ry){
			if(rx)x=HON-1-x,y=HON-1-y;
			swap(x,y);
		}
	}
	return d;
}
bool qcomp(const qu &a, const qu &b){return a.ord<b.ord;}
qu qs[MAXN];
ll ans[MAXN];
// bool qcomp(const qu &a, const qu &b){
// 	if(a.l/sq!=b.l/sq) return a.l<b.l;
// 	return (a.l/sq)&1?a.r<b.r:a.r>b.r;
// }
void mos(){
	fore(i,0,nq)qs[i].id=i,
	qs[i].ord=hilbertOrder(qs[i].l,qs[i].r);
	sq=sqrt(n)+.5;
	sort(qs,qs+nq,qcomp);
	int l=0,r=0;
	// init();
	fore(i,0,nq){
		qu q=qs[i];
		while(l>q.l)add(--l);
		while(r<q.r)add(r++);
		while(l<q.l)remove(l++);
		while(r>q.r)remove(--r);
		ans[q.id]=get_ans();
	}
}
int main(){JET
	init_sieve();
	cin>>n;
	fore(i,0,n)cin>>a[i],fac[i]=fact(a[i]);
	fore(i,0,n){
		ll m=SZ(fac[i]);
		num[i].resize(m,vector<ll>(2));
		inv[i].resize(m,vector<ll>(2));
		fore(j,0,m){
			auto [p,k]=fac[i][j];
			num[i][j][0]=fpow(p,k);
			num[i][j][1]=mul(fpow(p,k-1),p-1);
			inv[i][j][0]=fpow(num[i][j][0],MOD-2);
			inv[i][j][1]=fpow(num[i][j][1],MOD-2);
		}
	}
	// fore(i,0,n){
	// 	cout<<"\n"<<i<<":\n";
	// 	cout<<"fac: ";
	// 	ll m=SZ(fac[i]);
	// 	fore(j,0,m)cout<<fac[i][j].fst<<","<<fac[i][j].snd<<" ";
	// 	cout<<"\n";
	// 	cout<<"num 0: ";
	// 	fore(j,0,m)cout<<num[i][j][0]<<" ";
	// 	cout<<"\n";
	// 	cout<<"num 1: ";
	// 	fore(j,0,m)cout<<num[i][j][1]<<" ";
	// 	cout<<"\n";
	// }
	cin>>nq;
	fore(i,0,nq){
		cin>>qs[i].l>>qs[i].r; qs[i].l--;
	}
	mos();
	fore(i,0,nq)cout<<ans[i]<<"\n";
	return 0;
}