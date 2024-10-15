#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define forr(i,a,b) for(int i=b-1,jet=a;i>=jet;i--)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll INF=5e8;
struct MinQ{
	deque<ii>q;
	MinQ(){}
	void push(ll x){
		ll cnt=1;
		x=-x;
		while(SZ(q)&&x<=q.back().fst)
			cnt+=q.back().snd,q.pop_back();
		q.pb({x,cnt});
	}
	void pop(){
		if(!SZ(q))return;
		if(q.front().snd>1)q.front().snd--;
		else q.pop_front();
	}
	ll query(){
		// if(!SZ(q)) return INF;
		assert(SZ(q));
		return -q.front().fst;
	}
};
const ll MAXN=1e4+5,MAXM=5e3+5;
ll dp[MAXN][MAXM][2];
int main(){
	JET
	ll n,m,w; cin>>n>>m>>w;
	vector<ll>a(n),sp(n+1);
	fore(i,0,n)cin>>a[i];
	fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
	vector<MinQ>q(m+1);
	// cout<<SZ(sp)<<"\n";
	// for(auto i:sp)cout<<i<<" ";;cout<<"\n";
	forr(i,0,n){
		// cout<<i<<endl;
		fore(j,0,m+1){
			if(i+w+1<=n)q[j].pop();
			/*if(i+1>=w)*/q[j].push(dp[i+1][j][1]+sp[i+1]);
		}
		fore(j,0,m+1){
			dp[i][j][0]=max(dp[i+1][j][0],dp[i+1][j][1]);
			dp[i][j][1]=-INF;
			if(j&&i+w<=n){
				dp[i][j][1]=max(q[j-1].query()-sp[i],
								dp[i+w][j-1][0]+sp[i+w]-sp[i]);
			}
			// cout<<i<<" "<<j<<": "<<dp[i][j][0]<<","<<dp[i][j][1]<<"\n";
		}
	}
	ll res=max(dp[0][m][0],dp[0][m][1]);
	cout<<res<<"\n";
	return 0;
}