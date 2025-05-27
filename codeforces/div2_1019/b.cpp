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
		ll fij=n;
		string s; cin>>s;
		s.insert(s.begin(),'0');
		n=SZ(s);
		fore(i,0,n-1)fij+=s[i]!=s[i+1];
		vv pos(2,-1),cnt(4);
		fore(i,0,n){
			pos[s[i]-'0']=i;
			if(i<n-1){
				ll mk=2*(s[i]-'0')+(s[i+1]-'0');
				cnt[mk]++;
			}
		}
		ll res=0;
		if(cnt[1]>=2||cnt[2]>=2)res=2;
		else if(cnt[1]&&pos[0]==n-1)res=1;
		else if(cnt[2]&&pos[1]==n-1)res=1;
		cout<<fij-res<<"\n";
	}
	return 0;
}
