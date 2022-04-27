import java.util.*;
class SelectionSort<T>
{
public  void sort(T [] arr, Object c)
{
int n=arr.length;
for(int e=0;e<(n-1);e++)
{
int si=e;
for(int f=e+1;f<n;f++)
{
if(c.compare((T)arr[f],(T)arr[e])<0)
{
si=f;
}
}
T g=arr[e];
arr[e]=arr[si];
arr[si]=g;
}
}
}
class test
{
public static void main(String gg[])
{
Integer [] arr=new Integer[10];
for(int i=0;i<10;i++)
{
Scanner sc=new Scanner(System.in);
System.out.print("Enter a number :");
arr[i]=sc.nextInt();
}
SelectionSort<Integer> ss;
Integer t=new Integer(1);
//Comparator<Integer> r=(Comparator<Integer>)t;
ss.sort(arr,t);
for(int i=0;i<10;i++) System.out.println(arr[i]);
}
}