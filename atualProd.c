//
// Created by rh4f4 on 21/06/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include "subMenu.h"
#include "registros.h"
#include "funcoes.h"

void atualProd()
{
    FILE *arq;

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
                    printf("\n\nQuer Mesmo Editar Este Produto [S/N]? ");
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
                            printf("\n\nNovo setor: ");
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
                                    printf("COMANDO INVÁLIDO! \n");
                                    break;
                            }
                        } while ((set<1)||(set>5));
                        system("cls");
                        printf("\n\nNovo nome: ");
                        scanf(" %[^\n]s", novoProduto.nome);
                        printf("Novo preço: ");
                        scanf(" %lf", &novoProduto.preco);
                        printf("Nova data de válidade (dd/mm/aaaa): ");
                        scanf(" %d/%d/%d", &novoProduto.dataVal.dia, &novoProduto.dataVal.mes,
                              &novoProduto.dataVal.ano);
                        printf("Nova quantidade no estoque: ");
                        scanf(" %d", &novoProduto.qtdEstoq);

                        //GRAVANDO AS INFORMAÇÕES ATUALIZADOS NO ARQUIVO
                        fseek(arq, sizeof(TProduto) * (iden - 1), SEEK_SET);
                        fwrite(&novoProduto, sizeof(TProduto), 1, arq);
                        fflush(arq);
                        system("cls");
                        printf("\n\nInformações do Produto Modificadas com Sucesso! \n\n");
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
                printf("Deseja cadastrar um novo produto [S/N]? ");
                scanf(" %c", &cad);
                if ((cad == 's') || (cad == 'S')) {
                    cadNovProd();
                    return;
                } else if ((cad == 'n') || (cad == 'N')) {
                    return;
                } else {
                    printf("Comando inválido! \n");
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
