class Solution {
public:

   bool checkequal( int a[26] , int b[26])
   {
       for(int i = 0; i<26 ; i++)
       {
           if(a[i] != b[i])
           {
               return 0;
           }
       }
           return 1;
   }
    bool checkInclusion(string s1, string s2) {

        int arr1[26] = {0};
        

        for(int i = 0 ; i < s1.length() ; i++)
        {
            int index ;
         
            index = s1[i] - 'a' ;
             arr1[index]++;
        }

       

        int windowsize = s1.length();
        int i = 0;
        int arr2[26] = {0};

        while(i<windowsize  && i < s2.length())
        {
            int index ;
            index = s2[i] - 'a';
            arr2[index]++;
            i++;
        }

        if(checkequal(arr1 , arr2))
        {
            return 1;
        }

        while( i < s2.length()) {
             
             int index;
             char newchar = s2[i];
             index = newchar - 'a';
             arr2[index]++;
             

             char oldchar = s2[i - windowsize];
             index = oldchar - 'a';
             arr2[index]--;

             if(checkequal(arr1 , arr2))
             {
                 return 1;
             }

            i++;

        }

         return 0;
    }

   
};