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
		ll n; cin>>n;
		string s; cin>>s;
		vv a(n);
		fore(i,0,n)a[i]=s[i]-'0';
		vv c(2);
		ll can=!a[n-1]&&!a[n-2];
		ll e=0;
		fore(i,0,n){
			c[a[i]]++;
			if(c[1]<c[0])e=i+1,c[0]=c[1]=0;
		}
		can|=c[0]>=2;
		can|=n-e>3;
		if(can)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
