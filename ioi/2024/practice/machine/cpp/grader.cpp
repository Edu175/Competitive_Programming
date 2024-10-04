#include "machine.h"
#include <cstdio>
#include <cassert>
#include <cstdlib>

namespace {

int N, X;
std::vector<int> P;

int Q, M;

void quit(const char* message) {
  printf("%s\n", message);
  exit(0);
}

void run_scenario() {
  Q = 0;
  M = 0;

  assert(2 == scanf("%d%d", &N, &X));
  P.resize(N);
  for (int i = 0; i < N; i++)
    assert(1 == scanf("%d", &P[i]));

  std::vector<int> R = find_permutation(N);

  printf("%d\n", (int)R.size());
  for (int i = 0; i < (int)R.size(); i++)
    printf("%s%d", i == 0 ? "" : " ", R[i]);
  printf("\n");
  printf("%d %d\n", Q, M);
}

} // namespace

std::vector<int> use_machine(std::vector<int> A) {
  if ((int)A.size() != N)
    quit("Invalid argument");
  Q++;
  std::vector<int> B(N);
  for (int i = 0; i < N; i++) {
    B[i] = A[P[i]] ^ X;
    M = std::max(M, A[i]);
  }
  return B;
}

int main() {
  int T;
  assert(1 == scanf("%d", &T));
  for (int i = 1; i <= T; i++)
    run_scenario();

  return 0;
}
