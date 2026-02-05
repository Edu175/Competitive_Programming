#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a;i<b;++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e6;

ll a,b; vector<ll> cap(2);
ll cv(ll x, ll y){return x*(b+1)+y;}
ii cv(ll x){return {x/(b+1),x%(b+1)};}
ll d[MAXN];
tuple<ll,string,ll> fa[MAXN];
vector<string> ops={"MOVE","FILL","EMPTY"};
ii go(ll x, string t, ll bo){
	auto [A,B]=cv(x);
	ll w=0;
	if(t=="MOVE"){
		if(bo)swap(A,B),swap(a,b);
		ll q=min(A,b-B);
		w=q;
		A-=q; B+=q;
		if(bo)swap(A,B),swap(a,b);
	}
	else {
		ll &C=(bo?B:A);
		ll to=(t=="FILL"?cap[bo]:0);
		w=abs(to-C);
		C=to;
	}
	ll y=cv(A,B);
	return {y,w};
}
ll f(ll s, ll T){
	memset(d,-1,sizeof(d));
	priority_queue<ii> pq;
	d[s]=0; pq.push({0,s});
	while(!pq.empty()){
		auto [dis,x]=pq.top(); pq.pop(); dis=-dis;
		if(d[x]!=dis)continue;
		if(cv(x).first==T)return x;
		fore(i,0,3)fore(j,0,2){
			auto [y,w]=go(x,ops[i],j);
			ll nd=dis+w;
			if(d[y]==-1||nd<d[y]){
				d[y]=nd,pq.push({-nd,y});
				fa[y]={x,ops[i],j};
			}
		}
	}
	return -1;
}

int main(){
	ll T; cin>>a>>b>>T;
	cap={a,b};
	ll x=f(0,T);
	if(x==-1){
		cout<<"-1\n";
		return 0;
	}
	ll dis=d[x];
	stack<pair<string,ll>> q;
	while(x){
		auto [p,t,b]=fa[x];
		q.push({t,b});
		x=p;
	}
	cout<<q.size()<<" "<<dis<<"\n";
	while(!q.empty()){
		auto [t,b]=q.top(); q.pop();
		cout<<t<<" ";
		if(t=="MOVE"){
			char A='A',B='B';
			if(b)swap(A,B);
			cout<<A<<" "<<B<<"\n";
		}
		else cout<<char('A'+b)<<"\n";
	}
	return 0;
}