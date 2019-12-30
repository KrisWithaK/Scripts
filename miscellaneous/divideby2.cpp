#include<iostream>



int divideby10(int* n){
    int r = *n % 10;
    *n /= 10;
    return r;
    }


void divideby2(int* numer){
    
    static int count = 0;

    int r = divideby10(numer);
    if(*numer == 0){
        if(r % 2 == 1){
            *numer += r/2;
            *numer *= 10;
            *numer += 5;
        }
        else{
            *numer += r/2;
            *numer *= 10;
        }
        return;
    }
    count++;
    divideby2(numer);
    count--;

    if(r % 2 == 1){
        *numer += r/2;
        *numer *= 10;
        *numer += 5;
    }
    else{
        *numer += r/2;
        *numer *= 10;
    }
    
    if(count == 0){
        *numer /= 10;
    }
}




int main(){
    int test0 = 16;
    int test1 = 143;
    int test2 = 20;
    int test3 = 73823;

    std::cout << test0 <<std::endl;
    divideby2(&test0);
    std::cout << test0 <<std::endl << std::endl;

    std::cout << test1 <<std::endl;
    divideby2(&test1);
    std::cout << test1 <<std::endl << std::endl;

    std::cout << test2 <<std::endl;
    divideby2(&test2);
    std::cout << test2 <<std::endl << std::endl;

    std::cout << test3 <<std::endl;
    divideby2(&test3);
    std::cout << test3 <<std::endl << std::endl;
}

