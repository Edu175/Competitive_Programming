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
struct MinQ{ // for max
	deque<ii>q; ll dif=0;
	MinQ(){}
	void push(ll x){
		x-=dif;
		x=-x;
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
		if(!SZ(q))return 0;
		return -q.front().fst+dif;
	}
	void add(ll x){dif+=x;}
};
int main(){FIN;
	ll n,x; cin>>n>>x;
	vv b[3];
	fore(h,0,3){
		b[h].resize(n);
		fore(i,0,n)cin>>b[h][i];
	}
	vv dp(x+1);
	fore(i,0,n){
		ll w=b[0][i],v=b[1][i],c=b[2][i];
		vector<MinQ>qs(w);
		fore(i,0,SZ(dp)){
			auto &q=qs[i%w];
			q.push(dp[i]);
			dp[i]=q.query();
			q.add(v);
			if(i-w*c>=0)q.pop();
		}
	}
	cout<<dp[x]<<"\n";
	return 0;
}