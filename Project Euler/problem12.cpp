
#include <iostream>
#include <math.h>
#include <string>



int main(){


    int triangleNum = 0;
    int count = 0;
    int numDivisors = 0;

    while(numDivisors < 500){

        count++;
        triangleNum += count;
        numDivisors = 0;

        for(int i = 1; i < int(sqrt(triangleNum)); i++){
            if(int(triangleNum) % i == 0){
                numDivisors += 2;
            }
        }

    }

    std::cout << std::to_string(triangleNum) << std::endl;

}