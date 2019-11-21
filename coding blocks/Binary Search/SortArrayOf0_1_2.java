import java.util.Scanner;
public class SortArrayOf0_1_2 {
    public static void main(String args[]) {
        Scanner scan=new Scanner(System.in);
       int n=scan.nextInt();
       int arr[]=new int[n];
       for(int i=0;i<n;i++)
       arr[i]=scan.nextInt();
       sort(arr);
       printArray(arr);
    }
    public static void sort(int arr[])
    {
        int lo=0,hi=arr.length-1,mid=0;
        while(mid<hi)
        {
            if(arr[mid]==0)
            {
                int temp=arr[mid];
                arr[mid]=arr[lo];
                arr[lo]=temp;
                mid++;
                lo++;
            }
            else if(arr[mid]==1)
            mid++;
            else
            {
                int temp=arr[mid];
                arr[mid]=arr[hi];
                arr[hi]=temp;
                mid++;
                hi--;
            }
        }
    }
    public static void printArray(int arr[])
    {
        for(int i=0;i<arr.length;i++)
        System.out.print(arr[i]+" ");
    }
}
