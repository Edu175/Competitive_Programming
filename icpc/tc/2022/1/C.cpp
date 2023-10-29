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
	ll n; cin>>n;
	ll arr[n][3];
	map<pair<ll,ll>,priority_queue<pair<ll,ll>>>mp;
	fore(i,0,n){
		fore(j,0,3)cin>>arr[i][j];
		ll a=arr[i][0],b=arr[i][1],c=arr[i][2];
		pair<ll,ll> p1={min(a,b),max(a,b)};
		pair<ll,ll> p2={min(b,c),max(b,c)};
		pair<ll,ll> p3={min(a,c),max(a,c)};
		mp[p1].push({c,i});
		if(p2!=p1)mp[p2].push({a,i});
		if(p3!=p1&&p3!=p2)mp[p3].push({b,i});
	}
	ll maxi=0;
	vector<ll> k;
	/*priority_queue<pair<ll,ll>>pq=mp[{5,5}];
	while(SZ(pq)){
		cout<<"{"<<pq.top().fst<<","<<pq.top().snd<<"} ";
		pq.pop();
	}
	cout<<"\n";*/
	for(auto i:mp){
		vector<ll> ki;
		ll sum=i.snd.top().fst;
		ki.pb(i.snd.top().snd);
		i.snd.pop();
		if(SZ(i.snd))sum+=i.snd.top().fst,ki.pb(i.snd.top().snd);
		if((min({i.fst.fst,i.fst.snd,sum}))>maxi){
			k=ki;
			maxi=(min({i.fst.fst,i.fst.snd,sum}));
		}
	}
	cout<<SZ(k)<<"\n";
	
	for(auto i:k)cout<<i+1<<" ";
	cout<<"\n";
	return 0;
}
