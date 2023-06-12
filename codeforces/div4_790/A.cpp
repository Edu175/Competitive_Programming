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
		string s;
		cin>>s;
		ll sumf=0;
		ll suml=0;
		fore(i,0,6){
			if(i<3)sumf+=s[i]-'0';
			else suml+=s[i]-'0';
		}
		if(sumf==suml)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
