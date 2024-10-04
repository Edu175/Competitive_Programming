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
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi,popcnt,lzcnt")
const ll MAXN=1e9+5;
ll m=36;
vector<ll>us;
int ppc(ll n){return __builtin_popcountll(n);}
bool sub(ll a, ll b){return !(a&(~b));}
int bf(ll n, int L, int R){
	// n++;
	ull uv=(1ull<<(n+1))-1;
	uv^=1;
	ll cot=0;
	fore(i,1,n+1)if(i%6==5||i%6==1)cot|=1ll<<(i-1);
	int res=n;
	auto good=[&](ll mk)->bool{
		if(!sub(cot,mk))return 0;
		ull is=0;
		// is=mk|(mk<<2)|(mk<<)
		fore(i,1,n+1)if(mk>>(i-1)&1){
			is|=(1ull<<i);
			if(2*i>n)continue;
			is|=1ull<<(2*i);
			if(3*i>n)continue;
			is|=(1ull<<(3*i));
		}
		return sub(uv,is);
	};
	while(L<=R){
		ll k=(L+R)/2;
		cerr<<k<<" k\n";
		ll mk=(1ll<<k)-1,r,c,flag=0;
		while(mk<=(1ll<<n)-(1ll<<(n-k))){
			if(good(mk)){
				fore(j,0,n)if((mk>>j&1))cout<<j+1<<",";
				cout<<"\n";
				flag=1;
				break;
			}
			c=mk&-mk,r=mk+c,mk=r|(((r^mk)>>2)/c);
		}
		if(flag)R=k-1;
		else L=k+1;
	}
	return L;	
}
int g2(int n){
	bitset<MAXN>is;
	int res=0;
	vv ans;
	auto go=[&](ll i){
		// cerr<<i<<",";//" go\n";
		ans.pb(i);
		res++;
		is[i]=1;
		if(2*i>n)return;
		is[2*i]=1;
		if(3*i>n)return;
		is[3*i]=1;
	};
	fore(i,1,n+1)if(i%6==1||i%6==5)go(i);
	fore(i,1,n+1){
		// cerr<<i<<": ";
		// fore(i,1,n+1)cout<<is[i];;cerr<<"\n";
		if(!is[i])go(i);
		else if(3*i<=n&&!is[2*i]&&!is[3*i]){
			go(i);
		}
	}
	sort(ALL(ans));
	for(auto i:ans)cerr<<i<<",";; cerr<<"\n";
	return res;
}
int g1(int n){
	bitset<MAXN>is;
	int res=0;
	auto go=[&](ll i){
		res++;
		is[i]=1;
		if(2*i>n)return;
		is[2*i]=1;
		if(3*i>n)return;
		is[3*i]=1;
	};
	// fore(i,1,n+1)if(i%6==1||i%6==5)go(i);
	fore(i,1,n+1){
		if(!is[i])go(i);
	}
	return res;
}
int main(){FIN;
	ll n; cin>>n;
	// bf(n);
	// cout<<g2(n)<<"\n";
	ll res=0;
	fore(i,1,n+1){
		if(i%6==1||i%6==5)res++;
	}
	cerr<<g1(n)<<" g1\n";
	ll R=g2(n);
	cerr<<R<<" g2\n";
	cerr<<bf(n,res,R)<<" bf\n";
	cout<<res<<" L\n";
	return 0;
}
