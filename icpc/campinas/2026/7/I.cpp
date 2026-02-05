#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef unordered_map<ull,ll> table;
ll n,m;
vector<ii> sto(5);
vv tim(5);
ull vis;
ll cv(ll i, ll j){return m*i+j;}
const ll MAXN=5e6;
int tr[MAXN][2],cu[MAXN][2],qidx=0;

ll add(ll x, ll j){
	auto &res=tr[x][j];
	if(res!=-1)return res;
	return res=++qidx;
}
ll len;
void add_string(ull mk, ll w){
	ll x=0;
	fore(j,0,len)x=add(x,mk>>j&1);
	cu[x][w]++;
	cerr<<"add_string "<<mk<<" "<<w<<": "<<x<<"\n";
}
void reset(){
	fore(i,0,qidx+3){
		tr[i][0]=tr[i][1]=-1;
		cu[i][0]=cu[i][1]=0;
	}
	qidx=0;
}
ll nxt=0;
ll cant=0;
void f(ll i, ll j, ll t){
	ll dis=abs(i-sto[nxt].fst)+abs(j-sto[nxt].snd),ten=tim[nxt]-t;
	if(ten<dis)return;
	if(ten==0){
		add_string(vis,(nxt-1)&1);
		cant++;
		return;
	}
	ll pos=cv(i,j);
	vis^=1ull<<pos;
	fore(w,0,2)fore(di,0,2){
		ll r=i,c=j;
		auto &md=(w?r:c); md+=di?1:-1;
		if(r<0||r>=n||c<0||c>=m||(vis>>cv(r,c)&1))continue;
		f(r,c,t+1);
	}
	vis^=1ull<<pos;
}


table mp;
void f2(ll x, ll u, ull mk, ll d){
	cerr<<"f2 "<<x<<" "<<u<<" "<<mk<<" "<<d<<"\n";
	if(x==-1||u==-1)return;
	if(cu[x][0]){
		mp[mk]+=ll(cu[x][0])*cu[u][1];
		return;
	}
	fore(i,0,2)fore(j,0,2-i){
		f2(tr[x][i],tr[u][j],(mk<<1)|(i||j),d+1);
	}
}

int main(){FIN;
	mset(tr,-1);
	ll test=0;
	while(1){
		cin>>n>>m;
		if(!n)break;
		cout<<"Case #"<<++test<<": ";
		
		sto[0]={0,0};
		fore(i,1,4)cin>>sto[i].fst>>sto[i].snd;
		sto[4]={0,1};
		
		fore(i,0,5)tim[i]=i*n*m/4-1;
		tim[0]=0;
		
		table a,b;
		
		len=n*m-1;
		cerr<<"\n";
		fore(i,0,4){
			auto s=sto[i];
			nxt=i+1;
			f(s.fst,s.snd,tim[i]);
			cant=0;
			if(i&1){
				f2(0,0,0,0);
				(i==1?a:b)=mp; mp.clear();
				reset();
			}
		}
		cerr<<"a: ";for(auto [mk,cnt]:a)cerr<<mk<<","<<cnt<<" ";;cerr<<"\n";
		cerr<<"b: ";for(auto [mk,cnt]:b)cerr<<mk<<","<<cnt<<" ";;cerr<<"\n";
		ull all=(1ull<<len)-1;
		ll res=0;
		for(auto [mk,cnt]:a){
			ull cmp=all^mk;
			res+=cnt*b[cmp];
		}
		cout<<res<<"\n";
		
	}
	return 0;
}