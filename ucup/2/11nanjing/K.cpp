#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
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

ll b , q,mano;
string deck;

void takeone(int& i, bool bo){
	if(bo) q--;
	if(i == SZ(deck)) return;
	if(deck[i] == 'Q')q++;
	if(deck[i] == 'B')b++;
	i++;
}


void taketwo(int mx, int&i){
	b--;
	takeone(i,0);
	if(mano >= mx){
		i++;
		return;
	}
	mano++;
	takeone(i,0);
}

bool can(int mx){
	ll m = SZ(deck);
	int j = 0;
	while(j<m){
		if(!b && !q) return false;
		if(!b) takeone(j,1);
		else if(!q) taketwo(mx,j);
		else if(mano < mx) taketwo(mx, j);
		else if(j<m-1 && deck[j+1] == 'W')taketwo(mx,j);
		else takeone(j,1);
	}
	return true;
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll auxb = 0, auxq = 0;
		string s; cin>>s>>deck;
		ll r = n+m+10;
		fore(i,0,n){
			if(s[i] == 'B')auxb++;
			if(s[i] == 'Q')auxq++;
		} 
		
		fore(i,n,n+m+10){
			b =auxb, q = auxq;
			mano = n;
			if(can(i)){
				r = i; break;
			}
		}
		if(r == n+m+10)cout<<"IMPOSSIBLE\n";
		else cout<<r<<"\n";
	}
	return 0;
}