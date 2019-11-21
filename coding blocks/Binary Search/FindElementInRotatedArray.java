import java.util.Scanner;
public class Main {
    public static void FindElementInRotatedArray(String args[]) {
       Scanner scan=new Scanner(System.in);
       int n=scan.nextInt();
       int arr[]=new int[n];
       for(int i=0;i<n;i++)
       arr[i]=scan.nextInt();
       int key=scan.nextInt();
       int pivot=findPivot(arr,0,n-1);
       System.out.println(pivot);
       int res=solve(pivot,n-1,arr,key);
       System.out.println(res);
    }
    public static int findPivot(int arr[],int start,int end)
    {
        if(arr==null||arr.length==0)
        return -1;
        if(arr[start]<=arr[arr.length-1])
        return 0;
        int mid=(start+end)/2;
        if(arr[mid]>arr[mid+1])
        return mid;
        if(arr[start]<arr[mid])
        return findPivot(arr,mid+1,end);
        else
        return findPivot(arr,start,mid-1);
    }
    public static int solve(int start,int end,int arr[],int key)
    {
        if(start>end)
        return -1;
        int mid=(start+end)/2;
        if(arr[mid]==key)
        return mid+1;
        if(arr[mid]>key)
            return solve(start,mid-1,arr,key);
        else
             return solve(mid+1,end,arr,key);
    }
}
