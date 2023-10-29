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

int main(){//FIN;
	ll n,k,q; cin>>n>>k>>q;
	vector<ll>a(n);
	vector<ll>lq(n,-1);
	cout<<"k=n\n";
	if(k==n){
		ll sum=0;
		while(q--){
			ll p,v; cin>>p>>v; p--;
			sum+=-a[p]+v;
			a[p]=v;
			cout<<sum<<"\n";
		}
		return 0;
	}
	cout<<"pq\n";
	priority_queue<pair<ii,ll>>r;
	priority_queue<pair<ii,ll>,vector<pair<ii,ll>>,greater<pair<ii,ll>>>l;
	ll sum=0,c=0;
	cout<<"r\n";
	fore(i,0,n)r.push({{a[i],i},-1});
	cout<<"l\n";
	fore(i,0,k)l.push(r.top()),r.pop(),c++;
	cout<<"q\n";
	fore(i,0,q){ //l top y r top existen
		ll p,v; cin>>p>>v; p--;
		ii cur={a[p],p};
		if(cur<r.top().fst){
			sum-=a[p];
			c--;
		}
		a[p]=v;
		lq[p]=i;
		r.push({{a[p],p},i});
		cout<<"while c<k\n";
		while(c<k){
			ll id=r.top().snd;
			auto f=r.top().fst; r.pop();
			if(lq[f.snd]!=id)continue;
			l.push({f,id});
			sum+=f.fst;
			c++;
		}
		cout<<"while 1\n";
		while(1){
			ll ids=l.top().snd,ide=r.top().snd;
			auto s=l.top().fst;
			auto e=r.top().fst;
			if(lq[s.snd]!=ids){
				l.pop();
				continue;
			}
			if(lq[e.snd]!=ide){
				r.pop();
				continue;
			}
			cout<<s.fst<<","<<s.snd<<" "<<e.fst<<","<<e.snd<<"\n";
			if(s>e)break;
			l.pop(),r.pop();
			sum+=-s.fst+e.fst;
			l.push({e,ide}),r.push({s,ids});
		}
		cout<<sum<<"\n";
	}
	return 0;
}
