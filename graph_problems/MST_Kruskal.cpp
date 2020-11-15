#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back

struct edge
{
    int a, b, w;
};

edge ar[100000];
int parent[100001];
int R[100001];
int find(int n)
{
    if (parent[n] == -1)
        return n;
    else
        return parent[n] = find(parent[n]);
}
void merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if (R[a] > R[b])
    {
        //a would be parent
        parent[b] = a;
        R[a] += R[b];
    }
    else
    {
        //b would be parent
        parent[a] = b;
        R[b] += R[a];
    }
}
bool comp(edge a, edge b)
{
    if (a.w < b.w)
        return true;
    else
        return false;
}
#undef int
int main()
{
    int n, m, a, b;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        parent[i] = -1, R[i] = 1;

    for (int i = 0; i < m; i++)
    {
        cin >> ar[i].a >> ar[i].b >> ar[i].w;
    }
    sort(ar, ar + m, comp);

    int x, y;
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        x = find(ar[i].a);
        y = find(ar[i].b);

        if (x != y)
        {
            sum += ar[i].w;
            merge(x, y);
        }
    }
    cout << sum << endl;
    return 0;
}