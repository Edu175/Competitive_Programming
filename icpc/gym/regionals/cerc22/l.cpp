#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
queue<ll> cards; 
vv hand;
vv piles[4];

void take(){
	while(SZ(cards) && SZ(hand) < 8){
		ll x = cards.front();
		cards.pop();
		hand.pb(x);
	}
}

void quitar(ll x){
	vv aux;
	for(auto y:hand)if(y!=x) aux.pb(y);
	hand = aux;
}

bool truco(){
	for(auto x:hand){
		fore(i,0,2){
			if(x == piles[i].back() - 10){
				piles[i].pb(x);
				quitar(x);
				return true;
			}
		}
		fore(i,2,4){
			if(x == piles[i].back() + 10){
				piles[i].pb(x);
				quitar(x);
				return true;
			}
		}
	}
	return false;
}

bool normal(){
	ll cand = 1000, of = -1;
	fore(_,0,2){
		for(auto x:hand){
			fore(i,0,2){
				ll k = piles[i].back();
				if(x<k) continue;
				cand = min(cand,x-k);
				if(of == x-k){
					piles[i].pb(x);
					quitar(x);
					return true;
				}
			}
			fore(i,2,4){
				ll k = piles[i].back();
				if(x>k) continue;
				cand = min(cand, k-x);
				if(of == k-x){
					piles[i].pb(x);
					quitar(x);
					return true;
				}
			}
		}
		of = cand;
	}
	return false;
}

int main(){
	JET
	fore(i,2,100){
		ll x; cin>>x;
		cards.push(x);
	}
	fore(i,0,2) piles[i].pb(1);
	fore(i,2,4) piles[i].pb(100);
	while(1){
		take();
		ll use = 0;
		while(use < 2){
			if(truco())use++;
			else if(normal())use++;
			else break;
		}
		if(use<2) break;
	}
	fore(i,0,4) show(piles[i]);
	show(hand);
	while(SZ(cards)){
		cout<<cards.front()<<" ";
		cards.pop();
	}
	cout<<"\n";
	return 0;
}