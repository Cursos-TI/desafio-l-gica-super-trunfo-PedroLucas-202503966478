#include <stdio.h>

typedef struct Carta {
    char estado;                   // Nome do estado
    char codigo[4];                // Código
    char nome[129];                // Nome da cidade
    unsigned long int populacao;   // População da cidade
    double area;                   // Área em km²
    double pib;                    // PIB em bilhões de reais
    int pontos_turisticos;         // Número de pontos turísticos
    double dens_pop;               // Densidade populacional
    double pib_pc;                 // PIB per capita
    double poder;                  // Super poder
} Carta;

// Solicita os dados e retorna uma carta
Carta solicitarDados() {
    Carta carta;

    printf("Insira os dados da carta:\n"); // Exibe o texto no terminal
    printf("Estado: ");
    scanf("%c", &carta.estado);     // Lê a entrada do usuário
    getchar();                      // Limpa o buffer do teclado
    printf("Codigo: ");
    scanf("%s", &carta.codigo);
    getchar();
    printf("Nome da Cidade: ");
    scanf("%[^\n]", &carta.nome);
    getchar();
    printf("Populacao: ");
    scanf("%lu", &carta.populacao);
    getchar();
    printf("Area: ");
    scanf("%lf", &carta.area);
    getchar();
    printf("PIB (bilhoes): ");
    scanf("%lf", &carta.pib);
    getchar();
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta.pontos_turisticos);
    getchar();

    // Calcula a densidade populacional
    carta.dens_pop = (double)carta.populacao / carta.area;
    printf("Densidade Populacional: %.2f\n", carta.dens_pop);

    // Calcula o PIB per capita
    carta.pib_pc = carta.pib * 1000000000 / (double)carta.populacao;
    printf("PIB per Capita: %.2f reais\n", carta.pib_pc);

    // Calcula o Super Poder
    carta.poder = (double)carta.populacao + carta.area + carta.pib + (double)carta.pontos_turisticos + 1/carta.dens_pop + carta.pib_pc;
    printf("Super Poder: %.2f\n", carta.poder);

    return carta;
}

// Exibe os dados de uma carta formatados
void exibirCarta(Carta carta) {
    printf(
        "Nome do estado: %c\n"
        "Codigo: %s\n"
        "Nome da cidade: %s\n"
        "Populacao da cidade: %lu\n"
        "Area em km2: %lf\n"
        "PIB em bilhoes de reais: %lf\n"
        "Numero de pontos turisticos: %d\n"
        "Densidade populacional: %lf\n"
        "PIB per capita: %lf\n"
        "Super poder: %lf\n",
        carta.estado, carta.codigo, carta.nome, carta.populacao,
        carta.area, carta.pib, carta.pontos_turisticos,
        carta.dens_pop, carta.pib_pc, carta.poder
    );
}

void compararCartas (Carta carta1, Carta carta2, int campo) {
    switch (campo) {
        case 1: // Compara Populacao
            if (carta2.populacao == carta1.populacao) {
                printf("Populacao: Empate\n");
            } else {
                printf("Populacao: Carta %d venceu (%d)\n",
                    (carta2.populacao > carta1.populacao)+1, carta1.populacao >= carta2.populacao);
            }
        break;
        case 2: // Compara Area
            if (carta2.area == carta1.area) {
                printf("Area: Empate\n");
            } else {
                printf("Area: Carta %d venceu (%d)\n",
                    (carta2.area > carta1.area)+1, carta1.area >= carta2.area);
            }
        break;
        case 3: // Compara PIB
            if (carta2.pib == carta1.pib) {
                printf("PIB: Empate\n");
            } else {
                printf("PIB: Carta %d venceu (%d)\n",
                    (carta2.pib > carta1.pib)+1, carta1.pib >= carta2.pib);
            }
        break;
        case 4: // Compara Numero de Pontos Turisticos
            if (carta2.pontos_turisticos == carta1.pontos_turisticos) {
                printf("Numero de Pontos Turisticos: Empate\n");
            } else {
                printf("Numero de Pontos Turisticos: Carta %d venceu (%d)\n",
                    (carta2.pontos_turisticos > carta1.pontos_turisticos)+1, carta1.pontos_turisticos >= carta2.pontos_turisticos);
            }
        break;
        case 5: // Compara Densidade Populacional
            if (carta2.dens_pop == carta1.dens_pop) {
                printf("Densidade Populacional: Empate\n");
            } else {
                printf("Densidade Populacional: Carta %d venceu (%d)\n",
                    (carta2.dens_pop < carta1.dens_pop)+1, carta1.dens_pop <= carta2.dens_pop);
            }
        break;
        case 6: // Compara PIB per Capita
            if (carta2.pib_pc == carta1.pib_pc) {
                printf("PIB per Capita: Empate\n");
            } else {
                printf("PIB per Capita: Carta %d venceu (%d)\n",
                    (carta2.pib_pc > carta1.pib_pc)+1, carta1.pib_pc >= carta2.pib_pc);
            }
        break;
        case 7: // Compara Super Poder
            if (carta2.poder == carta1.poder) {
                printf("Super Poder: Empate\n");
            } else {
                printf("Super Poder: Carta %d venceu (%d)\n",
                    (carta2.poder > carta1.poder)+1, carta1.poder >= carta2.poder);
            }
        break;
    }
}

int main() {
    Carta carta1 = solicitarDados(); // Cria uma carta
    printf("\n");

    Carta carta2 = solicitarDados(); // Cria uma carta
    printf("\n");

    printf("Carta 1:\n");
    exibirCarta(carta1); // Exibe as cartas criadas
    printf("\n");

    printf("Carta 2:\n");
    exibirCarta(carta2); // Exibe as cartas criadas
    printf("\n");

    // Exibe o menu de comparacoes
    printf("########## Selicione 2 opcoes para comparar ou sair ##########\n\n");
    printf(
        "[1] Populacao da cidade\n"
        "[2] Area em km2\n"
        "[3] PIB em bilhoes de reais\n"
        "[4] Numero de pontos turisticos\n"
        "[5] Densidade populacional\n"
        "[6] PIB per capita\n"
        "[7] Super poder\n"
        "[8] Sair\n\n"
    );

    int opt1 = 0;
    int opt2 = 0;

    // Solicita as opcoes ate que as duas sejam validas
    while (1) {
        printf("Opcao 1: ");
        scanf("%d", &opt1);
        getchar();
        if (opt1 == 8) {
            break;
        }

        printf("Opcao 2: ");
        scanf("%d", &opt2);
        getchar();
        if (opt2 == 8) {
            break;
        }

        if (opt1 < 0 || opt1 > 7 || opt2 < 0 || opt2 > 7) {
            printf("\nEscolha apenas opcoes validas\n\n");
        } else if (opt1 == opt2) {
            printf("\nAs opcoes nao podem ser iguais\n\n");
        } else {
            break;
        }
    }

    // Encerra o programa caso a opcao 'Sair' seja selecionada
    if (opt1 == 8 || opt2 == 8) {
        return 0;
    }

    // Exibe a comparacao das opcoes selecionadas
    printf("\nComparacao das cartas:\n\n");
    compararCartas(carta1, carta2, opt1);
    compararCartas(carta1, carta2, opt2);

    // Agarda o ENTER para finalizar a exexução
    char buff;
    printf("\n\nPessione enter para sair...");
    scanf("%c", buff);
    getchar();

    return 0;
}
