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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll c=0,sum=0;
		ll res[2][2];
		mset(res,0);
		fore(i,1,n+1){
			ll w=0;
			if(i%4>=2)w=1;
			if(sum+i>n){
				fore(j,0,2)res[w][j]+=(n-sum)/2;
				if((n-sum)&1)res[w][c]++;
				break;
			}
			fore(j,0,2)res[w][j]+=i/2;
			if(i&1)res[w][c]++;
			sum+=i;
			if(i&1)c^=1;
		}
		fore(i,0,2)fore(j,0,2)cout<<res[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
