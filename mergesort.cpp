#include <iostream>
using namespace std;


class Solution
{

    public:
    void merge(int arr[], int l, int m, int r)
    {
        int i=0;
        int n=r - l + 1;
        int left=l;
        int right=m+1;
        int a[n];
        while(left<=m && right<=r )
        {
            if(arr[left]<=arr[right])
            {
                a[i]=arr[left];
                i++;
                left++;
            }
            else
            {
                a[i]=arr[right];
                i++;
                right++;
                
            }
        }
        while(left<=m)
        {
            a[i]=arr[left];
            i++;
            left++;
        }
        while(right<=r)
        {
            a[i]=arr[right];
            i++;
            right++;
        }
        for(int j=l;j<=r;j++)
        {
            arr[j]=a[j-l];
        }
         // Your code here
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r)
        {
            return;
        }
        int mid=l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
        //code here
    }
};

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main()
{
    Solution solution;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    cout << "Given array is \n";
    printArray(arr, n);

    solution.mergeSort(arr, 0, n - 1);

    cout << "Sorted array is \n";
    printArray(arr, n);

    return 0;
}
