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
	ll n,m; cin>>n>>m;
	vector<ll>a(m);
	fore(i,0,m)cin>>a[i];
	//sort(ALL(a)); reverse(ALL(a));
	string b[n];
	ll mx=0;
	vector<ll>p(n);
	fore(i,0,n){
		p[i]=i+1;
		cin>>b[i];
		fore(j,0,m)if(b[i][j]=='o')p[i]+=a[j];
		mx=max(mx,p[i]);
	}
	vector<ii>ai;
	fore(i,0,m)ai.pb({a[i],i});
	sort(ALL(ai)); reverse(ALL(ai));
	fore(i,0,n){
		vector<ll>vis(m);
		fore(j,0,m)if(b[i][j]=='o')vis[j]=1;
		ll res=0;
		fore(j,0,m){
			if(p[i]>=mx)break;
			if(!vis[ai[j].snd])p[i]+=ai[j].fst,res++;
		}
		cout<<res<<"\n";
	}
	return 0;
}
