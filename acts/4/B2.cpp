#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("Ofast") // may lead to precision errors
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXN=1505;
int ft[MAXN+1]; // for more dimensions, make ft multi-dimensional
void upd(int i0, int v){ // add v to i0th element (0-based)
	// add extra fors for more dimensions
	for(int i=i0+1;i<=MAXN;i+=i&-i)ft[i]=max(ft[i],v);
}
void reset(int i0){ // add v to i0th element (0-based)
	// add extra fors for more dimensions
	for(int i=i0+1;i<=MAXN;i+=i&-i)ft[i]=0;
}
int get(int i0){ // get sum of range [0,i0)
	int r=0;
	// add extra fors for more dimensions
	for(int i=i0;i;i-=i&-i)r=max(r,ft[i]);
	return r;
}
ll a[MAXN][MAXN];
ll n;
vector<vector<ll>> dp(){
	vector<ii>c[n*n];
	/*cout<<"\ndp\n";
	fore(i,0,n){
		fore(j,0,n)cout<<a[i][j]<<" ";;cout<<endl;
	}*/
	fore(i,0,n)fore(j,0,n){
		c[a[i][j]].pb({i,j});
	}
	vector<vector<ll>>resi(n,vector<ll>(n));
	fore(ai,0,n*n){
		//cout<<ai<<" ai\n";
		auto v=c[ai];
		sort(ALL(v));
		for(auto [i,j]:v){
			resi[i][j]=get(j+1)+1;
			upd(j,resi[i][j]);
			//cout<<i<<" "<<j<<": "<<resi[i][j]<<"\n";
		}
		for(auto [i,j]:v)reset(j);
	}
	return resi;
}
int main(){FIN;
	cin>>n;
	vector<ii>c(n*n);
	fore(i,0,n)fore(j,0,n){
		cin>>a[i][j]; a[i][j]--;
	}
	auto resi=dp();
	ll ai[n][n];
	fore(i,0,n)fore(j,0,n)ai[i][j]=a[i][j];
	fore(i,0,n)fore(j,0,n)a[i][j]=ai[n-1-i][n-1-j];
	auto resi2=dp();
	vector<ll>res(2*n-1);
	fore(i,0,n)fore(j,0,n){
		ll l=resi[i][j],r=resi2[n-1-i][n-1-j];
		//cout<<i<<" "<<j<<": "<<l<<" "<<r<<": "<<l+r<<"\n";
		res[l+r-2]++;
	}
	imp(res);
	return 0;
}
