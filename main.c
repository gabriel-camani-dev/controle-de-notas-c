#include <stdio.h>
#define ALUNOS 2
#define PROVAS 2

void cadastrarAluno(int matriculas[ALUNOS]){
    for(int i = 0; i<ALUNOS; i++){
        printf("Digite a Matricula do Aluno %d: ", i+1);
        scanf("%d", &matriculas[i]);
    }
}

void cadastrarNota(int matriculas[ALUNOS],float notas[ALUNOS][PROVAS]){
    for(int i = 0; i<ALUNOS; i++){
        for(int j=0; j<PROVAS;j++){
        printf("Digite a Nota da Prova [%d] do Aluno associado a matricula [%d]: ",j+1, matriculas[i]);
        scanf("%f", &notas[i][j]);
    
        }
    }
    
}

void listarAlunos(int matriculas[ALUNOS],float notas[ALUNOS][PROVAS],float mediaPorAluno[ALUNOS]){
        for(int i = 0; i<ALUNOS; i++){
        printf("Aluno [%d]| matricula: %d | Nota 1: %.2f | Nota 2: %.2f | Media: %.2f\n", i+1,matriculas[i],notas[i][0],notas[i][1],mediaPorAluno[i]);
    }
}

float calcMedia(float notas[ALUNOS][PROVAS]){
    float soma =0;

    for(int i = 0; i<ALUNOS; i++){
        for(int j=0; j<PROVAS; j++){
            soma += notas[i][j];
        }
    }

    return soma / (PROVAS * ALUNOS);
}

void mediaAlunos(float notas[ALUNOS][PROVAS], float mediaAluno[ALUNOS]){

        for(int i = 0; i<ALUNOS; i++){
        float soma = 0;
        for(int j=0; j<PROVAS; j++){
            soma += notas[i][j];
        }
        mediaAluno[i] = soma/PROVAS;
    }

}

float maiorMedia(float mediaAlunos[ALUNOS]){
        float maior = mediaAlunos[0];
        for(int i = 0; i<ALUNOS; i++){
      if(maior < mediaAlunos[i]) maior=mediaAlunos[i];
    }
    return maior;
}
float menorMedia(float mediaAlunos[ALUNOS]){
        float menor = mediaAlunos[0];
        for(int i = 0; i<ALUNOS; i++){
      if(menor > mediaAlunos[i]) menor=mediaAlunos[i];
    }
    return menor;
}
int main(){

    int opcao = 0;
    int cadastroRealizado = 0;

    int matriculas[ALUNOS];
    float notas[ALUNOS][PROVAS];
    float media=0;
    float mediaPorAluno[ALUNOS];
    float maiorMediaIndividual = 0;
    float menorMediaIndividual = 0;

    do {
    printf("============================\n");
    printf("     CONTROLE DE NOTAS\n");
    printf("============================\n");

    printf("1 - Cadastrar alunos e notas\n");
    printf("2 - Listar alunos\n");
    printf("3 - Calcular media da turma\n");
    printf("4 - Mostrar maior e menor media\n");
    printf("5 - Buscar aluno\n");
    printf("0 - Sair\n");

    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch(opcao){

    default:
        printf("Digite uma das opcoes validas.\n");
        break;

    case 1:

    cadastrarAluno(matriculas);
    cadastrarNota(matriculas,notas);
    cadastroRealizado = 1;
        break;

    case 2:

    if(cadastroRealizado == 0){
        printf("Nenhum cadastro realizado.\n");
    }
    else {
    mediaAlunos(notas,mediaPorAluno);
    listarAlunos(matriculas,notas,mediaPorAluno);
        }
        break;

    case 3:

    if(cadastroRealizado == 0){
        printf("Nenhum cadastro foi realizado.\n");
    }
    else {
        media = calcMedia(notas);
    printf("Media da turma: %.2f\n",media);
     }
        break;

    case 4:

    if(cadastroRealizado == 0){
        printf("Nenhum cadastro realizado\n");
    }
    else {
    mediaAlunos(notas,mediaPorAluno);
    maiorMediaIndividual = maiorMedia(mediaPorAluno);
    menorMediaIndividual = menorMedia(mediaPorAluno);
    printf("Maior media individual: %.2f\n",maiorMediaIndividual); 
    printf("Menor media individual: %.2f\n",menorMediaIndividual); 
    }
        break;

    case 5:

        if(cadastroRealizado == 0){
        printf("Nenhum cadastro realizado\n");
    }
    else {
        mediaAlunos(notas,mediaPorAluno);
        int matriculatest = 0;
        int encontrado = 0;
        printf("Insira a matricula do Aluno que esta procurando: ");
        scanf("%d",&matriculatest);

        for(int i =0; i<ALUNOS; i++){
            if(matriculatest == matriculas[i]){ 
                encontrado = 1;

                printf("Aluno: %d || Nota1: %.2f |Nota2: %.2f || Media: %.2f\n",matriculas[i],notas[i][0],notas[i][1],mediaPorAluno[i]);
            }
    }
    if(encontrado == 0) printf("O aluno nao foi encontrado.\n");
        
 }
        break;

    case 0:
        printf("Encerrando programa...\n");

}

} while (opcao != 0);
    

    return 0;
    }


