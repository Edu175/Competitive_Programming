#include "pyramids.h"
#include <cstdio>
#include <cassert>

int main() {
  int N, Q;
  assert(2 == scanf("%d %d", &N, &Q));
  std::vector<int> A(N), B(N);
  for (int i = 0; i < N; i++)
    assert(1 == scanf("%d", &A[i]));
  for (int i = 0; i < N; i++)
    assert(1 == scanf("%d", &B[i]));
  std::vector<int> L(Q), R(Q), X(Q), Y(Q);
  for (int i = 0; i < Q; i++)
    assert(4 == scanf("%d%d%d%d", &L[i], &R[i], &X[i], &Y[i]));
  fclose(stdin);

  init(A, B);

  std::vector<bool> P(Q);
  for (int i = 0; i < Q; i++)
    P[i] = can_transform(L[i], R[i], X[i], Y[i]);

  for (int i = 0; i < Q; i++)
    printf("%d\n", (P[i] ? 1 : 0));
  fclose(stdout);

  return 0;
}
