#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    double custoTotal;
    double custoPorPessoa;
} CustoTotal;

CustoTotal calcularCustoTotal(
    int duracao,
    int numPessoas,
    double custoTransporte,
    double custoHospedagem,
    double custoAlimentacao,
    double custoAtividades,
    char* seguro,
    double despesasExtras,
    double desconto
) {
    CustoTotal resultado;

    double custoHospedagemTotal = custoHospedagem * duracao;
    double custoAlimentacaoTotal = custoAlimentacao * numPessoas * duracao;
    double custoTransporteTotal = custoTransporte * numPessoas;
    double custoTotal =
        custoHospedagemTotal +
        custoAlimentacaoTotal +
        custoTransporteTotal +
        custoAtividades +
        despesasExtras;

    if (strcmp(seguro, "Sim") == 0) {
        custoTotal += 100;
    }

    custoTotal -= custoTotal * (desconto / 100);

    resultado.custoTotal = custoTotal;
    resultado.custoPorPessoa = custoTotal / numPessoas;

    return resultado;
}

void gerarSugestoesEconomia(
    double custoTotal,
    int numPessoas,
    double custoTransporte,
    double custoHospedagem,
    double custoAlimentacao
) {
    if (custoTransporte < 500) {// muta��o 2
        printf("Considere usar transporte p�blico ou caronas para economizar.\n");
    }
    if (custoHospedagem > 200) {
        printf("Verifique op��es de hospedagem mais baratas, como hostels ou Airbnb.\n");
    }
    if (custoAlimentacao > 100) {
        printf("Tente fazer algumas refei��es em casa ou escolha restaurantes mais econ�micos.\n");
    }
}

void calcularViagem(
    char* destino,
    int duracao,
    int numPessoas,
    double custoTransporte,
    double custoHospedagem,
    double custoAlimentacao,
    double custoAtividades,
    char* seguro,
    double despesasExtras,
    double desconto
) {
    CustoTotal custos = calcularCustoTotal(
        duracao,
        numPessoas,
        custoTransporte,
        custoHospedagem,
        custoAlimentacao,
        custoAtividades,
        seguro,
        despesasExtras,
        desconto
    );

    printf("Destino: %s\n", destino);
    printf("Custo Total: %.2f\n", custos.custoTotal);
    printf("Custo Por Pessoa: %.2f\n", custos.custoPorPessoa);
    gerarSugestoesEconomia(custos.custoTotal, numPessoas, custoTransporte, custoHospedagem, custoAlimentacao);
}

int main() {
    // Exemplo de uso
    calcularViagem(
        "Praia", // destino
        7, // dura��o
        4, // n�mero de pessoas
        300, // custo de transporte por pessoa
        150, // custo de hospedagem por dia
        50, // custo di�rio com alimenta��o
        200, // custo de atividades por dia
        "Sim", // seguro
        100, // despesas extras
        10 // desconto percentual
    );

    return 0;
}
