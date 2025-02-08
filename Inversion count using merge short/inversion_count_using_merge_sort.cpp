#include <bits/stdc++.h>
#define ll long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
#define N ((int)1e6 + 9)
using namespace std;

int inversion = 0;
int n = 0;

void printArray(int arr[], int n)
{
    cout << "Array = ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void marge_sort(int arr[], int l, int r)
{
    if (l == r)
    {
        return;
    }

    int mid = (l + r) / 2;
    marge_sort(arr, l, mid);
    marge_sort(arr, mid + 1, r);

    int i = l, j = mid + 1;
    vector<int> vect;
    while (i <= mid && j <= r)
    {
        if (arr[i] < arr[j])
        {
            vect.push_back(arr[i]);
            i++;
        }
        else
        {
            vect.push_back(arr[j]);
            inversion += (mid - i + 1);
            j++;
        }
    }
    while (i <= mid)
    {
        vect.push_back(arr[i]);
        i++;
    }
    while (j <= r)
    {
        vect.push_back(arr[j]);
        j++;
    }

    for (int i = l; i <= r; i++)
    {
        arr[i] = vect[i - l];
    }
}

int main()
{
    int arr[] = {4, 3, 2, 1};
    n = sizeof(arr) / sizeof(arr[0]);
    marge_sort(arr, 0, (n - 1));

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nNumber of Inversions = " << inversion << endl;

    return 0;
}
