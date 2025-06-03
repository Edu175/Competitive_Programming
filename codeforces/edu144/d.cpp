#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e15;
struct MinQ{
	deque<ii>q;
	MinQ(){}
	void push(ll x){
		ll cnt=1;
		while(SZ(q)&&x<=q.back().fst)cnt+=q.back().snd,q.pop_back();
		q.pb({x,cnt});
	}
	void pop(){
		if(!SZ(q))return;
		if(q.front().snd>1)q.front().snd--;
		else q.pop_front();
	}
	ll query(){
		if(!SZ(q))return INF;
		return q.front().fst;
	}
};

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k,x; cin>>n>>k>>x;
		if(x<0){
			x=abs(x);
			k=n-k;
		}
		vv a(n);
		fore(i,0,n)cin>>a[i];
		auto chicos=[&](vv a){ // subarrays de sz <=k
			for(auto &i:a)i+=x;
			ll res=0;
			vv sp(n+1);
			fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
			MinQ mq;
			fore(r,0,n){
				mq.push(sp[r]);
				if(r>=k)mq.pop();
				res=max(res,sp[r+1]-mq.query());
			}
			// cout<<"chicos "<<res<<"\n";
			return res;
		};
		auto grandes=[&](vv a){ // subarrays de sz >=k
			for(auto &i:a)i-=x;
			vv sp(n+1);
			fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
			ll res=-INF,mn=INF;
			fore(r,0,n+1){
				if(r>=k)mn=min(mn,sp[r-k]);
				res=max(res,sp[r]-mn);
			}
			res+=k*2*x; // tienen al menos k elementos
			// cout<<"grandes "<<res<<"\n";
			return res;
		};
		cout<<max(chicos(a),grandes(a))<<"\n";
	}
	return 0;
}