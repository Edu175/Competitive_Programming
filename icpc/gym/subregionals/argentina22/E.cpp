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
	map<ll,queue<ll>>pos;
	fore(i,0,n)cin>>a[i],pos[a[i]].push(i),vis[i]=0;
	fore(i,0,n){
		cout<<i<<": ";
		ll h=a[i],p=i;
		if(!vis[i]){
			pos[h].pop();
			vis[i]=1;
			res++;
			while(SZ(pos[h-1])){
				p=pos[h-1].front();
				pos[h-1].pop();
				vis[p]=1;
				h=a[p];
				cout<<p<<" ";
			}
		}
		cout<<"\n";
	}
	cout<<res<<"\n";
	return 0;
}
