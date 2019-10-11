#include <iostream>
using namespace std;

class pessoa{
    private:
    long int codigo;
    string nome;
    string cpf;
    string rg;
    string telefone;

    public:
    long int getCodigo() {
    	return this->codigo;
    }
    void setCodigo(long int codigo) {
    	this->codigo = codigo;
    }

    string getNome() {
 	    return this->nome;
    }
    void setNome(string nome) {
 	    this->nome = nome;
    }

    string getCpf() {
        return this->cpf;
    }

    void setCpf(string cpf) {
        this->cpf = cpf;
    }

    string getRg() {
    	return this->rg;
    }
    void setRg(string rg) {
    	this->rg = rg;
    }

    string getTelefone(){
        return this->telefone;
    }

    void setTelefone(string telefone) {
        this-> telefone = telefone;
    }
};