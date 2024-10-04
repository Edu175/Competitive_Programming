#include "holiday.h"
#include <stdio.h>

static int n, start, d;
static int attraction[100000];
static int i, n_s;

int main() {
  n_s = scanf("%d %d %d", &n, &start, &d);
  for (i = 0; i < n; ++i) {
    n_s = scanf("%d", &attraction[i]);
  }
  printf("%lld\n", findMaxAttraction(n, start, d, attraction));
  return 0;
}
