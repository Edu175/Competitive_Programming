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
ll n,m;
ll ask(ll x, ll y){
	assert(x>=0&&x<n&&y>=0&&y<m);
	cout<<"? "<<x+1<<" "<<y+1<<endl;
	ll r; cin>>r;
	return r;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m;
		vector<ll>qs={ask(0,0),ask(0,m-1),ask(n-1,0)};
		ii a={(qs[0]+qs[1]-m+1)/2,0};
		a.snd=qs[0]-a.fst;
		ii b={0,(qs[0]+qs[2]-n+1)/2};
		b.fst=qs[0]-b.snd;
		if(((qs[0]+qs[1]-m+1)&1)||a.fst<0||a.fst>=n||a.snd<0||a.snd>=m)a.fst=-1;
		if(a.fst>=0&&ask(a.fst,a.snd)==0){
			cout<<"! "<<a.fst+1<<" "<<a.snd+1<<endl;
		}
		else cout<<"! "<<b.fst+1<<" "<<b.snd+1<<endl;
	}
	return 0;
}
