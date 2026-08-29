#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

bool solve(vv c){
	ll sum=accumulate(ALL(c),0ll);
	return max(c[1],c[2])*2<=sum;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		string a,b; cin>>a>>b;
		vector<vv> sp(n+1,vv(4));
		fore(i,0,n){
			ll cur=(b[i]-'0')*2+a[i]-'0';
			sp[i+1]=sp[i];
			sp[i+1][cur]++;
		}
		while(q--){
			ll l,r; cin>>l>>r; l--;
			vv c(4);
			fore(i,0,4)c[i]=sp[r][i]-sp[l][i];
			if(solve(c))cout<<"YES\n";
			else cout<<"NO\n";
		}
		
	}
	return 0;
}
