#include "treasure.h"
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <random>

#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto sjdhg:v)cout<<sjdhg<<" ";cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
namespace {

const int MIN_VAL = 0;
const int MAX_VAL = 2'000'000'000;

void quit(const char* message) {
  printf("%s\n", message);
  exit(0);
}

void run_scenario() {
  int n;
  assert(1 == scanf("%d", &n));

  std::vector<std::pair<int, int>> P(n);
  for (int i = 0; i < n; i++)
    assert(2 == scanf("%d%d", &P[i].first, &P[i].second));

  std::vector<int> E = encode(P);
  int L = E.size();

  for (int i = 0; i < L; i++)
    if (E[i] < MIN_VAL || E[i] > MAX_VAL)
      quit("Invalid element in the returned array");

  std::vector<int> S = E;
  std::shuffle(S.begin(), S.end(), std::mt19937(0));

  std::vector<std::pair<int, int>> D = decode(S);
  int M = D.size();

  printf("%d\n%d\n", L, M);
  for (int i = 0; i < M; i++)
    printf("%d %d\n", D[i].first, D[i].second);
}

} // namespace
random_device rd;
mt19937 rng(rd());
void stress() {
	ll N,V,_=0; cin>>N>>V;
	while(1){
		ll n=rng()%N+1;
		vector<std::pair<int, int>> P(n);
		fore(i,0,n)P[i].fst=rng()%V+1,P[i].snd=rng()%V+1;
		auto E=encode(P);
		ll L=SZ(E);
		auto out=[&](string s){
			cout<<s<<"\nInput:\n"<<n<<"\n";
			for(auto i:P)cout<<i.fst<<" "<<i.snd<<"\n";
			exit(0);
		};
		fore(i,0,L){
			if (E[i] < MIN_VAL || E[i] > MAX_VAL){
				out("Invalid element in the returned array");
			}
		}
		shuffle(ALL(E),rng);
		auto D=decode(E);
		sort(ALL(P));
		sort(ALL(D));
		if(D!=P)out("Incorrect answer");
		cout<<"OK "<<++_<<". K "<<double(L)/N<<"\n";
		// <<L<<" queries\n";
	}
}
int main() {
	// stress();
  int T;
  assert(1 == scanf("%d", &T));
  for (int i = 1; i <= T; i++)
    run_scenario();

  return 0;
}
