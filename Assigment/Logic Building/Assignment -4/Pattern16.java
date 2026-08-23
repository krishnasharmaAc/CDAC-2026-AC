public class Pattern16 {
    public static void main(String[] args) {
        for(int i= 1; i<=5; i++){
            int a = 1; 
            for(int j=1; j<=(2*i-1); j++){
                if(j%2 != 0){
                    System.out.print(a++);
                }
                else{
                    System.out.print("*");
                }
            }
            System.out.println();
        }
    }
}
