#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF=1e15;

int main(){FIN;
	ll n; cin>>n;
	vector<ll>b(n),a(n+1);
	fore(i,0,n)cin>>b[i];
	fore(i,1,n)a[i]=b[i]-b[i-1];
	a[0]=a[n]=INF;
	n++;
	// imp(a);
	priority_queue<pair<ll,ii>>pq;
	set<ll>st;
	fore(i,0,n)if(a[i])st.insert(i);
	auto upd=[&](ll i, ll j){
		while(!(a[i]&&a[j]));
		if((a[i]<0)!=(a[j]<0)){
			// cout<<"upd "<<i<<","<<j<<"\n";
			if(a[j]<0)swap(i,j);
			pq.push({-abs(i-j),{i,j}});
		}
	};
	for(auto it=next(st.begin());it!=st.end();it++)upd(*prev(it),*it);
	ll res=0;
	while(SZ(pq)){
		auto [d,par]=pq.top(); pq.pop(); d=-d;
		auto [i,j]=par;
		if(!st.count(i)||!st.count(j))continue;
		ll q=min(abs(a[i]),abs(a[j]));
		imp(a);
		imp(st);
		cout<<i<<","<<j<<": "<<d<<" "<<q<<"\n";
		res+=q*d;
		a[i]+=q;
		if(!a[i]){
			// cout<<"saco "<<i<<"\n";
			st.erase(i);
			auto it=st.lower_bound(i);
			if(it!=st.end()&&it!=st.begin())upd(*prev(it),*it);
		}
		a[j]-=q;
		if(!a[j]){
			st.erase(j);
			// cout<<"saco "<<j<<"\n";
			auto it=st.lower_bound(j);
			if(it!=st.end()&&it!=st.begin())upd(*prev(it),*it);
		}
	}
	cout<<res<<"\n";
	return 0;
}