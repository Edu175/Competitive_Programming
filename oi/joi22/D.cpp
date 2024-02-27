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
typedef pair<ll,ll> ii;
const ll MAXN=5005;

ll dp[MAXN][MAXN];
ll opt[MAXN][MAXN];
const ll K=18;
ll st[K][1ll<<K];
ll a[MAXN];
ll n;

ll oper(ll i, ll j){
	if(i==-1)return j;
	if(j==-1)return i;
	if(a[i]>a[j])return i;
	return j;
}

void st_init(){
	fore(i,0,n)st[0][i]=i;
	fore(k,1,K)fore(i,0,n-(1ll<<k)+1){
		//if(i+(1ll<<k-1)>=n)break;
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
	}
}

ll st_query(ll s, ll e){
	if(e-s==0)return -1;
	ll k=63-__builtin_clzll(e-s);
	return oper(st[k][s],st[k][e-(1ll<<k)]);
}

void asi(ll &a, ll &b, ll ai, ll bi){
	if(ai>=a)a=ai,b=bi;
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i],a[i]--;
	st_init();
	fore(r,1,n+1)for(ll l=n-1;l>=0;l--){
		if(r-l<=1){
			opt[l][r]=l;
			continue;
		}
		ll k=st_query(l,r);
		ll &res=dp[l][r], &w=opt[l][r];
		fore(t,opt[l][r-1],opt[l+1][r]+1){
			if(t<k)asi(res,w,dp[t+1][r],t);
			if(t>k)asi(res,w,dp[l][t],t);
			if(t==k){
				ll k1=st_query(l,k),k2=st_query(k+1,r);
				//cout<<l<<","<<r<<" "<<k<<": "<<k1<<" "<<k2<<": ";
				if(oper(k1,k2)==k1)asi(res,w,dp[l][k]+k-k1,t);//,cout<<"1\n";
				else asi(res,w,dp[k+1][r]+k2-k,t);//,cout<<"2\n";
			}
		}
	}
	cout<<dp[0][n]<<"\n";
	return 0;
}
