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
const ll MAXN=35;
short mu[MAXN] = {0,1};
void mobius(){
	fore(i,1,MAXN){
		cout<<i<<"="<<mu[i]<<": ";
		if(mu[i])for(int j=i+i;j<MAXN;j+=i){
			cout<<j<<","<<mu[j]<<" ";
			mu[j]-=mu[i];
		}
		cout<<"\n\n";
	}
}
int main(){FIN;
	mobius();
	fore(i,0,35)cout<<i<<"="<<mu[i]<<" ";
	cout<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
