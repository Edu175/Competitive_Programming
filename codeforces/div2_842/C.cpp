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
		ll a[n],flag=1;
		vector<ll>p[n];
		fore(i,0,n){
			cin>>a[i];
			a[i]--;
			p[a[i]].pb(i);
			if(SZ(p[a[i]])>2)flag=0;
		}
		ll res[2][n];
		queue<ll>fr[2];
		for(int i=n-1;i>=0;i--){
			if(SZ(p[i])==2){
				fore(j,0,2){
					res[j][p[i][j]]=i;
					fr[j^1].push(p[i][j]);
				}
			}
			else if(SZ(p[i])==1){
				res[0][p[i][0]]=i;
				res[1][p[i][0]]=i;
			}
			else {
				if(SZ(fr[0])&&SZ(fr[1])){
					res[0][fr[0].front()]=i; fr[0].pop();
					res[1][fr[1].front()]=i; fr[1].pop();
				}
				else flag=0;
			}
		}
		if(flag){
			cout<<"YES\n";
			fore(i,0,2){
				fore(j,0,n)cout<<res[i][j]+1<<" ";
				cout<<"\n";
			}
		}
		else cout<<"NO\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
