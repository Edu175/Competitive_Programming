#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

bool is_sorted(vector<ll>a){
	fore(i,0,SZ(a)-1)if(a[i]>a[i+1])return 0;
	return 1;
}
void rot(vector<ll>&a, ll x){rotate(a.begin(),a.begin()+x,a.end());}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		ll flag=0;
		fore(i,0,n+5){
			rot(a,1);
			flag|=is_sorted(a);
		}
		if(flag)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
