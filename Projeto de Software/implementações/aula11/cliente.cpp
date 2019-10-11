#include <iostream>
#include "pessoa.cpp"

using namespace std;


class cliente : public pessoa{
    private:
        string tipoCliente;
    public:
        string gettipoCliente(){
            return this->tipoCliente;

        }
        void settipoCliente(string tipoCliente) {
            this->tipoCliente = tipoCliente;
        }

}