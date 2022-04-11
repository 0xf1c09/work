public class Hello
{
	public int addition( int x, int y)
	{
		int z = x + y;
		return z;
	}
	public static void main( String ar[ ] )
	{
		int a = 5, b = 6;
		Hello ob = new Hello();
		int c = ob.addition(a,b);
		System.out.println("Add: " + c);
	}
}

