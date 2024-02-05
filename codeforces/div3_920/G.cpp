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

struct SP{
	ll n,m; vector<vector<ll>>sp;
	SP(){}
	SP(vector<vector<ll>>a):n(SZ(a)),m(SZ(a[0])),sp(n+1,vector<ll>(m+1)){
		fore(i,1,n+1)fore(j,1,m+1)sp[i][j]=a[i-1][j-1]+sp[i][j-1];
		fore(i,1,n+1)fore(j,1,m+1)sp[i][j]+=sp[i-1][j];
	}
	ll get(ll i0, ll j0, ll i1, ll j1){
		i0=max(i0,(ll)0),j0=max(j0,(ll)0);
		i0=min(i0,n),j0=min(j0,m);
		i1++,j1++;
		i1=max(i1,(ll)0),j1=max(j1,(ll)0);
		i1=min(i1,n),j1=min(j1,m);
		return sp[i1][j1]-sp[i0][j1]-sp[i1][j0]+sp[i0][j0];
	}
};
ll n,m,k;
ii cv(ii p){
	return {p.fst-p.snd+n,p.fst+p.snd};
}
vector<vector<ll>>dp[4];
SP nor,diag;
ll f(ll h, ll i, ll j){
	if(i<0||i>=n||j<0||j>=m)return 0;
	ll &res=dp[h][i][j];
	if(res!=-1)return res;
	res=0;
	if(h<2)res=f(h,i,j+1);
	else res=f(h,i,j-1);
	if(h==0||h==3)res+=nor.get(i-k+1,j,i,j);
	else res+=nor.get(i,j,i+k-1,j);
	ii s,e;
	if(h==0){
		s={i-k+1,j+1};
		e={i,j+k};
	}
	if(h==1){
		s={i,j+k};
		e={i+k-1,j+1};
	}
	if(h==2){
		s={i,j-k};
		e={i+k-1,j-1};
	}
	if(h==3){
		s={i-k+1,j-1};
		e={i,j-k};
	}
	res-=diag.get(cv(s).fst,cv(s).snd,cv(e).fst,cv(e).snd);
	return res;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m>>k; k++;
		vector<vector<ll>>a(n,vector<ll>(m));
		fore(i,0,n)fore(j,0,m){
			char c; cin>>c;
			a[i][j]=c=='#';
		}
		vector<vector<ll>>b(n+m,vector<ll>(n+m));
		fore(i,0,n)fore(j,0,m)b[i-j+m][i+j]=a[i][j];
		nor=SP(a);
		diag=SP(b);
		
		fore(h,0,4){
			dp[h].clear();
			dp[h].resize(n,vector<ll>(m,-1));
		}
		ll res=0;
		fore(h,0,4)fore(i,0,n)fore(j,0,n)res=max(res,f(h,i,j));
		cout<<res<<"\n";
	}
	return 0;
}
