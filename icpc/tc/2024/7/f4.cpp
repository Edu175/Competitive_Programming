#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
int m;
const int maxm=1e5+5;
ll hs[maxm][4];
ll dist(string &a, string &b){
	ll res=0;
	fore(i,0,m){
		if(a[i]!=b[i]){
			res++;
		}
	}
	return res;
}
int main(){
	JET
	int n,k;
	cin>>n>>m>>k;
	string a[n];
	fore(i,0,n){
		cin>>a[i];
	}
	bool kl=false;
	fore(i,0,n){
		fore(j,0,m){
			fore(k,0,4){
				hs[j][k]++;
			}
			hs[j][a[i][j]-'A']--;
		}
	}
	string qowep;
	queue <pair<string,ll>> S;
	fore(i,0,n){
		ll sum=0;
		fore(j,0,m){
			sum+=hs[j][a[i][j]-'A'];
		}
		if(sum==k*(n-1)){
			S.push({a[i],i});	
		}
		else if(!kl){qowep=a[i]; kl=true;}
	}
	queue <pair<string,ll>> aux;
	//cout<<!S.empty();
	while(!S.empty()){
		auto [r,i]= S.front();
			if(dist(r,qowep)==k){cout<<i+1<<"\n";return 0;}
			S.pop();
	}
	assert(0);
	return 0;
}