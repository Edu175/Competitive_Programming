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
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const ll MAXN=2e4+5;
ll dp[MAXN];
const ll INF=1e15;
int main(){
	ll n;
	cin>>n;
	int v[n];
	int c[n];
	fore(i,0,n) cin>>v[i];
	fore(i,0,n) cin>>c[i];
	ll k; cin>>k;
	dp[0]=(pair<ll,ii>){0,(ii){INF,INF}};
	fore(i,1,k+1){dp[i]=(pair<ll,ii>){INF,(ii){INF,INF}};}
	fore(i,0,n){
		for(ll j=k; j>=v[i]; j--){
			ll pos=j-v[i];
			ll d=dp[pos];
			ll cnt=0;
			for(ll r=j; r<=k; r+=v[i])
		}
	}
	cout<<dp[k].fst<<"\n";
}