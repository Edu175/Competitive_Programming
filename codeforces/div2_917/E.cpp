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

vector<vector<ll>> f(ll n, ll k, ll bol=0){
	//cout<<n<<" "<<k<<"\n";
	vector<vector<ll>>a(n,vector<ll>(n,0));
	if(k%4==0){
		for(ll i=0;i<n;i+=2)for(ll j=0;j<n;j+=2){
			if(k==0)return a;
			if(bol&&i>=n-4&&j>=n-4)continue;
			a[i][j]=a[i][j+1]=a[i+1][j]=a[i+1][j+1]=1;
			k-=4;
		}
		return a;
	}
	if(n==2){
		return {{0,1},{1,0}};
	}
	if(k==2||k==n*n-2){a[0][0]=-1;return a;}
	if(k==6){
		a[0][0]=a[0][1]=a[1][0]=a[1][2]=a[2][1]=a[2][2]=1;
		return a;
	}
	if(k==10){
		fore(i,0,4)fore(j,0,4)a[i][j]=1;
		a[0][0]=a[0][1]=a[1][0]=a[1][2]=a[2][1]=a[2][2]=0;
		return a;
	}
	a=f(n,k-10,1);
	vector<vector<ll>>b=f(4,10);
	fore(i,0,4)fore(j,0,4)a[n-4+i][n-4+j]=b[i][j];
	return a;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		if(k%2){
			cout<<"No\n";
			continue;
		}
		ll fl=0;
		vector<vector<ll>>a=f(n,k);
		fore(i,0,n)fore(j,0,n)fl=min(fl,a[i][j]);
		if(fl==-1)cout<<"No\n";
		else {
			cout<<"Yes\n";
			fore(i,0,n){
				imp(a[i]);
			}
		}
	}
	return 0;
}
