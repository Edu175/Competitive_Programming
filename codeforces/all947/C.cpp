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

ll med(vector<ll>a){
	sort(ALL(a));
	return a[(SZ(a)+1)/2-1];
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		ll res=0;
		fore(i,0,n-1){
			res=max(res,med({a[i],a[i+1]}));
		}
		fore(i,0,n-2){
			res=max(res,med({a[i],a[i+1],a[i+2]}));
		}
		cout<<res<<"\n";
	}
	return 0;
}
