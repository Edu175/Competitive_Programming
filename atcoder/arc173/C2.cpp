#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n),p(n);
	fore(i,0,n)cin>>a[i],a[i]--,p[a[i]]=i;
	set<ll>st[2];
	fore(i,0,n-1)st[i&1].insert(i);
	vector<ll>b(n,1);
	vector<ll>res(n,n+5);
	fore(i,0,n){
		ll x=p[i];
		st[x&1].erase(x);
		st[(x-1)&1].erase(x-1);
		b[x]=0;
		if(x&&x<n-1&&b[x-1]==b[x+1]){
			res[x]=3;
		}
		else {
			set<ll> &s1=st[(x+1)&1], &s0=st[x&1];
			auto lwb=s1.lower_bound(x);
			
			if(lwb!=s1.end())res[x]=min(res[x],*lwb-x+2);
			
			if(x<n-1&&lwb!=s1.begin())res[x]=min(res[x],x-*prev(lwb)+2);
			
			lwb=s0.lower_bound(x);
			
			if(lwb!=s0.begin())res[x]=min(res[x],x-*prev(lwb)+1);
			
			if(x&&lwb!=s0.end())res[x]=min(res[x],*lwb-x+3);
			
		}
		b[x]=-1;
		if(x&&b[x-1]==-1)st[(x-1)&1].insert(x-1);
		if(x<n-1&&b[x+1]==-1)st[x&1].insert(x);
		if(res[x]%2==0)res[x]++;
		if(res[x]>n)res[x]=-1;
		assert(res[x]!=1);
	}
	imp(res);
	return 0;
}
