#include <iostream>
#include <vector>
using namespace std;

class countDigits
{
    public :
    int count(int n )
    {
        int cnt = 0 ; 
        vector<int>vec ; 

        while(n != 0)
        {
            int res = n % 10 ; 
            vec.push_back(res) ;
            n = n / 10 ;
            cnt++ ; 
        }

        for(int i = 0 ; i < vec.size() ; i++)
        {
            cout << vec[i] << " " ;
        }
        cout << endl ;
        return cnt;
    }
} ; 


int main ()
{
    countDigits obj ; 
    int number ; 
    cout << "Enter a number: " ;
    cin >> number ; 
    int result = obj.count(number) ; 
    cout << "Number of digits: " << result << endl ;
    return 0 ;
}