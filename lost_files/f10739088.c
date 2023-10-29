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
const ll MOD=1e9+7;

int main(){FIN;
	set<char>vow={'a','e','i','o','u'};
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		string s; cin>>s;
		ll a[n];
		fore(i,0,n)a[i]=vow.count(s[i]);
		vector<ii> ran;
		ll l,sp=0;
		fore(i,0,n){
			if(sp%k==0&&a[i])l=i;
			sp+=a[i];
			if(sp%k==0&&a[i])ran.pb({l,i});
		}
		//imp(a);
		ll res=1;
		fore(i,1,SZ(ran)){
			//cout<<i.fst<<","<<i.snd<<" ";
			res=(res*(ran[i].fst-ran[i-1].snd))%MOD;
		}
		//cout<<"\n";
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
