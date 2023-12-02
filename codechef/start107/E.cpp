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
const ll MAXN=105,R=3.5e4,MAXS=MAXN*R,INF=1e10;

ll dp1[2][MAXS];
ll dp2[2][MAXS];

void f1(vector<ii>a){ //max score with this capacity left
	ll n=SZ(a);
	fore(i,0,MAXS)dp1[n%2][i]=0;
	for(ll i=n-1;i>=0;i--)fore(s,0,MAXS){
		ll &res=dp1[i%2][s];
		res=dp1[(i+1)%2][s];
		if(s>=a[i].fst)res=max(res,a[i].snd+dp1[(i+1)%2][s-a[i].fst]);
	}
}
void f2(vector<ii>a){ //min capacitiy with this score
	ll n=SZ(a);
	fore(i,0,MAXS)dp2[n%2][i]=INF;
	dp2[n%2][0]=0;
	for(ll i=n-1;i>=0;i--)fore(s,0,MAXS){
		ll &res=dp2[i%2][s];
		res=dp2[(i+1)%2][s];
		if(s>=a[i].snd)res=min(res,a[i].fst+dp2[(i+1)%2][s-a[i].snd]);
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,v; cin>>n>>v;
		vector<ii>a(n),b,c;
		fore(i,0,n){
			cin>>a[i].fst>>a[i].snd;
			if(a[i].fst<R)b.pb(a[i]);
			else c.pb(a[i]);
		}
		f1(b);
		f2(c);
		vector<ii>d(MAXS);
		fore(i,0,MAXS)d[i]={dp2[0][i],i};
		sort(ALL(d));
		ll j=0,mx=0;
		ll res=0;
		for(ll s=MAXS-1;s>=0;s--){
			while(j<MAXS&&d[j].fst+s<=v)mx=max(mx,d[j].snd),j++;
			if(s<=v)res=max(res,dp1[0][s]+mx);
		}
		cout<<res<<"\n";
	}
	return 0;
}
