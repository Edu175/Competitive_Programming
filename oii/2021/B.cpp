#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dkjgh:v)cout<<dkjgh<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const int MAXN=4e6+5;

ll ans[MAXN];
int cr[MAXN];
void init_sieve(){
	mset(cr,-1);
	fore(i,2,MAXN)if(cr[i]==-1){
		for(ll j=1ll*i*i;j<MAXN;j+=i)if(cr[j]==-1)cr[j]=i;
		cr[i]=i;
	}
}
vector<int> pr(int n){
	vector<int>r;
	while(n>1){
		int x=cr[n];
		r.pb(x);
		while(n%x==0)n/=x;
	}
	return r;
}
int n;
vector<int>p;
vector<int>a,c;
ll res=0,steps=0;

int no(vector<int>&ban, int m){
	int res=0;
	fore(mk,0,1<<SZ(ban)){
		int prod=1;
		fore(i,0,SZ(ban)){
			if(mk>>i&1)prod*=ban[i];
		}
		int cnt=m/prod;
		if(__builtin_popcountll(mk)&1)res-=cnt;
		else res+=cnt;
//		steps+=SZ(ban);
	}
	return res;
}
vector<vector<ll>>pot;
void num(int x){
	vector<int>b;
	int flag=1;
	fore(i,0,SZ(p)){
		if(a[i]<c[i])b.pb(p[i]);
		flag&=2*a[i]<=c[i];
	}
	ll val=no(b,n/x);
	b.clear();
	fore(i,0,SZ(p))if(a[i]>0)b.pb(pot[i][c[i]-a[i]+1]);
	if(flag)res+=val;
	ll val2=no(b,n);
	res+=val*val2;
//	cout<<"num "<<x<<" | "; imp(a);
//	cout<<(flag?val:0)<<" + "<<val<<" "<<val2<<"\n";
}

ll solve(int N){
	n=N;
	ll &resi=ans[n];
	if(resi!=-1){
		return resi;
	}
	p=pr(n);
	c=vector<int>(SZ(p),0);
	int ni=n;
	fore(i,0,SZ(p))while(ni%p[i]==0){c[i]++;ni/=p[i];}
	pot.clear();
	fore(i,0,SZ(p)){
		pot.pb(vector<ll>(c[i]+1));
		pot[i][0]=1;
		fore(j,1,SZ(pot[i]))pot[i][j]=pot[i][j-1]*p[i];
//		imp(pot[i]);
	}
	res=0;
	a.resize(SZ(c));
//	cout<<n<<":\n";
//	imp(p); imp(c); cout<<endl;
	if(n==1)res=1;
	else {
		vector<int> sp(SZ(c)+1);
		sp[0]=1;
		fore(i,1,SZ(c)+1)sp[i]=sp[i-1]*(c[i-1]+1);
		fore(mk,0,sp.back()){
			int x=1;
			fore(i,0,SZ(c))a[i]=mk/sp[i]%(c[i]+1),x*=pot[i][a[i]];
//			cout<<mk<<" mk:\n";
//			imp(a);
//			cout<<"num "<<x<<endl;
			num(x);
		}
		res/=2;
	}
	resi=res;
	return res;
}
int main(){FIN;
	mset(ans,-1);
	init_sieve();
//	vector<ii>rs;
//	for(ll n=4e6;n;n--){
//		steps=0;
//		solve(n);
//		rs.pb({steps,n});
//	}
//	sort(ALL(rs));
//	reverse(ALL(rs));
//	ll o=0;
//	cout<<ll(1e6)<<"\n";
//	fore(i,0,1e6){
//		o+=rs[i].fst;
////		if(i<1000)cout<<rs[i].snd<<","<<rs[i].fst<<" ";
//		cout<<rs[i].snd<<"\n";
//	}
//	cout<<"total "<<o<<"\n";
	int t; cin>>t;
	while(t--){
		ll n; cin>>n;
		cout<<solve(n)<<"\n";
	}
	return 0;
}
