public class problem12{
    public static String intToRoman(int num) {
        StringBuilder builder = new StringBuilder();
        int temp = num;
        while(temp > 0){
            if(temp >= 1000){
                builder.append("M");
                temp -= 1000;
            }else if(temp >= 900){
                builder.append("CM");
                temp -= 900;
            }else if(temp >= 500){
                builder.append("D");
                temp -= 500;
            }else if(temp >= 400){
                builder.append("CD");
                temp -= 400;
            }else if(temp >= 100){
                builder.append("C");
                temp -= 100;
            }else if(temp >= 90){
                builder.append("XC");
                temp -= 90;
            }else if(temp >= 50){
                builder.append("L");
                temp -= 50;
            }else if(temp >= 40){
                builder.append("XL");
                temp -= 40;
            }else if(temp >= 10){
                builder.append("X");
                temp -= 10;
            }else if(temp >= 9){
                builder.append("IX");
                temp -= 9;
            }else if(temp >= 5){
                builder.append("V");
                temp -= 5;
            }else if(temp >= 4){
                builder.append("IV");
                temp -= 4;
            }else{
                builder.append("I");
                temp -= 1;
            }     
        }

        return builder.toString();
    }


    public static void main(String[] args) {
        System.out.println(intToRoman(19));
    }
}