#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dksjfg:v)cout<<dksjfg<<" ";cout<<endl;}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

const ll K=17,C=5;
ll F[K][1ll<<K];
ll get(char c){
	if(c=='a')return 0;
	if(c=='e')return 1;
	if(c=='i')return 2;
	if(c=='o')return 3;
	return 4;
}
int main(){FIN;
	ll n; cin>>n;
	string s; cin>>s;
	vector<ll> pos(C,n+1);
	for(ll i=n-1;i>=0;i--){
		pos[get(s[i])]=i+1;
		fore(j,0,C)F[0][i]=max(F[0][i],pos[j]);
	}
	F[0][n]=n+1;
	F[0][n+1]=n+1;
	// fore(i,0,n+2)cout<<F[0][i]<<" ";;cout<<"\n";
	fore(k,1,K)fore(i,0,n+2)F[k][i]=F[k-1][F[k-1][i]];
	ll q; cin>>q;
	while(q--){
		ll l,r; cin>>l>>r; l--;
		ll res=0,x=l;
		for(ll k=K-1;k>=0;k--){
			if(F[k][x]<=r){
				// cout<<x<<" --> "<<F[k][x]<<"\n";
				x=F[k][x],res+=1ll<<k;
				
			}
		}
		res+=1;
		cout<<res<<"\n";
	}
	
	return 0;
}