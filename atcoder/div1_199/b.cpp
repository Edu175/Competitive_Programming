#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

// I believe chat gpt is allowed in arc div1
// the following was prompted to chat gpt

vector<long long> findXorWays(const vector<long long>& a, long long k) {
    int n = (int)a.size();
    const int MAXB = 60;  // since elements are up to 60 bits
    
    // basis_val[b]: stores a basis vector whose highest set‐bit is b (or 0 if none).
    // basis_mask[b]: the corresponding mask (over indices 0..n−1) used to build basis_val[b].
    array<long long, MAXB> basis_val{}, basis_mask{};
    // Initialize all to 0
    for (int b = 0; b < MAXB; b++) {
        basis_val[b] = 0;
        basis_mask[b] = 0;
    }
    
    // null_masks: each entry is a mask over indices whose XOR is zero.
    // dimension = n − rank.  We will pick the first two to generate extra solutions.
    vector<long long> null_masks;
    
    // 1) Build basis
    for (int i = 0; i < n; i++) {
        long long x = a[i];
        long long mask = (1LL << i);
        // Reduce x against existing basis:
        for (int b = MAXB - 1; b >= 0; b--) {
            if (!(x & (1LL << b))) continue;
            if (basis_val[b] == 0) {
                // Found a new pivot at bit b
                basis_val[b] = x;
                basis_mask[b] = mask;
                x = 0;             // we have inserted it; no remainder
                break;
            } else {
                // eliminate that bit
                x ^= basis_val[b];
                mask ^= basis_mask[b];
            }
        }
        if (x == 0) {
            // If the vector reduced fully to 0, its mask is a null‐space vector
            // i.e. XOR of those indices is 0
            null_masks.push_back(mask);
        }
        // else: it was inserted into the basis
    }
    
    // 2) Try to reduce k to zero and record which basis masks we used
    long long sol_mask = 0;
    long long tmp = k;
    for (int b = MAXB - 1; b >= 0; b--) {
        if (!(tmp & (1LL << b))) continue;
        if (basis_val[b] == 0) {
            // No basis vector to eliminate this bit ⇒ no solution
            return {};
        }
        tmp ^= basis_val[b];
        sol_mask ^= basis_mask[b];
    }
    // Now tmp == 0, so sol_mask is one particular solution
    
    // 3) Build up to 3 distinct solutions
    vector<long long> result;
    result.reserve(3);
    result.push_back(sol_mask);
    if (!null_masks.empty()) {
        result.push_back(sol_mask ^ null_masks[0]);
        if (null_masks.size() >= 2) {
            result.push_back(sol_mask ^ null_masks[1]);
        }
    }
    return result;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll>res;
		vv to;
		auto op=[&](ll i, ll w=-1){
			assert(i<n-1);
			assert(i>=0);
			res.pb(i);
			ll j=i+1;
			if(to[i]&&to[j]){
				assert(w!=-1);
				to[i]=to[j]=0;
				to[(w?j:i)]=1;
			}
			else {
				if(to[i]||to[j]){
					ll p=i;
					if(!to[p])p=j;
					assert(a[i^j^p]==0);
					swap(to[i],to[j]);
				}
			}
			ll x=a[i]^a[j];
			a[i]=a[j]=x;
		};
		auto mata=[&](ll i){
			op(i);
			op(i);
		};
		if(!k){
			mata(0);
			cout<<"Yes\n";
			cout<<SZ(res)<<"\n";
			for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
			continue;
		}
		auto ways=findXorWays(a,k);
		for(auto mk:ways){
			vv is(n);
			fore(i,0,n)is[i]=mk>>i&1;
			ll good=0;
			fore(i,0,n-1)good|=is[i]==is[i+1];
			if(good)to=is;
		}
		if(!SZ(to)){
			cout<<"No\n";
			continue;
		}
		cout<<"Yes\n";
		auto chain=[&](ll i, ll j, ll d){
			for(ll p=i,did=0;!did;p+=d){
				did|=p==j;
				op(p,d==1);
			}
		};
		auto acum=[&](ll i, ll j){// accumulates in j xor[j..i]
			if(i==j)return;
			if(i<j)chain(i,j-1,1);
			else chain(i-1,j,-1);
		};
		ll p=-1,q=-1;
		fore(i,0,n-1){
			if(!to[i]&&!to[i+1])p=i;
			if(i+2<n&&to[i+1]&&(to[i]||to[i+2]))q=i;
		}
		if(p==-1){
			if(to[q])op(q,0),p=q+1;
			else op(q+1,1),p=q;
		}
		// to[p,p+1] = [0,0]
		assert(p<n-1&&!to[p]&&!to[p+1]);
		mata(p);
		while(p<n-2){
			acum(p+2,p);
			mata(p+1);
			p++;
		}
		while(p>1){
			while(p>=1&&!to[p-1])mata(--p);
			assert(p>=1);
			acum(p-1,p+1);
			mata(--p);
			ll q=p;
			while(q>=1&&!to[q-1])mata(--q);
			ll dst=max(q-1,0ll);
			acum(p+2,dst); // max: caso dst = 0
			p=dst+1;
		}
		cout<<SZ(res)<<"\n";
		for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
		assert(a[0]==k);
	}
	return 0;
}
