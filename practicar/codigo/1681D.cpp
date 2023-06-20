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
#define bint __int128

ll n;
ll cnt(bint x){
	ll res=0;
	while(x)x/=10,res++;
	return res;
}
vector<ll> has(ll x){
	vector<ll>oc(10,0);
	while(x){
		oc[x%10]=1;
		x/=10;
	}
	vector<ll>ret;
	fore(i,0,10)if(oc[i])ret.pb(i);
	return ret;
}
ll bfs(ll x){
	queue<pair<ll,ll>>q;
	q.push({x,0});
	ll res=-1;
	set<ll>st={x};
	while(SZ(q)&&res==-1){
		auto y=q.front(); q.pop();
		for(auto i:has(y.fst)){
			if(cnt(bint(y.fst)*i)==n){
				res=y.snd+1;
				break;
			}
			if(!st.count(y.fst*i))q.push({y.fst*i,y.snd+1});
			st.insert(y.fst*i);
		}
	}
	return res;
}
int main(){FIN;
	ll x; cin>>n>>x;
	cout<<bfs(x)<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
