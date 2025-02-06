#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll dp[2][20][2][7][8][9][1<<8][2];
ll m7[21];
ll m8[21];
ll m9[21];
vv digits;
ll dig;


ll f(ll e,ll i, ll b,ll m1, ll m2, ll m3, ll mask,ll cinco){
	ll &rta= dp[e][i][b][m1][m2][m3][mask][cinco];
		// cout<<"debug "<<e<<" "<<i<<" "<<b<<" "<<m1<<" "<<m2<<" "<<m3<<" "<<mask<<" "<<cinco<<"\n";
	if(i==0){
		if(mask%2==1 && m2%2!=0) return 0;
		mask/=2;
		if(mask%2==1 && (m3!=0 && m3!=3 && m3!=6)) return 0;
		mask/=2;
		if(mask%2==1 && m2%4!=0) return 0;
		mask/=2;
		if(mask%2==1 && cinco!=1) return 0;
		mask/=2;
		if(mask%2==1 && (m2%2!=0 || (m3!=0 && m3!=3 && m3!=6))) return 0;
		mask/=2;
		if(mask%2==1 && m1!=0) return 0;
		mask/=2;
		if(mask%2==1 && m2!=0) return 0;
		mask/=2;
		if(mask%2==1 && m3!=0) return 0;
		return 1;
	}
	if(rta!=-1) return rta;
	rta=0;
	if(!e){
		if(i>dig){
			rta+=f(0,i-1,1,m1,m2,m3,mask,cinco);
		}
		else if(i==dig){
			rta+=f(0,i-1,0,m1,m2,m3,mask,cinco);
			fore(j,1,digits[i-1]){
				ll nmask=mask;
				if(j>1) nmask=nmask | (1<<(j-2));
				rta+=f(1,i-1,0,(m1+m7[i]*j)%7,(m2+m8[i]*j)%8,(m3+m9[i]*j)%9,nmask,(j==0 ||j==5));
			}
			ll j=digits[i-1];
			// cout<<"wtf "<<i<<" "<<digits[i-1]<<" "<<m1<<" "<<m2<<" "<<m3<<"\n";
			ll nmask=mask;
			if(j>1) nmask=nmask | (1<<(j-2));
			rta+=f(1,i-1,1,(m1+m7[i]*j)%7,(m2+m8[i]*j)%8,(m3+m9[i]*j)%9,nmask,(j==0 ||j==5));
		}
		
		else{
			rta+=f(0,i-1,0,m1,m2,m3,mask,cinco);
			fore(j,1,10){
				ll nmask=mask;
				if(j>1) nmask=nmask | (1<<(j-2));
				rta+=f(1,i-1,0,(m1+m7[i]*j)%7,(m2+m8[i]*j)%8,(m3+m9[i]*j)%9,nmask,(j==0 ||j==5));
			}
		}
		return rta;
	}
	if(b){
		fore(j,1,digits[i-1]){
			ll nmask=mask;
			if(j>1) nmask=nmask | (1<<(j-2));
			rta+=f(1,i-1,0,(m1+m7[i]*j)%7,(m2+m8[i]*j)%8,(m3+m9[i]*j)%9,nmask,(j==0 || j==5));
		}
		ll nmask=mask;
		if(digits[i-1]>1) nmask=nmask | (1<<(digits[i-1]-2));
		if(digits[i-1]>0)rta+=f(1,i-1,1,(m1+m7[i]*digits[i-1])%7,(m2+m8[i]*digits[i-1])%8,(m3+m9[i]*digits[i-1])%9,nmask,(digits[i-1]==0 || digits[i-1]==5));
	}
	else{
		fore(j,1,10){
			ll nmask=mask;
			if(j>1) nmask=nmask | (1<<(j-2));
			rta+=f(1,i-1,0,(m1+m7[i]*j)%7,(m2+m8[i]*j)%8,(m3+m9[i]*j)%9,nmask,(j==0 || j==5));
		}
	}
	return rta;
}


int main(){
	JET
	ll n,m; cin>>n>>m;
	mset(dp,-1);
	if(m==1e18)m--;
	if(n==1e18) n--;
	n--;
	m7[1]=1;
	m8[1]=1;
	m9[1]=1;
	fore(i,2,20){
		m7[i]=(m7[i-1]*10)%7;
		m8[i]=(m8[i-1]*10)%8;
		m9[i]=(m9[i-1]*10)%9;
		
	}
	while(n>0){
		digits.pb(n%10);
		n/=10;
	}	
	dig=SZ(digits);
	while(SZ(digits)<18)digits.pb(0);
	// reverse(ALL(digits));
	ll r1=f(0,19,1,0,0,0,0,0);
	// cout<<"digits: ";
	// for(auto x:digits) cout<<x;
	// cout<<"\n";
	digits.clear();
	mset(dp,-1);
	while(m>0){
		digits.pb(m%10);
		m/=10;
	}	
	dig=SZ(digits);
	while(SZ(digits)<18)digits.pb(0);
	// reverse(ALL(digits));
	ll r2=f(0,19,1,0,0,0,0,0);
	cout<<r2-r1<<"\n";
	return 0;
}