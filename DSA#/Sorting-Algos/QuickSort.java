//Quick Sort: It is a divide and conquer algorithm.
// Select a pivot
// partition the array into two sub arrays
// Elements smaller than pivot are to be placed at left
// Elements greater than pivot are to be placed at right

public class QuickSort{

    // Example of Recursion1`
    public static void quickSort(int[] arr, int low, int high){
        if(low<high){
            int pivotIdx = divide(arr, low, high);
            quickSort(arr, low, pivotIdx-1); //left subarray
            quickSort(arr, pivotIdx+1, high); //right subarray
        }
    }

    //Example of Encapsulation
    private static int divide(int[] arr, int low, int high){
        int pivot =arr[high];
        int i =low-1;
        for(int j=low; j<high; j++){
            if(arr[j]<pivot){
                i++;        
                //Swap the elements
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]= temp;
           }
        }
        int temp=arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;

        return i+1;
    }
    public static void main(String[] args){
        int[] numbers = {6,2,8,1,7,0};
        quickSort(numbers, 0, numbers.length -1);
        for(int num:numbers){
            System.out.print(num + " ");
        }
    }
}
//Time Complexity: O(n log n)
//The fastest sorting algorithm
//In-place sorting, ideal for larder datasets
//Arrays.sort() is based on this algorithm