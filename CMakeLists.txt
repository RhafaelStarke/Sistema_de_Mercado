cmake_minimum_required(VERSION 3.22)
project(Mercado_do_Bairro C)

set(CMAKE_C_STANDARD 11)

add_executable(Mercado_do_Bairro
        Source/programaPrincipal.c
        Source/subMenuClientes.c
        Source/subMenuProdutos.c
        Source/subMenuVendas.c
        Source/subMenu.h
        Source/registros.h
        Source/cadNovProd.c
        Source/atualProd.c
        Source/funcoes.h
        Source/cadNovClien.c
        Source/atualClien.c
        Source/listar18a25.c
        Source/listar1000.c
        Source/listarSet.c
        Source/estoqBaixo.c
        Source/venda.c
        Source/listarVendas.c)
