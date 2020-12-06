#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <windows.h>

typedef struct {
    char nome[100];
    char corrente[10];
    char senha[30];
    char chave[10];
    float valor;
} conta;

int sorteio(){
    char conta[10] = "";
    char aux[10] = "";
    int random, i;
    for (i = 0; i < 4; i++){
        random = rand() % 100 + 1;
        sprintf(aux, "%d", random);
        if (random < 10){
            char aux_teste[4] = "0";
            strcat(aux_teste, aux);
            strcpy(aux, aux_teste);
        }
        strcat(conta, aux);
    }
    conta[9] = '\0';
    random = atoi(conta);
    return random;
}

int localizaConta(conta *ponteiro, char *corrente){
    int i, retorno;
    for(i = 0; i < strlen(ponteiro); i++){
        retorno = strcmp(corrente, ponteiro[i].corrente);
        if (retorno == 0){
            return i;
        }
    }
    return -1;
}

int menu(){
    system("cls");
    int op;

    printf("\n------------------------------");
    printf("\n-------------MENU-------------");
    printf("\n------------------------------");
    printf("\n[1] CRIAR CONTA");
    printf("\n[2] SALDO");
    printf("\n[3] DEPOSITAR");
    printf("\n[4] SAQUE");
    printf("\n[5] CANCELAR CONTA");
    printf("\n[0] SAIR DO PROGRAMA");
    printf("\n------------------------------");
    printf("\nDigite uma das opções: ");
    scanf("%d", &op);
    fflush(stdin);

    return op;
}

void senha(conta *ponteiro, int indice){
    char senha_aux[30];
    int comp;

    while (1){
        printf("\nDigite a sua senha: ");
        scanf("%s", senha_aux);
        fflush(stdin);
        comp = strcmp(senha_aux, ponteiro[indice].senha);
        if (comp == 0){
            break;
        }
        printf("\nSenha inválida!Digite novamente!");
    }
}

int localizaIndice(conta *ponteiro){
    int retorno = -1;
    char aux[10];
    while (retorno == -1){
        printf("\nDigite o número da sua conta: ");
        scanf("%s", aux);
        fflush(stdin);
        retorno = localizaConta(ponteiro, aux);
        if (retorno != -1){
            return retorno;
        }
        printf("\nConta não localizada!\nDigite novamente!\n");
    }
}

void localizaNome(conta *ponteiro, int indice){
    char nome_aux[100];
    int comp;
    while (1){
        printf("\nDigite o nome do cliente: ");
        scanf("%[^\n]", nome_aux);
        fflush(stdin);
        comp = strcasecmp(nome_aux, ponteiro[indice].nome);
        if (comp == 0){
            break;
        }
        printf("\nNome digitado inválido!");
    }
}

void localizaChave(conta *ponteiro, int indice){
    char chave[10];
    int comp;
    while (1){
        printf("\nDigite a chave da sua conta: ");
        scanf("%s", chave);
        fflush(stdin);
        comp = strcasecmp(chave, ponteiro[indice].chave);
        if (comp == 0){
            break;
        }
        printf("\nChave digitada inválida!");
    }
}

void saque(conta *ponteiro, int indice){
    float valor;
    while (1){
        printf("\nSeu saldo atual é de: R$ %.2f\n", ponteiro[indice].valor);
        printf("\nDigite um valor para saque: R$ ");
        scanf("%f", &valor);
        fflush(stdin);
        if (valor <= ponteiro[indice].valor){
            ponteiro[indice].valor = ponteiro[indice].valor - valor;
            printf("\nSaque autorizado, retire o seu dinheiro no valor de: R$ %.2f", valor);
            printf("\nSeu saldo atual é de: R$ %.2f\n", ponteiro[indice].valor);
            break;
        }
        printf("\nValor digitado acima do obtido. Favor digitar algum valor que tenha!\n");
    }
}

void criarConta(conta *usuario, int indice){
    int retorno = 0;
    int sortt;
    char aux[10];
    printf("\nDigite o nome do Usuário: ");
    scanf("%[^\n]", usuario[indice].nome);
    fflush(stdin);

    while (retorno != -1){
        sortt = sorteio();
        sprintf(aux, "%d", sortt);
        retorno = localizaConta(usuario, aux);
        if (retorno == -1){
            break;
        }
    };
    strcpy(usuario[indice].corrente, aux);
    while (1){
        printf("\nA sua conta é: ");
        puts(usuario[indice].corrente);
        fflush(stdin);
        printf("\nJá anotou sua conta? [S] -> ");
        scanf("%s", aux);
        fflush(stdin);
        if(strcasecmp(aux, "S") == 0){
            break;
        }
        printf("Repetindo...");
    }

    printf("\nDigite a sua senha: ");
    scanf("%s", usuario[indice].senha);
    fflush(stdin);

    printf("\nDigite a sua chave: ");
    scanf("%s", usuario[indice].chave);
    fflush(stdin);

    usuario[indice].valor = 0;
    printf("\nUsuario adicionado!\n");
}

void dados(conta *ponteiro, int indice){
    system("cls");
    printf("\n\nNome: ");
    puts(ponteiro[indice].nome);
    printf("Conta Corrente: ");
    puts(ponteiro[indice].corrente);
    printf("Valor na sua conta: R$ %.2f\n", ponteiro[indice].valor);
}

void encerrraConta(conta *usuario, int indice, int total, int total_aux){
    conta usuario_aux[total];
    int i;
    for (i = 0; i < total_aux; i++){
        if (indice < total_aux - 1){
            if (i >= indice){
                strcpy(usuario[i].nome, usuario[i+1].nome);
                strcpy(usuario[i].corrente, usuario[i+1].corrente);
                strcpy(usuario[i].senha, usuario[i+1].senha);
                strcpy(usuario[i].chave, usuario[i+1].chave);
                usuario[i].valor = usuario[i+1].valor;
            }
        }
        else if (indice == total_aux - 1){
            if (i == indice){
                strcpy(usuario[i].nome, "");
                strcpy(usuario[i].corrente, "");
                strcpy(usuario[i].senha, "");
                strcpy(usuario[i].chave, "");
                usuario[i].valor = 0;
            }
        }
    }
    printf("\nConta encerrada com sucesso!");
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int opcao, total, sortt;
    int retorno = 0;
    int indice = 0;
    float valor_aux;
    char encerra[10];
    printf("Número máximo de usuários para o Banco: ");
    scanf("%d", &total);
    fflush(stdin);
    conta usuario[total];
    do{
        opcao = menu();
        switch(opcao){
            case 0:
                system("cls");
                printf("\nObrigado por usar o nosso Programa!\nTenha um ótimo dia!");
                sleep(2);
                break;
            case 1:
                if (total == indice - 1){
                    printf("\nA quantidade de usuarios cadastrados está no número máximo!\nRemova algum usuário para poder adicionar outro!\n");
                    sleep(3);
                    break;
                }
                criarConta(usuario, indice);
                indice++;
                sleep(3);
                break;
            case 2:
                if (indice == 0){
                    printf("\nNenhum usuário cadastrado!Impossível verificar opção!");
                    sleep(3);
                    break;
                }
                retorno = localizaIndice(usuario);
                senha(usuario, retorno);
                printf("\nO seu saldo é de R$ %.2f\n", usuario[retorno].valor);
                sleep(3);
                break;
            case 3:
                if (indice == 0){
                    printf("\nNenhum usuário cadastrado!Impossível verificar opção!");
                    sleep(3);
                    break;
                }
                retorno = localizaIndice(usuario);
                localizaNome(usuario, retorno);
                printf("\nDigite um valor a ser depositado: R$ ");
                scanf("%f", &valor_aux);
                if (valor_aux <= 0){
                    printf("\nValor digitado errado! Tente novamente mais tarde!\n");
                    sleep(3);
                    break;
                }
                fflush(stdin);
                usuario[retorno].valor = usuario[retorno].valor + valor_aux;
                printf("\nValor depositado com sucesso!\n");
                sleep(3);
                break;
            case 4:
                if (indice == 0){
                    printf("\nNenhum usuário cadastrado!Impossível verificar opção!");
                    sleep(3);
                    break;
                }
                retorno = localizaIndice(usuario);
                senha(usuario, retorno);
                localizaChave(usuario, retorno);
                saque(usuario, retorno);
                sleep(3);
                break;
            case 5:
                if (indice == 0){
                    printf("\nNenhum usuário cadastrado!Impossível verificar opção!");
                    sleep(3);
                    break;
                }
                retorno = localizaIndice(usuario);
                senha(usuario, retorno);
                localizaChave(usuario, retorno);
                dados(usuario, retorno);
                while(1){
                    printf("\nDeseja realizar o encerramento de sua conta? [S/N] -> ");
                    fflush(stdin);
                    scanf("%s", encerra);
                    fflush(stdin);
                    if (strcasecmp(encerra, "S") == 0){
                        encerrraConta(usuario, retorno, total, indice);
                        indice--;
                        sleep(3);
                        break;
                    }
                    else if(strcasecmp(encerra, "N") == 0){
                        break;
                    }
                    printf("\nOpção inválida!Digite novamente!\n");
                }
                break;
            default:
                printf("\nOpção inválida! Digite novamente!");
                sleep(2);
                break;
        }

    }while(opcao != 0);

    return 0;
}
