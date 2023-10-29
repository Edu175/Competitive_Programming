#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	vector<ll>res;
	fore(n,0,10000){
		ll sum=0,flag=0;
		fore(i,0,6){
			sum+=n+i;
			if((n+i)%7==0)flag=1;
		}
		if(flag)continue;
		string s=to_string(sum);
		if(SZ(s)!=4)continue;
		ll r=sqrt(sum);
		if(r*r==sum)res.pb(n);
	}	
	for(auto n:res){
		fore(i,0,6)cout<<n+i<<" ";
		ll sum=0;
		fore(i,0,6)sum+=n+i;
		cout<<"= "<<sum<<" "<<sqrt(sum)<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
