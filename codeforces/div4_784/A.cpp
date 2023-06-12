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
		ll n;cin>>n;
		if(n<=1399){
			cout<<"Division 4\n";
			continue;
		}
		if(n<=1599){
			cout<<"Division 3\n";
			continue;
		}
		if(n<=1899){
			cout<<"Division 2\n";
			continue;
		}
		else{
			cout<<"Division 1\n";
		}
	}
	return 0;
}
