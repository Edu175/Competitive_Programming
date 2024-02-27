#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n=6;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	sort(ALL(a));
	map<ll,ll>mp;
	fore(i,0,n-1){
		mp[a[i+1]-a[i]]=i;
	}
	ll d=mp.begin()->fst;
	if(SZ(mp)==2){
		ii p=*prev(mp.end());
		if(p.fst==2*d){
			cout<<a[p.snd]+d<<"\n";
		}
	}
	else if(SZ(mp)==1){
		if(a[0]-d>0)cout<<a[0]-d<<"\n";
		if(a[n-1]+d!=a[0]-d)cout<<a[n-1]+d<<"\n";
	}
	return 0;
}
