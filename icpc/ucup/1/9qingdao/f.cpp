#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		ll fg=1;
		// if(k>3){cout<<"Impossible\n";continue;}
		vector<vector<ll>>a(k,vector<ll>(n));
		fore(j,0,k)fore(i,0,n){
			ll to=i^(j+1);
			a[j][i]=to;
			fg&=to<n;
		}
		if(!fg){cout<<"Impossible\n";continue;}
		fore(i,0,k){
			fore(j,0,n){
				if(j)cout<<" ";
				cout<<a[i][j]+1;
			}
			cout<<"\n";
		}
	}
	return 0;
}

/*

2 1 4 3 6 5 8 7
3 4 1 2 7 8 5 6
4 3 2 1 8 7 6 5
5 6 7 8 1 2 3 4



*/