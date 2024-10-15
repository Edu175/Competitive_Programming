#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=405;
ll mem[3][3][MAXN][MAXN];
int main(){
	JET
	ll n; cin>>n;
	vv d(n);
	fore(i,0,n)cin>>d[i];
	vector<vv> a(3,vv(n));
	fore(h,0,3)fore(i,0,n)cin>>a[h][i];
	vector<vector<vector<ii>>> ts(3,vector<vector<ii>>(n));
	auto cut=[&](ll x){return x<n?x:0;};
	auto get=[&](ll p, ll s){
		auto t=ts[p][s];
		if(SZ(t))return t;
		t=vector<ii>(n,{-1,-1});
		ll tot=0;
		for(ll i=s;t[i].fst==-1;i=cut(i+1)){
			t[i]={tot,tot+a[p][i]};
			tot+=a[p][i]+d[i];
		}
		return t;
	};
	mset(mem,-1);
	auto choca=[&](ll pa, ll pb, ll sa, ll sb)->ll{
		ll &res=mem[pa][pb][sa][sb];
		if(res!=-1)return res;
		auto ta=get(pa,sa);
		auto tb=get(pb,sb);
		fore(i,0,n){
			ll l=max(ta[i].fst,tb[i].fst);
			ll r=min(ta[i].snd,tb[i].snd);
			if(l<r)return res=1;
		}
		return res=0;
	};
	fore(i,0,n)fore(j,0,n)fore(k,0,n){
		if(!choca(0,1,i,j)&&!choca(0,2,i,k)&&!choca(1,2,j,k)){
			cout<<i+1<<" "<<j+1<<" "<<k+1<<"\n";
			return 0;
		}
	}
	cout<<"impossible\n";
}