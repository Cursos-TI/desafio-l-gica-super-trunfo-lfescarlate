#include <stdio.h>
#include <string.h>                                    // Necessário para usar o fgets (para ler strings com espaços)

int main(){
    // Definir as variáveis
    char estado1[3] = "", estado2[3] = "";
    char codigoCarta1[50] = {'\0'};                    // {'\0'} serve para inicializar a string com um valor nulo (Quando estiver retornando 0 no valor)
    char codigoCarta2[50] = {'\0'};                    // {'\0'} serve para inicializar a string com um valor nulo (Quando estiver retornando 0 no valor)
    char nomeCidade1[50], nomeCidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int numPontosTuristicos1, numPontosTuristicos2, escolhaJogador;
    float densidadePop1, densidadePop2;
    float pibPer1, pibPer2;
    float superPoder1, superPoder2;

    // Solicitar a entrada de dados da Carta 1
    printf("Carta 1\n");
    printf("Estado: %s", estado1);
    scanf("%s", estado1);                           // O espaço antes do %c é para ignorar o caractere de nova linha que pode ter sido deixado no buffer de entrada

    printf("Código da carta: %s", codigoCarta1);
    scanf("%s", codigoCarta1); 

    printf("Nome da cidade: %s", nomeCidade1);        // scanf(" %s", nomeCidade); Não funciona corretamente para nomes com espaços
    getchar();                                        // Solução para limpar o buffer de entrada para evitar problemas com fgets
    fgets(nomeCidade1, sizeof(nomeCidade1), stdin);
    nomeCidade1[strcspn(nomeCidade1, "\n")] = '\0';   // Usar o fgets para conseguir ler o nome da cidade corretamente, incluindo espaços

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
    printf("Super Poder: %.2f\n", superPoder1);
    
    

    // Comando para pular linha com o intuito de separar as cartas
    printf("\n\n");                                   

    // Solicitar a entrada de dados da Carta 2
    printf("Carta 2\n");
    printf("Estado: %s", estado2);
    scanf(" %s", estado2);                           

    printf("Código da carta: %s", codigoCarta2);
    scanf(" %s", codigoCarta2); 

    printf("Nome da cidade: %s", nomeCidade2);        
    getchar();                                        
    fgets(nomeCidade2, sizeof(nomeCidade2), stdin); 
    nomeCidade2[strcspn(nomeCidade2, "\n")] = '\0';

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
    printf("O Super Poder: %.2f\n", superPoder2);

    //Menu Interativo (Escolha um atributo para comaparar)

    printf(" *** Escolha um atributo para comparar *** \n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de pontos turísticos\n");
    printf("5. Densidade demográfica\n");
    scanf("%d", &escolhaJogador);

    switch (escolhaJogador){
    case 1:
        if (populacao1 > populacao2){
            printf("%s : %d  --- %s : %d\n", nomeCidade1, populacao1, nomeCidade2, populacao2);
            printf("A cidade %s venceu!\n", nomeCidade1);
        } else if (populacao2 > populacao1){
            printf("%s : %d  --- %s : %d\n", nomeCidade1, populacao1, nomeCidade2, populacao2);
            printf("A cidade %s venceu!\n", nomeCidade2);
        } else {
            printf("%s : %d  --- %s : %d\n", nomeCidade1, populacao1, nomeCidade2, populacao2);
            printf("Empate!\n");
        }    
        break;
    case 2:
        if (area1 > area2){
            printf("%s : %.2f  --- %s : %.2f\n", nomeCidade1, area1, nomeCidade2, area2);
            printf("A cidade %s venceu!\n", nomeCidade1);
        } else if (area2 > area1){
            printf("%s : %.2f  --- %s : %.2f\n", nomeCidade1, area1, nomeCidade2, area2);
            printf("A cidade %s venceu!\n", nomeCidade2);
        } else {
            printf("%s : %.2f  --- %s : %.2f\n", nomeCidade1, area1, nomeCidade2, area2);
            printf("Empate!\n");
        }    
        break;
    case 3:
        if (pib1 > pib2){
            printf("%s : %.2f  --- %s : %.2f\n", nomeCidade1, pib1, nomeCidade2, pib2);
            printf("A cidade %s venceu!\n", nomeCidade1);
        } else if (pib2 > pib1){
            printf("%s : %.2f  --- %s : %.2f\n", nomeCidade1, pib1, nomeCidade2, pib2);
            printf("A cidade %s venceu!\n", nomeCidade2);
        } else {
            printf("%s : %.2f  --- %s : %.2f\n", nomeCidade1, pib1, nomeCidade2, pib2);
            printf("Empate!\n");
        }    
        break;
    case 4:
        if (numPontosTuristicos1 > numPontosTuristicos2){
            printf("%s : %d  --- %s : %d\n", nomeCidade1, numPontosTuristicos1, nomeCidade2, numPontosTuristicos2);
            printf("A cidade %s venceu!\n", nomeCidade1);
        } else if (numPontosTuristicos2 > numPontosTuristicos1){
            printf("%s : %d  --- %s : %d", nomeCidade1, numPontosTuristicos1, nomeCidade2, numPontosTuristicos2);
            printf("A cidade %s venceu!\n", nomeCidade2);
        } else {
            printf("%s : %d  --- %s : %d\n", nomeCidade1, numPontosTuristicos1, nomeCidade2, numPontosTuristicos2);
            printf("Empate!\n");
        }    
        break;
    case 5:
        if (densidadePop1 < densidadePop2){
            printf("%s : %.2f  --- %s : %.2f\n", nomeCidade1, densidadePop1, nomeCidade2, densidadePop2);
            printf("A cidade %s venceu!\n", nomeCidade1);
        } else if (densidadePop2 < densidadePop1){
            printf("%s : %.2f  --- %s : %.2f\n", nomeCidade1, densidadePop1, nomeCidade2, densidadePop2);
            printf("A cidade %s venceu!\n", nomeCidade2);
        } else {
            printf("%s : %.2f  --- %s : %.2f\n", nomeCidade1, densidadePop1, nomeCidade2, densidadePop2);
            printf("Empate!\n");
        }    
        break;
    default:
        printf("Entrada inválida!");
        break;
    }

    return 0;
}