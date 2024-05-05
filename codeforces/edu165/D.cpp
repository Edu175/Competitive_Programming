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

bool cmp(ii a, ii b){
	ii c={a.snd,a.fst};
	ii d={b.snd,b.fst};
	return c<d;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<ii>a(n);
		fore(i,0,n)cin>>a[i].fst;
		fore(j,0,n)cin>>a[j].snd;
		sort(ALL(a),cmp);
		vector<ll>is(n);
		ll res=0;
		priority_queue<ii>pq;
		fore(i,0,n)pq.push({-a[i].fst,i});
		ll c=0;
		fore(_,0,k){
			auto [v,i]=pq.top(); pq.pop(); v=-v;
			c-=v;
			is[i]=1;
		}
		ll done=0;
		fore(i,0,n){
			if(is[i]){
				c+=a[i].fst;
				//cout<<"+="<<a[i].fst<<"\n";
				if(!SZ(pq)){done=1;break;}
				auto j=pq.top().snd; pq.pop();
				while(is[j]||j<=i){
					if(!SZ(pq)){done=1;break;}
					j=pq.top().snd; pq.pop();
				}
				if(done)break;
				//cout<<"-="<<a[j].fst<<" ("<<j<<")\n";
				c-=a[j].fst;
				is[j]=1;
			}
			if(a[i].snd-a[i].fst>=0)c+=a[i].snd-a[i].fst;
			//cout<<i<<": "<<c<<"\n";
			res=max(res,c);
		}
		cout<<res<<"\n";
	}
	return 0;
}
