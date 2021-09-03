class Algorithm{
    //let x = 2^m0 * 3^m1 * 5^m2 * (other primes)^m_i
    //y = 2^n0 * 3^n1 * 5^n2 * (other primes)^n_i
    //gcd(x,y) = 2^min(m0,n0) * 3^min(m1,n1) * 5^min(m2,n2) * ...
    //lcm(x,y) = 2^max(m0,n0) * 3^max(m1,n1) * 5^max(m2,n2) * ...
    public int gcd(int i, int j){
        return (j == 0) ? a : gcd(j, i % j);
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