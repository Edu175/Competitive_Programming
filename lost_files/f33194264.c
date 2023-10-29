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
typedef int ll;

int main(){FIN;
	ll n; cin>>n;
	ll vis[15];
	fore(i,0,15)vis[i]=4;
	vis[10]=16;
	ll a=0,b=0;
	ll c[4];
	fore(i,0,4){
		cin>>c[i];
		c[i]=min(c[i],10);
		vis[c[i]]--;
	}
	a+=c[0]+c[1];
	b+=c[3]+c[2];
	fore(i,0,n){
		ll x; cin>>x;
		x=min(x,10);
		vis[x]--;
		a+=x;
		b+=x;
	}
	imp(vis);
	ll res;
	if(b>=a){
		res=23-b;
		if(!vis[res])res=-1;
	}
	else{
		res=24-a;
		while(vis[res]==0)res++;
		if(b+res>23)res=-1;
	}
	cout<<res<<"\n";
	return 0;
}

