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

const ll MAXN=1005;
ll a[MAXN][MAXN];
ll sp[MAXN][MAXN];

ll get(ll i0, ll i1, ll j0, ll j1){
	return sp[i1][j1]-sp[i1][j0]-sp[i0][j1]+sp[i0][j0];
}
int main(){FIN;
	ll n,q; cin>>n>>q;
	fore(i,0,n)fore(j,0,n){
		char c; cin>>c;
		a[i][j]=(c=='B');
	}
	fore(i,1,n+1)fore(j,1,n+1)sp[i][j]=a[i-1][j-1]+sp[i][j-1];
	fore(i,1,n+1)fore(j,1,n+1)sp[i][j]+=sp[i-1][j];
	while(q--){
		ll i0,j0,i1,j1; cin>>i0>>j0>>i1>>j1; i1++,j1++;
		ll b=(i0+n-1)/n*n,c=i1/n*n;
		ll d=(j0+n-1)/n*n,e=j1/n*n;
		vector<ll>r={i0%n,i1%n,j0%n,j1%n};
		if(r[0]==0)r[0]=n;
		if(r[2]==0)r[2]=n;
		ll res=((e-d)/n)*((c-b)/n)*get(0,n,0,n);
		//cout<<res<<"\n";
		//cout<<b<<" "<<c<<" "<<d<<" "<<e<<"\n";
		//cout<<(c-b)/n<<" "<<(e-d)/n<<"\n";
		ll add=0;
		add=(get(0,n,0,r[3])+get(0,n,r[2],n))*((c-b)/n);
		res+=add;
		//cout<<add<<"\n";
		add=(get(0,r[1],0,n)+get(r[0],n,0,n))*((e-d)/n);
		res+=add;
		//cout<<add<<"\n";
		add=get(r[0],n,r[2],n);
		res+=add;
		//cout<<add<<"\n";
		add=get(r[0],n,0,r[3]);
		res+=add;
		//cout<<add<<"\n";
		add=get(0,r[1],r[2],n);
		res+=add;
		//cout<<add<<"\n";
		add=get(0,r[1],0,r[3]);
		res+=add;
		//cout<<add<<"\n";
		cout<<res<<"\n";
		//cout<<"\n";
	}
	return 0;
}
