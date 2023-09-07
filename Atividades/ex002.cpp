#include <iostream>
#include <vector>

using namespace std;

class Funcionario
{
private:
    string nome, dataAdmissao;
    float salario;

public:
    string getNome();
    void setNome(string other);
    float getSalario();
    void setSalario(float other);
    string getDataAdmissao();
    void setDataAdmissao(string other);
    
    Funcionario(string nomeF, float salarioF, string dataAdmissaoF) {
    nome = nomeF;
    salario = salarioF;
    dataAdmissao = dataAdmissaoF;
    }

};
    string Funcionario::getNome() {
        return nome;
    }
    void Funcionario::setNome(string other) {
        nome = other;
    }
    float Funcionario::getSalario() {
        return salario;
    }
    void Funcionario::setSalario(float other) {
        salario = other;
    }
    string Funcionario::getDataAdmissao() {
        return dataAdmissao;
    }
    void Funcionario::setDataAdmissao(string other) {
        dataAdmissao=other;
    }

class Empresa {
    private:
    string nome, cnpj;
    vector<Funcionario> funcionarios;

    public:
    string getNome();
    void setNome (string NovoNomeEmpresa);
    string getCnpj();

    Empresa(string nomeEmpresa, string cnpjEmpresa) {
        nome = nomeEmpresa;
        cnpj = cnpjEmpresa;
    }

    void adicionarFuncionario(Funcionario funcionario) {
        funcionarios.push_back(funcionario);
    }

    void exibirFuncionarios() {
    cout << "Funcinarios da empresa: " << getNome();
    for(auto& funcionario : funcionarios) {
        
    }

};
    string Empresa::getNome() {
        return nome;
    }
    void Empresa::setNome(string NovoNomeEmpresa) {
        nome = NovoNomeEmpresa;
    }
    string Empresa::getCnpj() {
        return cnpj;
    }


int main() {

    Funcionario f1("Henrique", 1.200, "15/12/2002");
    cout << "\nFuncionario: " << endl;
    cout << "\nNome: " << f1.getNome();
    cout << "\nSalario: " << f1.getSalario();
    cout << "\nData de Admissao: " << f1.getDataAdmissao();

    Empresa rjfrutas("RjFrutas", "00000000/1111");
    rjfrutas.adicionarFuncionario(f1);
    cout <<"\n\n";
    cout << "Empresa: " << endl;
    cout <<"\nNome da empresa: " << rjfrutas.getNome();
    cout <<"\nCNPJ: " << rjfrutas.getCnpj();
    
    return 0;
}