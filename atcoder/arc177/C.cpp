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
const ll MAXN=500*500+5;

ll a[MAXN];
ll n;
ll cv(ii i){return i.fst*n+i.snd;}
ii cv(ll i){return {i/n,i%n};}
vector<ll>p;
bool allowed(ii i){
	if(i.fst>=0&&i.fst<n&&i.snd>=0&&i.snd<n)return 1;
	return 0;
}
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
vector<ii>dir={{1,0},{0,-1},{-1,0},{0,1}};
ll bfs(ll s, ll e, ll w){
	vector<ll>d(n*n,-1);
	d[s]=(a[s]!=w);
	deque<ll>q;
	q.pb(s);
	while(SZ(q)){
		auto x=q.front(); q.pop_front();
		vector<ll>v;
		for(auto di:dir){
			if(!allowed(cv(x)+di))continue;
			ll y=cv(cv(x)+di);
			if(d[y]!=-1)continue;
			if(a[y]==w){
				d[y]=d[x];
				q.push_front(y);
			}
			else {
				d[y]=d[x]+1;
				q.pb(y);
			}
		}
	}
	return d[e];
}

int main(){FIN;
	cin>>n;
	fore(i,0,n*n){
		char c; cin>>c;
		a[i]=c=='R';
	}
	ll res=bfs(cv({0,0}),cv({n-1,n-1}),1)+bfs(cv({n-1,0}),cv({0,n-1}),0);
	cout<<res<<"\n";
	return 0;
}
