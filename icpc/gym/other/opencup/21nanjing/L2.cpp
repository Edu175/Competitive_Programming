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
ii robot, m;
string rta;

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

ll u,d,r,l;

void local(){
	U = u, L = l, R = r, D = d;
	rta = "";
	robot = {0,0};
}

bool fp1(){
	while(U){
		up();
		if(robot  == m) return false;
	}
	while(D){
		down();
		if(robot  == m) return false;
	}
	while(R){
		right();
		if(robot  == m) return false;
	}
	while(L){
		left();
		if(robot  == m) return false;
	}
	return true;
}

bool fq1(){
	while(R){
		right();
		if(robot  == m) return false;
	}
	while(L){
		left();
		if(robot  == m) return false;
	}
	while(U){
		up();
		if(robot  == m) return false;
	}
	while(D){
		down();
		if(robot  == m) return false;
	}
	return true;
}

bool f1(bool modo){
	local();
	while(U && D){
		up();
		if(robot == m) return false;
		down();
	}
	while(R && L){
		left();
		if(robot  == m) return false;
		right();
	}
	return (modo ? fp1(): fq1()) ;
}
bool f2(bool modo){
	local();
	while(R && L){
		right();
		if(robot  == m) return false;
		left();
	}
	while(U && D){
		down();
		if(robot == m) return false;
		up();
	}
	return (modo ? fp1(): fq1()) ;
}

bool check(string s){
	ii rob = {0,0};
	if(rob == m) return false;
	for(auto x:s){
		if(x == 'U') rob.snd++;
		else if(x == 'D') rob.snd--;
		else if(x == 'L') rob.fst--;
		else if(x == 'R') rob.fst++;
		else return false;
		if(rob == m) return false;
	}
	return true;
}

bool imp(){
	local();
	ii fin = { R-L,U-D};
	// cout<<U<<" "<<D<<"\n";
	// cout<<fin.fst<<" "<<fin.snd<<"\n";
	// cout<<m.fst<<" "<<m.snd<<endl;
	if(fin == m || robot == m) return true;
	if(R+L == 0){
		if(U > D && (m.fst == 0 && m.snd>0 && m.snd < U-D)) return true;
		if(D > U && m.fst == 0 && m.snd < 0 && m.snd > U-D) return true; 
	}
	if(U+D == 0 && m.snd == 0){
		if(R > L && m.fst > 0 && m.fst < R-L) return true;
		if(L > R && m.fst < 0 && m.fst > R-L) return true;
	}
	return false;
}

void solve1 (){
	rta = "";
	if(R) right();
	else if(L) left();
	if(fp1()){
		assert(check(rta));
		cout<<rta<<"\n";
	}
	else{
		assert(imp());
		cout<<"Impossible\n";
	}
}

void solve2(){
	rta = "";
	if(U) up();
	else if(D) down();
	if(fq1())cout<<rta<<"\n";
	else cout<<"Impossible\n";
}



int main(){
	JET
	ll t; cin>>t;
	// ll t = 1;
	while(t--){
		U = 0, D = 0, L = 0, R = 0;
		robot = {0,0};
		cin>>m.fst>>m.snd;
		string s; cin>>s;
		for(auto x:s){
			if(x == 'U') U++;
			if(x == 'D') D++;
			if(x == 'L') L++;
			if(x == 'R') R++;
		}
		ii fin = {R-L,U-D};
		if(m == (ii){0,0}){
			cout<<"Impossible\n";
			continue;
		}
		u = U; l = L; r = R; d = D;
		if(m.fst == 0 && fin.fst == 0 && (R || L)){
			// cout<<U<<" "<<D<<"\n";
			solve1();
			continue;
		}
		if(m.snd == 0 && fin.snd == 0 && (U || D)){
			solve2();
			continue;
		}
		if(f1(0)){
			assert(check(rta));
			cout<<rta<<"\n";
		}
		else if(f1(1)){
			assert(check(rta));
			cout<<rta<<"\n";
		}
		else if(f2(0)){
			assert(check(rta));
			cout<<rta<<"\n";
		}
		else if(f2(1)){
			assert(check(rta));
			cout<<rta<<"\n";
		}
		else{
			assert(imp());
			cout<<"Impossible\n";
		}
	}
	return 0;
}