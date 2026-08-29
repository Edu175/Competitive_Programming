#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
struct MinQ{ // max now
	deque<ii>q; ll dif=0;
	MinQ(){}
	void push(ll x){
		x=-x;
		ll cnt=1;
		x-=dif;
		while(SZ(q)&&x<=q.back().fst)cnt+=q.back().snd,q.pop_back();
		q.pb({x,cnt});
	}
	void pop(){
		if(!SZ(q))return;
		if(q.front().snd>1)q.front().snd--;
		else q.pop_front();
	}
	ll query(){
		assert(SZ(q));
		// if(!SZ(q))return INF; // querying empty queue
		return -(q.front().fst+dif);
	}
	void add(ll x){x=-x;dif+=x;}
};

vv getmxs(vv a){
	ll n=SZ(a);
	vv ret(n);
	MinQ q;
	fore(i,0,2*n){
		ll p=i%n;
		q.push(0);
		q.add(a[p]);
		if(i-n>=0)q.pop();
		ret[p]=max(q.query(),0ll);
	}
	return ret;
}
ll cmss(vv a){
	vv le=getmxs(a);
	return *max_element(ALL(le));
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll h=n; n*=2;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		ll mx=*max_element(ALL(a));
		if(mx<=0){
			cout<<mx<<"\n";
			continue;
		}
		ll res=cmss(a);
		
		auto b=vv(a.begin()+h,a.end());
		a=vv(a.begin(),a.begin()+h);
		auto la=getmxs(a); reverse(ALL(a));
		auto ra=getmxs(a); reverse(ALL(a)); reverse(ALL(ra));
	
		auto lb=getmxs(b); reverse(ALL(b));
		auto rb=getmxs(b); reverse(ALL(b)); reverse(ALL(rb));
		
		fore(i,0,h-1){
			ll cur1=la[i]+rb[i+1];
			ll cur2=lb[i]+ra[i+1];
			res=max({res,cur1,cur2});
		}
		cout<<res<<"\n";
	}
	return 0;
}
