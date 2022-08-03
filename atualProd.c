//
// Created by rh4f4 on 21/06/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include "registros.h"
#include "funcoes.h"
#include <time.h>

void atualProd()
{
    FILE *arq;
    time_t dataSist;
    dataSist = time(NULL);
    struct tm tm = *localtime(&dataSist);

    system("cls");
    printf ("\n\nATUALIZAÇÃO DE DADOS DOS PRODUTOS: \n");
    arq = fopen ("../Produtos.dat", "r+b");
    if (arq != NULL)
    {
        int iden;
        int flag=0;
        TProduto produto, novoProduto;
        char edit = 'n';
        int set;
        bool flagIden=false;

        //USUÁRIO ENTRA COM A IDENTIFICAÇÃO DO PRODUTO QUE SERÁ ATUALIZADO
        system("cls");
        printf("\nPRODUTOS:");
        printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
        while (fread(&produto, sizeof(TProduto), 1, arq)){
            printf("Identificação: %d; \tSetor: %s; \tNome: %s; \tPreço: R$ %.2lf; \tVencimento: %d/%d/%d; \tEstoque: %d; \n\n",
                   produto.idenProd, produto.setor, produto.nome, produto.preco, produto.dataVal.dia, produto.dataVal.mes,
                   produto.dataVal.ano, produto.qtdEstoq);
        }
        printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

        printf("\n\nEntre com a identificação do produto que quer atualizar as informações: ");
        scanf(" %d", &iden);
        do {
            fseek(arq, sizeof(TProduto)*flag, SEEK_SET);
            fread(&novoProduto, sizeof(TProduto), 1, arq);
            if(iden==novoProduto.idenProd) {

                //MOSTRA O PRODUTO QUE TERÁ SEUS DADOS ATUALIZADOS
                flagIden = true;
                system("cls");
                printf("\n\nPRODUTO COM IDENTIFICAÇÃO CORRESPONDENTE: \n\n");
                printf("Identificação: %d \n", novoProduto.idenProd);
                printf("Setor: %s \n", novoProduto.setor);
                printf("Nome: %s \n", novoProduto.nome);
                printf("Preço: R$ %.2lf \n", novoProduto.preco);
                printf("Data de validade: %d/%d/%d \n", novoProduto.dataVal.dia, novoProduto.dataVal.mes,
                       novoProduto.dataVal.ano);
                printf("Quantidade no estoque: %d \n", novoProduto.qtdEstoq);
                do {
                    printf("\n\nQuer Mesmo Editar Este Produto? [S]im / [N]ão\n");
                    scanf(" %c", &edit);

                    //ATUALIZAÇÃO DOS DADOS DO PRODUTO
                    if ((edit == 'S') || (edit == 's')) {
                        system("cls");
                        printf("\n\nSetores de produtos: \n\n");
                        printf("1. Higiene e Limpeza \n");
                        printf("2. Bebidas \n");
                        printf("3. Frios \n");
                        printf("4. Padaria \n");
                        printf("5. Açougue \n");
                        do{
                            printf("\n\nSetor do produto: ");
                            scanf(" %d", &set);
                            switch (set) {
                                case 1:
                                    strcpy(novoProduto.setor, "Higiene e limpeza");
                                    break;
                                case 2:
                                    strcpy(novoProduto.setor, "Bebidas");
                                    break;
                                case 3:
                                    strcpy(novoProduto.setor, "Frios");
                                    break;
                                case 4:
                                    strcpy(novoProduto.setor, "Padaria");
                                    break;
                                case 5:
                                    strcpy(novoProduto.setor, "Acougue");
                                    break;
                                default:
                                    printf("\nCOMANDO INVÁLIDO!");
                                    break;
                            }
                        } while ((set<1)||(set>5));
                        system("cls");
                        printf("\n\nNome: ");
                        scanf(" %[^\n]s", novoProduto.nome);
                        do {
                            printf("Preço: ");
                            scanf(" %lf", &novoProduto.preco);
                            if(novoProduto.preco < 0){
                                printf("\nPREÇO INVÁLIDO!\n\n");
                            }
                        } while (novoProduto.preco < 0);
                        do{
                            printf("Data de validade: (dd/mm/aaaa) ");
                            scanf(" %d/%d/%d", &novoProduto.dataVal.dia, &novoProduto.dataVal.mes, &novoProduto.dataVal.ano);
                            if ((novoProduto.dataVal.dia < 0)||(novoProduto.dataVal.dia > 31))
                            {
                                printf("\nDIA INVÁLIDO!\n\n");
                            }
                            else if ((novoProduto.dataVal.mes < 0)||(novoProduto.dataVal.mes > 12))
                            {
                                printf("\nMÊS INVÁLIDO!\n\n");
                            }
                            else if ((novoProduto.dataVal.ano < 0)||(novoProduto.dataVal.ano < (tm.tm_year+1900)))
                            {
                                printf("\nANO INVÁLIDO!\n\n");
                            }
                        }while((novoProduto.dataVal.dia < 0)||(novoProduto.dataVal.dia > 31)||(novoProduto.dataVal.mes < 0)||(novoProduto.dataVal.mes > 12)
                               ||(novoProduto.dataVal.ano < 0)||(novoProduto.dataVal.ano < (tm.tm_year+1900)));
                        do {
                            printf("Quantidade no estoque: ");
                            scanf(" %d", &novoProduto.qtdEstoq);
                            if(novoProduto.qtdEstoq < 0){
                                printf("\nESTOQUE INVÁLIDO\n\n");
                            }
                        }while(novoProduto.qtdEstoq < 0);

                        //GRAVANDO AS INFORMAÇÕES ATUALIZADOS NO ARQUIVO
                        fseek(arq, sizeof(TProduto) * (iden - 1), SEEK_SET);
                        fwrite(&novoProduto, sizeof(TProduto), 1, arq);
                        fflush(arq);
                        system("cls");
                        printf("\nInformações do Produto Modificadas com Sucesso! \n\n");
                        system("pause");
                        return;
                    } else if ((edit == 'n') || (edit == 'N')) {
                        return;
                    } else {
                        printf("\nCOMANDO INVÁLIDO!");
                    }
                } while (1);
            }
            flag+=1;
        }while(feof(arq) == false);
        if (flagIden==false){
            char cad;
            system("cls");
            printf("\n\nNENHUM PRODUTO FOI ENCONTRADO COM ESSA IDENTIFICAÇÃO! \n\n");
            do {
                printf("Deseja cadastrar um novo produto? [S]im / [N]ão\n");
                scanf(" %c", &cad);
                if ((cad == 's') || (cad == 'S')) {
                    cadNovProd();
                    return;
                } else if ((cad == 'n') || (cad == 'N')) {
                    return;
                } else {
                    printf("\nComando inválido!\n\n");
                }
            } while (1);
        }
    }
    else
    {
        system("cls");
        printf ("ERRO NA ABERTURA DO ARQUIVO! \n");
        system("pause");
    }
}
