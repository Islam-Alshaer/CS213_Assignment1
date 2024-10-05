/* student name : Islam Waleed Salah
 * Id: 20230062
 * version: 1.0
 * */
#include "iostream"
#include "vector"


//O(nlog(n))
std::vector<bool> SieveOfEratosthenes(int n)
{

    std::vector<bool> isprime(n + 1, true);
    isprime[0] = false;
    isprime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (isprime[p]) {
            for (int i = p * p; i <= n; i += p)
                isprime[i] = false;
        }
    }

    return isprime;

}

int main(void){
    //It can be noticed that input validation could have been done more efficiently than it is,
    //but it has been done using try and catch for educational and practice purposes

    //take input
    std::cout << "Ahlan ya user ya habibi\nEnter a positive number bigger than 2:";
    int n;
    //to ensure user doesn't enter a string
    while(true){
        try{
            std::cin >> n;
            std::cin.exceptions(std::ios::failbit | std::ios::badbit);
            if(n < 2)
                std::cin.setstate(std::ios::badbit);
            else
                break;
        }
        catch (const std::ios_base::failure& e){
            std::cin.ignore(100,'\n');
            std::cin.clear();
            std::cout << "invalid input!" << std::endl << "Try again:";
        }
    }


    //proccessing
    std::vector<bool> isprime = SieveOfEratosthenes(n+1);
    for (int i = 2; i <= n; ++i) {
        if(isprime[i])
            std::cout << i << ' ';
    }

}


/*
 test cases:
 1-15
 2-1024
 3-7
 4-hi
 5- '-5'
 6- 0
 7- 1
 8- 2
 */