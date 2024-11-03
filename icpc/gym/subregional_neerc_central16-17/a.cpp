#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define snd second
#define fst first
#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
 
 int main(){JET
	#ifdef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	ll n,k; cin>>n>>k;
	ll res;
	if(n<=k)res=2;
	else res=(2*n+k-1)/k;
	cout<<res<<"\n";
	return 0;
 }