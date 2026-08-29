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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll tot=n*(n+1)/2;
		string s; cin>>s;
		vv a(n);
		fore(i,0,n)a[i]=s[i]-'0';
		ll badm3=0;
		vv cnt(3);
		ll c=0;
		cnt[0]++;
		fore(i,0,n){
			c+=a[i]?1:-1;
			c=(c+3)%3;
			badm3+=cnt[c]++;
		}
		ll q=0;
		ll badalt=0;
		fore(i,0,n){
			q++;
			if(i==n-1||a[i]==a[i+1]){
				fore(l,2,q+1)if(l&1)badalt+=q-l+1;
				q=0;
			}
		}
		ll res=tot-badm3-badalt;
		cout<<res<<"\n";
	}
	return 0;
}
