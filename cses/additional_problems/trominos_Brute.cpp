#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXP=63;

ll n,m;
string bin(ll mk){
	string s;
	fore(i,0,n){
		fore(j,0,m)s.pb('0'+((mk>>(m*i+j))&1));
		s.pb('\n');
	}
	return s;
}

unordered_map<ll,bool>dp;
vector<ll> mv[MAXP];
ll f(ll mk){
	if(dp.count(mk))return dp[mk];
	bool &res=dp[mk];
	if(mk==(1ll<<(n*m))-1)return res=1;
	ll x=__builtin_ctzll(~mk);
	for(auto m:mv[x])if(!(m&mk)&&f(mk|m))return res=1;
	return res=0;
}
vector<vector<ll>>a;
ll cnt=1;
void add(ll mk){
	fore(i,0,n)fore(j,0,m)if((mk>>(m*i+j))&1)a[i][j]=cnt;
	cnt++;
}
void build(ll mk){
	if(mk==(1ll<<(n*m))-1)return;
	ll x=__builtin_ctzll(~mk);
	for(auto m:mv[x])if(!(m&mk)&&f(mk|m)){
		add(m);
		build(mk|m);
		return;
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m;
		if(n==1||m==1){
			cout<<"NO\n";
			continue;
		}
		dp.clear();
		ll qu[4]={0,1,m,m+1};
		ll Ls[4]={};
		fore(i,0,4)fore(j,0,4)if(i!=j)Ls[i]|=1ll<<qu[j];
		//fore(i,0,4)cout<<bin(Ls[i])<<"\n";
		vector<ll>all;
		fore(i,0,n-1)fore(j,0,m-1)fore(k,0,4)all.pb(Ls[k]<<(m*i+j));
		fore(i,0,n*m)mv[i].clear();
		for(auto mk:all){
			fore(i,0,n*m)if((mk>>i)&1)mv[i].pb(mk);
		}
		/*fore(i,0,n*m){
			cout<<i<<" ("<<i/m<<","<<i%m<<"):\n";
			for(auto mk:mv[i])cout<<bin(mk)<<"\n";
			cout<<"\n";
		}*/
		
		if(f(0))cout<<"YES\n";
		else cout<<"NO\n";
		a.clear();
		cnt=1;
		a.resize(n,vector<ll>(m));
		build(0);
		fore(i,0,n){imp(a[i]);}
		cout<<endl;
	}
	return 0;
}
