#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto dfkg:v)cout<<dfkg<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

ll val[MAXN];
priority_queue<ii> pq[MAXN]; //val,to
struct node{
	vector<ll>v;
	priority_queue<ii>st; //val,node
	ll sum=0;
	node(ll x):v(1,x),/*st(1,),*/sum(val[x]){
		if(SZ(pq[x])){
			//cout<<x<<": "<<SZ(pq[x])<<endl;
			//cout<<pq[x].top().fst<<endl;
			st.push({pq[x].top().fst,x});
		}
	}
	node(){}
};
vector<ll> g[MAXN];
node cmp[MAXN]; ll id[MAXN];
void uf_init(){fore(i,0,MAXN)cmp[i]=node(i),id[i]=i;}
bool join(ll a, ll b){
	a=id[a],b=id[b];
	if(a==b)return 0;
	if(SZ(cmp[a].v)>SZ(cmp[b].v))swap(a,b);
	for(auto i:cmp[a].v)cmp[b].v.pb(i),id[i]=b;
	while(SZ(cmp[a].st))cmp[b].st.push(cmp[a].st.top()),cmp[a].st.pop();
	//puedo sacar self lopps ^
	//for(auto i:cmp[a].st)cmp[b].st.insert(i);
	cmp[b].sum+=cmp[a].sum;
	cmp[a].v.clear(); cmp[a].sum=0;
	return 1;
}

int main(){FIN;
	ll n; cin>>n;
	vector<ii>ed;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
		ed.pb({u,v});
	}
	ii a[n];
	fore(i,0,n)cin>>val[i],a[i]={val[i],i};
	sort(a,a+n);
	fore(x,0,n)for(auto y:g[x]){
		pq[x].push({-val[y],y});
		//cout<<x<<" + "<<y<<" "<<SZ(pq[x])<<endl;
	}
	uf_init();
	ll res[n];
	for(auto i:a){
		ll x=i.snd;
		node& c=cmp[id[x]];
		//cout<<x<<": "<<endl;
		while(SZ(c.st)&&-c.st.top().fst<c.sum){
			//imp(c.v);
			//cout<<SZ(c.st)<<": "<<c.st.top().fst<<","<<c.st.top().snd<<endl;
			ll k=c.st.top().snd;
			c.st.pop();
			//cout<<"pq "<<SZ(pq[k])<<endl;
			//cout<<pq[k].top().fst<<","<<pq[k].top().snd<<endl;
			if(!SZ(pq[k]))continue;
			ll y=pq[k].top().snd;
			pq[k].pop();
			if(SZ(pq[k]))c.st.push({pq[k].top().fst,k});
			if(id[x]==id[y])continue;
			join(x,y);
			c=cmp[id[x]];
		}
		res[x]=c.sum;
	}
	imp(res);
	return 0;
}
