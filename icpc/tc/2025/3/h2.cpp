#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

vv g[27];
ll ord[27];
ll in[27];


ll c = 0;
bool dfs(int x){
	ord[x] = c;
	c++;
	bool b = true;
	for(auto y:g[x]){
		if(ord[y]==-1) b = b && dfs(y);
		else if(ord[y] <= ord[x]){
			return false;
		}
	}	
	return b;
}


ii get(string a, string b){
	fore(i,0,SZ(b)){
		if(i>=SZ(a)) return {-2,-2};
		if(a[i]!=b[i]){
			in[b[i]-'a']++;
			return {a[i]-'a',b[i]-'a'};
		}
	}
	return {-1,-1};
}


int main(){
	JET
	mset(ord,-1);
	ll n; cin>>n;
	string a[n];
	fore(i,0,n) cin>>a[i];
	fore(i,1,n){
		ii r = get(a[i-1],a[i]);
		if(r.fst==-1){
			cout<<"Impossible\n";
			return 0;
		}
		// cout<<"KHE "<<r.fst<<endl;
		if(r.fst>=0)g[r.fst].pb(r.snd);
	}
	fore(i,0,26){
		if(in[i]) continue;
		if(!dfs(i)){
			cout<<"Impossible\n";
			return 0;
		}
	}
	bool b = false;
	fore(i,0,26) if(ord[i]==-1) b= true;
	if(b){
		cout<<"Impossible\n";
		return 0;
	}
	fore(x,0,26){
		fore(j,0,26){
			if(ord[j] == x) cout<<char(j+'a');
		}
	}
	cout<<"\n";
	return 0;
}
