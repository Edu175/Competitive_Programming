#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll n,m;
vector<ii> dirs;
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
ll cv(ii a){return a.fst*m+a.snd;}
ii cv(ll a){return {a/m,a%m};}
bool allowed(ii a){return a.fst>=0&&a.fst<n&&a.snd>=0&&a.snd<m;}

void see_dists(vv d){
	vector<vector<ii>> lev(n*m+1);
	fore(i,0,n)fore(j,0,m){
		ll p=cv({i,j});
		if(d[p]!=-1)lev[d[p]].pb({i,j});
	}
	fore(l,0,SZ(lev))if(SZ(lev[l])){
		cerr<<"distance "<<l<<":\n";
		vector<string> arr(n,string(m,'.'));
		for(auto [i,j]:lev[l])arr[i][j]='x';
		fore(i,0,n)cout<<arr[i]<<"\n";
		cout<<"\n";
	}
}

ll manh(ii a, ii b){return abs(a.fst-b.fst)+abs(a.snd-b.snd);}
ll rey(ii a, ii b){return max(abs(a.fst-b.fst),abs(a.snd-b.snd));}
ll sq(ll a){return a*a;}
double dist(ii a, ii b){
	// return sqrt(sq(a.fst-b.fst)+sq(a.snd-b.snd));
	return max(rey(a,b)/4.,manh(a,b)/6.);
}
map<ii,ll> d;
void bfs(ii s){
	// vv d(n*m,-1);
	d[s]=0;
	queue<ii>q; q.push(s);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto dd:dirs){
			ii py=x+dd;
			if(!allowed(py))continue;
			if(d.count(py)||dist({0,0},py)>15)continue;
			d[py]=d[x]+1;
			q.push(py);
		}
	}
	// see_dists(d);
}
ll brute(ii s, ii t){
	if(s==t)return 0;
	set<ll> st;
	queue<ii> q; q.push({0,cv(s)}); st.insert(cv(s));
	while(SZ(q)){
		auto [d,x]=q.front(); q.pop();
		for(auto dd:dirs){
			ii py=cv(x)+dd;
			if(!allowed(py))continue;
			ll y=cv(py);
			if(st.count(y))continue;
			if(py==t)return d+1;
			q.push({d+1,y});
			st.insert(y);
		}
	}
	assert(0);
}
const ll INF=1e18;
ll greedy(ii s, ii t){
	set<ii> st;
	ll res=0;
	while(dist(s,t)>5){
		cerr<<"greedy "<<s.fst<<","<<s.snd<<" "<<t.fst<<","<<t.snd<<"\n";
		st.insert(s);
		ii wh={0,0}; ll val=INF;
		for(auto dd:dirs)if(!st.count(s+dd)){
			ll cur=dist(s+dd,t);
			if(allowed(s+dd)&&cur<val)val=cur,wh=dd;
		}
		assert(wh!=ii({0,0}));
		res++,s=s+wh;
	}
	return res+brute(s,t);
}

ll get(ii s){
	if(dist(s,{0,0})<=15)return d[s];
	ii wh={0,0}; ll val=INF;
	for(auto dd:dirs){
		ll cur=dist(s+dd,{0,0});
		if(allowed(s+dd)&&cur<val)val=cur,wh=dd;
	}
	return 1+get(s+wh);
}



int main(){FIN;
	fore(si,0,2)fore(sj,0,2)fore(sw,0,2){
		ll a=si?-1:1;
		ll b=sj?-2:2;
		if(sw)swap(a,b);
		dirs.pb({a,b});
	}
	if(1){
		ii s;
		cin>>n>>m>>s.fst>>s.snd;
		// bfs(cv(s));
		vv d(n*m,-1);
		fore(i,0,n)fore(j,0,m){
			ll di=greedy(s,{i,j});
			d[cv({i,j})]=di;
		}
		see_dists(d);
	}
	else {
		bfs({0,0});
		ll t; cin>>t;
		while(t--){
			ll x,y; cin>>x>>y; x--,y--;
			cout<<get({x,y})<<"\n";
		}
	}
	return 0;
}