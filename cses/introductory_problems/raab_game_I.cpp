#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,a,b; cin>>n>>a>>b;
		if(a+b>n)cout<<"NO\n";
		else if(a==0&&b==0){
			cout<<"YES\n";
			fore(j,0,2){
				fore(i,0,n)cout<<i+1<<" ";;cout<<"\n";
			}
		}
		else if(!a||!b)cout<<"NO\n";
		else {
			cout<<"YES\n";
			vv A(n),B(n);
			iota(ALL(A),1);
			ll cnt=1;
			auto llena=[&](ll s, ll e){
				fore(i,s,e)B[i]=cnt++;
			};
			llena(0,n-b-a);
			llena(n-a,n);
			llena(n-b-a,n-a);
			imp(A)
			imp(B)
		}
	}
	return 0;
}