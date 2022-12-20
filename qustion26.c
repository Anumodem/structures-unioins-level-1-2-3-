#include <stdio.h>
#include <stdlib.h>
#define N 1024
#define M (N * N)
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
char aa[N][N + 1], bb[N][N + 1];
int ii[N], jj[N], pp[N], qq[N];
int ll[M], rr[M], stack[M];
char stabbed[M];
struct V {
int i, lr;
} vv[M * 2];
int compare_j(const void *a, const void *b) {
int j1 = *(int *) a;
int j2 = *(int *) b;
return j1 - j2;
}
int compare_v(const void *a, const void *b) {
struct V *u = (struct V *) a;
struct V *v = (struct V *) b;
int x = u->lr == 0 ? ll[u->i] : rr[u->i];
int y = v->lr == 0 ? ll[v->i] : rr[v->i];
return x != y ? x - y : u->lr - v->lr;
}
int main() {
int t;
scanf("%d", &t);
while (t--) {
static char (*cc)[N + 1];
int n, m, h, i, j, empty_, empty, h_, b, ans;
scanf("%d%d", &n, &m);
for (i = 0; i < n; i++)
scanf("%s", aa[i]);
if (n <= m)
cc = aa;
else {
int tmp;
for (i = 0; i < n; i++)
for (j = 0; j < m; j++)
bb[j][i] = aa[i][j];
cc = bb;
tmp = n, n = m, m = tmp;
}
for (i = 0; i < n; i++)
qq[i] = 0;
for (j = 0; j < m; j++)
pp[j] = 0;
for (i = 0; i < n; i++)
for (j = 0; j < m; j++)
if (cc[i][j] == 'K')
qq[i] = pp[j] = 1;
empty_ = 0;
for (i = 0; i < n; i++)
if (qq[i] == 0) {
empty_ = 1;
break;
}
if (!empty_) {
printf("-1\n");
continue;
}
for (j = 0; j < m; j++) {
pp[j] = pp[j] == 0;
if (j > 0)
pp[j] += pp[j - 1];
}
h_ = 0;
for (i = 0; i <= n; i++) {
empty = i == n || !qq[i];
if (empty && !empty_)
ii[h_++] = i;
empty_ = empty;
}
ans = 0;
if (h_ > 0) {
ans = M;
for (b = 0; b < 1 << (h_ - 1); b++) {
int hcuts, vcuts, nv, k, cnt;
hcuts = 0;
nv = 0;
for (h = 0, i = 0, k = 0; h < h_; h++) {
if (b & 1 << h)
hcuts++;
while (i < ii[h]) {
for (j = 0; j < m; j++)
if (cc[i][j] == 'K')
jj[k++] = j;
i++;
}
if ((b & 1 << h) || h == h_ - 1) {
int u;
qsort(jj, k, sizeof *jj, compare_j);
for (u = 1; u < k; u++) {
int l = pp[jj[u - 1]] + 1, r =
pp[jj[u]];
if (l > r)
goto end;
ll[nv] = l; rr[nv] = r;
nv++;
}
k = 0;
}
}
for (i = 0; i < nv; i++) {
vv[i * 2 + 0].i = i;
vv[i * 2 + 0].lr = 0;
vv[i * 2 + 1].i = i;
vv[i * 2 + 1].lr = 1;
}
qsort(vv, nv * 2, sizeof *vv, compare_v);
vcuts = 0, cnt = 0;
for (i = 0; i < nv; i++)
stabbed[i] = 0;
for (i = 0; i < nv * 2; i++) {
struct V *v = &vv[i];
if (stabbed[v->i])
continue;
if (v->lr == 0)
stack[cnt++] = v->i;
else {
vcuts++;
while (cnt > 0)
stabbed[stack[--cnt]] = 1;
}
}
ans = min(ans, max(hcuts, vcuts));
end:;
}
if (ans == M)
ans = -1;
}
printf("%d\n", ans);
}
return 0;
}
