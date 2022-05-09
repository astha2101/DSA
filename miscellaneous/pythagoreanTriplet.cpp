class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    // code here
	    for(int i=0;i<n;i++) arr[i]=arr[i]*arr[i];  // O(n)
	    sort(arr,arr+n);  // O(nlogn)
	    
	    int x,y,z;
	     z=n-1;
	     while(z>1)
	     {
	         x=0;
	         y=z-1;
	         while(x<y)
	         {
	             if(arr[x]+arr[y] == arr[z]) return true;
	             if(arr[x]+arr[y] > arr[z]) y--;
	             else x++;
	         }
	         z--;
	     }
	     return false;
	}
};
