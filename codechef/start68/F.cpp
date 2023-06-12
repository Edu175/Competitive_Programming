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
const ll MAXN=2e5+5,INF=1e16;

ll did[MAXN];
ll k;
ll ask(ll x){
	x%=(k+1);
	ll &res=did[x];
	if(res!=INF)return res;
	cout<<"? "<<x<<endl;
	cin>>res;
	//cout<<"did "<<x<<"= "<<did[x]<<endl;
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>k>>n;
		fore(i,0,k+3)did[i]=INF;
		/*while(1){
			ll q; cin>>q;
			cout<<ask(q)<<endl;
		}*/
		ll b[n];
		set<ll>st;
		fore(i,0,n)cin>>b[i],st.insert(b[i]%(k+1));
		if(SZ(st)>=k+1){
			ll sum=0;
			fore(i,0,k){
				sum+=ask(i);
			}
			did[k]=-sum;
		}
		ll res[n];
		fore(i,0,n)res[i]=ask(b[i]);
		cout<<"! ";
		for(auto i:res)cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
