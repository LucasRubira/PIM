#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char nome[30], cpf[20], sexo[30], funcao[30], login[50], senha[30];
    float salario, idade;
}funcionario;

typedef struct {
    char forn[30], nome[30];
    bool lact, lati, glut, acuc, gord, inte, carn, sodi;
    float preco;
}produto;

int menuCol() {
    char opcao;

    printf("=================================\n--------  LASTFOOD MENU  --------\n=================================\n\n");
    printf("[1] SIMULADOR DE VALORES\n\n");
    printf("[2] CADASTRAR PRODUTO \n");
    printf("[3] ALTERAR PRODUTO \n");
    printf("[4] LISTA DE PRODUTOS \n");
    printf("[5] BUSCAR PRODUTO \n");
    printf("[0] SAIR\n");
    printf("\nEscolha uma op��o: ");
    opcao = getche();

    return opcao;
}

void cadastrarProduto(produto *q, int *quantidadeProduto){
    char *novoCadastro, *r;
    int i;
    novoCadastro = malloc(sizeof(char));
    r = malloc(sizeof(char));
    do {
        i = *quantidadeProduto;
        fflush(stdin);
        system("cls");
        printf("======== CADASTRO DE PRODUTOS ========\n");
        printf("\nInforme o fornecedor: ");
        gets((q+i)->forn);
        printf("Informe o nome do produto: ");
        gets((q+i)->nome);
        printf("\n\n======= INFORMA��ES DO PRODUTO =======\n");
        printf("\nProduto possui latic�nios? (s/n)\n");
        fflush(stdin);
        do{
            *r = getche();
            switch(*r){
                case 's': (q+i)->lati=true;
                break;
                case 'n': (q+i)->lati=false;
                break;
                default: printf("\n\nCARACTER INV�LIDO\nPOR FAVOR, DIGITE NOVAMENTE.");
            }
        }while(*r!='s' && *r!='n');
        fflush(stdin);
        printf("\nProduto possui lactose? (s/n)\n");
        fflush(stdin);
        do{
            *r = getche();
            switch(*r){
                case 's': (q+i)->lact=true;
                break;
                case 'n': (q+i)->lact=false;
                break;
                default: printf("\n\nCARACTER INV�LIDO\nPOR FAVOR, DIGITE NOVAMENTE.");
            }
        }while(*r!='s' && *r!='n');
        fflush(stdin);
        printf("\nProduto possui glut�m? (s/n)\n");
        do{
            *r = getche();
            switch(*r){
                case 's': (q+i)->glut=true;
                break;
                case 'n': (q+i)->glut=false;
                break;
                default: printf("\n\nCARACTER INV�LIDO\nPOR FAVOR, DIGITE NOVAMENTE.");
            }
        }while(*r!='s' && *r!='n');
        printf("\nProduto possui a�ucar? (s/n) \n");
        do{
            *r = getche();
            switch(*r){
                case 's': (q+i)->acuc=true;
                break;
                case 'n': (q+i)->acuc=false;
                break;
                default: printf("\n\nCARACTER INV�LIDO\nPOR FAVOR, DIGITE NOVAMENTE.");
            }
        }while(*r!='s' && *r!='n');
        printf("\nProduto possui gordura? (s/n) \n");
        do{
            *r = getche();
            switch(*r){
                case 's': (q+i)->gord=true;
                break;
                case 'n': (q+i)->gord=false;
                break;
                default: printf("\n\nCARACTER INV�LIDO\nPOR FAVOR, DIGITE NOVAMENTE.");
            }
        }while(*r!='s' && *r!='n');
        printf("\nProduto � integral? (s/n) \n");
        do{
            *r = getche();
            switch(*r){
                case 's': (q+i)->inte=true;
                break;
                case 'n': (q+i)->inte=false;
                break;
                default: printf("\n\nCARACTER INV�LIDO\nPOR FAVOR, DIGITE NOVAMENTE.");
            }
        }while(*r!='s' && *r!='n');
        printf("\nProduto possui algum tipo de carne? (s/n) \n");
        do{
            *r = getche();
            switch(*r){
                case 's': (q+i)->carn=true;
                break;
                case 'n': (q+i)->carn=false;
                break;
                default: printf("\n\nCARACTER INV�LIDO\nPOR FAVOR, DIGITE NOVAMENTE.");
            }
        }while(*r!='s' && *r!='n');
        fflush(stdin);
        printf("\nProduto possui alto teor de s�dio? (s/n)\n");
        do{
            *r = getche();
            switch(*r){
                case 's': (q+i)->sodi=true;
                break;
                case 'n': (q+i)->sodi=false;
                break;
                default: printf("\n\nCARACTER INV�LIDO\nPOR FAVOR, DIGITE NOVAMENTE.");
            }
        }while(*r!='s' && *r!='n');

        *quantidadeProduto = *quantidadeProduto + 1;

        printf("\n\n-----------------------------------");
        printf("\n  CADASTRO REALIZADO COM SUCESSO! \a\n");
        printf("-----------------------------------\n");
        printf("\n[1] REALIZAR UM NOVO CADASTRO");
        printf("\n[2] VOLTAR PARA O MENU\n");
        *novoCadastro = getche ();
        while(*novoCadastro!='1' && *novoCadastro!='2'){
            printf("\nOP��O INV�LIDA.\nPOR FAVOR, DIGITE NOVAMENTE: ");
            *novoCadastro = getche();
        }
    } while (*novoCadastro != '2');
    free(novoCadastro);
    free(r);
}

int menuAdm() {
    char opcao;

    printf("=================================\n--------  LASTFOOD MENU  --------\n=================================\n\n");
    printf("[1] CADASTRAR NOVO FUNCION�RIO\n");
    printf("[2] ALTERAR FUNCION�RIO \n");
    printf("[3] LISTA DE FUNCION�RIOS \n");
    printf("[4] BUSCAR FUNCION�RIO \n\n");
    printf("[5] CADASTRAR PRODUTO \n");
    printf("[6] ALTERAR PRODUTO \n");
    printf("[7] LISTA DE PRODUTOS \n");
    printf("[8] BURCAR PRODUTO\n\n");
    printf("[9] SIMULADOR DE VALORES \n\n");
    printf("[0] SAIR\n");
    printf("\nEscolha uma op��o: ");
    opcao = getche();

    return opcao;
}

void cadastrarFuncionarios(funcionario *p, int *quantidadeFuncionario){
    char *novoCadastro;
    int i;
    novoCadastro = malloc(sizeof(char));
    do {
        i = *quantidadeFuncionario;
        fflush(stdin);
        system("cls");
        printf("===== CADASTRO DE FUNCION�RIO =====\n");
        printf("\nInforme o CPF do funcion�rio (sem h�fen): ");
        gets((p+i)->cpf);
        printf("Informe o nome do funcion�rio: ");
        gets((p+i)->nome);
        printf("Informe a idade do funcion�rio: ");
        fflush(stdin);
        scanf("%f", &(p+i)->idade);
        fflush(stdin);
        printf("Informe o sexo do funcion�rio: ");
        gets((p+i)->sexo);
        printf("Informe o cargo do funcion�rio: ");
        gets((p+i)->funcao);
        printf("Informe o sal�rio do funcion�rio: R$ ");
        scanf("%f", &(p+i)->salario);
        fflush(stdin);
        printf("\n----------CRIANDO LOGIN----------\nInforme o login do funcion�rio: ");
        gets((p+i)->login);
        fflush(stdin);
        printf("Informe a senha do funcion�rio: ");
        gets((p+i)->senha);

        *quantidadeFuncionario = *quantidadeFuncionario + 1;

        printf("\n\n-----------------------------------");
        printf("\n  CADASTRO REALIZADO COM SUCESSO! \a\n");
        printf("-----------------------------------\n");
        printf("\n[1] REALIZAR NOVO CADASTRO");
        printf("\n[2] VOLTAR PARA O MENU\n");
        *novoCadastro = getche ();
        while(*novoCadastro!='1' && *novoCadastro!='2'){
            printf("\nOP��O INV�LIDA.\nPOR FAVOR, DIGITE NOVAMENTE: ");
            *novoCadastro = getche();
        }
    } while (*novoCadastro != '2');
    free(novoCadastro);
}

void listarFuncionarios(int *quantidadeFuncionario, funcionario *p) {
    int i;
    system("cls");
    printf("======= LISTA DE FUNCION�RIOS =======\n\n");
    for (i = 0; i < *quantidadeFuncionario; i++) {
        printf("CPF: %s \n", (p+i)->cpf);
        printf("Nome: %s \n", (p+i)->nome);
        fflush(stdin);
        printf("Idade: %.0f \n", (p+i)->idade);
        printf("Sexo: %s \n", (p+i)->sexo);
        printf("Fun��o: %s \n", (p+i)->funcao);
        printf("Sal�rio: R$ %.2f \n", (p+i)->salario);
        printf("Login: %s \n", (p+i)->login);
        printf("Senha: %s \n", (p+i)->senha);
        printf("- - - - - - - - - - - - - - - - - - -\n");
    }
}

void listarProdutos(int *quantidadeProduto, produto *q) {
    int i;
    system("cls");
    printf("======= LISTA DE PRODUTOS =======\n\n");
    for (i = 0; i < *quantidadeProduto; i++) {
        printf("Fornecedor: %s \n", (q+i)->forn);
        printf("Produto: %s \n\n", (q+i)->nome);
        fflush(stdin);
        printf("Lactose: ");
        if((q+i)->lact == true)
            printf("SIM\n");
        else
            printf("N�O\n");
        printf("Latic�nios: ");
        if((q+i)->lati == true)
            printf("SIM\n");
        else
            printf("N�O\n");
        printf("Gl�ten: ");
        if((q+i)->glut == true)
            printf("SIM\n");
        else
            printf("N�O\n");
        printf("A��car: ");
        if((q+i)->acuc == true)
            printf("SIM\n");
        else
            printf("N�O\n");
        printf("Gordura: ");
        if((q+i)->gord == true)
            printf("SIM\n");
        else
            printf("N�O\n");
        printf("Integral: ");
        if((q+i)->inte == true)
            printf("SIM\n");
        else
            printf("N�O\n");
        printf("S�dio: ");
        if((q+i)->sodi == true)
            printf("SIM\n");
        else
            printf("N�O\n");
        printf("- - - - - - - - - - - - - - - - - - -\n");
    }
    printf("\n\n");
    system("pause");
}

void buscarFuncionario(funcionario *p, int *quantidadeFuncionario){
        char c;
        system("cls");
        printf("----------------------------------\n");
        printf("            BUSCAR POR\n");
        printf("----------------------------------\n\n");
        printf("[1] NOME\n[2] CPF\n[3] FUN��O\n\nEscolha uma op��o: ");
        c = getche();
        switch (c){
            case '1':
                procurarNome(quantidadeFuncionario, p);
                system("pause");
                system("cls");
                break;
            case '2':
                procurarCpf(quantidadeFuncionario,p);
                system("pause");
                system("cls");
                break;
            case'3':
                procurarFuncao(quantidadeFuncionario,p);
                system("pause");
                system("cls");
                break;
            default:
                printf("\nESSA OP��O N�O EXISTE! ESCOLHA UMA OP��O V�LIDA \n");
        }
}

void procurarFuncao(int *quantidadeFuncionario,funcionario *p) {
    bool achou = false;
    char funcao[30];
    int i;

    fflush(stdin);
    printf("\nINFORME O CARGO DO FUNCION�RIO: ");
    gets(funcao);
    achou = false;
    for (i = 0; i < *quantidadeFuncionario; i++){
        if (strcmp(funcao, (p+i)->funcao) == 0){
            achou = true;

            printf("\nCPF: %s \n", (p+i)->cpf);
            printf("Nome: %s \n", (p+i)->nome);
            printf("Idade: %.0f \n", (p+i)->idade);
            printf("Sexo: %s \n", (p+i)->sexo);
            printf("Fun��o: %s \n", (p+i)->funcao);
            printf("Sal�rio: R$ %.2f \n\n", (p+i)->salario);
            printf("- - - - - - - - - - - - - - - - - - -\n");
        }
    }
    if (achou == false) {
        printf("\nO CARGO DIGITADO N�O FOI ENCONTRADO! \n\n");
    }
}

void procurarNome(int *quantidadeFuncionario,funcionario *p) {
    bool achou = false;
    char nome[30];
    int i;

    fflush(stdin);
    printf("\nINFORME O NOME COMPLETO DO FUNCION�RIO: ");
    gets(nome);
    achou = false;
    for (i = 0; i < *quantidadeFuncionario; i++){
        if (strcmp(nome, (p+i)->nome) == 0){
            achou = true;

            printf("\nCPF: %s \n", (p+i)->cpf);
            printf("Nome: %s \n", (p+i)->nome);
            printf("Idade: %.0f \n", (p+i)->idade);
            printf("Sexo: %s \n", (p+i)->sexo);
            printf("Fun��o: %s \n", (p+i)->funcao);
            printf("Sal�rio: R$ %.2f \n", (p+i)->salario);
            printf("- - - - - - - - - - - - - - - - - - -\n");
        }
    }
    if (achou == false) {
        printf("\nO NOME DIGITADO N�O FOI ENCONTRADO! \n\n");
    }
}

void procurarCpf(int *quantidadeFuncionario,funcionario *p) {
    bool achou = false;
    char cpf[20];
    int i;

    fflush(stdin);
    printf("\nINFORME O CPF DO FUNCION�RIO (SEM H�FEN): ");
    gets(cpf);
    achou = false;
    for (i = 0; i < *quantidadeFuncionario; i++) {
        if (strcmp(cpf, (p+i)->cpf) == 0) {
            achou = true;

            printf("\nCPF: %s \n", (p+i)->cpf);
            printf("Nome: %s \n", (p+i)->nome);
            printf("Idade: %.0f \n", (p+i)->idade);
            printf("Sexo: %s \n", (p+i)->sexo);
            printf("Fun��o: %s \n", (p+i)->funcao);
            printf("Sal�rio: R$ %.2f \n", (p+i)->salario);
            printf("- - - - - - - - - - - - - - - - - - -\n");
        }
    }
    if (achou == false) {
        printf("O CPF digitado n�o foi encontrado! Digite um CPF v�lido! \n\n");
    }
}

void simulador(){
    float po, pc, pv, comp;
    char *c;
    c=malloc(sizeof(char));
    system("cls");
    do{
        printf("====== SIMULADOR DE PRE�OS ======\n\n");
        printf("Digite o valor do produto: ");
        scanf("%f", &po);
        if(po<3){
            printf("\nVALORES MENORES DO QUE");
            printf("\nR$ 3,00 N�O S�O ACEITOS!!\n");
        }else if(po<=5){
                pc = po*0.15;
                pv = pc+2;
                comp = (1-(pv/po))*100;
                printf("\n\nPRE�O DE COMPRA: R$ %.2f\n", pc);
                printf("\nPRE�O DE VENDA: R$ %.2f\n", pv);
                printf("\nDESCONTO AO CLIENTE: %.2f%%\n", comp);
            }else if(po<=10){
                    pc = po*0.2;
                    pv = pc+3;
                    comp = (1-(pv/po))*100;
                    printf("\n\nPRE�O DE COMPRA: R$ %.2f\n", pc);
                    printf("\nPRE�O DE VENDA: R$ %.2f\n", pv);
                    printf("\nDESCONTO AO CLIENTE: %.2f%%\n", comp);
                }else if(po<=30){
                        pc = po*0.25;
                        pv = pc+4.5;
                        comp = (1-(pv/po))*100;
                        printf("\n\nPRE�O DE COMPRA: R$ %.2f\n", pc);
                        printf("\nPRE�O DE VENDA: R$ %.2f\n", pv);
                        printf("\nDESCONTO AO CLIENTE: %.2f%%\n", comp);
                    }else if(po<=70){
                            pc = po*0.3;
                            pv = pc+6;
                            comp = (1-(pv/po))*100;
                            printf("\n\nPRE�O DE COMPRA: R$ %.2f\n", pc);
                            printf("\nPRE�O DE VENDA: R$ %.2f\n", pv);
                            printf("\nDESCONTO AO CLIENTE: %.2f%%\n", comp);
                        }else if(po<=999999999){
                                pc = po*0.35;
                                pv = pc+7.5;
                                comp = (1-(pv/po))*100;
                                printf("\n\nPRE�O DE COMPRA: R$ %.2f\n", pc);
                                printf("\nPRE�O DE VENDA: R$ %.2f\n", pv);
                                printf("\nDESCONTO AO CLIENTE: %.2f%%\n", comp);
                            }else{
                                printf("\nVALOR INV�LIDO!\n");
                            }
        printf("\n\n[1] FAZER OUTRA SIMULA��O\n[0] SAIR\n");
        *c = getche();
        system("cls");
    }while(*c!='0');
    free(c);
}

void loginCol(funcionario *p, int *quantidadeFuncionario){
    system("cls");
    int i=0;
    bool achou = false;
    char login1[30], senha1[30];
    if (*quantidadeFuncionario == 0) {
        printf("\nNENHUM COLABORADOR CADASTRADO!!\n\n");
        return;
    }
    printf("---------------------------------\n\tLOGIN COLABORADOR\n---------------------------------\n");
    do{
        fflush(stdin);
        printf("\nUSU�RIO: ");
        scanf("%s", &login1);
        printf("SENHA: ");
        scanf("%s", &senha1);
        for(i=0; i<*quantidadeFuncionario; i++){
            if (strcmp((p+i)->login, login1) == 0 && strcmp((p+i)->senha, senha1) == 0){
                achou = true;

                printf("\n---------------------------------\n\tLOGIN CONCLU�DO!\n---------------------------------\n\n");
                printf("\tSEJA BEM VINDO \n\t%s!!\n\n", (p+i)->nome);
                system("pause");
                system("cls");
                return i;
            }
        }
        if(achou == false){
            printf("\nLOGIN INCORRETO.");
            printf("\nPOR FAVOR, TENTE NOVAMENTE: \n");
        }
    }while(strcmp((p+i)->login, login1) != 0 || strcmp((p+i)->senha, senha1) != 0);
}

void loginAdm(){
    system("cls");
    char login[50] = "adm", login1[50], senha[8] = "1234", senha1[8];
    printf("---------------------------------\n       LOGIN ADMINISTRADOR\n---------------------------------\n");
    do{
        fflush(stdin);
        printf("\nUSU�RIO: ");
        scanf("%s", &login1);
        printf("SENHA: ");
        scanf("%s", &senha1);
        if (strcmp(login, login1) != 0 || strcmp(senha, senha1) != 0){
            printf("\nLOGIN INCORRETO.");
            printf("\nPOR FAVOR, TENTE NOVAMENTE: \n");
        }
    }while(strcmp(login, login1) != 0 || strcmp(senha, senha1) != 0);
    printf("\n---------------------------------\n        LOGIN CONCLU�DO!\n---------------------------------\n\n");
    system("pause");
    system("cls");
}

void main(){
    setlocale(LC_ALL, "portuguese");
    char *v;
    int opcao, *quantidadeFuncionario, *quantidadeProduto, novoCadastro;
    funcionario *p;
    produto *q;
    p = malloc(10 * sizeof(funcionario));
    q = malloc(50 * sizeof(produto));
    quantidadeFuncionario = malloc(sizeof(int));
    quantidadeProduto=malloc(sizeof(int));
    v = malloc(sizeof(char));
    *quantidadeFuncionario = 0;
    *quantidadeProduto = 0;
    do{
        printf("================================\n-----  Com.TI.go SISTEMAS  -----\n================================\n\n");
        printf("\n[1] ADMINISTRADOR\n\n[2] COLABORADOR\n\n[0] SAIR\n");
        *v = getche();
        while(*v != '1' && *v != '2' && *v != '0'){
            printf("\n--------------------------------\nOP��O INV�LIDA! \nPOR FAVOR, DIGITE NOVAMENTE: ");
            *v = getche();
        }
        switch (*v){
            case '1':
                loginAdm();
                do{
                    opcao = menuAdm();
                    switch (opcao){
                        case '1':
                            cadastrarFuncionarios(p, quantidadeFuncionario);
                            system("cls");
                            break;
                        case '3':
                            if (*quantidadeFuncionario == 0) {
                                system("cls");
                                printf("-----------------------------------\n");
                                printf("  NENHUM FUNCION�RIO CADASTRADO!!\n");
                                printf("-----------------------------------\n\n");
                                system("pause");
                                system("cls");
                            }
                            else{
                                listarFuncionarios(quantidadeFuncionario, p);
                                system("pause");
                                system("cls");
                                break;
                            }
                            break;
                        case '4':
                            if (*quantidadeFuncionario == 0) {
                                system("cls");
                                printf("-----------------------------------\n");
                                printf("  NENHUM FUNCION�RIO CADASTRADO!!\n");
                                printf("-----------------------------------\n\n");
                                system("pause");
                                system("cls");
                            }
                            else{
                                buscarFuncionario(p, quantidadeFuncionario);
                                break;
                            }
                            break;
                        case '5':
                            cadastrarProduto(q, quantidadeProduto);
                            system("cls");
                            break;
                        case '6':
                            if (*quantidadeProduto == 0) {
                                system("cls");
                                printf("-----------------------------------\n");
                                printf("    NENHUM PRODUTO CADASTRADO!!\n");
                                printf("-----------------------------------\n\n");
                                system("pause");
                                system("cls");
                            }
                            else{
                                //alterarProduto(q, quantidadeProduto);
                                system("cls");
                            }
                            break;
                        case '7':
                            if (*quantidadeProduto == 0) {
                                system("cls");
                                printf("-----------------------------------\n");
                                printf("    NENHUM PRODUTO CADASTRADO!!\n");
                                printf("-----------------------------------\n\n");
                                system("pause");
                                system("cls");
                            }
                            else{
                                listarProdutos(quantidadeProduto, q);
                                system("cls");
                            }
                            break;
                        case '9':
                            simulador();
                            system("cls");
                            break;
                        case '0':
                            printf("\n\nSESS�O FINALIZADA \n\n");
                            system("pause");
                            break;
                        default:
                            printf("\nESSA OP��O N�O EXISTE! ESCOLHA UMA OP��O V�LIDA \n");
                    }
                }while(opcao != '0');
                system("cls");
                break;
            case '2':
                loginCol(p, quantidadeFuncionario);
                do{
                    opcao = menuCol();
                    switch (opcao){
                        case '1':
                            simulador();
                            system("cls");
                            break;
                        case '2':
                            cadastrarProduto(q, quantidadeProduto);
                            system("cls");
                            break;
                        case '3':
                            if (*quantidadeProduto == 0) {
                                system("cls");
                                printf("-----------------------------------\n");
                                printf("    NENHUM PRODUTO CADASTRADO!!\n");
                                printf("-----------------------------------\n\n");
                                system("pause");
                                system("cls");
                            }
                            else{
                                //alterarProduto(q, quantidadeProduto);
                                system("cls");
                            }
                            break;
                        case '4':
                            if (*quantidadeProduto == 0) {
                                system("cls");
                                printf("-----------------------------------\n");
                                printf("    NENHUM PRODUTO CADASTRADO!!\n");
                                printf("-----------------------------------\n\n");
                                system("pause");
                                system("cls");
                            }
                            else{
                                listarProdutos(quantidadeProduto, q);
                                system("cls");
                            }
                            break;
                        case '0':
                            printf("\n\nSESS�O FINALIZADA \n\n");
                            system("pause");
                            break;
                        default:
                            printf("\nESSA OP��O N�O EXISTE! ESCOLHA UMA OP��O V�LIDA \n");
                    }
                }while(opcao != '0');
                system("cls");
                break;
            case '0':
                printf("\n\nPROGRAMA FINALIZADO! \n\n");
                system("pause");
                break;
            default:
                printf("\nESSA OP��O N�O EXISTE! ESCOLHA UMA OP��O V�LIDA \n");
            free(v);
        }
    }while(*v!='0');
}
