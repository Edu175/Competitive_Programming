#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const ll MAXN=2e4+5;
pair<ll,ii> dp[MAXN];// {dp,{c,i}}
const ll INF=1e15;
int v[MAXN];
int c[MAXN];
ll k,n;
void upd(ll j, ll val, ll can, ll del, ll i){
	if(j>k) return;
	auto [de,p]=dp[j];
	auto [ncan,pos]=p;
	if((can+del<c[i])&&(de>val+del+1||(de==val+del+1&&ncan>can+del+1))){
		if(pos!=i){
			ncan=0;
		}
		if(ncan<can+del+1) upd(j+(c[i]-can-del)*v[i],de,0,c[i]-can-del,i);
		dp[j].fst=val+del+1;
		dp[j].snd=(ii){can+del+1,i};
	}
}
int main(){
	cin>>n;
	
	fore(i,0,n) cin>>v[i];
	fore(i,0,n) cin>>c[i];
	 cin>>k;
	dp[0]=(pair<ll,ii>){0,(ii){INF,INF}};
	fore(i,1,k+1){dp[i]=(pair<ll,ii>){INF,(ii){INF,INF}};}
	fore(i,0,n){
		fore(j,v[i],k+1){
			auto [de,p]= dp[j-v[i]];
			auto [can,pos]=p;
			if(de==INF) continue;
			if((can<c[i])||(i!=pos)){
				if(i!=pos) can=0;
				if(dp[j].fst>de+1||(de==de+1&&dp[j].snd.fst>can+1)){
					auto [ncan,npos]= dp[j].snd;
					if(npos!=i)ncan=0;
					if(ncan<can+1)upd(j+(c[i]-can)*v[i],dp[j].fst,ncan,c[i]-can-1,i);
					dp[j].fst=de+1;
					dp[j].snd=(ii){can+1,i};
				}
			}
		}
	}
	cout<<dp[k].fst<<"\n";
}