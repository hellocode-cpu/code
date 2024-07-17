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
