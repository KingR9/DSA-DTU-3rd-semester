#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}
int main() { 

   int n;
   cout << "Enter the no. of elements ";
    cin >> n;
   int arr[50];
   cout << "Enter the elements ";
   for(int i = 0; i < n; i++){
    cin >> arr[i];
   }
   int x;
   cout << "Enter the element to be search ";
   cin >> x;
    int ans = linearSearch(arr, n, x);
    cout << "Index of x is " << ans ;
    return 0;
}