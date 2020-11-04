#include <iostream>

int imprime_secuencia(){

    int sum = 0;
    for (int i = 0; i<10; i++){
        std::cout<< i << " ";
        sum = sum + i;
    }
    std::cout<<std::endl;

    return sum;
}

int main(){

    std::cout << "\nHola mundo!\n"<<std::endl;

    std::cout   << "La suma de la secuencia: " << std::endl;
    int temp = imprime_secuencia();
    std::cout << "es: "<< temp <<std::endl;

    std::cout << "\nprograma finalizado correctamente\n" <<std::endl;
    
    return 0;
}