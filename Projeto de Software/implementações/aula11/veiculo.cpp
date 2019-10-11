#include <iostream>
using namespace std;

class veiculo{
    private:
        int numPlaca;
        string marca;
        string modelo;
    public:
        int getNumPlaca() {
	        return this->numPlaca;
        }
        void setNumPlaca(int numPlaca) {
	        this->numPlaca = numPlaca;
        }

        string getMarca() {
	        return this->marca;
        }
        void setMarca(string marca) {
	        this->marca = marca;
        }
        string getModelo() {
        	return this->modelo;
        }
        void setModelo(string modelo) {
        	this->modelo = modelo;
        }
}