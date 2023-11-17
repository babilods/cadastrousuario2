#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USUARIOS 1000

struct Usuario {
    int id;
    char nome[100];
    char email[100];
    char sexo[20];
    char endereco[200];
    double altura;
    int vacina;
};

bool validarEmail(const char *email);

void cadastrarUsuario(struct Usuario usuarios[], int *numUsuarios);
void editarUsuario(struct Usuario usuarios[], int numUsuarios);
void excluirUsuario(struct Usuario usuarios[], int *numUsuarios);
void buscarUsuarioPorEmail(struct Usuario usuarios[], int numUsuarios);
void imprimirUsuarios(struct Usuario usuarios[], int numUsuarios);

int main() {
    struct Usuario usuarios[MAX_USUARIOS];
    int numUsuarios = 0;
    char opcao;

    do {
        // Menu de opções
        printf("\nMenu:\n");
        printf("1. Cadastrar Usuário\n");
        printf("2. Editar Usuário\n");
        printf("3. Excluir Usuário\n");
        printf("4. Buscar Usuário por E-mail\n");
        printf("5. Imprimir Todos os Usuários\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                cadastrarUsuario(usuarios, &numUsuarios);
                break;
            case '2':
                editarUsuario(usuarios, numUsuarios);
                break;
            case '3':
                excluirUsuario(usuarios, &numUsuarios);
                break;
            case '4':
                buscarUsuarioPorEmail(usuarios, numUsuarios);
                break;
            case '5':
                imprimirUsuarios(usuarios, numUsuarios);
                break;
            case '6':
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != '6');

    return 0;
}

bool validarEmail(const char *email) {
    // Verifica se o e-mail contém o símbolo "@" e não está na primeira posição
    const char *posArroba = strchr(email, '@');

    // Retorna verdadeiro se o "@" for encontrado e não estiver na primeira posição
    return posArroba != NULL && posArroba != email;
}

void cadastrarUsuario(struct Usuario usuarios[], int *numUsuarios) {
    if (*numUsuarios < MAX_USUARIOS) {
        struct Usuario novoUsuario;

        novoUsuario.id = *numUsuarios + 1; 
        printf("Nome: ");
        scanf("%99s", novoUsuario.nome);

        // Loop para solicitar um e-mail válido
        do {
            printf("Email: ");
            scanf("%99s", novoUsuario.email);

            if (!validarEmail(novoUsuario.email)) {
                printf("E-mail inválido. Certifique-se de incluir o símbolo '@'.\n");
            }
        } while (!validarEmail(novoUsuario.email));

        printf("Sexo (Feminino/Masculino/Indiferente): ");
        scanf("%19s", novoUsuario.sexo);
        printf("Endereço: ");
        scanf("%199s", novoUsuario.endereco);
        printf("Altura: ");
        scanf("%lf", &novoUsuario.altura);
        printf("Vacina (0 para Não, 1 para Sim): ");
        scanf("%d", &novoUsuario.vacina);

        usuarios[*numUsuarios] = novoUsuario;
        (*numUsuarios)++;
        printf("Usuário cadastrado com sucesso!\n");
    } else {
        printf("Limite de usuários atingido.\n");
    }
}

void editarUsuario(struct Usuario usuarios[], int numUsuarios) {
    int id;
    printf("Digite o ID do usuário que deseja editar: ");
    scanf("%d", &id);

    for (int i = 0; i < numUsuarios; i++) {
        if (usuarios[i].id == id) {
            printf("Novo Nome: ");
            scanf("%99s", usuarios[i].nome);
            printf("Novo Email: ");
            scanf("%99s", usuarios[i].email);
            printf("Novo Sexo (Feminino/Masculino/Indiferente): ");
            scanf("%19s", usuarios[i].sexo);
            printf("Novo Endereço: ");
            scanf("%199s", usuarios[i].endereco);
            printf("Nova Altura: ");
            scanf("%lf", &usuarios[i].altura);
            printf("Nova Vacina (0 para Não, 1 para Sim): ");
            scanf("%d", &usuarios[i].vacina);

            printf("Usuário editado com sucesso!\n");
            return;
        }
    }

    printf("ID de usuário não encontrado.\n");
}

void excluirUsuario(struct Usuario usuarios[], int *numUsuarios) {
    int id;
    printf("Digite o ID do usuário que deseja excluir: ");
    scanf("%d", &id);

    for (int i = 0; i < *numUsuarios; i++) {
        if (usuarios[i].id == id) {
            // Mover o último elemento para a posição do elemento a ser excluído
            usuarios[i] = usuarios[*numUsuarios - 1];
            (*numUsuarios)--;
            printf("Usuário excluído com sucesso!\n");
            return;
        }
    }

    printf("ID de usuário não encontrado.\n");
}

void buscarUsuarioPorEmail(struct Usuario usuarios[], int numUsuarios) {
    char email[100];
    printf("Digite o email do usuário que deseja buscar: ");
    scanf("%99s", email);

    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(usuarios[i].email, email) == 0) {
            printf("\nID: %d\n", usuarios[i].id);
            printf("Nome: %s\n", usuarios[i].nome);
            printf("Email: %s\n", usuarios[i].email);
            printf("Sexo: %s\n", usuarios[i].sexo);
            printf("Endereço: %s\n", usuarios[i].endereco);
            printf("Altura: %.2f\n", usuarios[i].altura);
            printf("Vacina: %d\n", usuarios[i].vacina);
            return;
        }
    }

    printf("Email não encontrado.\n");
}

void imprimirUsuarios(struct Usuario usuarios[], int numUsuarios) {
    printf("\nTodos os Usuários:\n");
    for (int i = 0; i < numUsuarios; i++) {
        printf("\nID: %d\n", usuarios[i].id);
        printf("Nome: %s\n", usuarios[i].nome);
        printf("Email: %s\n", usuarios[i].email);
        printf("Sexo: %s\n", usuarios[i].sexo);
        printf("Endereço: %s\n", usuarios[i].endereco);
        printf("Altura: %.2f\n", usuarios[i].altura);
        printf("Vacina: %d\n", usuarios[i].vacina);
    }
}
