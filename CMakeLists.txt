cmake_minimum_required(VERSION 3.22)
project(Mercado_do_Bairro C)

set(CMAKE_C_STANDARD 11)

add_executable(Mercado_do_Bairro
        programaPrincipal.c
        subMenuClientes.c
        subMenuProdutos.c
        subMenuVendas.c
        subMenu.h
        registros.h
        cadNovProd.c
        atualProd.c
        funcoes.h
        cadNovClien.c
        atualClien.c
        atuaPontos.c
        listar18a25.c
        listar1000.c
        listarSet.c
        estoqBaixo.c
        venda.c
        listarVendas.c)
