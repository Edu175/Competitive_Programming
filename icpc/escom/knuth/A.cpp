#include<bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,cuca=b;i<cuca;i++)
#define SZ(x) ll(x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto i:a)cout<<i<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll BOUND=1e9;

int main(){
	FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		ll sum=0;
		ll bad=0;
		fore(i,0,n){
			if(a[i]!=-1){
				bad|=a[i]<=sum;
			}
			else {
				a[i]=sum+1;
			}
			sum+=a[i];
			if(a[i]>BOUND){
				bad=1;
				break;
			}
		}
		if(bad)cout<<"NO\n";
		else {
			cout<<"YES\n";
			show(a)
		}
	}
}