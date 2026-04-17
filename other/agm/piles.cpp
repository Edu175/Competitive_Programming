//notes https://github.com/Edu175/padalustro/blob/master/padalustro.cpp
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
typedef pair<ll,ll> ii;
vector<ii>res;

vector<vector<ll>>a;
ll n,m;
void move(ll i, ll j){
	a[j].pb(a[i].back());
	a[i].pop_back();
	res.pb({i,j});
	//fore(i,0,n+1){imp(a[i]);}
	//cout<<endl;
	//assert(SZ(a[j])<=m);
}
void move(ll x, ll i, ll j){
	fore(_,0,x){
		move(i,j);
	}
}
//assuming SZ(a[n]) == 0
void go_top(ll i, ll j){
	if(j==m-1)return;
	//cout<<"go_top "<<i<<" "<<j<<"\n";
	//fore(i,0,n+1){imp(a[i]);}
	
	ll x=n-1;
	move(n-1,x,n);
	move(m-1-j,i,x);
	move(i,n);
	move(m-1-j,x,i);
	move(n,i);
	move(n-1,n,x);
	
	//fore(i,0,n+1){imp(a[i]);}
	//cout<<"end\n\n";
}
void go_down(ll i, ll j){
	if(j==m-1)return;
	//cout<<"go_down "<<i<<" "<<j<<"\n";
	//fore(i,0,n+1){imp(a[i]);}
	
	ll x=n-1;
	move(n-1,x,n);
	move(i,n);
	move(m-1-(j-1),i,x);
	move(n,i);
	move(m-1-(j-1),x,i);
	move(n-1,n,x);
	
	//fore(i,0,n+1){imp(a[i]);}
	//cout<<"end\n\n";
}
void swp(ll i, ll j, ll w){
	//cout<<"swp "<<i<<" "<<j<<" "<<w<<"\n";
	//fore(i,0,n+1){imp(a[i]);}
	
	move(m-1-j,i,n);
	move(i,n);
	//fore(i,0,n+1){imp(a[i]);}
	move(w,i);
	//fore(i,0,n+1){imp(a[i]);}
	move(n,w);
	//fore(i,0,n+1){imp(a[i]);}
	move(m-1-j,n,i);
	
	//fore(i,0,n+1){imp(a[i]);}
	//cout<<"end\n\n";
}
void swp(ll i, ll j, ll i1, ll j1){
	//assert(i!=i1);
		go_top(i,j);
		swp(i1,j1,i);
		go_down(i,j);
	/*}
	else {
		
	}*/
}
int main(){FIN;
	cin>>n>>m; n--;
	a.resize(n+1,vector<ll>(m));
	a[n].resize(0);
	fore(i,0,n)fore(j,0,m)cin>>a[i][j];
	fore(i,0,n-1){
		ll c=a[i][0];
		fore(j,0,m){
			if(a[i][j]==c)continue;
			fore(i1,i+1,n)fore(j1,0,m){
				if(a[i1][j1]==c){
					swp(i,j,i1,j1);
					break;
				}
			}
			//cout<<i<<" "<<j<<":\n";
			//fore(i,0,n+1){imp(a[i]);}cout<<endl;
		}
	}
	//fore(i,0,n){imp(a[i]);}
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	return 0;
}
