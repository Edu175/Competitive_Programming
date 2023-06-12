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
const ll INF=1e9+5,MAXN=3e5+5;

ll res[MAXN],a[MAXN],n,s;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		vector<ll> a(n);
		ll maxi=-INF,mini=INF;
		vector<ll>pos,neg;
		fore(i,0,n){
			cin>>a[i];
			maxi=max(maxi,a[i]);
			mini=min(mini,a[i]);
			if(a[i]>=0)pos.pb(a[i]);
			else neg.pb(a[i]);
		}
		s=maxi-mini;
		if(maxi<=0||mini>=0){
			cout<<"No\n";
			continue;
		}
		cout<<"Yes\n";
		sort(ALL(pos));
		sort(ALL(neg)); reverse(ALL(neg));
		vector<ll>res(n);
		ll P=0,N=0;
		//ll flag=1;
		//cout<<s<<"\n";
		fore(i,0,n){
			ll x=-INF;
			//cout<<i<<": "<<P<<" "<<N<<"\n";
			if(SZ(pos)&&abs(P+pos.back())<s)x=pos.back(),pos.pop_back();
			else /*if(SZ(neg)&&abs(N+neg.back())<s)*/x=neg.back(),neg.pop_back();
			/*else {
				flag=0;
				cout<<"NO\n";
				//continue;
			}*/
			res[i]=x;
			P=max((ll)0,P+x); N=min((ll)0,N+x);
		}
		//if(flag){
			imp(res);
		//}
		//else cout<<"-1\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
