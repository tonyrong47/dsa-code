// Based on divide and conquer algorithm
// Divide the array into two halves and recursively sort them
// Then merge the arrays to get a sorted array

public class MergeSort{
    public static void mergeSort(int[] arr, int left, int right){
        if(left< right){
            int mid = left + (right-left) /2; //the middle element index
            mergeSort(arr, left, mid); //left subarray
            mergeSort(arr, mid+1, right); //right subarray
            merge(arr, left, mid, right);
        }
    }

    //to merge both sorted subarrays
    private static void merge(int[] arr, int left, int mid, int right){
        int n1= mid-left+1;
        int n2= right-mid;

        int[] leftArray = new int[n1];
        int[] rightArray = new int[n2];

        for(int i=0; i<n1; i++){
            leftArray[i] = arr[left+i];
        }

        for(int j=0; j <n2; j++){
            rightArray[j] = arr[mid+1+j];
        }

        int i=0;
        int j=0;
        int k=left;

        while(i<n1 && j<n2){
            if(leftArray[i]<=rightArray[j]){
                arr[k] = leftArray[i];
                i++;
            }
            else{
                arr[k] = rightArray[j];
                j++;
            }
            k++;
        }

        while(i<n1){
            arr[k] = leftArray[i];
            i++;
            k++;
        }

        while(j<n2){
            arr[k] = rightArray[j];
            j++;
            k++;
        }
    }

    public static void main(String[] args){
        int[] numbers = {5,2,3,12,5};
        mergeSort(numbers, 0, numbers.length-1);
        for(int num:numbers){
            System.out.print(num + " ");
        }
    }
}