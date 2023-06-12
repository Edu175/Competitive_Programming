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
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll l[n],r[n];
		vector<pair<ll,ll>>a(n);
		fore(i,0,n)cin>>l[i],a[i].snd=l[i];
		fore(i,0,n)cin>>r[i],a[i].fst=r[i];
		sort(ALL(a));
		fore(i,0,n)swap(a[i].fst,a[i].snd);
		vector<pair<ll,ll>>minp(n+1,{4*n,n});	//min [i,n)
		//vector<ll> b(2*n+5,-1);
		//fore(i,0,n)b[a[i].fst]=i;
		for(ll i=n-1;i>=0;i--){
			if(a[i].fst<minp[i+1].fst)minp[i]={a[i].fst,i};
			else minp[i]=minp[i+1];
		}
		/*for(auto i:a)cout<<i.fst<<","<<i.snd<<" ";
		cout<<"\n";
		for(auto i:minp)cout<<i.fst<<","<<i.snd<<" ";
		cout<<"\n";*/
		vector<ll>ap(n,n);
		fore(i,0,n)if(minp[i+1].fst<=a[i].snd)ap[i]=minp[i+1].snd;
		vector<ll>h(n+1);
		fore(i,0,n){
			h[ap[i]]=max(h[ap[i]],h[i]+1);
		}
		/*imp(ap);
		imp(h);*/
		ll res=h[n]-1;
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
