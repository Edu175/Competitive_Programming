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
	ll vis[15];mset(vis,0);//imp(vis);
	ll a=0,b=0;
	ll c[4];
	fore(i,0,4){
		cin>>c[i];
		vis[c[i]]++;
	}
	a+=min(10,c[0])+min(10,c[1]);
	b+=min(10,c[3])+min(10,c[2]);
	fore(i,0,n){
		ll x; cin>>x;
		vis[x]++;
		a+=min(10,x);
		b+=min(10,x);
	}
	//imp(vis);
	//cout<<a<<" "<<b<<"\n";
	ll res=-1;
	assert((a<23&&b<23)&&(a>=13||b>=13));
	if(b>=a){
		res=23-b;
		//cout<<">= "<<res<<"\n";
		if(vis[res]==4)res=-1;
	}
	else{
		res=24-a;
		while(vis[res]==4)res++;
		if(b+res>23||res>13)res=-1;
		
	}
	cout<<res<<"\n";
	return 0;
}
