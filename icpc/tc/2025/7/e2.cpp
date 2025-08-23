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

ll man(ii a, ii b){
	return abs(a.fst-b.fst)+abs(a.snd-b.snd);
}

int main(){
	// JET
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll TOT = (n-1) + (m-1);
		vector<ii> e = {(ii){0,0},(ii){0,m-1},(ii){n-1,0},(ii){n-1,m-1}};
		ll a,b,c,A,B,C;
		cout<<"SCAN "<<e[0].fst+1<<" "<<e[0].snd+1<<"\n";
		cin>>A;
		a=A;
		cout<<"SCAN "<<e[3].fst+1<<" "<<e[3].snd+1<<"\n";
		cin>>B;
		b=B;
		cout<<"SCAN "<<e[1].fst+1<<" "<<e[1].snd+1<<"\n";
		cin>>C;
		c=C;
		if(a<=b){
			a = TOT-a;
			b = TOT-b;
		}
		a = a/2;
		b = b/2;
		ll auxr = TOT-b-a;
		c = (c-auxr+1)/2;
		ii dentro = {-1,-1};
		fore(i,0,n){
			fore(j,0,m){
				ii p = {i,j};
				if(dentro.fst !=-1) continue;
				if(man(e[0],p) >= a && man(e[3],p) >=b && man(e[1],p) >=c){
					dentro = p;
				}
			}
		}
		ll r;
		cout<<"SCAN "<<dentro.fst+1<<" "<<dentro.snd+1<<"\n";
		cin>>r;
		bool as = true;
		fore(i,0,n){
			fore(j,0,m){
				fore(k,0,n){
					fore(k2,0,n){
						if(i==k && j==k2) continue;
						ii p1,p2,p3,p4;
						p1 = {i,j};
						p2 = {i,k2};
						p3 = {k,j};
						p4 = {k,k2};
						if(man(p1,p4) != r) continue;
						if(man(e[0],p1) * 2 + r != A) continue;
						if(man(e[3],p4) * 2 + r != B) continue;
						if(man(e[1],p2) * 2 + r != C) continue;
						assert(as);
						as = false;
						ll ans;
						cout<<"DIG "<<p1.fst+1<<" "<<p1.snd+1<<"\n";
						cin>>ans;
						if(ans){
							cout<<"DIG "<<p4.fst+1<<" "<<p4.snd+1<<"\n";
							cin>>ans;
							continue;
						}
						cout<<"DIG "<<p2.fst+1<<" "<<p2.snd+1<<"\n";
						cin>>ans;
						cout<<"DIG "<<p3.fst+1<<" "<<p3.snd+1<<"\n";
						cin>>ans;
					}
				}
			}
		}
		
	
		
	}
	return 0;
}
