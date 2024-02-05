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

int main(){FIN;
	ll N,M,V; srand((ll)&N); cin>>N>>M>>V;
	ll n=rand()%N+1; n=max(n,(ll)2);
	ll m=rand()%M+1;
	m=max(m,n-1);
	vector<ll>a={0};
	vector<ll>vis(n);
	vis[0]=1;
	vector<ii>ed;
	fore(i,0,n-1){
		ll p=rand()%(n-1-i);
		fore(j,0,n){
			if(vis[j])continue;
			if(!p){
				ed.pb({a[rand()%SZ(a)],j});
				vis[j]=1;
				a.pb(j);
			}
			p--;
		}
	}
	fore(i,n-1,m){
		ll x=rand()%n,y=rand()%n;
		if(x==y){i--;continue;}
		ed.pb({x,y});
	}
	cout<<"1\n";
	cout<<n<<" "<<m<<"\n";
	for(auto [u,v]:ed){
		cout<<u+1<<" "<<v+1<<" "<<rand()%V+1<<"\n";
	}
	fore(i,0,n){
		if(i)cout<<" ";
		cout<<rand()%(min(V,(ll)1000))+1;
	}
	cout<<"\n";
	return 0;
}
