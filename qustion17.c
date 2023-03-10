#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define boolean int
#define true 1
#define false 0
#define null NULL
#define new_line printf("\n")
#define new(type) ((type *)malloc(sizeof(type)))
typedef struct Node {
int key, pri, cnt;
boolean rv;
struct Node *l, *r;
} Node;
Node *get_node(int key) {
Node *v = new(Node);
v->key = key;
v->pri = rand();
v->cnt = 1;
v->rv = false;
v->l = v->r = null;
return v;
}
int get_cnt(Node *v) {
return (v == null) ? 0 : v->cnt;
}
void upd_cnt(Node *v) {
if(v != null) v->cnt = 1 + get_cnt(v->l) + get_cnt(v->r);
}
void rev(Node *v) {
if(v == null || !v->rv) return;
Node *t = v->l;
v->l = v->r;
v->r = t;
v->rv = false;
if(v->l) v->l->rv ^= true;
if(v->r) v->r->rv ^= true;
}
void merge(Node **v, Node *l, Node *r) {
if(l == null || r == null) return (void) (*v = (l == null) ? r : l);
rev(l);
rev(r);
if(l->pri > r->pri) {
merge(&l->r, l->r, r);
*v = l;
}
else {
merge(&r->l, l, r->l);
*v = r;
}
upd_cnt(*v);
}
void split(Node *v, Node **l, Node **r, int at, int seen) {
if(v == null) return (void) (*l = *r = null);
rev(v);
int idx = seen + get_cnt(v->l);
if(idx < at) {
split(v->r, &v->r, r, at, idx+1);
*l = v;
}
else {
split(v->l, l, &v->l, at, seen);
*r = v;
}
upd_cnt(v);
}
void update(Node **root, int a, int b, int c) {
Node *ta, *tb, *tc;
split(*root, &ta, root, a, 0);
split(*root, &tb, root, b, 0);
merge(root, ta, *root);
split(*root, &tc, root, c, 0);
tb->rv ^= true;
merge(root, tb, *root);
merge(root, tc, *root);
}
void show(Node *v) {
if(v == null) return;
rev(v);
show(v->l);
printf("%d ", v->key);
show(v->r);
}
int main() {
int i, n, m, a, b, c;
Node *root = null;
scanf("%d %d", &n, &m);
for(i=0; i<n; i++) merge(&root, root, get_node(i+1));
for(i=0; i<m; i++) {
scanf("%d %d %d", &a, &b, &c);
update(&root, a, b, c);
}
show(root);
new_line;
return 0;
}
