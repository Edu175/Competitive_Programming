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

map<pair<ll,vector<pair<ll,ll>>>,ll>dp;
ll n;
ll db=0;
ll cost(vector<pair<ll,ll>>a){
	ll res=0;
	fore(mk,0,1ll<<(n+1)){
		vector<ll>vis(n);
		//if(db)cout<<mk<<": ";
		fore(i,0,n+1){
			ll x=a[i].fst;
			if(mk&(1ll<<i))x=a[i].snd;
			//if(db)cout<<x<<" ";
			if(vis[x]){
				//if(db)cout<<"| \n";
				res+=(i&1?1:-1);
				break;
			}
			vis[x]=1;
		}
	}
	return res;
}
ll f(ll p, vector<pair<ll,ll>>a){
	if(dp.count({p,a}))return dp[{p,a}];
	ll &res=dp[{p,a}];
	if(p==n+1)return res=cost(a);
	if(p&1){
		res=(1ll<<(n+5))+5;
		fore(i,0,n)fore(j,i,n){
			vector<pair<ll,ll>>ai=a;
			ai.pb({i,j});
			res=min(res,f(p+1,ai));
		}
	}
	else{
		res=-((1ll<<(n+5))+5);
		fore(i,0,n)fore(j,i,n){
			vector<pair<ll,ll>>ai=a;
			ai.pb({i,j});
			res=max(res,f(p+1,ai));
		}
	}
	return res;
}
vector<pair<ll,ll>>ans;
void build(ll p, vector<pair<ll,ll>>a){
	ll &res=dp[{p,a}];
	if(p==n+1){
		ans=a;
		return;
	}
	fore(i,0,n)fore(j,i,n){
		vector<pair<ll,ll>>ai=a;
		ai.pb({i,j});
		if(res==f(p+1,ai)){
			build(p+1,ai);
			break;
		}
	}
}
int main(){FIN;
	ll k; cin>>n>>k;
	vector<pair<ll,ll>>a(k);
	fore(i,0,k)cin>>a[i].fst>>a[i].snd,a[i].fst--,a[i].snd--;
	/*if(k==0&&n>1){
		cout<<(1ll<<n)<<" "<<(1ll<<n)<<"\n";
		return 0;
	}*/
	ll res=f(k,a);
	cout<<res<<"\n";
	build(k,a);
	for(auto i:ans)cout<<i.fst<<" "<<i.snd<<"\n";
	//db=1; cout<<"==============\n";
	cout<<(1ll<<n)+res/2<<" "<<(1ll<<n)-res/2<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
