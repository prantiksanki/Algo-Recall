// longest unique substring without repeating characters

// abcabcd


#include<iostream>
#include<map>
#include<string>
using namespace std ;

// BRUIT FORCE APPROACH
int longest_unique_substring(string s , int n)
{

    int maxLen = 0 ;
    
    for(int i = 0 ; i< n ; i++)
    {
        map<char,int> m ;
        for(int j = i ; j< n ; j++)
        {
            if(m[s[j]] == 1)
            {
                break ; 
            }
            
            int len = j - i + 1 ;

            m[s[j]] = 1 ;
            maxLen = max(maxLen, len) ;

        }
    }

    return maxLen ;

}

// TWO POINTERS APPROACH

int longest_unique_substring_two_pointers(string s, int n)
{
    
    int maxLen  = 0 ; 
    int l = 0 ; 
    int r = 0  ;
    map<char,int> m ;

    while(r < n-1)
    {
        
        m[s[r]]++ ; 
        while(m[s[r]] > 1)
        {
            m[s[l]]-- ;
            l++ ;
        }
        maxLen = max(maxLen, r - l + 1) ;
        r++ ;
    }

    return maxLen;
}

int main()
{
    string s = "abcdeffacbgh";
    int n = s.length() ;
    int result = longest_unique_substring(s, n);
    cout << "Length of the longest substring without repeating characters: " << result << endl;


    int result1 = longest_unique_substring_two_pointers(s, n);
    cout << "Length of the longest substring without repeating characters: " << result1 << endl;
}