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
	ll N; srand((ll)&N); cin>>N;
	ll n=rand()%N+1;
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
	vector<ll>p(n);
	for(auto [u,v]:ed)p[v]=u;
	cout<<"1\n";
	cout<<n<<"\n";
	fore(i,1,n)cout<<p[i]+1<<" ";
	cout<<"\n";
	fore(i,0,n)cout<<rand()%n+1<<" ";
	cout<<"\n";
	return 0;
}
