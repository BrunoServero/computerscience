#include <iostream>
using namespace std;

class ordemServico{
    private:
        long int numOs;
        int dataExp;
        int dataConclusao;

    public:
        long int getnumOs() {
        	return this->numOs;
        }
        void setnumOs(long int numOs) {
	        this->numOs = numOs;
        }

        int getDataExp() {
        	return this->dataExp;
        }
        void setDataExp(int dataExp) {
	        this->dataExp = dataExp;
        }

        int getdataConclusao() {
        	return this->dataConclusao;
        }
        void setdataConclusao(int dataConclusao) {
        	this->dataConclusao = dataConclusao;
        }        

}