#include <bits/stdc++.h>
using namespace std;

int maxProduct(int arr[], int n)
{
    int max_so_far = arr[0];
    int max_ending_here = arr[0];
    int min_ending_here = arr[0];

    for (int i = 1; i < n; i++)
    {
        int temp_max = max(arr[i], max(max_ending_here * arr[i], min_ending_here * arr[i]));
        min_ending_here = min(arr[i], min(max_ending_here * arr[i], min_ending_here * arr[i]));
        max_ending_here = temp_max;
        max_so_far = max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int largest_product = maxProduct(arr, n);
    cout << largest_product << endl;
    return 0;
}
