#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		ll wg = 0, rg = 0;
		fore(i,0,SZ(s)){
			if(i<n && s[i] == 'W') wg++;
			if(i>=n && s[i] == 'R') rg++;
		}
		ll pre = 0, suf = 0;
		while(s[pre] == 'W')pre++;
		while(s[2*n-1-suf] == 'R') suf++;
		
		if(!(wg&1) && wg == rg && pre>=wg/2 && suf>= rg/2) cout<<"YES\n";
		else cout<<"NO\n";
		
	}
	
	
	return 0;
}