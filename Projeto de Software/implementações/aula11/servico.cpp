#include <iostream>
using namespace std;

class servico{
    private:
        int codServico;
        string Descricao;
        double Valor;
    public:
        

        int getCodServico() {
        	return this->codServico;
        }
        void setCodServico(int codServico) {
        	this->codServico = codServico;
        }


        string getDescricao() {
        	return this->Descricao;
        }
        void setDescricao(string Descricao) {
        	this->Descricao = Descricao;
        }


        double getValor() {
        	return this->Valor;
        }
        void setValor(double Valor) {
        	this->Valor = Valor;
        }



}