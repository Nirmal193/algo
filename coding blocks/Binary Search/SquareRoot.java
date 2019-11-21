import java.util.Scanner;
public class SquareRoot {
    public static void main(String args[]) {
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        int d=scan.nextInt();
        System.out.println(solve(0,n,n,d));
    }
    public static float solve(int start,int end,int key,int digits)
    {

        double ans=0.0;
       while(start<=end)
       {
           int mid=(start+end)/2;
           if(mid*mid==key)
           {
               ans=mid;
               break;
           }
           else if(mid*mid<key)
           {
               ans=mid;
               start=mid+1;
           }
           else
           end=mid-1;
       }

        double inc=0.1;
        for(int i=0;i<digits;i++)
        {
            while(ans*ans<=key)
            ans+=inc;
            ans=ans-inc;
            inc/=10;
        }
        return (float)ans;
    }
}
