#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const int tam = 355;
ll dp[tam][305][2];
vv ant(tam,0);

ll f(int i, int s, bool b){
	if(s<0) return 0;
	if(i == tam) return s==0 && b==0;
	auto &res = dp[i][s][b];
	if(res!=-1) return res;
	res = false;
	fore(j,((b) ? ant[i] : 0),10){
		// cout<<i<<" "<<s<<" "<<b<<": prueba "<<j<<"\n";
		if(f(i+1,s-j, b & (j==ant[i]))){
			res = true;
			break;
		}
	}
	// cout<<"f de "<<i<<" "<<s<<" "<<b<<" da "<<res<<"\n";
	return res;
}


int main(){
	JET
	ll n; cin>>n;
	fore(i,0,n){
		mset(dp,-1);
		ll x; cin>>x;
		vv now(tam,0);
		ll b = 1;
		// for(auto i:ant)cout<<i<<" ";;cout<<"\n";
		fore(i,0,tam){
			fore(j,((b) ? ant[i] : 0),10){
				if(f(i+1,x-j,b&(j==ant[i]))){
					if(j > ant[i]) b = false;
					now[i] = j;
					// cout<<"puse "<<j<<"\n";
					x-=j;
					break;
				}
			}
		}
		ll ld = 1;
		fore(i,0,tam){
			if(!now[i] && ld) continue;
			cout<<now[i];
			ld = 0;
		}
		ant=now;
		cout<<"\n";
	}
	
	return 0;
}
