//
// Created by rh4f4 on 21/06/2022.
//

#ifndef MERCADO_DO_BAIRRO_ESTRUTURAS_H
#define MERCADO_DO_BAIRRO_ESTRUTURAS_H
typedef struct TData
{
    int dia;
    int mes;
    int ano;
} TData;
typedef struct TVenda
{
    int idenVenda;
    char cpf[13];
    TData dataCompr;
    float valorTot;
    int qtdProd;
} TVenda;
typedef struct TProduto
{
    int idenProd;
    char setor[20];
    char nome[50];
    double preco;
    TData dataVal;
    int qtdEstoq;
} TProduto;
typedef struct TCliente
{
    char cpf[13];
    char nomeCliente[50];
    TData nasc;
    int idade;
    char end[50];
    char cid[50];
    char est[2];
    int pontos;
} TCliente;
#endif //MERCADO_DO_BAIRRO_ESTRUTURAS_H
