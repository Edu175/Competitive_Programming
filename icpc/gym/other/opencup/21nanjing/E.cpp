#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet; i++)
#define snd second
#define fst first
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll U,D,L,R;
ii robot, m,f;
string rta;

void init(){
	U = 0, D = 0, L = 0, R = 0;
	rta = "";
	robot = {0,0};
	f = {0,0};
}

void up(){
	robot.snd ++;
	U--;
	rta.pb('U');
}
void down(){
	robot.snd -- ;
	D--;
	rta.pb('D');
}
void left(){
	robot.fst -- ;
	L--;
	rta.pb('L');
}
void right(){
	robot.fst++;
	R--;
	rta.pb('R');
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		init();
		cin>>m.fst>>m.snd;
		string s; cin>>s;
		for(auto x:s){
			if(x == 'U'){
				f.snd++;
				U++;
			}
			if(x == 'D'){
				f.snd--;
				D++;
			}
			if(x == 'L'){
				f.fst --;
				L++;
			}
			if(x == 'R'){
				f.fst ++;
				R++;
			}
		}
		if(m == f){
			cout<<"Impossible\n";
			continue;
		}
		bool b = (f.fst == m.fst);
		bool r = 1;
		while(L+R+D+U){
			if(b){
				if(robot.snd != m.snd){
					while(U)up();
					while(D) down();
				}
				if(L) left();
				else if(R) right();
				else if(D) down();
				else if(U) up();
			}
			else{
				if(robot.fst != m.fst){
					while(L) left();
					while(D) right();
				}
				if(U) up();
				else if(D) down();
				else if(L) left();
				else if(R) right();
			}
		}
	}
	return 0;
}