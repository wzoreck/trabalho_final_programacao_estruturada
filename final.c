#include <stdio.h>
#include <stdlib.h>

// Estruturas
struct videogame {
    int id;
    char nome[50];
    char marca[50];
};
struct jogo {
    int id;
    int videogame_id;
    char nome[50];

};
struct pessoa {
    int id;
    char p_nome[50];
    char u_nome[50];
    char cpf[13];
    int mes_nasc;
    int ano_nasc;
    int sexo;
};
struct venda {
    int pessoa_id;
    int jogo_id;
    char data[12];
};

// Funções
int cadastrar_videogame(struct videogame v);
int cadastrar_jogo(struct jogo j);
int cadastrar_pessoa(struct pessoa p);
int cadastrar_venda(struct venda v);

int listar_videogame();
int listar_jogo();
int listar_pessoa();
int listar_venda();

int alterar_videogame(struct videogame v);
int alterar_jogo(struct jogo j);
int alterar_pessoa(struct pessoa p);
int alterar_venda(struct venda v);

int videogame_id_automatico();
int jogo_id_automatico();
int pessoa_id_automatico();

int videogame_busca_por_referencia(int id);
int jogo_busca_por_referencia(int id);
int pessoa_busca_por_referencia(int id);
int venda_busca_por_referencia(int id_pessoa);

int main() {

    struct videogame videogame;
    struct jogo jogo;
    struct pessoa pessoa;
    struct venda venda;

    int escolha1, escolha2, retorno, loop=0, limpar_tela=0, busca_id;

    // LOOP PRINCIPAL DO PROGRAMA
    while(loop == 0) {

        printf(" ██████╗  █████╗ ███╗   ███╗███████╗\n██╔════╝ ██╔══██╗████╗ ████║██╔════╝\n██║  ███╗███████║██╔████╔██║█████╗\n██║   ██║██╔══██║██║╚██╔╝██║██╔══╝\n╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗\n ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝\n\n███████╗████████╗ ██████╗ ██████╗ ███████╗\n██╔════╝╚══██╔══╝██╔═══██╗██╔══██╗██╔════╝\n███████╗   ██║   ██║   ██║██████╔╝█████╗\n╚════██║   ██║   ██║   ██║██╔══██╗██╔══╝\n███████║   ██║   ╚██████╔╝██║  ██║███████╗\n╚══════╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝╚══════╝\n\n");

        printf("\nEscolha a operação que deseja realizar!");
        printf("\n\n[1] - Cadastrar");
        printf("\n[2] - Consultar registro");
        printf("\n[3] - Atualizar registro");
        printf("\n\nInforme sua escolha: ");

        scanf("%d", &escolha1);

        switch (escolha1) {
            case 1: // CADASTROS
                system("clear");
                printf(" ██████╗ █████╗ ██████╗  █████╗ ███████╗████████╗██████╗  ██████╗\n██╔════╝██╔══██╗██╔══██╗██╔══██╗██╔════╝╚══██╔══╝██╔══██╗██╔═══██╗\n██║     ███████║██║  ██║███████║███████╗   ██║   ██████╔╝██║   ██║\n██║     ██╔══██║██║  ██║██╔══██║╚════██║   ██║   ██╔══██╗██║   ██║\n╚██████╗██║  ██║██████╔╝██║  ██║███████║   ██║   ██║  ██║╚██████╔╝\n ╚═════╝╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝\n\n");
                printf("\nEscolha a operação que deseja realizar!");
                printf("\n\n[1] - Cadastrar Videogame");
                printf("\n[2] - Cadastrar Jogo");
                printf("\n[3] - Cadastrar Cliente");
                printf("\n[4] - Cadastrar Venda");
                printf("\n\nInforme sua escolha: ");
                scanf("%d", &escolha2);
                switch (escolha2) {
                    case 1: // CADASTRO VIDEOGAME
                        videogame.id = videogame_id_automatico();
                        printf("\nInforme o nome do videogame: ");
                        setbuf(stdin, NULL); // Para resolver problemas com o buffer
                        fgets(videogame.nome, 50, stdin);
                        printf("Informe a marca do videogame: ");
                        setbuf(stdin, NULL);
                        fgets(videogame.marca, 50, stdin);
                        retorno = cadastrar_videogame(videogame);
                        if(retorno == 1) {
                            printf("Falha ao abrir o arquivo");
                        } else if(retorno == 0) {
                            retorno = 0;
                        }
                    break;

                    case 2:  // CADASTRO JOGO
                        jogo.id = jogo_id_automatico();
                        printf("\nInforme o id do videogame: ");
                        scanf("%d", &jogo.videogame_id);
                        printf("Informe o nome do jogo: ");
                        setbuf(stdin, NULL); // Para resolver problemas com o buffer
                        fgets(jogo.nome, 50, stdin);
                        retorno = cadastrar_jogo(jogo);
                        if(retorno == 1) {
                            printf("Falha ao abrir o arquivo");
                        } else if(retorno == 0) {
                            retorno = 0;
                        }
                    break;

                    case 3: // CADASTRO CLIENTE
                        pessoa.id = pessoa_id_automatico();
                        printf("\nInforme o primeiro nome do cliente: ");
                        setbuf(stdin, NULL); // Para resolver problemas com o buffer
                        fgets(pessoa.p_nome, 50, stdin);
                        printf("Informe o sobrenome do cliente: ");
                        setbuf(stdin, NULL);
                        fgets(pessoa.u_nome, 50, stdin);
                        printf("Informe o cpf do cliente (somente números): ");
                        setbuf(stdin, NULL);
                        fgets(pessoa.cpf, 13, stdin);
                        //scanf("%ld", &pessoa.cpf);
                        printf("Informe de forma numérica o mês de nascimento do cliente: ");
                        scanf("%d", &pessoa.mes_nasc);
                        printf("Informe de forma numérica o ano de nascimento do cliente: ");
                        scanf("%d", &pessoa.ano_nasc);
                        printf("Informe o sexo do cliente\n[1] - Masculino\n[2] - Feminino\n[3] - Outro\nInforme o sexo: ");
                        scanf("%d", &pessoa.sexo);
                        retorno = cadastrar_pessoa(pessoa);
                        if(retorno == 1) {
                            printf("Falha ao abrir o arquivo");
                        } else if(retorno == 0) {
                            retorno = 0;
                        }
                    break;

                    case 4:  // CADASTRO VENDA
                        printf("\nInforme o id da pessoa: ");
                        scanf("%d", &venda.pessoa_id);
                        printf("Informe o id do jogo: ");
                        scanf("%d", &venda.jogo_id);
                        printf("Informe a data (AAAA/MM/DD):");
                        setbuf(stdin, NULL); // Para resolver problemas com o buffer
                        fgets(venda.data, 12, stdin);
                        retorno = cadastrar_venda(venda);
                        if(retorno == 1) {
                            printf("Falha ao abrir o arquivo");
                        } else if(retorno == 0) {
                            retorno = 0;
                        }
                    break;
                }
            break;

            case 2:  // CONSULTAS
                system("clear");
                printf(" ██████╗ ██████╗ ███╗   ██╗███████╗██╗   ██╗██╗  ████████╗ █████╗\n██╔════╝██╔═══██╗████╗  ██║██╔════╝██║   ██║██║  ╚══██╔══╝██╔══██╗\n██║     ██║   ██║██╔██╗ ██║███████╗██║   ██║██║     ██║   ███████║\n██║     ██║   ██║██║╚██╗██║╚════██║██║   ██║██║     ██║   ██╔══██║\n╚██████╗╚██████╔╝██║ ╚████║███████║╚██████╔╝███████╗██║   ██║  ██║\n ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝ ╚═════╝ ╚══════╝╚═╝   ╚═╝  ╚═╝\n\n");
                printf("\nEscolha a operação que deseja realizar!");
                printf("\n\n[1] - Listar Videogames");
                printf("\n[2] - Listar Jogos");
                printf("\n[3] - Listar Clientes");
                printf("\n[4] - Listar Vendas");
                printf("\n[5] - Consultar Videogame por ID");
                printf("\n[6] - Consultar Jogos por ID");
                printf("\n[7] - Consultar Clientes por ID");
                printf("\n[8] - Consultar Vendas por ID");
                printf("\n\nInforme sua escolha: ");
                scanf("%d", &escolha2);
                switch (escolha2) {
                    case 1: // CONSULTAR VIDEOGAMES
                        retorno = listar_videogame();
                        if(retorno == 1) {
                            printf("Falha ao abrir o arquivo!");
                        }
                    break;


                    case 2: // CONSULTAR JOGOS
                        retorno = listar_jogo();
                        if(retorno == 1) {
                            printf("Falha ao abrir o arquivo!");
                        }
                    break;

                    case 3: // CONSULTAR CLIENTES
                        retorno = listar_pessoa();
                        if(retorno == 1) {
                            printf("Falha ao abrir o arquivo!");
                        }
                    break;

                    case 4: // CONSULTAR VENDAS
                        retorno = listar_venda();
                        if(retorno == 1) {
                            printf("Falha ao abrir o arquivo!");
                        }
                    break;

                    case 5:
                        printf("\nInforme o id do vídeogame: ");
                        scanf("%d", &busca_id);
                        retorno = videogame_busca_por_referencia(busca_id);
                        if(retorno == 1) {
                            printf("\nNão há registro referente a esse ID!");
                        }
                    break;

                    case 6:
                        printf("\nInforme o id do jogo: ");
                        scanf("%d", &busca_id);
                        retorno = jogo_busca_por_referencia(busca_id);
                        if(retorno == 1) {
                            printf("\nNão há registro referente a esse ID!");
                        }
                    break;

                    case 7:
                        printf("\nInforme o id da pessoa: ");
                        scanf("%d", &busca_id);
                        retorno = pessoa_busca_por_referencia(busca_id);
                        if(retorno == 1) {
                            printf("\nNão há registro referente a esse ID!");
                        }
                    break;

                    case 8:
                        printf("\nInforme o id do cliente: ");
                        scanf("%d", &busca_id);
                        retorno = venda_busca_por_referencia(busca_id);
                        if(retorno == 1) {
                            printf("\nNão há registro referente a esse ID!");
                        }
                    break;
                }
            break;

            case 3:  // ALTERAÇÕES
                system("clear");
                printf(" █████╗ ████████╗██╗   ██╗ █████╗ ██╗     ██╗███████╗ █████╗ ██████╗\n██╔══██╗╚══██╔══╝██║   ██║██╔══██╗██║     ██║╚══███╔╝██╔══██╗██╔══██╗\n███████║   ██║   ██║   ██║███████║██║     ██║  ███╔╝ ███████║██████╔╝\n██╔══██║   ██║   ██║   ██║██╔══██║██║     ██║ ███╔╝  ██╔══██║██╔══██╗\n██║  ██║   ██║   ╚██████╔╝██║  ██║███████╗██║███████╗██║  ██║██║  ██║\n╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝\n\n");
            break;
        }
        printf("\n\nDigite [1] para voltar ao menu inicial: ");
        scanf("%d", &limpar_tela);
        if(limpar_tela == 1) {
            system("clear");
        }
    }

    return 0;
}

// FUNÇÕES DE CADASTRO
int cadastrar_videogame(struct videogame v) {
    FILE *f = fopen("arquivos/videogame.bin", "ab");
    if(f == NULL) {
        return 1;
    }
    fwrite(&v, sizeof(struct videogame), 1, f);
    fclose(f);
    return 0;
}
int cadastrar_jogo(struct jogo j) {
    FILE *f = fopen("arquivos/jogo.bin", "ab");
    if(f == NULL) {
        return 1;
    }
    fwrite(&j, sizeof(struct jogo), 1, f);
    fclose(f);
    return 0;
}
int cadastrar_pessoa(struct pessoa p) {
    FILE *f = fopen("arquivos/pessoa.bin", "ab");
    if(f == NULL) {
        return 1;
    }
    fwrite(&p, sizeof(struct pessoa), 1, f);
    fclose(f);
    return 0;
}
int cadastrar_venda(struct venda v) {
    FILE *f = fopen("arquivos/venda.bin", "ab");
    if(f == NULL) {
        return 1;
    }
    fwrite(&v, sizeof(struct venda), 1, f);
    fclose(f);
    return 0;
}

// FUNÇÕES DE CONSULTA
int listar_videogame() {
    struct videogame v;
    FILE *f = fopen("arquivos/videogame.bin", "rb");
    if(f == NULL) {
        return 1;
    }

    while(fread(&v, sizeof(struct videogame), 1, f)) {
        printf("\nID: %d\nNome: %sMarca: %s\n", v.id, v.nome, v.marca);
    }

    fclose(f);
    return 0;
}
int listar_jogo() { // OK
    struct jogo j;
    struct videogame v;
    FILE *fv = fopen("arquivos/videogame.bin", "rb");
    FILE *f = fopen("arquivos/jogo.bin", "rb");
    if(f == NULL) {
        return 1;
    }

    while(fread(&j, sizeof(struct jogo), 1, f)) {
        fread(&v, sizeof(struct videogame), 1, fv);
        if(j.videogame_id == v.id) {
            printf("\nID: %d\nNome: %sVideogame: %s", j.id, j.nome, v.nome);
        } else {
            printf("\nID: %d\nNome: %sID Videogame: %d\n", j.id, j.nome, j.videogame_id);
        }
    }

    fclose(f);
    return 0;
}

/*
int listar_jogo() { // original
    struct jogo j;
    FILE *f = fopen("arquivos/jogo.bin", "rb");
    if(f == NULL) {
        return 1;
    }

    while(fread(&j, sizeof(struct jogo), 1, f)) {
        printf("\nID: %d\nNome: %sID Videogame: %d\n", j.id, j.nome, j.videogame_id);
    }

    fclose(f);
    return 0;
}
*/

int listar_pessoa() {
    struct pessoa p;
    FILE *f = fopen("arquivos/pessoa.bin", "rb");
    if(f == NULL) {
        return 1;
    }

    while(fread(&p, sizeof(struct pessoa), 1, f)) {
        printf("\nID: %d\nNome: %sSobrenome: %sCPF: %sMês de nascimento: %d\nAno de nascimento: %d\nSexo: %d\n", p.id, p.p_nome, p.u_nome, p.cpf, p.mes_nasc, p.ano_nasc, p.sexo);
    }

    fclose(f);
    return 0;
}
int listar_venda() {
    struct venda v;
    FILE *f = fopen("arquivos/venda.bin", "rb");
    if(f == NULL) {
        return 1;
    }

    while(fread(&v, sizeof(struct venda), 1, f)) {
        printf("\nID Cliente: %d\nID Jogo: %d\nData da venda: %s", v.pessoa_id, v.jogo_id, v.data);
    }

    fclose(f);
    return 0;
}

// FUNÇÕES PARA ID AUTOMÁTICO
int videogame_id_automatico() {
    struct videogame v;
    FILE *f = fopen("arquivos/videogame.bin", "rb");
    int retorno = fseek(f, -1*sizeof(struct videogame), 2);
    fread(&v, sizeof(struct videogame), 1, f);
    fclose(f);
    if(retorno == 0) {
        return v.id+1;
    } else {
        return 0;
    }
}
int jogo_id_automatico() {
    struct jogo j;
    FILE *f = fopen("arquivos/jogo.bin", "rb");
    int retorno = fseek(f, -1*sizeof(struct jogo), 2);
    fread(&j, sizeof(struct jogo), 1, f);
    fclose(f);
    if(retorno == 0) {
        return j.id+1;
    } else {
        return 0;
    }
}
int pessoa_id_automatico() {
    struct pessoa p;
    FILE *f = fopen("arquivos/pessoa.bin", "rb");
    int retorno = fseek(f, -1*sizeof(struct pessoa), 2);
    fread(&p, sizeof(struct pessoa), 1, f);
    fclose(f);
    if(retorno == 0) {
        return p.id+1;
    } else {
        return 0;
    }
}

// BUSCAS POR REFERÊNCIA DE ID
int videogame_busca_por_referencia(int id) {
    struct videogame v;
    FILE *f = fopen("arquivos/videogame.bin", "rb");
    int x=1;
    while(fread(&v, sizeof(struct videogame), 1, f)) {
        if(v.id == id) {
            printf("\nID: %d\nNome: %sMarca: %s\n", v.id, v.nome, v.marca);
            x=0;
        }
    }

    fclose(f);
    return x;
}
int jogo_busca_por_referencia(int id) {
    struct jogo j;
    FILE *f = fopen("arquivos/jogo.bin", "rb");
    int x=1;
    while(fread(&j, sizeof(struct jogo), 1, f)) {
        if(j.id == id) {
            printf("\nID: %d\nID Videogame: %d\nNome: %s", j.id, j.videogame_id, j.nome);
            x=0;
        }
    }

    fclose(f);
    return x;
}

int pessoa_busca_por_referencia(int id) {
    struct pessoa p;
    FILE *f = fopen("arquivos/pessoa.bin", "rb");
    int x=1;
    while(fread(&p, sizeof(struct pessoa), 1, f)) {
        if(p.id == id) {
            printf("\nID: %d\nNome: %sSobrenome: %sCPF: %sMês de nascimento: %d\nAno de nascimento: %d\nSexo: %d\n", p.id, p.p_nome, p.u_nome, p.cpf, p.mes_nasc, p.ano_nasc, p.sexo);
            x=0;
        }
    }

    fclose(f);
    return x;
}
int venda_busca_por_referencia(int id_pessoa) {
    struct venda v;
    FILE *f = fopen("arquivos/venda.bin", "rb");
    int x=1;
    while(fread(&v, sizeof(struct venda), 1, f)) {
        if(v.pessoa_id == id_pessoa) {
            printf("\nID Cliente: %d\nID Jogo: %d\nData da venda: %s", v.pessoa_id, v.jogo_id, v.data);
            x=0;
        }
    }

    fclose(f);
    return x;
}
