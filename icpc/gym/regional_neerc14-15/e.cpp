#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=105,MAXM=5e4+5;

ll g[MAXN][3];
char col[MAXN];

char may(vv h){
	map<ll,ll>mp;
	for(auto i:h)mp[col[i]]++;
	pair<ll,ll> mx={-1,0};
	for(auto _i:mp){
		ii i=_i;
		swap(i.fst,i.snd);
		mx=max(mx,i);
	}
	// cout<<"may "<<mx.fst<<": "<<char(mx.snd)<<"\n";
	return mx.snd;
}
string rps="RPS";
ll dame(char c){
	return find(ALL(rps),c)-rps.begin();
}
vv trans(vv h, char d, char c){
	ll j=dame(c);
	vv hi;
	for(auto i:h)if(col[i]==d)hi.pb(g[i][j]);
	return hi;
}
// ll cnt;

vector<vv> my;
vector<char> mycol;
vector<vv> hs;
const ll CYC=105;
// const ll CYC=4;

void f(ll x, vv h, vv fat){
	assert(SZ(h));
	// cout<<x<<": ";
	// for(auto i:h)cout<<i<<" ";;cout<<"| ";
	// for(auto i:fat)cout<<i<<" ";;cout<<"| ";
	my.pb({0,0,0});
	mycol.pb(0);
	hs.pb(h);
	char w=may(h);
	// cout<<w<<"\n";
	mycol[x]=w;
	if(SZ(fat)>CYC){
		ll p=-1;
		for(ll i=SZ(fat)-1;i>=0;i--){
			if(hs[fat[i]]==h)p=i;
		}
		assert(p!=-1);
		my[x][dame(w)]=fat[p+1];
		return;
	}
	vv to0,to1,to2;
	to0=trans(h,'R',w);
	to1=trans(h,'P',w);
	to2=trans(h,'S',w);
	auto doit=[&](ll b, vv to){
		if(SZ(to)){
			ll idx=SZ(my);
			//
			my[x][b]=idx;
			vv fati=fat;
			if(rps[b]==w)fati.pb(x);
			else fati.clear();
			f(idx,to,fati);
		}
	};
	doit(0,to0);
	doit(1,to1);
	doit(2,to2);
}

int main(){
	#ifdef ONLINE_JUDGE
	freopen("epic.in","r",stdin);     freopen("epic.out","w",stdout);
	#endif
	JET
	ll n; cin>>n;
	fore(i,0,n){
		cin>>col[i]>>g[i][0]>>g[i][1]>>g[i][2];
		fore(j,0,3)g[i][j]--;
		col[i]=rps[(dame(col[i])+1)%3];
	}
	vv all(n); iota(ALL(all),0);
	f(0,all,{});
	cout<<SZ(my)<<"\n";
	fore(i,0,SZ(my)){
		cout<<mycol[i]<<" ";
		fore(j,0,3)cout<<my[i][j]+1<<" ";
		cout<<"\n";
	}
	return 0;
	
}