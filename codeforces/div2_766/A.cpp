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
		ll n,m,c,r;cin>>n>>m>>r>>c;vector<string> a(n);
		ll x=0;set<ll> stc,str;
		fore(i,0,n){
			cin>>a[i];
			fore(j,0,m){
				if(a[i][j]=='B')x=1,str.insert(i),stc.insert(j);
			}
		}
		ll res=-1;
		if(x)res=2;
		if(str.count(r-1)||stc.count(c-1))res=1;
		if(a[r-1][c-1]=='B')res=0;
		cout<<res<<"\n";
	}
	 return 0;
}
