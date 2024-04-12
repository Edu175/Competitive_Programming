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
	ll n; cin>>n;
	vector<ll> h(n),s(n),t(n);
	fore(i,0,n)cin>>h[i]>>s[i]>>t[i];
	priority_queue<pair<ll,ii>>ev;
	deque<ll>q; // literally the queue
	ll av=1;
	fore(i,0,n)ev.push({-s[i],{1,i}});
	vector<ll>res;
	while(SZ(ev)){
		auto ppar=ev.top(); ev.pop();
		auto [v,par]=ppar; v=-v;
		auto [ty,i]=par;
		if(ty){ // person entering
			if(av){
				ev.push({-(v+t[i]),{0,i}});
				av=0;
				res.pb(i);
			}
			else {
				if(SZ(q)>=2&&h[i]!=h[q.back()]&&h[q.end()[-2]]==h[q.back()]){
					ll col=h[q.back()];
					while(SZ(q)&&h[q.back()]==col)q.pop_back();
				}
				q.pb(i);
			}
		}
		else {
			if(SZ(q)){
				auto i=q.front(); q.pop_front();
				ev.push({-(v+t[i]),{0,i}});
				res.pb(i);
			}
			else av=1;
		}
	}
	for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}
