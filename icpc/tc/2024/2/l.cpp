#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		ll B=31;
		fore(i,0,n)cin>>a[i];
		vector<ll>h(B);
		fore(j,0,B){
			fore(i,0,n)h[j]+=a[i]>>j&1;
		}
		fore(k,1,n+1){
			ll flag=1;
			fore(j,0,B)flag&=h[j]%k==0;
			if(flag)cout<<k<<" ";
		}
		cout<<"\n";
	}
}