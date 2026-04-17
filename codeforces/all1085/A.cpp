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
		fore(i,1,n-1)if(s[i-1]=='1'&&s[i+1]=='1')s[i]='1';
		ll mx=count(ALL(s),'1');
		ll mn=0;
		ll q=0;
		fore(i,0,n){
			q+=s[i]=='1';
			if(i==n-1||s[i]!=s[i+1]){
				if(q)mn+=(q+2)/2;
				// cerr<<q<<" q\n";
				q=0;
			}
		}
		cout<<mn<<" "<<mx<<"\n";
	}
	return 0;
}
