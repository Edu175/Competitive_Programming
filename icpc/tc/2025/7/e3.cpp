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

ll dis(ii a, ii b){
	return abs(a.fst-b.fst)+abs(a.snd-b.snd);
}
ll ask(ii a){
	cout<<"SCAN "<<a.fst+1<<" "<<a.snd+1<<endl;
	ll ret; cin>>ret;
	return ret;
}
ll mita(ll a){
	// assert(a%2==0);
	return a/2;
}
ll sep(pair<ii,ii> a){
	return dis(a.fst,a.snd);
}
bool dig(ii a){
	cout<<"DIG "<<a.fst+1<<" "<<a.snd+1<<endl;
	ll ret; cin>>ret;
	// cnt+=ret;
	return ret;
}
void imp(ii a, ii b){
	cout<<a.fst+1<<","<<a.snd+1<<" "<<b.fst+1<<","<<b.snd+1;
}

ll get(ii a, ii b, ii c){
	ll x=min(abs(c.fst-b.fst),abs(c.fst-a.fst));
	ll y=min(abs(c.snd-b.snd),abs(c.snd-a.snd));
	return dis(a,b)+2*(x+y);
}

int main(){
	// JET
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll T = (n-1) + (m-1);
		vector<ii> e = {(ii){0,0},(ii){0,m-1},(ii){n-1,0},(ii){n-1,m-1}};
		ll c1=ask(e[0]);
		ll c2=ask(e[1]);
		ll c3=2*T-c2;
		ll c4=2*T-c1;
		
		ll dif23=mita(c2-c3);
		ll dif14=mita(c1-c4);
		
		vector<pair<ii,ii>>cand;
		
		fore(i,0,n)fore(j,0,m)fore(i1,i,n)fore(j1,j,m){
			ll deb14=(dis(e[0],{i,j})-dis(e[3],{i1,j1}));
			ll deb23=(dis(e[1],{i,j1})-dis(e[2],{i1,j}));
			if(deb14==dif14&&deb23==dif23)
				cand.pb({{i,j},{i1,j1}});
		}
		sort(ALL(cand),[&](pair<ii,ii> a, pair<ii,ii> b){
			return sep(a)<sep(b);
		});
		auto [a,b]=cand[0];
		
		// cout<<"a b ";
		// imp(a,b);
		// cout<<"\n";
		
		ll r=ask(a);
		
		vv ds={	mita(c1-r),
				mita(c2-r),
				mita(c3-r),
				mita(c4-r),
		};
		typedef pair<ii,ii> tre;
		
		map<ll,tre>wh;
		ii sh;
		fore(qi,0,n)fore(qj,0,m){
			wh.clear();
			ll good=1;
			fore(i,0,n)fore(j,0,m)fore(i1,i,n)fore(j1,j,m){
				vv deb={dis(e[0],{i,j}),
						dis(e[1],{i,j1}),
						dis(e[2],{i1,j}),
						dis(e[3],{i1,j1})
				};
				tre t={{i,j},{i1,j1}};
				ll fg=dis(t.fst,t.snd)==r;
				fore(_,0,4)fg&=deb[_]==ds[_];
				if(fg){
					ii s={qi,qj};
					ll key=get(t.fst,t.snd,s);
					good&=!wh.count(key);
					wh[key]=t;
				}
			}
			if(good){
				sh={qi,qj};
				break;
			}
		}
		assert(SZ(wh));
		auto [fst,snd]=wh[ask(sh)];
		auto [i,j]=fst;
		auto [i1,j1]=snd;
		
		if(dig({i,j}))dig({i1,j1});
		else dig({i1,j}),dig({i,j1});
		
	}
	return 0;
}
