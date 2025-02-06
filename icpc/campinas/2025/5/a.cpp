#include <bits/stdc++.h>
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

const ll maxn=2e4+5;
ll rta[maxn];


int main(){
	JET
	mset(rta,-1);
	ll n;
	cin>>n;
	int a[n];
	int b[n];
	fore(i,0,n) cin>>a[i];
	fore(i,0,n) cin>>b[i];
	rta[0]=0;
	fore(i,0,n){
		ll x=a[i];
		ll limit=b[i];
		ll cnt;
		ll ant=0;
		for(ll j=maxn-1-x; j>=1; j--){
			if(rta[j]!=-1){
				ll num=j+x;
				cnt=1;
				ant=rta[j];
			// if(x==3 && j==4) cout<<"el bol choto es "<<vis[j]<<" lo otro "<<num<<" "<<cnt<<" "<<"\n";
				while(num<maxn && cnt<=limit){
					// if(x==3) cout<<"debug "<<num<<"\n";
					if(cnt+ant<rta[num] || rta[num]==-1){
						rta[num]=cnt+ant;
						cnt++;
						//vis[num]=1;
						num+=x;
					}
					else{
						cnt=1;
						ant=rta[num];
						//vis[num]=1;
						num+=x;
					}
				}
			}
		}
		cnt=1;
		ll num=x;
		// cout<<"el primer num va a ser "<<num<<"\n";
		while(cnt<=limit && num<maxn){
			rta[num]=cnt;
			cnt++;
			num+=x;
		}
		// cout<<"---------------------\ncoso  en x: "<<x<<"\n";
		// fore(i,1,11) cout<<rta[i]<<" ";
		// cout<<"\n";
	}
	
	int k; cin>>k;
	if(rta[k]==-1){
		cout<<0;
		return 0;
	}
	cout<<rta[k]<<"\n";
	return 0;
}