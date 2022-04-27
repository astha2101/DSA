import java.util.Scanner;
class psp
{
public static void main(String gg[])
{
int[] arr=new int[10];
for(int i=0;i<10;i++)
{
Scanner sc=new Scanner(System.in);
System.out.print("Enter a number :");
arr[i]=sc.nextInt();
}
for(int e=0;e<9;e++)
{
int si=e;
for(int f=e+1;f<10;f++)
{
if(arr[f]<arr[si]) si=f;
}
int g=arr[e];
arr[e]=arr[si];
arr[si]=g;
}
for(int i=0;i<10;i++) System.out.println(arr[i]);
}
}