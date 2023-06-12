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
		vector<pair<ll,ll>>p(n);
		fore(i,0,n){
			cin>>p[i].fst;
			p[i].second=i;
		}
		string s;cin>>s;
		fore(i,0,n)if(s[i]=='1')p[i].fst+=n;
		sort(ALL(p)); reverse(ALL(p));
	//for(auto i:p)cout<<i.fst<<"/"<<i.snd<<" "; cout<<"\n";
		fore(i,0,n) p[i].fst=n-i;
	//for(auto i:p)cout<<i.fst<<"/"<<i.snd<<" "; cout<<"\n";
		fore(i,0,n) swap(p[i].fst,p[i].snd);
		sort(ALL(p));
		fore(i,0,n) cout<<p[i].snd<<" ";
		cout<<"\n";
	}
	 return 0;
}
