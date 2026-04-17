#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n; cin>>n;
	vector<ll>l(n),d(n),c(n);
	fore(i,0,n)cin>>l[i]>>d[i]>>c[i];
	priority_queue<ii>pq;
	deque<ll>dq;
	fore(i,0,n)pq.push({-l[i],i});
	vector<ll>res;
	ll t=0;
	while(SZ(pq)+SZ(dq)){
		ll i=-1,j=-1;
		if(SZ(dq))i=dq.front();
		if(SZ(pq))j=pq.top().snd;
		if(!SZ(dq)){
			dq.pb(j),t=l[j],pq.pop();
		}
		else if(!SZ(pq)||t+d[i]<=l[j]){
			t+=d[i];
			dq.pop_front();
		}
		else {
			if(c[j]){
				res.pb(i);
				dq.pop_front();
				dq.push_front(j);
				t=l[j];
			}
			else dq.pb(j);
			pq.pop();
		}
	}
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}