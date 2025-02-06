#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n),res;
	ll sum=0;
	fore(i,0,n)cin>>a[i],sum+=a[i];
	fore(i,0,n)if(a[i]*n==sum)res.pb(i);
	if(!SZ(res)){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n"<<SZ(res)<<"\n";
	fore(i,0,SZ(res)){
		if(i)cout<<" ";
		cout<<res[i]+1;
	}
	cout<<"\n";
	return 0;
}
