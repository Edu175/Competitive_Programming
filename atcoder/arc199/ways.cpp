#include <bits/stdc++.h>
using namespace std;

/*
  findUpToThreeXorWays(a, k):
    - a: vector<long long> of size n (n ≤ 60), each element fits in 60 bits.
    - k:  target XOR value (assume k != 0).
    Returns a vector<long long> of up to three distinct masks m (as 60-bit longs),
    where each mask m corresponds to a subset S ⊆ {0,…,n-1} with XOR_{i in S}(a[i]) == k.
    If fewer than three such subsets exist, return exactly those; if none exist, return {}.

  Overview:
    1) Build a linear‐basis over all a[i].  For each basis pivot at bit b, we store:
         • basis_val[b]: the 60-bit value whose highest set‐bit is b.
         • basis_mask[b]: the 60-bit mask indicating exactly which original indices in ’a’ produced that basis_val[b].
       Whenever an a[i] reduces fully to zero, the final mask “m” we tracked is a null‐space vector: XOR of those indices is 0.  We collect all such “dependent‐insertion” masks into null_masks[].
    2) To find one particular subset S with XOR = k, we “reduce” k against the basis.  Whenever we eliminate bit b of k by XOR’ing with basis_val[b], we also XOR our accumulating sol_mask with basis_mask[b].  If in the end k reduces to zero, sol_mask is one valid subset‐mask.  Otherwise, no solution.
    3) Now every null‐space vector z (i.e. z ∈ null_masks) has XOR(a[i] for i in z) = 0.  Hence, if sol_mask ↦ XOR = k, then (sol_mask ⊕ z) ↦ XOR = k as well.  By picking up to two independent null_vectors, we generate up to two more distinct solutions.  If null_masks.size()==0, we only return {sol_mask}.  If null_masks.size()==1, we return {sol_mask, sol_mask⊕null_masks[0]}.  If ≥2, we return three: { sol_mask, sol_mask⊕null_masks[0], sol_mask⊕null_masks[1] }.
*/

vector<long long> findUpToThreeXorWays(const vector<long long>& a, long long k) {
    int n = (int)a.size();
    const int MAXB = 60;  // assume each a[i] uses ≤ 60 bits
    
    // basis_val[b] = a basis vector whose leading bit is b (or 0 if none)
    // basis_mask[b] = the 60-bit mask (over indices 0..n−1) that produced basis_val[b]
    array<long long, MAXB> basis_val{}, basis_mask{};
    for (int b = 0; b < MAXB; b++) {
        basis_val[b] = 0;
        basis_mask[b] = 0;
    }
    
    // null_masks collects one mask “m” per dependent insertion, where XOR(a[i] for i in m) = 0
    vector<long long> null_masks;
    
    // 1) Build the basis
    for (int i = 0; i < n; i++) {
        long long x = a[i];
        long long m = (1LL << i);  // start with mask selecting exactly index i
        // Reduce x against existing basis (highest bit → 0)
        for (int b = MAXB - 1; b >= 0; b--) {
            if (!(x & (1LL << b))) continue;
            if (basis_val[b] == 0) {
                // New pivot at bit b
                basis_val[b] = x;
                basis_mask[b] = m;
                x = 0;
                break;
            } else {
                // Eliminate bit b
                x ^= basis_val[b];
                m ^= basis_mask[b];
            }
        }
        if (x == 0) {
            // “m” is a null‐space vector: XOR(a[i] for i in m) = 0
            null_masks.push_back(m);
        }
        // Otherwise, (x,m) became a new basis pivot
    }
    
    // 2) Reduce k to find one particular solution (if any)
    long long tmp = k;
    long long sol_mask = 0;
    for (int b = MAXB - 1; b >= 0; b--) {
        if (!(tmp & (1LL << b))) continue;
        if (basis_val[b] == 0) {
            // Cannot eliminate bit b of k ⇒ no subset can XOR to k
            return {};
        }
        tmp ^= basis_val[b];
        sol_mask ^= basis_mask[b];
    }
    // Now tmp == 0, so sol_mask is one valid subset‐mask with XOR = k.
    
    // 3) Assemble up to three distinct solutions
    vector<long long> result;
    result.reserve(3);
    result.push_back(sol_mask);
    
    if ((int)null_masks.size() >= 1) {
        // Second solution: flip the first null‐space vector
        result.push_back(sol_mask ^ null_masks[0]);
    }
    if ((int)null_masks.size() >= 2) {
        // Third solution: flip the second null‐space vector
        result.push_back(sol_mask ^ null_masks[1]);
    }
    return result;
}

// ---------------------------- Example/Test ----------------------------

#include <iostream>

int main() {
    vector<long long> a = {2, 3, 4};
    long long k = 5;
    auto ways = findUpToThreeXorWays(a, k);
    
    cout << "Number of solutions found: " << ways.size() << "\n";
    for (auto mask : ways) {
        cout << "  mask = " << mask << "  -> indices = { ";
        for (int i = 0; i < (int)a.size(); i++) {
            if (mask & (1LL << i)) cout << i << " ";
        }
        long long x = 0;
        for (int i = 0; i < (int)a.size(); i++) {
            if (mask & (1LL << i)) x ^= a[i];
        }
        cout << "},  XOR = " << x << "\n";
    }
    return 0;
}
//
// Explanation of the sample run (a={2,3,4}, k=5):
//   • Basis construction sees {2,3,4} are linearly independent in GF(2), so null_masks.size() == 0.
//   • Reducing k=5 yields exactly one sol_mask = 0b111 (i.e. indices {0,1,2}).  That’s the only subset whose XOR is 5.
//   • Since null_masks is empty, we return exactly one mask.  (No “phantom” second or third solution.)
//
