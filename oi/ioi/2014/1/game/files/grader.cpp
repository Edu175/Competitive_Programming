#include <stdio.h>
#include <assert.h>
#include "game.h"

static const int buf_size = 4096;

inline int getChar() {
	static char buf[buf_size];
	static int len = 0, pos = 0;
	if (pos == len)
		pos = 0, len = fread(buf, 1, buf_size, stdin);
	if (pos == len)
		return -1;
	return buf[pos++];
}

inline int readChar() {
	int c = getChar();
	while (c <= 32)
		c = getChar();
	return c;
}

template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}


static char ans[1500 * 1500];

int main() {
    int n, u, v, i;
    n = readInt<int>();
    initialize(n);
    for (i = 0; i < n * (n - 1) / 2; i++) {
        u = readInt<int>();
        v = readInt<int>();
        if (hasEdge(u, v)) ans[i] = '1';
        else ans[i] = '0';
    }
    puts(ans);
    return 0;
}
