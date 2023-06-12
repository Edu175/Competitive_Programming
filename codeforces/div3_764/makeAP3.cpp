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
		ll a,b,c; cin>>a>>b>>c;
		ll aAP=b-c+b;
		ll bAP=c-((c-a)/2);
		ll cAP=b+b-a;
		if((aAP>0&&aAP%a==0)||(bAP>0&&(c-a)%2==0&&bAP%b==0)||(cAP>0&&cAP%c==0&&aAP))cout<<"YES\n";
		else cout<<"NO\n";
	}
	 return 0;
}
 
