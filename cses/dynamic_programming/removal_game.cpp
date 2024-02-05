#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=5005;

ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
ii dp[MAXN][MAXN];
ll a[MAXN];
ii f(ll l, ll r, ll p){
	ii &res=dp[l][r];
	if(res.fst!=-1)return res;
	if(l>r)return res={0,0};
	if(!p){
		res=ii({a[l],0})+f(l+1,r,p^1);
		if(a[r]+f(l,r-1,p^1).fst>res.fst)res=ii({a[r],0})+f(l,r-1,p^1);
	}
	else {
		res=ii({0,a[l]})+f(l+1,r,p^1);
		if(a[r]+f(l,r-1,p^1).snd>res.snd)res=ii({0,a[r]})+f(l,r-1,p^1);
	}
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n+3)fore(j,0,n+3)dp[i][j]={-1,-1};
	fore(i,0,n)cin>>a[i];
	cout<<f(0,n-1,0).fst<<"\n";
	return 0;
}
