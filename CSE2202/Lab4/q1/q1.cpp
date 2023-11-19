#include <bits/stdc++.h>
using namespace std;
int asc[100], desc[100];
void ascendingSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
            if (a[j] < a[min])
                min = j;
        swap(a[i], a[min]);
    }
    for (int i = 0; i < n; i++)
        asc[i] = a[i];
}
void descendingsort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int max = i;
        for (int j = i; j < n; j++)
            if (a[j] > a[max])
                max = j;
        swap(a[i], a[max]);
    }
    for (int i = 0; i < n; i++)
        desc[i] = a[i];
}
void KnapSack(int P1[], int W[], int n, int M, int P2[], double X[], int P[])
{
    int sum = 0, c = 0, prev = M;
    for (int i = 0; i < n; i++)
        P2[i] = P1[i];
    descendingsort(P1, n);
    while (M > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (P2[i] == desc[c])
            {
                cout << P2[i] << " " << M << endl;
                if (M < W[i])
                    X[i] = (float)M / W[i];
                else
                    X[i] = M / W[i];
                sum = sum + X[i] * P2[i];
                M = M - X[i] * W[i];
                prev = M;
                c++;
                i++;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << X[i] << " ";
    cout << endl;
    cout << sum << endl;
}
int main()
{
    int n, M;
    cin >> n;
    cin >> M;
    int P1[n], P2[n], W1[n], W2[n];
    double X[n];
    memset(X, 0, sizeof(X));
    for (int i = 0; i < n; i++)
        cin >> P1[i];
    for (int i = 0; i < n; i++)
        cin >> W1[i];
    double PbyW[n];
    for (int i = 0; i < n; i++)
        PbyW[i] = (double)P1[i] / W1[i];
    // KnapSack(P1, W1, n, M, P2, X, P1);
    KnapSack(W1, W1, n, M, P2, X, P1);
}