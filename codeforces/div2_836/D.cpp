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
		if(n==2){
			cout<<"3 1\n";
			continue;
		}
		if(n==3){
			cout<<"3 6 7\n";
			continue;
		}
		vector<ll> res(n);
		fore(i,0,n)res[i]+=1+2*i;
		res[n-1]+=2;
		fore(i,0,n)res[i]+=3*n;
		res[1]--,res[2]--;
		ll sum=0;
		fore(i,0,n)sum+=res[i];
		assert((res[n-1]-res[0])*(res[n-1]-res[0])==sum);
		imp(res);
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
