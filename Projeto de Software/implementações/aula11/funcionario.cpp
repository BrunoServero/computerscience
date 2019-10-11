#include <iostream>
#include "pessoa.cpp"

using namespace std;


class funcionario : public pessoa{
    private:
        int datadeAdimissao;
        double salario;
        string especialidade;
    public:
        int getdatadeAdmissão(){
            return this->datadeAdimissao;

        }
        void setdatadeAdimissao(string datadeAdmissão) {
            this->datadeAdimissao = datadeAdimissao;
        }

        double getSalario(){
            return this->salario;
        
        }

        void setSalario(double salario) {
            this->salario = salario;
        }

        string getEspecialidade() {
            return this->especialidade;
        }

        void setEspecialidade( string especialidade) {
            this->especialidade = especialidade;
        }
}