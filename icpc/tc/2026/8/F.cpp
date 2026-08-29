#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a) cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef long double ld;
const ll MAXN=35,MAXK=205;

ld dp[MAXN][MAXN][MAXK];
// a[i] < a[j]
ll tra(ll i, ll l, ll r){
	if(i<l||i>r)return i;
	return l+r-i;
}
int main(){
	JET
	ll n,k; cin>>n>>k;
	assert(n<=30&&k<=200);
	vv a(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)fore(j,0,n)if(i!=j)dp[i][j][0]=i>j;
	ll tot=n*(n+1)/2;
	fore(c,1,k+1)fore(i,0,n)fore(j,0,n)if(i!=j){
		auto &res=dp[i][j][c];
		res=0;
		fore(l,0,n)fore(r,l,n){
			res+=dp[tra(i,l,r)][tra(j,l,r)][c-1];
		}
		res/=tot;
	}
	ld res=0;
	fore(i,0,n)fore(j,0,n)if(i!=j&&a[i]<a[j])res+=dp[i][j][k];
	cout<<fixed<<setprecision(15);
	cout<<res<<"\n";
	return 0;
}