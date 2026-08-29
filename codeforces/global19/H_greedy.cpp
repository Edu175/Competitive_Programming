#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {cout<<#v<<": ";;for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		vv is(n); // is o
		ll inv=0;
		fore(i,0,n)fore(j,i+1,n)inv+=a[i]>a[j];
		auto cam=[&](ll i){
			ll dif=0;
			fore(j,0,n)if(i!=j){
				ll d=a[j]>a[i]?-1:1;
				if((j>i)==is[j])dif+=d;
			}
			return dif;
		};
		
		cout<<inv<<" ";
		ll dif=0;
		fore(_,0,n){
			ll mx=-1;
			fore(i,0,n)if(!is[i]){
				if(mx==-1||cam(i)<cam(mx))mx=i;
			}
			ll d=cam(mx);
			cout<<"\n\nstep "<<_<<":\n";
			imp(is)
			cout<<d<<","<<mx<<"\n";
			dif+=d;
			is[mx]=1;
			cout<<inv+dif<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
