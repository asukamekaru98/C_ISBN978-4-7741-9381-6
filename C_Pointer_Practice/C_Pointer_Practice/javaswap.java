import java.util.Arrays;

class JavaSwap{
	public static void main(String[] args){
		int[] a = int[] {1,2}
		int[] b = int[] {3,4}
		
		Sysyem.out.println("a.."+Arrays.toString(a) + ",b.." + Arrays.toString(b));
		
		swap(a,b);
		
		Sysyem.out.println("a.."+Arrays.toString(a) + ",b.." + Arrays.toString(b));
	}
	
	public static void swap(int[] a,int[] b) {
		int[] temp;
		
		temp = a;
		a = b;
		b = temp;
	}
}
