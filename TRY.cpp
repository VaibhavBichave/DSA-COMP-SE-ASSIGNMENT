#include<iostream> 
using namespace std;
 bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
  
    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
  
    return true;
}
int main(){
    int n ;
     int sum = 0;
     cout <<"hello git"<<endl;

for(int i =0;i<5;i++)
{
    cin >>n;
   
    if(isPrime(n))
    {
        cout<< "no is prime \n";
        sum += n;
    }
    

}
cout<< sum;
    
    
    return 0;
}