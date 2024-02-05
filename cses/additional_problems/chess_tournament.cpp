#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n);
	priority_queue<ii>q;
	fore(i,0,n){
		cin>>a[i];
		if(a[i])q.push({a[i],i});
	}
	ll res=1;
	vector<ii>ed;
	while(SZ(q)){
		vector<ii>c;
		auto [v,x]=q.top(); q.pop();
		if(v>SZ(q)){
			res=0;
			break;
		}
		while(v--){
			auto [u,y]=q.top(); q.pop();
			u--;
			ed.pb({x,y});
			if(u)c.pb({u,y});
		}
		for(auto i:c)q.push(i);
	}
	if(!res)cout<<"IMPOSSIBLE\n";
	else {
		cout<<SZ(ed)<<"\n";
		for(auto [x,y]:ed)cout<<x+1<<" "<<y+1<<"\n";
	}
	return 0;
}
