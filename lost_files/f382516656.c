#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n; 
		string s;
		cin>>s;
		string r;
		fore(i,0,n){
			if(s[0]==s[1]){
				r.pb(s[0]);
				break;
			}
			if(i+1!=n&&s[i]<s[i+1]){
				fore(j,0,i+1)r.pb(s[j]);
				break;
			}
			if(i+1==n){
				fore(j,0,i+1)r.pb(s[j]);
				break;
			}
		}
		string R=r;
		reverse(ALL(R));
		cout<<r<<R<<"\n";
	}
	 return 0;
}
