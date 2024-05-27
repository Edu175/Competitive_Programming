#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,t; cin>>n>>t;
	vector<ll>col(n,n),row(n,n),diag(2,n);
	ll res=t+5;
	fore(_,0,t){
		ll x; cin>>x; x--;
		ll i=x/n,j=x%n;
		row[i]--,col[j]--;
		if(!row[i]||!col[j]){
			res=_;
			break;
		}
		if(i-j==0){
			diag[0]--;
			if(!diag[0]){
				res=_;
				break;
			}
		}
		if(i+j==n-1){
			diag[1]--;
			if(!diag[1]){
				res=_;
				break;
			}
		}
	}
	if(res>=t)cout<<"-1\n";
	else cout<<res+1<<"\n";
	return 0;
}
