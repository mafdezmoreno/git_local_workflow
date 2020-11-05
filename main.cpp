#include <iostream>
#include <vector>

std::vector<int> imprime_secuencia(int &max){

    std::vector<int> lista;
    for (int i = 0; i<max; i++){
        std::cout<< i << " ";
        lista.push_back(i);
    }
    std::cout<<std::endl;

    return lista;
}

int multiplica_secuencia(std::vector<int> v){

    int producto = 1;
    for(auto it = std::begin(v); it != std::end(v); it++) {
        
        if((*it)!=0){
            producto = producto * (*it); 
        }else{
            std::cout<<"(Saltado: " << *it << ") "<<std::endl;
        }

    }    
    return producto;
}

int main(){

    std::cout<< "\nHola mundo!\n"<<std::endl;

    int maximo;
    std::cout << "Escribe valor maximo de la lista: " << std::endl;
    std::cin >> maximo;

    std::vector<int> lista = imprime_secuencia(maximo);

    std::cout<<"El producto de la secuencia es: "
             << multiplica_secuencia(lista)<<std::endl;

    std::cout<< "\nprograma finalizado correctamente\n"<<std::endl;
    
    return 0;
}