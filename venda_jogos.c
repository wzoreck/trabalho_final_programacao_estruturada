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
    int video_game_id;
    char nome[50];

};
struct pessoa {
    int id;
    char p_nome[50];
    char u_nome[50];
    char cpf[11];
    int mes_nasc;
    int ano_nasc;
    int sexo;
};
struct venda {
    int pessoa_id;
    int jogo_id;
    char data[10];
};

// Funções
int cadastrar(int *p, int size, char arquivo[22]);
int listar();
int alterar(struct videogame v);

int main() {

    struct videogame videogame;
    struct jogo jogo;
    struct pessoa pessoa;
    struct venda venda;

    int tamanho=0, escolha;
    int *v[4];
    char arquivo_videogame[22] = "arquivos/videogame.bin";
    char arquivo_jogo[17] = "arquivos/jogo.bin";
    char arquivo_pessoa[19] = "arquivos/pessoa.bin";
    char arquivo_venda[18] = "arquivos/venda.bin";

    v[0] = &arquivo_videogame;


    printf("Escolha: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            printf("Informe o id do videogame: ");
            scanf("%d", &videogame.id);
            printf("Informe o nome do videogame: ");
            setbuf(stdin, NULL); // Para resolver problemas com o buffer
            fgets(videogame.nome, 50, stdin);
            printf("Informe a marca do videogame: ");
            setbuf(stdin, NULL);
            fgets(videogame.marca, 50, stdin);
            tamanho = sizeof(struct videogame);
            cadastrar(&videogame, tamanho, v[0]);
        break;

        case 2:

        break;
    }

    return 0;
}

// Função responsável por realizar todos os registros do programa
int cadastrar(int *p, int size, char arquivo[22]) {
    FILE *f = fopen(arquivo, "ab");
    fwrite(p, size, 1, f);
    fclose(f);
}
