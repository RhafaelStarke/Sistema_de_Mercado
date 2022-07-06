//
// Created by rh4f4 on 03/07/2022.
//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "registros.h"
#include "funcoes.h"

void venda(){

    FILE *arqVendas;
    FILE *arqCliente;
    FILE *arqProdutos;
    TVenda venda;
    TCliente cliente;
    TProduto produto;
    TItensCompra itensCompra;
    time_t t = time(NULL);
    struct tm dataSist=*localtime(&t);
    int cod=1, cad, exis, cont;

    if(arqVendas){
        while(fread(&venda, sizeof(TVenda), 1, arqVendas)){
            cod+=1;
        }
    }

    arqVendas= fopen("../Vendas.dat", "ab");

    if (arqVendas){
        venda.idenVenda=cod;
        venda.qtdProd=0;
        printf("CPF: ");
        scanf(" %[^\n]s", venda.cpf);
        cad=1;
        arqCliente= fopen("../Clientes.dat", "rb");
        if (arqCliente){
            while(fread(&cliente, sizeof(TCliente), 1, arqCliente)&&(cad==1)){
                if (strcmp(venda.cpf, cliente.cpf)==0){
                    cad=0;
                }
            }
            fclose(arqCliente);
        }
        if (cad==1){
            char simOUnao;
            system("cls");
            printf("NENHUM CPF ENCONTRADO!");
            do {
                printf("Deseja cadastrar novo cliente? \n");
                scanf(" %c", &simOUnao);
                if ((simOUnao=='s')||(simOUnao=='S')){
                    cadNovClien();
                    return;
                }
                else if ((simOUnao=='n')||(simOUnao=='N')) {
                    return;
                }
                else{
                    printf("Comando inválido! \n");
                }
            } while (1);
        }
        venda.dataCompr.dia=dataSist.tm_mday;
        venda.dataCompr.mes=dataSist.tm_mon+1;
        venda.dataCompr.ano=dataSist.tm_year+1900;
        system("cls");
        do{
            printf("Código do produto: ");
            scanf(" %d", &itensCompra.codProd);
            arqProdutos = fopen("../Produtos.dat", "rb+");
            if(arqProdutos){
                exis=0;
                while ((exis==0)&&(fread(&produto, sizeof(TProduto), 1, arqProdutos))){
                    if(itensCompra.codProd==produto.idenProd){
                        exis=1;
                    }
                }
                if(exis==1){
                    if (produto.qtdEstoq>0){
                        printf("\n%s \tR$ %.2lf \t%d Unidades\n\n", produto.nome, produto.preco, produto.qtdEstoq);
                        printf("Quantidade: ");
                        scanf(" %d", &itensCompra.qtd);
                        if(itensCompra.qtd<=produto.qtdEstoq){
                            produto.qtdEstoq=produto.qtdEstoq-itensCompra.qtd;
                            fseek(arqProdutos, (produto.idenProd-1)* sizeof(TProduto), SEEK_SET);
                            fwrite(&produto, sizeof(TProduto), 1, arqProdutos);
                            venda.qtdProd++;
                            itensCompra.precoUni=(float)produto.preco;
                            itensCompra.precoTot=itensCompra.precoUni*(float)itensCompra.qtd;
                            venda.valorTot+=itensCompra.precoTot;
                            system("cls");
                        }else{
                            system("cls");
                            printf("Não há quantidade disponível do produto! \n");
                        }
                    }else{
                        system("cls");
                        printf("Não há quantidade disponível do produto! \n");
                    }
                }else{
                    system("cls");
                    printf("Código inválido! \n");
                }
                fclose(arqProdutos);
            }
            printf("Digite 1 para continuar a compra, ou qualquer outro para finalizar: ");
            scanf(" %d", &cont);
        } while (cont==1);
        arqCliente = fopen("../Clientes.dat", "rb+");
        if(arqCliente){
            cliente.pontos+=(int)venda.valorTot;
            fseek(arqCliente, (cliente.cod-1)*sizeof(TCliente), SEEK_SET);
            fwrite(&cliente, sizeof(TCliente), 1, arqCliente);
            fclose(arqCliente);
        }
        fwrite(&venda, sizeof(TVenda), 1, arqVendas);
        fclose(arqVendas);
        system("cls");
    } else{
        system("cls");
        printf("ERRO NA ABERTURA DO ARQUIVO! \n");
    }
}