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

int main(){FIN;
	ll n; cin>>n;
	ll a[n],vis[n];
	ll res=0;
	map<ll,set<ll>>pos;
	fore(i,0,n)cin>>a[i],pos[a[i]].insert(i),vis[i]=0;
	fore(i,0,n){
		//cout<<i<<": ";
		ll h=a[i]-1,p=i;
		pos[a[i]].erase(i);
		if(!vis[i]){
			res++;
			auto upp=pos[h].upper_bound(p);
			while(upp!=pos[h].end()){
				p=*upp;
				pos[h].erase(p);
				//cout<<p<<" ";
				vis[p]=1;
				h=a[p]-1;
				upp=pos[h].upper_bound(p);
			}
			//cout<<upp<<"\n";
		}
		//cout<<"\n";
	}
	cout<<res<<"\n";
	return 0;
}
