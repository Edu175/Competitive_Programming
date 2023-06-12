#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll a[m];
		ll oc[n];
		ll h=0;
		ll w[n];
		mset(oc,0);
		mset(w,0);
		priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>minw;
		queue<ll>task;
		fore(i,0,m){
			cin>>a[i];
			a[i]--;
			oc[a[i]]++;
			if(oc[a[i]]>2)task.push(a[i]);
			else w[a[i]]++;
		}
		//imp(w);
		fore(i,0,n){
			pair<ll,ll> p;
			p.fst=w[i]; p.snd=i;
			minw.push(p);
			h=max(h,w[i]);
		}
		while(SZ(task)){
			ll i=task.front();
			if(w[i]+1<=h)w[i]++;
			else if(w[i]+1<=minw.top().fst+2)w[i]++,h=w[i];
			else{
				pair<ll,ll>tp;
				tp.fst=minw.top().fst;
				tp.snd=minw.top().snd;
				w[tp.snd]+=2;
				h=w[tp.snd];
				minw.push({tp.fst+2,tp.snd});
				minw.pop(); 
			}
			task.pop();
		}
		cout<<h<<"\n";
	}
	return 0;
}
