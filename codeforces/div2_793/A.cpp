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
		string s; cin>>s;
		ll res=0;
		if(n%2==1){
			res++;
			fore(i,1,n/2+1){
				if(s[n/2]==s[n/2+i]&&s[n/2]==s[n/2-i])res+=2;
				else {
					break;
				}
			}
		}
		else {
			res+=2;
			fore(i,1,n/2){
				if(s[n/2]==s[n/2+i]&&s[n/2]==s[n/2-i-1])res+=2;
				else {
					break;
				}
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
