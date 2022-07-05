//
// Created by rh4f4 on 03/07/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "registros.h"
#include "funcoes.h"

void venda(){
    FILE *arqProduto;
    FILE *arqVendas;
    FILE *arqCliente;
    TVenda venda;
    TCliente cliente;
    TProduto produto;
    bool flagCpf=false;
    bool flagIden;
    int point=0;

    //ENTRADA DO CPF DO CLIENTE
    system("cls");
    printf("\n\nREALIZAR NOVA VENDA: \n");
    printf("Entre com a identificação [0] para sair. \n");
    printf("\n\nCPF do cliente: ");
    scanf(" %[^\n]s", venda.cpf);
    arqCliente = fopen("../Clientes.dat", "rb");
    if (arqCliente!=NULL){
        while (fread(&cliente, sizeof(TCliente), 1, arqCliente)){

            //VERIFICAÇÃO SE O CLIENTE É CADASTRADO
            if (strcmp(venda.cpf, cliente.cpf) == 0){
                flagCpf=true;

                arqProduto = fopen("../Produtos.dat", "r+b");
                if(arqProduto!=NULL){
                    do {
                        printf("Identificação do produto: ");
                        scanf(" %d", &venda.idenVenda);

                        while(fread(&produto, sizeof(TProduto), 1, arqProduto)){

                            //VERIFICAÇÃO DA IDENTIFICAÇÃO DO PRODUTO
                            if (venda.idenVenda==produto.idenProd) {
                                flagIden=true;
                                printf("Nome: %s; Preço: %.2lf; QTD: %d; \n", produto.nome, produto.preco,
                                       produto.qtdEstoq);
                                printf("Quantidade: ");
                                scanf(" %d", &venda.qtdProd);

                                //VERIFICAÇÃO DE ESTOQUE
                                if(produto.qtdEstoq>=venda.qtdProd) {
                                    produto.qtdEstoq=produto.qtdEstoq-venda.qtdProd;
                                    fseek(arqProduto, sizeof(TProduto)*point, SEEK_SET);
                                    fwrite(&produto, sizeof(TProduto), 1, arqProduto);
                                    fflush(arqProduto);
                                }
                                else{
                                    printf("Não há qtd disponível do produto! \n");
                                }
                            }
                            else if(venda.idenVenda==0){
                                flagIden=true;
                            }
                            point+=1;
                        }
                        fclose(arqProduto);
                        if (flagIden==false){

                            //CASO NÃO SEJA CADASTRADO, PODE SER REDIRECIONADO PARA A FUNÇÃO QUE CADASTRA
                            char cad2;
                            system("cls");
                            printf("PRODUTO NÃO ENCONTRADO! \n");
                            printf("Deseja cadastrar um novo produto? [S/N] ");
                            scanf(" %c", &cad2);
                            if ((cad2=='s')||(cad2=='S')){
                                cadNovProd();
                            }
                        }
                    } while (venda.idenVenda!=0);
                }
                else{
                    system("cls");
                    printf ("ERRO NA ABERTURA DO ARQUIVO! \n");
                    system("pause");
                }
            }
        }
        fclose(arqCliente);
        if(flagCpf==false){

            //CASO NÃO SEJA, PODE SER REDIRECIONADO PARA A FUNÇÃO QUE CADASTRA
            char cad;
            system("cls");
            printf ("CPF NÃO ENCONTRADO! \n");
            printf("Deseja cadastrar o cliente? [S/N] ");
            scanf(" %c", &cad);
            if((cad=='s')||(cad=='S')){
                cadNovClien();
            }
        }
    }
    else{
        system("cls");
        printf ("ERRO NA ABERTURA DO ARQUIVO! \n");
        system("pause");
    }
}