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

ll solve(vector<vector<char>>a, ll k){
	ll n=SZ(a),m=SZ(a[0]);
	ll res=k+5;
	if(k>m)return res;
	fore(i,0,n){
		ll x=0,p=0;
		fore(j,0,k){
			x+=a[i][j]=='x';
			p+=a[i][j]=='.';
		}
		if(!x)res=min(res,p);
		fore(j,k,m){
			x-=a[i][j-k]=='x';
			p-=a[i][j-k]=='.';
			x+=a[i][j]=='x';
			p+=a[i][j]=='.';
			if(!x)res=min(res,p);
		}
	}
	return res;
}

int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	vector<vector<char>>a(n,vector<char>(m));
	fore(i,0,n)fore(j,0,m)cin>>a[i][j];
	ll res=solve(a,k);
	vector<vector<char>>ai(m,vector<char>(n));
	fore(i,0,n)fore(j,0,m)ai[m-1-j][i]=a[i][j];
	res=min(res,solve(ai,k));
	if(res>k)cout<<"-1\n";
	else cout<<res<<"\n";
	return 0;
}
