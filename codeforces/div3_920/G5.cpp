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
ll n,m,k;

ii cut(ll i, ll j){
	//cout<<"cut "<<i<<","<<j<<" --> ";
	if(i<0)j+=-i,i+=-i;
	if(j<0)i+=-j,j+=-j;
	if(i>n)j+=n-i,i+=n-i;
	if(j>m)i+=m-j,j+=m-j;
	//cout<<i<<","<<j<<endl;
	if(!(0<=i&&i<=n&&0<=j&&j<=m))return {-1,-1};
	return {i,j};
}
ll solve(vector<vector<ll>>a){
	n=SZ(a),m=SZ(a[0]);
	ll sp[n][m+1]={};
	fore(i,0,n)fore(j,1,m+1)sp[i][j]=a[i][j-1]+sp[i][j-1];
	ll sd[n+1][m+1]={};
	fore(i,1,n+1)fore(j,1,m+1)sd[i][j]=sd[i-1][j-1]+a[i-1][j-1];
	ll dp[n][m]={};
	ll ans=0;
	fore(i,0,n)fore(j,0,m){
		ll &res=dp[i][j];
		if(i){
			res+=dp[i-1][j];
			ii e=cut(i,j+k),s=cut(i-k,j);
			if(s.fst!=-1&&e.fst!=-1)res-=sd[e.fst][e.snd]-sd[s.fst][s.snd];
		}
		res+=sp[i][min(j+k,m)]-sp[i][j];
		ans=max(ans,res);
	}
	return ans;
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m>>k; k++;
		vector<vector<ll>>a(n,vector<ll>(m));
		fore(i,0,n)fore(j,0,m){
			char c; cin>>c;
			a[i][j]=c=='#';
		}
		ll res=0;
		fore(_,0,4){
			res=max(res,solve(a));
			vector<vector<ll>>ai(m,vector<ll>(n));
			fore(i,0,n)fore(j,0,m)ai[m-1-j][i]=a[i][j];
			a=ai;
			swap(n,m);
		}
		cout<<res<<"\n";
	}
	return 0;
}

