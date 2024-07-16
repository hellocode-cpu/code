#include <iostream>
using namespace std;

class Solution
{
    void swap(int &a,int &b)
    {
        int temp=a;
        a=b;
        b=temp;
        
    }
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low>=high)
        {
            return;
        }
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
        // code here
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        int pivot=arr[high];
        int i=low-1;
        for(int j=low;j<high;j++)
        {
            if(arr[j]<pivot)
            {
                i++;
                swap(arr[j],arr[i]);
                
            }
        }
        swap(arr[i+1],arr[high]);
        return i+1;
        
        
       // Your code here
    }
};

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution solution;
    solution.quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
