//Bubble Sort: Compare the adjacent elements and swap them if they are in wrong order repeatedly, until the array is sorted.

public class BubbleSort {
    public static void bubbleSort(int[] arr){
        int n =arr.length;
        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-i-1; j++){
                if(arr[j]>arr[j+1]){
                    //Swap using a temp variable
                    int temp=arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
    public static void main(String[] args){
        int[] numbers={9,2,6,3,8};
        bubbleSort(numbers);
        for(int num: numbers){
            System.out.print(num+" ");
        }
    }
    
}
//Time Complexity: O(n^2)
//Preferred when dataset is small / Nearly sorted