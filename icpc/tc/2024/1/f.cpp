#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll n,k;
	cin>>n>>k;
	multiset<ll> s;
	ll aux=0;
	ll acc=0;
	string s1; 
	cin>>s1;
	fore(i,0,n){
		if(s1[i]=='1') aux++;
		else{
			if(aux)s.insert(aux);
			acc+=((aux)*(aux+1)/2);
			aux=0;
		}	
	}
	if(aux)s.insert(aux);
	acc+=((aux)*(aux+1)/2);
	ll rta=0;
	while(acc>k){
		auto it=s.end();
		it--;
		ll aa=*it;
		s.erase(it);
		if(aa %2==0){
			s.insert(aa/2-1);
			s.insert(aa/2);
			acc-=(aa*(aa+1)/2);
			ll bb=aa/2;
			acc+=((bb)*(bb+1)/2);
			acc+=((bb-1)*(bb)/2);
		}		
		else{
			s.insert(aa/2);
			s.insert(aa/2);
			acc-=(aa*(aa+1)/2);
			ll bb=aa/2;
			acc+=((bb)*(bb+1)/2);
			acc+=((bb)*(bb+1)/2);
		}
		rta++;
	}
	cout<<rta<<"\n";
}