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
	ll n;cin>>n;
	vector<pair<ll,ll>>v(n);
	fore(i,0,n)cin>>v[i].fst;
	fore(i,0,n)v[i].second=i;
	sort(ALL(v));
	for(auto i:v)cout<<i.fst<<" "<<i.snd<<"\n";
	 return 0;
}
