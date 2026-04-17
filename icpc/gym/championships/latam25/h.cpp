#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll INF=1e18;

map<ll,vector<ii>> best;
ll del=INF;
vv widA,widB;
ll wa=-10,wb=-10;
vv idA,idB;
ll cur=0;
ll lim,A,B,d;
ll need=0;
void g(ll d, ll i){
	if(d==0){
		if(cur<del){
			del=cur;
			widA=idA;
			widB=idB;
			wa=A,wb=B;
		}
		return;
	}
	fore(j,i,lim){
		auto [v,id]=best[B][j];
		if(need){
			ll good=1;
			for(auto otr:idA)good&=otr!=id;
			if(!good)continue;
		}
		cur+=v; idB.pb(id);
		g(d-1,j+1);
		cur-=v; idB.pop_back();
	}
}
void f(ll c, ll i){
	if(c==0){
		g(d,0);
		return;
	}
	fore(j,i,lim){
		auto [v,id]=best[A][j];
		cur+=v; idA.pb(id);
		f(c-1,j+1);
		cur-=v; idA.pop_back();
	}
}

void doit(ll _a, ll c, ll _b, ll _d, ll _need=0){
	A=_a,B=_b,d=_d,lim=min(c+d,2ll); need=_need;
	f(c,0);
}

int main(){
	JET
	ll n; cin>>n;
	vector<vv> a(n,vv(4));
	fore(i,0,n)fore(j,1,4)cin>>a[i][j];
	map<ll,priority_queue<ii>> ch;
	vv po(n);
	auto val=[&](ll i, ll d)-> ll { // INF if invalid
		auto &p=po[i];
		if(p+d>=4||p+d<0)return INF;
		return a[i][p+d]-a[i][p];
	};
	auto upd=[&](ll i){
		fore(d,-3,4){
			ll v=val(i,d);
			if(v<INF)ch[d].push({-v,i});
		}
	};
	auto get=[&](ll d)-> ii { // v,i
		auto &pq=ch[d];
		while(SZ(pq)){
			auto [v,i]=pq.top(); v=-v;
			if(val(i,d)==v)return {v,i};
			pq.pop();
		}
		return {INF,-1};
	};
	fore(i,0,n)upd(i);
	ll res=0;
	fore(k,1,3*n+1){
		// cout<<k<<": ";
		// for(auto i:po)cout<<i<<" ";;cout<<"\n";
		// map<ll,vector<ii>> best;
		best.clear();
		fore(d,-3,4){
			fore(c,0,2){
				auto p=get(d);
				if(p.snd!=-1)ch[d].pop();
				best[d].pb(p);
			}
			for(auto p:best[d]){
				p.fst*=-1;
				if(p.snd!=-1)ch[d].push(p);
			}
		}
		del=INF;
		widA.clear(),widB.clear();
		wa=-10,wb=-10;
		idA.clear(),idB.clear();
		cur=0;
		
		doit(1,1,0, 0); // +1
		doit(2,1,-1,1,1); // +2 -1
		doit(3,1,-2,1); // +3 -2
		doit(3,1,-1,2); // +3 -1 -1
		// doit(2,2,-1,3); // +2 +2 -1 -1 -1
		doit(2,2,-3,1); // +2 +2 -3
		
		// cout<<"del "<<del<<"\n";
		// cout<<"wa "<<wa<<" wb "<<wb<<"\n";
		assert(wa!=-10);
		res+=del;
		cout<<res<<"\n";
		for(auto i:widA){
			po[i]+=wa,upd(i);
			// cout<<"widA "<<i<<"\n";
		}
		for(auto i:widB){
			po[i]+=wb,upd(i);
			// cout<<"widB "<<i<<"\n";
		}
		// cout<<"\n\n";
	}
	return 0;
}