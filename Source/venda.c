//
// Created by rh4f4 on 03/07/2022.
//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "registros.h"
#include "funcoes.h"

void venda(){
    TVenda venda;
    TCliente cliente;
    TProduto produto;
    TItensCompra itensCompra;
    int cod=1, cad, exis, cont;
    time_t t = time(NULL);
    struct tm dataSist=*localtime(&t);
    FILE *arqCliente;
    FILE *arqProdutos;
    FILE *arqVendas = fopen("../arquivos/Vendas.dat", "rb");

    //GERADOR DE CÓDIGOS DE VENDAS
    if (arqVendas) {
        while (fread(&venda, sizeof(TVenda), 1, arqVendas)) {
            cod += 1;
        }
        fclose(arqVendas);
    }

    arqVendas = fopen("../arquivos/Vendas.dat", "ab");

    if (arqVendas) {
        venda.idenVenda = cod;
        venda.qtdProd = 0;

        //ENTRADA DO CPF DO CLIENTE
        system("cls");
        printf("\n\nNOVA VENDA: \n");
        printf("\nCPF do cliente: ");
        scanf(" %[^\n]s", venda.cpf);
        cad = 1;

        arqCliente = fopen("../arquivos/Clientes.dat", "rb");
        if (arqCliente) {

            //VERIFICA SE O CLIENTE JÁ É CADASTRADO
            while (fread(&cliente, sizeof(TCliente), 1, arqCliente) && (cad == 1)) {
                if (strcmp(venda.cpf, cliente.cpf) == 0) {
                    cad = 0;
                }
            }
            fclose(arqCliente);

            //SE NÃO FOR, PODE SER REDIRECIONADO PARA A FUNÇÃO DE CADASTRO
            if (cad == 1) {
                char simOUnao;
                system("cls");
                printf("\n\nNENHUM CPF ENCONTRADO!\n\n");
                do {
                    printf("Deseja cadastrar novo cliente? [S]im / [N]ão\n");
                    scanf(" %c", &simOUnao);
                    if ((simOUnao == 's') || (simOUnao == 'S')) {
                        cadNovClien();
                        return;
                    } else if ((simOUnao == 'n') || (simOUnao == 'N')) {
                        return;
                    } else {
                        printf("\nCOMANDO INVÁLIDO!\n\n");
                    }
                } while (1);
            }
            venda.dataCompr.dia = dataSist.tm_mday;
            venda.dataCompr.mes = dataSist.tm_mon + 1;
            venda.dataCompr.ano = dataSist.tm_year + 1900;
            system("cls");

            //ENTRADA DOS PRODUTOS
            do {
                printf("\n\nCódigo do produto: ");
                scanf(" %d", &itensCompra.codProd);
                arqProdutos = fopen("../arquivos/Produtos.dat", "rb+");
                if (arqProdutos) {
                    exis = 0;

                    //VERIFICA SE O PRODUTO EXISTE NO ESTOQUE
                    while ((exis == 0) && (fread(&produto, sizeof(TProduto), 1, arqProdutos))) {
                        if (itensCompra.codProd == produto.idenProd) {
                            exis = 1;
                        }
                    }

                    //SE SIM, REALIZA A VENDA
                    if (exis == 1) {
                        if (produto.qtdEstoq > 0) {
                            printf("\n%s \tR$ %.2lf \t%d Unidades\n\n", produto.nome, produto.preco, produto.qtdEstoq);
                            printf("Quantidade: ");
                            scanf(" %d", &itensCompra.qtd);
                            if (itensCompra.qtd <= produto.qtdEstoq) {
                                produto.qtdEstoq = produto.qtdEstoq - itensCompra.qtd;
                                fseek(arqProdutos, (produto.idenProd - 1) * sizeof(TProduto), SEEK_SET);
                                fwrite(&produto, sizeof(TProduto), 1, arqProdutos);
                                venda.qtdProd++;
                                itensCompra.precoUni = (float) produto.preco;
                                itensCompra.precoTot += (itensCompra.precoUni * (float) itensCompra.qtd);
                            } else {
                                printf("\nNÃO HÁ QUANTIDADE DISPONÍVEL DO PRODUTO!\n\n");
                            }
                        } else {
                            printf("\nNÃO HÁ QUANTIDADE DISPONÍVEL DO PRODUTO!\n\n");
                        }
                    } else {
                        printf("\nCÓDIGO INVÁLIDO\n\n");
                    }
                    fclose(arqProdutos);
                }
                printf("\nDIGITE 1 PARA CONTINUAR...\n");
                scanf(" %d", &cont);
            } while (cont == 1);
            venda.valorTot = itensCompra.precoTot;
            arqCliente = fopen("../arquivos/Clientes.dat", "rb+");

            system("cls");
            printf("\n\nIdentificação da venda: %d \n", venda.idenVenda);
            printf("\nCPF do cliente: %s \n", venda.cpf);
            printf("\nData da compra: %d/%d/%d \n", venda.dataCompr.dia, venda.dataCompr.mes, venda.dataCompr.ano);
            printf("\nValor total da compra: R$ %.2f \n", venda.valorTot);
            printf("\nQuantidade de produtos: %d \n", venda.qtdProd);
            printf("\nPontos gerados: %d \n\n", (int) venda.valorTot);
            printf("\n");
            system("pause");

            if (arqCliente) {
                cliente.pontos += (int) venda.valorTot;
                fseek(arqCliente, (cliente.cod - 1) * sizeof(TCliente), SEEK_SET);
                fwrite(&cliente, sizeof(TCliente), 1, arqCliente);
                fclose(arqCliente);
            }
            fwrite(&venda, sizeof(TVenda), 1, arqVendas);
            fclose(arqVendas);
            system("cls");
        } else {
            system("cls");
            printf("\n\nERRO NA ABERTURA DO ARQUIVO! \n\n");
            printf("\n");
            system("pause");
        }
    }
}