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

int main(){
	JET
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n) cin>>a[i];
	vector<ll>c(2);
	c[0]=1;
	ll sum=0,res=0;
	fore(i,0,n){
		sum^=a[i];
		res+=c[sum^1];
		c[sum]++;
	}
	cout<<res<<"\n";
	return 0;
}