#include <stdio.h>
#include <string.h>

float calcINSS(float x) //tabela do INSS - https://www.in.gov.br/en/web/dou/-/portaria-n-914-de-13-de-janeiro-de-2020-237937443
{
    float desc;
    if (x <= 1830.29)
    {
        desc = (x * 8) / 100;
        printf("\nINSS\t\t\t\t8%%\t\t\t\t\t\t %.2f", desc);
    }
    else if (x >= 1830.30 && x <= 3050.52)
    {
        desc = (x * 9) / 100;
        printf("\nINSS\t\t\t\t9%%\t\t\t\t\t\t %.2f", desc);
    }
    else if (x >= 3050.53)
    {
        desc = (x * 11) / 100;
        printf("\nINSS\t\t\t\t11%%\t\t\t\t\t\t %.2f", desc);
    }
    return desc;
}
float calcIRPF(float x) //tabela IRPF - https://www.gov.br/receitafederal/pt-br/assuntos/orientacao-tributaria/tributos/irpf-imposto-de-renda-pessoa-fisica
{
    float desc;
    if (x <= 1903.98)
    {
        printf("\nIRPF\t\t\t\t\t\t\t\t\t\t ISENTO");
    }
    else if (x >= 1903.99 && x < 2826.65)
    {
        desc = (x * 7.5) / 100;
        printf("\nIRPF\t\t\t\t7.5%%\t\t\t\t\t\t %.2f", desc);
    }
    else if (x >= 2826.66 && x <= 3751.05)
    {
        desc = (x * 15) / 100;
        printf("\nIRPF\t\t\t\t15%%\t\t\t\t\t\t %.2f", desc);
    }
    else if (x >= 3751.06 && x <= 4664.68)
    {
        desc = (x * 22.5) / 100;
        printf("\nIRPF\t\t\t\t22.5%%\t\t\t\t\t\t %.2f", desc);
    }
    else if (x >= 4664.68)
    {
        desc = (x * 27.5) / 100;
        printf("\nIRPF\t\t\t\t27.5%%\t\t\t\t\t\t %.2f", desc);
    }
    return desc;
}
float FGTS(float x)
{
    float desc;
    desc = x * 8 / 100;
    printf("\nFGTS\t\t\t\t8%%\t\t\t\t\t\t %.2f", desc);
    return desc;
}
int main()
{
    char mes[100], nomeFunc[100], cargoFunc[100];
    float ano, codFunc, salBruto, totalDesconto, valorINSS, valorIRPF, valorFGTS, totalVencimento, salLiquido;
    int faixaIRPF;
    printf("\nSistema de Calculo de Contracheque (v1.0)");
    printf("\n-----------------------------------------");
    printf("\n\nInforme o mes: ");
    scanf("%[^\n]s", &mes);
    setbuf(stdin, NULL);
    printf("Informe o ano: ");
    scanf("%f", &ano);
    if (ano < 2020)
    {
        printf("O ano que voce digitou nao e o vigente. O programa sera fechado.");
        return 0;
    }
    printf("Informe o codigo (4 digitos): ");
    scanf("%f", &codFunc);
    if (codFunc > 9999)
    {
        printf("O registro do funcionario nao existe. O programa sera fechado");
        return 0;
    }
    setbuf(stdin, NULL);
    printf("Informe o cargo: ");
    scanf("%[^\n]s", &cargoFunc);
    setbuf(stdin, NULL);
    printf("Informe o nome: ");
    scanf("%[^\n]s", &nomeFunc);
    setbuf(stdin, NULL);
    printf("Salario: ");
    scanf("%f", &salBruto);
    if (salBruto <= 1903.98)
    {
        faixaIRPF = 0;
    }
    else if (salBruto >= 1903.99 && salBruto < 2826.65)
    {
        faixaIRPF = 1;
    }
    else if (salBruto >= 2826.66 && salBruto <= 3751.05)
    {
        faixaIRPF = 2;
    }
    else if (salBruto >= 3751.06 && salBruto <= 4664.68)
    {
        faixaIRPF = 3;
    }
    else if (salBruto >= 4664.68)
    {
        faixaIRPF = 4;
    }
    system("cls"); //LIMPE A TELA
    printf("\n------------------------------------------------------------------------------------------");
    printf("\nEmpresa: CONEXCOM SOLUCOES DIGITAIS                                                       ");
    printf("\nCNPJ: 37.400.459/0001-16                                                                  ");
    printf("\n------------------------------------------------------------------------------------------");
    printf("\n                              Recibo de Pagamento de Salario                              ");
    printf("\n------------------------------------------------------------------------------------------");
    printf("\nMes: %s / %.0f", mes, ano);
    printf("\nNome do Funcionario: %s\t\tCodigo: %.0f", nomeFunc, codFunc);
    printf("\nCargo: %s", cargoFunc);
    printf("\n------------------------------------------------------------------------------------------");
    printf("\nDESCRICAO\t\t\tREFERENCIA\t\tVENCIMENTOS\t\tDESCONTOS");
    printf("\n\nSALARIO\t\t\t\t\t\t\t %.2f", salBruto);
    totalVencimento = salBruto;
    valorINSS = calcINSS(salBruto);
    valorIRPF = calcIRPF(salBruto);
    valorFGTS = FGTS(totalVencimento);
    totalDesconto = valorINSS + valorIRPF + valorFGTS;
    salLiquido = totalVencimento - totalDesconto;
    printf("\n------------------------------------------------------------------------------------------");
    printf("\n\t\t\t\t\t\t\tTotal de Vencimentos\t %.2f", totalVencimento);
    printf("\n\t\t\t\t\t\t\tTotal de Descontos\t %.2f", totalDesconto);
    printf("\n------------------------------------------------------------------------------------------");
    printf("\n\t\t\t\t\t\t\tValor Liquido\t\t %.2f", salLiquido);
    printf("\n------------------------------------------------------------------------------------------");
    printf("\nSal. Base\tSal. INSS\tBase FGTS\tFGTS Mes\tBase IRRF\tFaixa IRRF");
    printf("\n%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t0%d", salBruto, totalVencimento, totalVencimento, valorFGTS, salLiquido, faixaIRPF);
    printf("\n------------------------------------------------------------------------------------------\n");
    system("pause");
    return 0;
}
