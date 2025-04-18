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
ii cv(ll i, ll j){
	ll x=i-j+m,y=j;
	x=max(x,(ll)0); x=min(x,n+m);
	y=max(y,(ll)0); y=min(y,n+m);
	return {x,y};
}
ll solve(vector<vector<ll>>a){
	n=SZ(a),m=SZ(a[0]);
	//cout<<"===\nsolve\n"; fore(i,0,n){imp(a[i]);}
	//cout<<k<<"\n";
	ll sp[n][m+1]={};
	fore(i,0,n)fore(j,1,m+1)sp[i][j]=a[i][j-1]+sp[i][j-1];
	//fore(i,0,n){imp(sp[i]);}
	map<ii,ll>b;
	fore(i,0,n)fore(j,0,m)b[{cv(i,j).fst,cv(i,j).snd}]=a[i][j];
	map<ii,ll>sd;
	fore(i,0,n)fore(j,0,m){
		auto [x,y]=cv(i,j);
		sd[{x,y+1}]=sd[{x,y}]+b[{x,y}];
		//sd[{i,j}]=b[{i,j-1}]+sd[{i,j-1}];
	}
	
	ll dp[n][m]={};
	ll ans=0;
	fore(i,0,n)fore(j,0,m){
		ll &res=dp[i][j];
		//cout<<i<<" "<<j<<": ";
		if(i){
			res+=dp[i-1][j];
			ii s=cv(i-k,j),e=cv(i,j+k);
			res-=sd[{e.fst,e.snd}]-sd[{s.fst,s.snd}];
			//cout<<dp[i-1][j]<<" "<<sd[e.fst][e.snd]-sd[s.fst][s.snd]<<" ";
		}
		res+=sp[i][min(j+k,m)]-sp[i][j];
		//cout<<"["<<i<<","<<min(j+k,m)<<" "<<i<<","<<j<<"|"<<sp[i][min(j+k,m)]<<"-"<<sp[i][j]<<"] ";
		//cout<<sp[i][min(j+k,m)]-sp[i][j]<<" = "<<res<<"\n";
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
