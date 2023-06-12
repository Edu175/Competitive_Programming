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
		ll l=0,o=0;ll res=0;
		fore(i,0,n){
			if(s[i]=='0'){
				if(o)o++;
				else if(l%2==0)o++,l=0;
				else res++,o+=2,l=0;
			}
			if(s[i]=='1'){
				if(l)l++;
				else if(o%2==0)l++,o=0;
				else res++,l+=2,o=0;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
