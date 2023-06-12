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
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll res=0;
	vector<pair<ll,ll>>b;
	fore(i,0,n){
		if(a[i]==0)res+=(i+1)*(n-i)-1;
		else b.pb({a[i],i});
	}
	ll dif=0;
	//cout<<res-dif<<"\n";dif=res;
	ll m=SZ(b);
	res+=(n*(n+1))/2;
	//cout<<res-dif<<"\n";dif=res;
	ll l=-1;
	fore(i,1,m){
		if((b[i].fst==1&&b[i-1].fst==2)||(b[i].fst==2&&b[i-1].fst==1)){
			//cout<<b[i-1].snd<<" "<<b[i].snd<<": "<<b[i-1].snd-l<<" "<<n-b[i].snd<<"\n";
			res+=(b[i-1].snd-l)*(n-b[i].snd);
			l=b[i-1].snd;
		}
	}
	//cout<<res-dif<<"\n";dif=res;
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
