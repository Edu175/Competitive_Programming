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
int ft[MAXN+1][MAXN+1];
void upd(int i0, int j0, int v){
	for(int i=i0+1;i<=MAXN;i+=i&-i)
	for(int j=j0+1;j<=MAXN;j+=j&-j){
		ft[i][j]=max(ft[i][j],v);
	}
}
void reset(int i0, int j0){
	i0++,j0++;
	for(int i=i0;i<=MAXN;i+=i&-i)
	for(int j=j0;j<=MAXN;j+=j&-j){
		if(!ft[i][j])break;
		else ft[i][j]=0;
	}
}
int get(int i0, int j0){
	i0++,j0++;
	//[0,i0) [0,j0)
	int r=0;
	for(int i=i0;i;i-=i&-i)
	for(int j=j0;j;j-=j&-j)
		r=max(r,ft[i][j]);
	return r;
}
bool cmp(ii a, ii b){return a.fst+a.snd<b.fst+b.snd;}
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
		sort(ALL(v),cmp);
		for(auto [i,j]:v){
			resi[i][j]=get(i,j)+1;
			upd(i,j,resi[i][j]);
			//cout<<i<<" "<<j<<": "<<resi[i][j]<<"\n";
		}
		for(auto [i,j]:v)reset(i,j);
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
