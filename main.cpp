#include <iostream>

void imprime_secuencia(){

    for (int i = 0; i<10; i++)
        std::cout<< i << " ";
    std::cout<<std::endl;
}

int main(){

    std::cout<< "\nHola mundo!\n"<<std::endl;

    imprime_secuencia();

    std::cout<< "\nprograma finalizado correctamente\n"<<std::endl;
    
    return 0;
}