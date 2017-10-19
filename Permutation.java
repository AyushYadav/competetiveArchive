import java.io.*;
import java.util.*;
 
class Permutation {
    
    public Permutation(){}
    
    /* arr[]  ---> Input Array
    data[] ---> Temporary array to store current combination
    start & end ---> Staring and Ending indexes in arr[]
    index  ---> Current index in data[]
    r ---> Size of a combination to be printed */

    public int binaryToInt(int data[],String full_str,int len)
    {
        int number = 0;
        int power_of_two = 1;
        for(int i = 0;i < len;i++){
            if(full_str.charAt(data[i]) == '1')
                number += 1 * power_of_two;
            else
                number += 0 * power_of_two;
            power_of_two *= 2;  
        }
        return number;
    }
    public int minimumPixelRequired(int data[],String full_str_array[], int n, int r, int K, int len)
    {
        Set<Integer> set_of_number = new HashSet<Integer>();
        for(int i = 0;i < K;i++){
            int number = binaryToInt(data,full_str_array[i], len);
            set_of_number.add(number);
        }
        int set_size = set_of_number.size();
        return set_size;
    }

    public void combinationUtil(String full_str_array[],int arr[], int n, int r, int index,
                                int data[], int i,int K)
    {
        // Current combination is ready to be printed, print it
        if (index == r)
        {
            // for (int j=0; j<r; j++)
            //     System.out.print(data[j]+" ");
            // System.out.println("\n");
            int set_size = minimumPixelRequired(data, full_str_array,n, r, K, data.length);
            if(set_size == K) {
                System.out.println(data.length);
                System.exit(0);
            }
            return;
        }
 
        // When no more elements are there to put in data[]
        if (i >= n)
            return;
 
        // current is included, put next at next location
        data[index] = arr[i];
        combinationUtil(full_str_array,arr, n, r, index+1, data, i+1, K);
 
        // current is excluded, replace it with next (Note that
        // i+1 is passed, but index is not changed)
        combinationUtil(full_str_array,arr, n, r, index, data, i+1, K);
    }
 
    // The main function that prints all combinations of size r
    // in arr[] of size n. This function mainly uses combinationUtil()
    public void printCombination(String full_str_array[], int arr[], int n, int r, int K)
    {
        // A temporary array to store all combination one by one
        int data[]=new int[r];
 
        combinationUtil(full_str_array, arr, n, r, 0, data, 0, K);
    }
 
    /*Driver function to check for above function*/
    public static void main (String[] args) {
        Permutation object = new Permutation();
        Scanner reader = new Scanner(System.in);  // Reading from System.in
        int T = reader.nextInt();
        for(int tt=1;tt<=T;tt++){
            int N = reader.nextInt();                 // Number of rows
            int M = reader.nextInt();                 // Number of Column
            int K = reader.nextInt();                 // Number of blocks
            String [] full_str_array = new String[10];
            String full_str = "";
            String row = "";

            // reader.skip("[\r\n]+"); // To flush out the "\n"
            reader.nextLine();
            // Input the pixel matrix
            for(int j = 0;j < K;j++){
                full_str = "";
                for(int i = 0;i < N;i++){
                    row = reader.nextLine();
                    full_str = full_str.concat(row);
                }
                full_str_array[j] = full_str;
                if(j == K - 1) break;
                reader.nextLine();
            }

            // lower bound and upper bound of the answer
            // (answer can be between them only(inclusive))
            double log = Math.log(K);
            int lower_bound = (int)Math.ceil(log);
            int upper_bound = K - 1;

            // initialize array for considering each subset of required size
            int [] arr = new int[105];
            for(int i = 0;i < (N*M);i++){
                arr[i] = i;
            }
            
            // Call printCombination function for each number 
            for(int r = lower_bound;r <= upper_bound;r++){
                int n = N*M;
                object.printCombination(full_str_array, arr, n, r, K);
            }
            reader.nextLine();
        }    
    }
}
