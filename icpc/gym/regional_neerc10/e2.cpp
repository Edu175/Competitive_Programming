#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
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

vv teams;
set<ii> shel;
set<ii> st;
ll dp[5010][2];
ii rec[5010][2];

ll dist (ll a, ll b){return abs(a-b);}


ll f(ll i, ll m){
	if(i>=SZ(teams)) return (m==0) ? 0 : 1e15;  
	if(dp[i][m]!=-1) return dp[i][m];
	if(m==1){
		ll r;
		if(i<teams[i]-1){
			ll otro = i+1;
			auto sig_coso = shel.upper_bound({teams[i]+1,-1});
			if(sig_coso == shel.begin()) return 1e15;
			auto it = sig_coso;
			it--;
			if(sig_coso!=shel.end() && (*sig_coso).fst<teams[otro]){
				r = f(i+1,1);
				rec[i][m] = {0,1};
			}
			else{
				r = f(i+1,0);
				rec[i][m] = {0,0};
			}
			dp[i][m] = r+dist((*it).fst,teams[i]);
			return dp[i][m];
		}
		else{
			r = f(i+1,0);
			auto sig_coso = shel.upper_bound({teams[i]+1,-1});
			if(sig_coso == shel.begin()) return 1e15;
			auto it = sig_coso;
			it--;
			
			dp[i][m] = r+dist((*it).fst,teams[i]);
			rec[i][m] = {0,0};
			return dp[i][m];
		}
	}
	auto it = st.upper_bound((ii){teams[i]+1,-1});
	if(it==st.end()){
		auto it = shel.upper_bound({teams[i]+1,-1});
		if(it!=shel.begin()){
			it--;
			ll r = f(i+1,0);
			dp[i][m] = r+dist((*it).fst,teams[i]);
			rec[i][m]={0,0};
			return dp[i][m];
		}
		else{
			dp[i][m]=1e15;
			rec[i][m]={1,0};
			return dp[i][m];
		}
	}
	if((*it).snd==0){
		ll r = f(i+1,0);
		auto it2 = shel.upper_bound({teams[i]+1,-1});
		ll val2=1e15,val3=1e14;
		if(it2!=shel.end()) val2 = dist((*it).fst,teams[i]);
		if(it2!=shel.begin()){it--; val3 = dist((*it).fst,teams[i]);}
		if(val2 <= val3){
			dp[i][m] = r+val2;
			rec[i][m] = {1,0};
		}
		else{ 
			dp[i][m] = r+val3;
			rec[i][m] = {0,0};
		}
		return dp[i][m];
	}
	else{
		ll r = f(i+1,0);
		ll r2 = f(i+1,1);
		auto it2 = shel.upper_bound({teams[i]+1,-1});
		ll val2=1e15,val3=1e14;
		if(it2!=shel.end()) val2 = dist((*it).fst,teams[i]);
		if(it2!=shel.begin()){it--; val3 = dist((*it).fst,teams[i]);}
		if(r+val2 <= val3+r2){
			dp[i][m] = r+val2;
			rec[i][m] = {1,0};
		}
		else{
			dp[i][m] = r2+val3;
			rec[i][m] = {0,1};
		}
		return dp[i][m];
	}
}

int main(){
	#ifdef ONLINE_JUDGE
	freopen("evacuation.in","r",stdin);     freopen("evacuation.out","w",stdout);
	#endif
	JET
	int n; cin>>n;
	teams.resize(n);
	fore(i,0,n){
		cin>>teams[i];
		st.insert({teams[i],0});
	}
	sort(ALL(teams));
	int m; cin>>m;
	fore(i,0,m){
		int x;
		cin>>x;
		shel.insert({x,i+1});
		st.insert({x,1});
	}
	mset(dp,-1);
	f(0,0);
	f(0,1);
	// fore(i,0,n){
	// 	cout<<" i "<<i<<": ";
	// 	fore(j,0,2){
	// 		cout<<rec[i][j].fst<<"/"<<rec[i][j].snd<<"       ";
	// 	}
	// 	cout<<endl;
	// }
	if((*shel.begin()).fst<teams[0]){
		ll rta = f(0,1);
		cout<<rta<<"\n";
		ll k = rec[0][1].fst;
		auto it = shel.upper_bound({teams[0]+1,-1});
		if(k==1) cout<<(*it).snd;
		else{
			it--;
			cout<<(*it).snd;
		} 
		ll aux=rec[0][1].snd;
		fore(i,1,n){
			k = rec[i][aux].fst;
			auto it = shel.upper_bound({teams[i]+1,-1});
			if(k==1) cout<<(*it).snd<<" ";
			else{
				it--;
				cout<<(*it).snd<<" ";
			} 
			ll aux=rec[i][aux].snd;
		}
	}
	else{
		ll rta = f(0,0);
		cout<<rta<<"\n";
		ll k = rec[0][0].fst;
		auto it = shel.upper_bound({teams[0]+1,-1});
		if(k==1) cout<<(*it).snd<<" ";
		else{
			it--;
			cout<<(*it).snd;
		} 
		ll aux=rec[0][0].snd;
		fore(i,1,n){
			k = rec[i][aux].fst;
			auto it = shel.upper_bound({teams[i]+1,-1});
			if(k==1) cout<<(*it).snd<<" ";
			else{
				it--;
				cout<<(*it).snd<<" ";
			} 
			// cout<<endl;
			// cout<<i<<" "<<aux<<endl;
			aux=rec[i][aux].snd;
		}
	}
	cout<<"\n";
	return 0;
}