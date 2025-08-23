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
struct MinQ{
	deque<ii>q;
	MinQ(){}
	void push(ll x){
		x=-x; // quiero max
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
		assert(SZ(q));
		return -q.front().fst;
	}
};

int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<vv> a(n,vv(m));
	fore(i,0,n)fore(j,0,m)cin>>a[i][j];
	ll h,w; cin>>h>>w;
	vector<vv> b(n);
	fore(i,0,n){
		MinQ q;
		fore(j,0,w)q.push(a[i][j]);
		fore(j,w,m+1){
			b[i].pb(q.query());
			q.pop();
			if(j<m)q.push(a[i][j]);
		}
	}
	m=SZ(b[0]);
	vector<vv> res(n+1);
	fore(j,0,m){
		MinQ q;
		fore(i,0,h)q.push(b[i][j]);
		fore(i,h,n+1){
			res[i].pb(q.query());
			q.pop();
			if(i<n)q.push(b[i][j]);
		}
	}
	fore(i,h,n+1){
		fore(j,0,m){
			if(j)cout<<" ";
			cout<<res[i][j];
		}
		cout<<"\n";
	}
	return 0;
}
// la puta que te pario presentation error
