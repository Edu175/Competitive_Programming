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

int main(){FIN;
	ll n; cin>>n;
	vector<string>s(n);
	map<string,ll>id;
	fore(i,0,n)cin>>s[i],id[s[i]]=i;
	vector<ll>a(n);
	fore(i,0,n){
		string t; cin>>t;
		a[id[t]]=i;
	}
	vector<string>res;
	ii mn={a[n-1],n-1};
	for(ll i=n-1;i>=0;i--){
		mn=min(mn,ii({a[i],i}));
		res.pb(s[mn.snd]);
	}
	reverse(ALL(res));
	fore(i,0,n){
		if(i)cout<<" ";
		cout<<res[i];
	}
	cout<<"\n";
	return 0;
}
