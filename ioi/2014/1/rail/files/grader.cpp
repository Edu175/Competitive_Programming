#include "rail.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Station {
  int index;
  int type;
  int location;
  int L, R;
} STATION;
static long long cnt;
static int S, SUBTASK;
static STATION stations[10004];

static int cmp_fun_1(const void *a, const void *b) {
  STATION c, d;
  c = *(STATION *)(a);
  d = *(STATION *)(b);
  return c.location < d.location ? -1 : 1;
}

static int cmp_fun_2(const void *a, const void *b) {
  STATION c, d;
  c = *(STATION *)(a);
  d = *(STATION *)(b);
  return c.index < d.index ? -1 : 1;
}

static void now_I_want_to_getLR() {
  int now = stations[S - 1].index, i;
  for (i = S - 2; i >= 0; i--) {
    stations[i].R = now;
    if (stations[i].type == 2)
      now = stations[i].index;
  }
  now = stations[0].index;
  for (i = 1; i < S; i++) {
    stations[i].L = now;
    if (stations[i].type == 1)
      now = stations[i].index;
  }
}

int getDistance(int x, int y) {
  cnt++;
  if (x == y)
    return 0;
  if (x < 0 || x >= S || y < 0 || y >= S)
    return -1;
  if (stations[x].location > stations[y].location) {
    int tmp = x;
    x = y;
    y = tmp;
  }
  int ret = 0;
  if (stations[x].type == 1 && stations[y].type == 1) {
    ret = stations[stations[y].R].location - stations[x].location +
          stations[stations[y].R].location - stations[y].location;
  } else if (stations[x].type == 1 && stations[y].type == 2) {
    ret = stations[y].location - stations[x].location;
  } else if (stations[x].type == 2 && stations[y].type == 2) {
    ret = stations[x].location - stations[stations[x].L].location +
          stations[y].location - stations[stations[x].L].location;
  } else if (stations[x].type == 2 && stations[y].type == 1) {
    ret = stations[x].location - stations[stations[x].L].location +
          stations[stations[y].R].location - stations[stations[x].L].location +
          stations[stations[y].R].location - stations[y].location;
  }
  return ret;
}

static void getInput() {
  assert(scanf("%d", &SUBTASK) == 1);
  assert(scanf("%d", &S) == 1);
  int s;
  for (s = 0; s < S; s++) {
    int type, location;
    assert(scanf(" %d %d", &type, &location) == 2);
    stations[s].index = s;
    stations[s].location = location;
    stations[s].type = type;
    stations[s].L = -1;
    stations[s].R = -1;
  }
  qsort(stations, S, sizeof(STATION), cmp_fun_1);
  now_I_want_to_getLR();
  qsort(stations, S, sizeof(STATION), cmp_fun_2);
}

static int serverGetFirstStationLocation() { return stations[0].location; }

static int location[10005];
static int type[10005];
static int ok = 1;

int main() {
  int i;
  getInput();
  cnt = 0;

  findLocation(S, serverGetFirstStationLocation(), location, type);
  if (SUBTASK == 3 && cnt > S * (S - 1))
    ok = 0;
  if (SUBTASK == 4 && cnt > 3 * (S - 1))
    ok = 0;

  for (i = 0; i < S; i++)
    if (type[i] != stations[i].type || location[i] != stations[i].location)
      ok = 0;
  if (ok == 0)
    printf("Incorrect");
  else
    printf("Correct");
  return 0;
}
