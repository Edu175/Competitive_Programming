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
	ll a[n],b[n];
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>b[i];
	ll k,l; cin>>k>>l;
	ll res=0;
	map<ll,ll>best;map<ll,queue<ll>>pos;
	priority_queue<pair<ll,ll>>pq;
	ll sl=0,sk=0;
	fore(i,n-k,n){
		sk+=a[i];
		pq.push({b[i],i});
	}
	fore(i,0,l){
		sl+=pq.top().fst;
		best[pq.top().fst]++;
		pos[pq.top().fst].push(pq.top().snd);
		//cout<<"pos["<<pq.top().fst<<"].push "<<pq.top().snd<<"\n";
		pq.pop();
	}
	res=sk+sl;
	fore(i,0,k){
		ll s=(i+n-k)%n;
		ll e=i;
		//cout<<s<<" "<<e<<":\n";
		while(SZ(pq)&&pq.top().snd>e&&pq.top().snd<=s)pq.pop();
		sk-=a[s],sk+=a[e];
		pq.push({b[e],e});
		if(best[b[s]]){
			best[b[s]]--;
			sl-=b[s];
			//cout<<"rm: "<<b[s]<<" "<<pos[b[s]].front()<<"\n";
			///cout<<"sz pos = "<<SZ(pos[b[s]])<<"\n";
			pos[b[s]].pop();
			pair<ll,ll> in=pq.top();pq.pop();
			sl+=in.fst;
			best[in.fst]++;
			pos[in.fst].push(in.snd);
			//cout<<"pos["<<in.fst<<"].push "<<in.snd<<"\n";
			//cout<<"in: "<<in.fst<<" "<<in.snd<<"\n";
		}
		ll f;//=(*best.begin()).fst;
		for(auto i:best){
			if(i.snd>0){
				f=i.fst;
				break;
			}
		}
		if(pq.top().fst>f){
			sl-=f;
			best[f]--;
			//cout<<f<<" = "<<best[f]<<"\n";
			pq.push({f,pos[f].front()});
			//cout<<"rm restore: "<<f<<" "<<pos[f].front()<<"\n";
			//cout<<"sz pos = "<<SZ(pos[f])<<"\n";
			pos[f].pop();
			pair<ll,ll> in=pq.top();pq.pop();
			sl+=in.fst;
			best[in.fst]++;
			pos[in.fst].push(in.snd);
			//cout<<"pos["<<in.fst<<"].push "<<in.snd<<"\n";
			//cout<<"in: "<<in.fst<<" "<<in.snd<<"\n";
		}
		//cout<<sk<<" "<<sl<<"\n";
		res=max(res,sk+sl);
	}
	cout<<res<<"\n";
	return 0;
}
