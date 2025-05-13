#include <stdio.h>
#include <string.h>                                    // Necessário para usar o fgets (para ler strings com espaços)

int main()
{
    // Definir as variáveis
    char estado1[3], estado2[3] = {'\0'};
    char codigoCarta1[50] = {'\0'};                    // {'\0'} serve para inicializar a string com um valor nulo (Quando estiver retornando 0 no valor)
    char codigoCarta2[50] = {'\0'};                    // {'\0'} serve para inicializar a string com um valor nulo (Quando estiver retornando 0 no valor)
    char nomeCidade1[50], nomeCidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int numPontosTuristicos1, numPontosTuristicos2;
    float densidadePop1, densidadePop2;
    float pibPer1, pibPer2;
    float superPoder1, superPoder2;

    // Solicitar a entrada de dados da Carta 1
    printf("Carta 1\n");
    printf("Estado: %s", estado1);
    scanf("%s", &estado1);                           // O espaço antes do %c é para ignorar o caractere de nova linha que pode ter sido deixado no buffer de entrada

    printf("Código da carta: %s", codigoCarta1);
    scanf("%s", codigoCarta1); 

    printf("Nome da cidade: %s", nomeCidade1);        // scanf(" %s", nomeCidade); Não funciona corretamente para nomes com espaços
    getchar();                                        // Solução para limpar o buffer de entrada para evitar problemas com fgets
    fgets(nomeCidade1, sizeof(nomeCidade1), stdin);   // Usar o fgets para conseguir ler o nome da cidade corretamente, incluindo espaços

    printf("População: ");                            // Sem usar a variavel populacao(1,2), pois retornava um valor inicial "0"
    scanf("%lu", &populacao1);

    printf("Área (em km²): ");                         // Sem usar a variavel area(1,2), pois retornava um valor inicial "0"
    scanf("%f", &area1);

    
    printf("PIB (em bilhões de R$): ");                // Sem usar a variavel pib(1,2), pois retornava um valor inicial "0"
    scanf("%f", &pib1);

    printf("Número de pontos turísticos: ");
    scanf("%d", &numPontosTuristicos1);

    densidadePop1 = populacao1 / area1;
    printf("Densidade Populacional (hab/km²): %.2f\n", densidadePop1);
    

    pibPer1 = pib1 * 1000000000 / populacao1;   //Linha feita pra alterar o valor de entrada xxx.xx para bilhões, sendo possível dividi-lo pela população
    printf("PIB per Capita(R$): %.2f\n", pibPer1);

    superPoder1 = populacao1 + area1 + pib1 + (float)numPontosTuristicos1 + pibPer1 + (1 / densidadePop1); // (1 / densidadepop2) é uma linha para conseguir o inverso da densidade
    printf("O Super poder de %s é de: %.2f", nomeCidade1, superPoder1);
    
    

    // Comando para pular linha com o intuito de separar as cartas
    printf("\n\n");                                   

    // Solicitar a entrada de dados da Carta 2
    printf("Carta 2\n");
    printf("Estado: %s", estado2);
    scanf(" %s", &estado2);                           

    printf("Código da carta: %s", codigoCarta2);
    scanf(" %s", &codigoCarta2); 

    printf("Nome da cidade: %s", nomeCidade2);        
    getchar();                                        
    fgets(nomeCidade2, sizeof(nomeCidade2), stdin);   

    printf("População: ");                            
    scanf("%lu", &populacao2);

    printf("Área (em km²): ");                         
    scanf("%f", &area2);

    printf("PIB (em bilhões de R$): ");                
    scanf("%f", &pib2);

    printf("Número de pontos turísticos: ");
    scanf("%d", &numPontosTuristicos2);

    densidadePop2 = populacao2 / area2;
    printf("Densidade Populacional (hab/km²): %.2f\n", densidadePop2);

    pibPer2 = pib2 * 1000000000 / populacao2;
    printf("PIB per Capita(R$): %.2f\n", pibPer2);

    superPoder2 = populacao2 + area2 + pib2 + (float)numPontosTuristicos2 + pibPer2 + (1 / densidadePop2); // (1 / densidadepop2) é uma linha para conseguir o inverso da densidade
    printf("O Super poder de %s é de: %.2f", nomeCidade2, superPoder2);


    /*Criar comparação das cartas (exceto estado, código e nome)

    Utilizando operador ternário para melhorar a exibição de qual carta venceu (forma compacta de escrever um if...else)
    
    Sintaxe geral: 
    condição ? valor_se_verdadeiro : valor_se_falso;

    Exemplo:
    (populacao1 > populacao2 ? 1 : 2):
    Se a população da carta 1 for maior, retorna 1 (Carta 1 venceu).

    Caso contrário, retorna 2 (Carta 2 venceu).
    (populacao1 > populacao2):
    Retorna 1 se verdadeiro, 0 se falso (usado para exibir o valor da comparação).

    */
    
    printf("\n *** Comparação das cartas ***\n\n");
    printf("População: Carta %d venceu (%d)\n", (populacao1 > populacao2 ? 1 : 2),(populacao1 > populacao2));
    printf("Área: Carta %d venceu (%d)\n", (area1 > area2 ? 1 : 2), (area1 > area2));
    printf("PIB: Carta %d venceu (%d)\n",(pib1 > pib2 ? 1 : 2), (pib1 > pib2));
    printf("Pontos turísticos: Carta %d venceu (%d)\n",(numPontosTuristicos1 > numPontosTuristicos2 ? 1 : 2), (numPontosTuristicos1 > numPontosTuristicos2));
    printf("Densidade Populacional: Carta %d venceu (%d)\n",(densidadePop1 < densidadePop2 ? 1 : 2), (densidadePop1 < densidadePop2));
    printf("PIB per Capita: Carta %d venceu (%d)\n",(pibPer1 > pibPer2 ? 1 : 2), (pibPer1 > pibPer2));
    printf("Super Poder: Carta %d venceu (%d)\n",(superPoder1 > superPoder2 ? 1 : 2), (superPoder1 > superPoder2));
    
    

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    printf("*** Comparação de cartas ***\n");
    printf("*** Atributo: População ***\n");
    printf("Carta 1 - %s %s: %d\n", nomeCidade1, estado1, populacao1);
    printf("Carta 2 - %s %s: %d\n", nomeCidade2, estado2, populacao2);

    if (populacao1 > populacao2)
    {
        printf("Resultado: Carta 1 %s (%s) venceu!\n", nomeCidade1, estado1);
    }
    else
    {
        printf("Resultado: Carta 2 %s (%s) venceu!\n", nomeCidade2, estado2);
    }
    


    return 0;
}