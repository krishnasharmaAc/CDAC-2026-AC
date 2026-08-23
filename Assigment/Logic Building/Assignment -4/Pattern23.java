public class Pattern23 {
    public static void main(String[] args) {
        int r =4;
        for(int i=0; i<r; i++){
            // printing spaces first
            for(int j=1; j<=r-i;j++){
                System.out.print(" ");
            }
            //printing first half 
            for(int j=1; j<=(2*i+1); j++){
                System.out.print("*");
            }
            System.out.println();
        }
        for(int i=r; i>0; i--){
            // printing spaces first
            for(int j=1; j<=r-i;j++){
                System.out.print(" ");
            }
            //printing first half 
            for(int j=1; j<=(2*i+1); j++){
                System.out.print("*");
            }
            System.out.println();
        }
    }
}

