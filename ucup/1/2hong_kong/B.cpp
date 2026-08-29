#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define fst first
#define snd second
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll mod=998244353;
ll addm(ll a, ll b){a+=b; return a<mod?a:a-mod;}
ll subm(ll a, ll b){a-=b; return a<0?a+mod:a;}
ll mulm(ll a, ll b){return a*b%mod;}

vector<vv> p[2];


ll get(bool b, ll i, ll l, ll r){
	if(b) return subm(p[1][r][i],p[1][l][i]);
	return subm(p[0][i][r],p[0][i][l]);
}
int main(){
	JET
	ll n,m; cin>>n>>m;
	p[0]=p[1]=vector<vv>(n+2,vv(m+2,0));
	
	fore(_,0,2)fore(i,0,n)fore(j,0,m) cin>>p[_][i+_][j+1-_];
	fore(_,0,2)fore(i,0,n+1) fore(j,0,m+1){
		p[_][i+_][j+1-_]=addm(p[_][i+_][j+1-_],p[_][i][j]);
	}
	ll r=2;
	fore(i,0,n)fore(j,0,m){
		ll b=mulm(get(0,i+1,j,m),get(1,j+1,i,n));
		ll w=mulm(get(0,i,0,j),get(1,j,0,i));
		// cout<<i<<" "<<j<<" "<<b<<" "<<w<<"\n";
		r=addm(r,mulm(b,w));
	}
	// fore(_,0,2){
	// 	fore(i,0,n+2) show(p[_][i])
	// 	cout<<"\n";
	// }
	cout<<r<<"\n";
	return 0;
}