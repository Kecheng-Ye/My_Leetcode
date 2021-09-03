class Algorithm{
    public int gcd(int i, int j){
        if(j == 0){
            return i;
        }else{
            return gcd(j, i % j);
        }
    }
}

public class gcd{
    public static void main(String[] args) {
        Algorithm algo = new Algorithm();
        System.out.println(gcd(14, 4));
    }
}