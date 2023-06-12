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
const ll INF=1e10;

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll a[n],w[m];
	fore(i,0,n)cin>>a[i],a[i]--;
	fore(i,0,m)cin>>w[i];
	set<pair<ll,ll>>st;
	fore(i,1,n)st.insert({min(a[i-1],a[i]),max(a[i-1],a[i])});
	st.insert({a[0],a[0]});
	st.insert({a[n-1],a[n-1]});
	for(auto i:st)cout<<i.fst<<","<<i.snd<<" ";
	cout<<"\n";
	vector<ll> meet(1ll<<((m+1)/2),INF);
	fore(bm,0,1ll<<(m/2)){
		ll flag=1;
		ll des=0,sum=0;
		fore(i,0,m/2)if((1ll<<i)&bm)sum+=w[i];
		cout<<bm<<":\n";
		for(auto i:st){
			if(i.fst>=m/2||(bm&(1ll<<i.fst))==0){
			if(i.snd>=m/2||(bm&(1ll<<i.snd))==0){
				if(i.fst<m/2&&i.snd<m/2)flag=0;
				else {
					if(i.fst<m/2||i.snd<m/2){
						cout<<i.fst<<","<<i.snd<<": ";
						if(i.fst>=m/2)
							des|=(1ll<<(i.fst-m/2)),cout<<(1ll<<(i.fst-m/2))<<" ";
						if(i.snd>=m/2)
							des|=(1ll<<(i.snd-m/2)),cout<<(1ll<<(i.snd-m/2))<<" ";
						cout<<des<<"\n";
					}
				}
			}
			}
		}
		cout<<flag<<" -> "<<des<<": "<<sum<<"\n\n";
		if(flag)meet[des]=min(meet[des],sum);
	}
	imp(meet);
	ll res=INF;
	fore(bm,0,1ll<<((m+1)/2)){
		ll sum=0,des=0;
		fore(i,0,(m+1)/2)if((1ll<<i)&bm)sum+=w[i+m/2];
		ll flag=1;
		cout<<bm<<":\n";
		for(auto i:st){
			if((bm&(1ll<<(i.fst-m/2)))==0&&(bm&(1ll<<(i.snd-m/2)))==0){
				if(i.fst>=m/2&&i.snd>=m/2)flag=0;//,cout<<i.fst<<","<<i.snd<<"\n";
			}
			if((i.fst>=m/2)xor(i.snd>=m/2)){
				cout<<i.fst<<","<<i.snd<<": ";
				if(i.fst>=m/2)
					if(bm&(1ll<<(i.fst-m/2)))
						des|=(1ll<<(i.fst-m/2)),cout<<(1ll<<(i.fst-m/2))<<" ";
				if(i.snd>=m/2)
					if(bm&(1ll<<(i.snd-m/2)))
						des|=(1ll<<(i.snd-m/2)),cout<<(1ll<<(i.snd-m/2))<<" ";
				cout<<des<<"\n";
			}
		}
		cout<<flag<<" -> "<<des<<": "<<sum<<"\n\n";
		ll resi=INF;
		if(flag)resi=meet[des]+sum;
		res=min(res,resi);
	}
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
