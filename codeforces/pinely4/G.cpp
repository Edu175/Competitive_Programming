#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=105;

ll a[MAXN][MAXN];
ll n,m,k;
void limpio(){
	vector<ll>col(m,1),row(n,1);
	fore(i,0,n){
		fore(j,0,m){
			row[i]&=a[i][j];
			col[j]&=a[i][j];
		}
	}
	fore(i,0,n)fore(j,0,m){
		if(row[i]||col[j])a[i][j]=0;
	}
}
void pinto(ll i, ll j){
	assert(!a[i][j]);
	a[i][j]=1;
}
vector<ii>res;
void go(ll i, char d){
	
	if(d=='H'){
		res.pb({i,0});
		fore(j,0,k)pinto(i,j);
	}
	else {
		res.pb({n-k,i});
		fore(j,0,k)pinto(n-1-j,i);
	}
	limpio();
}
void move(char d){
	if(d=='H'){
		//pruebo clear
		fore(i,0,n){
			ll flagi=1;
			fore(j,0,m){
				flagi&=(j>=k)==a[i][j];
			}
			if(flagi){go(i,d);return;}
		}
		
		//sino
		fore(i,0,n){
			ll flag=1;
			fore(j,0,k)flag&=!a[i][j];
			if(flag){go(i,d);return;}
		}
		
		
		assert(0);
	}
	else {
		//pruebo clear
		fore(j,0,m){
			ll flagi=1;
			fore(i,0,n){
				flagi&=(i<n-k)==a[i][j];
			}
			if(flagi){go(j,d);return;}
		}
		
		//sino
		for(ll j=m-1;j>=0;j--){
			ll flag=1;
			fore(i,0,k)flag&=!a[n-1-i][j];
			if(flag){go(j,d);return;}
		}
		
		assert(0);
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll q; cin>>n>>m>>k>>q;
		string s; cin>>s;
		fore(i,0,n)fore(j,0,m)a[i][j]=0;
		res.clear();
		fore(i,0,q)move(s[i]);
		if(SZ(res)!=q)cout<<"-1\n";
		else {
			for(auto i:res)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
		}
	}
	return 0;
}
