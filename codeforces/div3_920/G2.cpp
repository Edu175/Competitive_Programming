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

ll k;
ll solve(vector<vector<ll>>a){
	ll n=SZ(a),m=SZ(a[0]);
	cout<<"===\nsolve\n"; fore(i,0,n){imp(a[i]);}
	ll sp[n+1][m+1]={};
	fore(i,1,n+1)fore(j,1,m+1)sp[i][j]=a[i-1][j-1]+sp[i][j-1];
	fore(i,1,n+1)fore(j,1,m+1)sp[i][j]+=sp[i-1][j];
	vector<ll>diag(n+m);
	fore(i,0,n)fore(j,0,m)diag[i+j]+=a[i][j];
	vector<ll>sd(n+m+1);
	fore(i,1,n+m+1)sd[i]=sd[i-1]+diag[i-1];
	imp(diag); imp(sd);
	ll res=0;
	fore(i,0,n)fore(j,0,m){
		ll resi=sd[min(i+j+k,n+m)]-sp[min(i+k,n)][j]-sp[i][min(j+k,m)]+sp[i][j];
		cout<<"["<<i<<","<<j<<"|"<<sd[min(i+j+k,n+m)]<<" "<<sp[min(i+k,n)][j]<<" "<<sp[i][min(j+k,m)]<<" "<<sp[i][j]<<"="<<resi<<"]\n";
		res=max(res,resi);
	}
	return res;
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
