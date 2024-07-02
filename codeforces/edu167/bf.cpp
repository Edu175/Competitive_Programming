#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1005;

vector<ll> g[MAXN];

ll idx[MAXN],lw[MAXN],cmp[MAXN],is[MAXN],qidx=0,qcmp=0;
stack<ll>st;

void tjn(ll x){
	lw[x]=idx[x]=qidx++;
	st.push(x); cmp[x]=-2;
	for(auto y:g[x]){
		if(idx[y]==-1||cmp[y]==-2){
			if(idx[y]==-1)tjn(y);
			lw[x]=min(lw[x],lw[y]);
		}
	}
	if(lw[x]==idx[x]){
		// ll y;
		// do{y=st.top(),st.pop(),cmp[y]=x;}
		// while(y!=x);
		while(st.top()!=x){
			cmp[st.top()]=qcmp; st.pop();
		}
		cmp[st.top()]=qcmp; st.pop();
		qcmp++;
	}
}

ll N;
void scc(){
	fore(i,0,N)idx[i]=-1;
	qidx=qcmp=0;
	fore(x,0,N)if(idx[x]==-1)tjn(x);
}

int main(){FIN;
	ll n,n2,m; cin>>n>>n2>>m;
	N=n+n2;
	vector<ii> ed;
	fore(i,0,m){
		ll x,y; cin>>x>>y; x--,y--;
		char c; cin>>c;
		y+=n;
		if(c=='B')ed.pb({x,y});
		else ed.pb({y,x});
	}
	fore(i,0,m){
		g[ed[i].fst].pb(ed[i].snd);
		scc();
		vector<ll>c(qcmp);
		fore(x,0,N)c[cmp[x]]++;
		ll res=0;
		fore(x,0,qcmp)if(c[x]>1)res+=c[x]*c[x];
		cout<<res<<"\n";
	}
	return 0;
}