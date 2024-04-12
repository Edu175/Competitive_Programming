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
const ll MAXN=505;
unordered_map<ll,ll> dp[MAXN];
int main(){FIN;
	ll n,d; cin>>n>>d;
	vector<vector<ll>>a(n,vector<ll>a(n));
	fore(i,0,n)fore(j,0,n)cin>>a[i][j];
	
	return 0;
}


m=100
for i in range(m):
	for j in range(i+1,m):
		for h in range(j+1,m):
			for i1 in range(h+1,m):
				a=v[i][:51]
				for k in range(51):
					a[k]+=v[j][k]+v[h][k]+v[i1][k]
				if(valid(a)):
					print(i,j,h,i1,a)
					
def suma(w):
	a=[0 for i in range(51)]
	for i in range(w):
		for j in range(51):
			a[j]+=v[i][j]
	return a

