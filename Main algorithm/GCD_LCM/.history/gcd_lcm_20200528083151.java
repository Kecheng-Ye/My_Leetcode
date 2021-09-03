class Algorithm{
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