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

ll nz(ll n){
	ll res=0;
	while(n%10==0)res++,n/=10;
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m; m++;
		vector<ll>op,a(n);
		ll sum=0;
		fore(i,0,n){
			cin>>a[i],sum+=SZ(to_string(a[i]));
			op.pb(nz(a[i]));
		}
		sort(ALL(op)); reverse(ALL(op));
		for(ll i=0;i<SZ(op);i+=2)sum-=op[i];
		if(sum>=m)cout<<"Sasha\n";
		else cout<<"Anna\n";
	}
	return 0;
}
