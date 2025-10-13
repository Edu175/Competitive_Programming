#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

struct info{
	ll s,i,j; // i<j
	ii cmp;
	info(ll s, ll i, ll j):s(s),i(i),j(j),cmp({s,rng()}){}
	bool operator<(const info& rhs) const {
		return cmp<rhs.cmp;
	}
};

int main(){
	JET
	ll n,S; cin>>n>>S;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vector<info> b;
	fore(i,0,n)fore(j,i+1,n)b.pb(info(a[i]+a[j],i,j));
	sort(ALL(b)); // se puede mejor?
	ll p=n-1;
	vv vis(n);
	for(auto &x:b){
		vis[x.i]=vis[x.j]=1;
		while(p>=0){
			auto &y=b[p];
			ll s=x.s+y.s;
			if(s<S)break;
			if(s>S||vis[y.i]||vis[y.j])p--;
			else {
				cout<<x.i+1<<" "<<x.j+1<<" "<<y.i+1<<" "<<y.j+1<<"\n";
				return 0;
			}
		}
		vis[x.i]=vis[x.j]=0;
	}
	cout<<"IMPOSSIBLE\n";
	return 0;
}