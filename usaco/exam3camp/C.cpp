#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e6+5,INF=MAXN;

ll n,p,d;
ll a[MAXN];
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
bool can(ll m){
	if(m<=d)return 1;
	ll sm=0,sd=0;
	fore(i,0,d)sd+=a[i];
	fore(i,0,m)sm+=a[i];
	MinQ st;
	st.push(sm);
//	multiset<ll>st={sm};
//	vector<ll>sums(n);
//	sums[0]=sm;
	fore(i,0,n-d+1){
		
		if(st.query()-sd<=p)return 1;
		
		if(i+m<n){
			sm=sm-a[i]+a[i+m];
			st.push(sm);
//			sums[i+1]=sm;
		}
		if(i+d-m>=0)st.pop();
//		st.erase(st.find(sums[i+d-m]));
		if(i+d<n)sd=sd-a[i]+a[i+d];
	}
	return 0;
}

int main(){FIN;
	cin>>n>>p>>d;
	fore(i,0,n)cin>>a[i];
	ll l=0,r=n;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))l=m+1;
		else r=m-1;
	}
	cout<<r<<"\n";
	return 0;
}
