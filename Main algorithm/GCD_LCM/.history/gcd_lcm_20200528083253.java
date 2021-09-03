class Algorithm{
    
    //gcd(x,y) = 2^min(m0,n0) * 3^min(m1,n1) * 5^min(m2,n2) * ...
    //lcm(x,y) = 2^max(m0,n0) * 3^max(m1,n1) * 5^max(m2,n2) * ...
    public int gcd(int i, int j){
        if(j == 0){
            return i;
        }else{
            return gcd(j, i % j);
        }
    }

    public int lcm(int i, int j){
        return (i * j)/gcd(i, j);
    }
}

public class gcd_lcm{
    public static void main(String[] args) {
        Algorithm algo = new Algorithm();
        System.out.println(algo.gcd(15, 6));
    }
}