#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <time.h>

#define tam1 1000
//#define tam1 1000000
//#define tam1 10000000
//#define tam1 100000000
//#define tam1 1000000000

/*  
	Autor: Flávio Ramos
	Matrícula: 4809

 */

using namespace std;

//Árvore pesquisa
typedef struct sReg{
	int chave;

}Registro;

typedef struct sTabela{
	Registro *elementos;
	int ultimo;
}Tabela;

void inicializar(Tabela *t,int tam){
  t->elementos = (Registro*)malloc(tam*sizeof(Registro));
	t->ultimo = -1;
}

int pesquisar(Tabela *t, int p){
	int i = -1;
	while((t->elementos[i+1].chave != p) && (i <= t->ultimo)){
		i++;
	}
	return i;
}

void imprimirListaSequencial(Tabela *t){
	for(int c = 0; c < t->ultimo +1; c++){
		cout << t->elementos[c].chave << endl;
	}
}

int inserir(Tabela *t, Registro p){
	if(t->ultimo == tam1){
		return 0;
	}
	t->elementos[t->ultimo+1] = p;
	t->ultimo++;
}

int retElemento(Tabela *t, int pos){

	return t->elementos[pos].chave;
}

int pesquisaBinaria(Tabela *t, int p){
	int i,esq,dir;
	if(t->ultimo == -1){
		return 0;
	}else{
		esq = 1;
		dir = t->ultimo;
		do{
			i = (esq + dir)/2;
			if(p > t->elementos[i].chave){
				esq = i + 1;
			}else{
				dir = i - 1;
			}
		}while(p != t->elementos[i].chave && esq <= dir);
		if(p == t->elementos[i].chave){
			return i;
		}else{
			return -1;
		}
	}
}

//Árvore binária
typedef struct tree
{
  int num;
  struct tree* sad;
  struct tree* sae;
} Tree;

/* A estrutura da árvore é representada por um ponteiro
   para o nó raiz. Com esse ponteiro, temos acesso aos
   demais nós. */

/* Função que cria uma árvore */
Tree* createTree()
{
  /* Uma árvore é representada pelo endereço do nó raiz,
     essa função cria uma árvore com nenhum elemento,
     ou seja, cria uma árvore vazia, por isso retorna NULL. */
  return NULL;
}

/* Função que verifica se uma árvore é vazia */
int treeIsEmpty(Tree* t)
{
  /* Retorna 1 se a árvore for vazia e 0 caso contrário */
  return t == NULL;

}

/* Função que insere um dado na árvore */
void insertTree(Tree** t, int num)
{
  /* Essa função insere os elementos de forma recursiva */
  if(*t == NULL)
  {
    *t = (Tree*)malloc(sizeof(Tree)); /* Aloca memória para a estrutura */
    (*t)->sae = NULL; /* Subárvore à esquerda é NULL */
    (*t)->sad = NULL; /* Subárvore à direita é NULL */
    (*t)->num = num; /* Armazena a informação */
  } else {
    if(num < (*t)->num) /* Se o número for menor então vai pra esquerda */
    {
      /* Percorre pela subárvore à esquerda */
      insertTree(&(*t)->sae, num);
    }
    if(num > (*t)->num) /* Se o número for maior então vai pra direita */
    {
      /* Percorre pela subárvore à direita */
      insertTree(&(*t)->sad, num);
    }
  }
}

/* Função que verifica se um elemento pertence ou não à árvore */
int isInTree(Tree* t, int num) {
  
  if(treeIsEmpty(t)) { /* Se a árvore estiver vazia, então retorna 0 */
    return 0;
  }
  
  /* O operador lógico || interrompe a busca quando o elemento for encontrado */
  return t->num==num || isInTree(t->sae, num) || isInTree(t->sad, num);
}


class pratica{
	
	public:

~pratica(){
	//delete [] vetor;
}


void setTempoGastoArvoreBinaria(float t){
	this->tempoGastoArvoreBinaria = t;
}

float getTempoGastoArvoreBinaria(){
	return this->tempoGastoArvoreBinaria;
}

void setTempoGastoPesquisaS(float t){
	this->tempoGastoPesquisaS = t;
}

float getTempoGastoPesquisaS(){
	return this->tempoGastoPesquisaS;
}

void setTempoGastoPesquisaB(float t){
	this->tempoGastoPesquisaB = t;
}

float getTempoGastoPesquisaB(){
	return this->tempoGastoPesquisaB;
}

void setTempoGastoShell(float t){
	this->tempoGastoShell = t;
}

float getTempoGastoShell(){
	return this->tempoGastoShell;
}

void setTempoGastoBubble(float t){
	this->tempoGastoBubble = t;
}

float getTempoGastoBubble(){
	return this->tempoGastoBubble;
}

void setTempoGastoInsertion(float t){
	this->tempoGastoInsertion = t;
}

float getTempoGastoInsertion(){
	return this->tempoGastoInsertion;
}

void setTempoGastoMerge(float t){
	this->tempoGastoMerge = t;
}

float getTempoGastoMerge(){
	return this->tempoGastoMerge;
}

void setTempoGastoSelection(float t){
	this->tempoGastoSelection = t;
}

float getTempoGastoSelection(){
	return this->tempoGastoSelection;
}

void setTempoGastoHeap(float t){
	this->tempoGastoHeap = t;
}

float getTempoGastoHeap(){
	return this->tempoGastoHeap;
}

void setTempoGastoQuick(float t){
	this->tempoGastoQuick = t;
}

float getTempoGastoQuick(){
	return this->tempoGastoQuick;
}

void setTamanhoV(int t){
	this->tamVetor = t;
}

int getTamanhoV(){
	return this->tamVetor;
}

void setTempoGastohashingLista(float t){
	this->tempoGastohashingLista = t;
}

float getTempoGastohashingLista(){
	return this->tempoGastohashingLista;
}

void setTempoGastohashingEnderecamento(float t){
	this->tempoGastohashingEnderecamento = t;
}

float getTempoGastohashingEnderecamento(){
	return this->tempoGastohashingEnderecamento;
}

float getTempoGastoProcuraMax(){
	return this->tempoGastoProcuraMax;
}

float getTempoGastoProcuraMinMax1(){
	return this->tempoGastoProcuraMinMax1;
}

float getTempoGastoProcuraMinMax2(){
	return this->tempoGastoProcuraMinMax2;
}

float getTempoGastoProcuraMinMax3(){
	return this->tempoGastoProcuraMinMax3;
}

void setTempoGastoProcuraMax(float t){
	this->tempoGastoProcuraMax;
}

void setTempoGastoProcuraMinMax1(float t){
	this->tempoGastoProcuraMinMax1 = t;
}

void setTempoGastoProcuraMinMax2(float t){
	this->tempoGastoProcuraMinMax2 = t;
}

void setTempoGastoProcuraMinMax3(float t){
	this->tempoGastoProcuraMinMax3 = t;
}

void bubbleSort(int *vet, int length){
	int i, j, temp, x = 0;

	for (i = 0; i < length - 1; i++){
        for (j = (i+1); j < length; j++){
            if (vet[j] < vet[i]){
                temp = vet[i];
                vet[i] = vet[j];
                vet[j] = temp;
            }
        }
x++;
cout << x << "bubble" << endl;
    }
}

void shellSort(int *vetor, int tam){
	int i,j,h = 1;
	do{
		h = 3 * h + 1;
	}while(h < tam);

	do{
		h/=3;
		for(i = h + 1; i <= tam; i++){
			int x = vetor[i];
      j = i;
			while(vetor[j-h] > x){
				vetor[j] = vetor[j - h];
				j -= h;
				if(j <= h){
					goto Rotulo;
				}
			}
			Rotulo: vetor[j] = x;
		}
	}while(h != 1);
}

void selectionSort(int *vetor, int tam){
		int i,j, x = 0;
		float tempo1;
		for(i = 0; i < tam; i++){
			int minIndex = i;
			for(j = i+1; j <=tam; j++){
				

				if(vetor[minIndex] > vetor[j]){
					minIndex = j;
				}
			}
			int temp = vetor[i];
			vetor[i] = vetor[minIndex];
			vetor[minIndex] = temp;
			x++;
			cout << x << "selection" << endl;		
	}
}

void insertionSort(int *vetor, int tam){
	
	int i,j, r = 0;
	for(i = 1; i < tam; i++){
		j = i-1;
		int x = vetor[i];
		while(x < vetor[j] && j >= 0){
			vetor[j + 1] = vetor[j];
			vetor[j] = x;
			j--;
		}
r++;
cout << r << "insertion" << endl;
	}	
}

void merge(int *vetor, int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }
    
    free(vetAux);
}

void mergeSort(int *vetor, int comeco, int fim){
	if (comeco < fim) {
        int meio = (fim+comeco)/2;
        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

void quickSort(int *vetor, int began, int end){
	int i, j, pivo, aux;
	i = began;
	j = end-1;
	pivo = vetor[(began + end) / 2];
	while(i <= j) {
		while(vetor[i] < pivo && i < end) {
			i++;
		}
		while(vetor[j] > pivo && j > began)	{
			j--;
		}
		if(i <= j){
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i++;
			j--;
		}
	}
	if(j > began)
		quickSort(vetor, began, j+1);
	if(i < end)
		quickSort(vetor, i, end);
}

void heapSort(int *a, int n){
	int i = n / 2, pai, filho, t;
   while(true) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n == 0) return;
          t = a[n];
          a[n] = a[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
   }
}

void imprimeVetor(int *vetor, int tam){
	for(int c = 0; c < tam; c++){
		cout << vetor[c] << endl;
	}
}

	private:
		float tempoGastoPesquisaS;
		float tempoGastoArvoreBinaria;
		float tempoGastoPesquisaB;
		float tempoGastoQuick;
		float tempoGastoHeap;
		float tempoGastoShell;
		float tempoGastoSelection;
		float tempoGastoInsertion;
		float tempoGastoMerge;
		float tempoGastoBubble;
		float tempoGastohashingLista;
		float tempoGastohashingEnderecamento;
		int tamVetor;
		float tempoGastoProcuraMax;
		float tempoGastoProcuraMinMax1;
		float tempoGastoProcuraMinMax2;
		float tempoGastoProcuraMinMax3;

};

void imprimirVetor(int *vetor, int tam){
	for(int c = 0; c < tam; c++){
		cout << vetor[c] << endl;
	}
}

int preencheTad(Tabela *t, Registro r,int tam){
char *palavra;
char line[50];
int valor;
FILE *a;
a = fopen("vetorCriado.txt","r");

		while(!feof(a)){
			fscanf(a,"%d",&valor);
			r.chave = valor;
			//cout << valor << endl;
			inserir(t,r);
		}
fclose(a);

return 0;
}

int preencheTadOrdenado(Tabela *t, Registro r,int tam){

int valor;
FILE *a;
a = fopen("vetorOrdenado.txt","r");

		while(!feof(a)){
			fscanf(a,"%d",&valor);
			r.chave = valor;
			inserir(t,r);
		}
fclose(a);


return 0;
}

int pesquisaSequencial(Tabela *t, int p){
	int i = -1;
	while((t->elementos[i+1].chave != p) && (i <= t->ultimo)){
		i++;
	}
	return i+=1;

return 0;
}

int arvoreBinaria(){

}

int pesquisaHashingLista(){

}

int pesquisaHashingEndrecamento(){

}

int procuraMax(Tabela *t, int tam){
	int i, max = t->elementos[0].chave;
		for(i = 1; i < tam; i++){
			if(max < t->elementos[i].chave){
				max = t->elementos[i].chave;
			}
		}
}

int procuraMinMax1(Tabela *t, int tam){

	int i,min,max;
	max = t->elementos[0].chave;
	min = t->elementos[0].chave;
		for(i = 1; i < tam; i++){
			if(t->elementos[i].chave < min){
				min = t->elementos[i].chave;
			}if(t->elementos[i].chave > max){
				max = t->elementos[i].chave;
			}
		}
}

int procuraMinMax2(Tabela *t, int tam){
	int i, min, max;
	max = t->elementos[0].chave;
	min = t->elementos[0].chave;
		for(i = 1; i < tam; i++){
			if(t->elementos[i].chave < min){
				min = t->elementos[i].chave;
			}else if(t->elementos[i].chave > max){
				max = t->elementos[i].chave;
			}
		}
}

int procuraMinMax3(Tabela *t, int n){
	int i, fimAnel, min, max;
	if(n % 2 != 0){
		t->elementos[n].chave = t->elementos[n-1].chave;
		fimAnel = n;
	}else{
		fimAnel = n-1;
	}
	if(t->elementos[0].chave > t->elementos[1].chave){
		max = t->elementos[0].chave;
		min = t->elementos[1].chave;
	}else{
		max = t->elementos[1].chave;
		min = t->elementos[0].chave;	
	}
	for(i = 3; i <= fimAnel; i += 2){
		if(t->elementos[i-1].chave > t->elementos[i].chave){
			if(t->elementos[i-1].chave > max){
				max = t->elementos[i-1].chave;
			}

			if(t->elementos[i].chave < min){
				min = t->elementos[i].chave;
			}

		}else{
			if(t->elementos[i].chave > max){
				max = t->elementos[i].chave;
			}

			if(t->elementos[i-1].chave < min){
				min = t->elementos[i-1].chave;
			}
		}
	}
}

void showTree(Tree* t)
{
  /* Essa função imprime os elementos de forma recursiva */
  
  //printf("<"); /* notação para organizar na hora de mostrar os elementos */
  if(!treeIsEmpty(t)) /* se a árvore não for vazia... */
  {
    /* Mostra os elementos em pré-ordem */
    printf("%d\n ", t->num); /* mostra a raiz */
    showTree(t->sae); /* mostra a sae (subárvore à esquerda) */
    showTree(t->sad); /* mostra a sad (subárvore à direita) */
  }
}

int main(){
int respostaP = 0;
do{

float tempo;
char palavra[255];
int resposta, tamV, tam, i, valor, retorno, v;
pratica p;
cout << "----------------------------------------" << endl;
	cout << "Informe os valores de entrada:" << endl;
	cout << "----------------------------------------" << endl;	
	cout << "[1] 1.000" << endl;
	cout << "[2] 10.000" << endl;
	cout << "[3] 100.000" << endl;
	cout << "[4] 1000.000" << endl;
	cout << "----------------------------------------" << endl;
	cout << "Informe o tamanho da entrada: " << endl;
	cin >> tam;
tamV = 1000000;
	if(tam == 1){
		tamV = 1000;
		p.setTamanhoV(tamV);
	}else if(tam == 2){
		tamV = 10000;
		p.setTamanhoV(tamV);
	}else if(tam == 3){
		tamV = 100000;
		p.setTamanhoV(tamV);
	}else if(tam == 4){
		tamV = 1000000;
		p.setTamanhoV(tamV);
	}else{
		cout << " Valor incorreto" << endl;
	}

	FILE *u;
	u = fopen("arquivoDados.txt","w");
		fprintf(u,"%s\n\n","============================================================================");
		fprintf(u,"%s\n\n"," Programa executado em um processador i5 e espaço de memória principal de 8g");
		fprintf(u,"%s","                     Tamanho da entrada de dados: ");
		fprintf(u,"%d\n",tamV);
		fprintf(u,"%s\n\n","============================================================================");
	fclose(u);

Tabela t;
Tree* arv = createTree();
Registro re;
inicializar(&t,tamV);

int *vetor = new int[tamV];
int *vetorSelection = new int[tamV];
int *vetorInsertion = new int[tamV];
int *vetorBubble = new int[tamV];
int *vetorMerge = new int[tamV];
int *vetorShell = new int[tamV];
int *vetorQuick = new int[tamV];
int *vetorHeap = new int[tamV];

FILE *arq1;
arq1 = fopen("vetorCriado.txt","w");

srand((unsigned)time(NULL));

for(i = 0; i < tamV ; i++){
	valor = rand();
	if(valor <= 0){
		continue;
	}else{
		vetor[i] = valor;
		fprintf(arq1,"%d\n",valor);
	}
}
fclose(arq1);

p.shellSort(vetor,tamV);

FILE *arq2;
FILE *arq3;
arq2 = fopen("vetorOrdenado.txt","w");
arq3 = fopen("vetorDecrescente.txt","w");
for(i = 0; i < tamV ; i++){
	valor = vetor[i];
	sprintf(palavra,"%d",valor);
	fprintf(arq2,"%s\n",palavra);
}

for(i = tamV; i > 0 ; i--){
	valor = vetor[i];
	sprintf(palavra,"%d",valor);
	fprintf(arq3,"%s\n",palavra);
}
fclose(arq3);
fclose(arq2);
do{
	cout << "=======================================" << endl;
	cout << "                  MENU                 " << endl;
	cout << "=======================================" << endl;
	cout << "[1] Pesquisa Sequêncial" << endl;
	cout << "[2] Pesquisa Binária" << endl;
	cout << "[3] Árvore Binária" << endl;
	cout << "[4] Ordenar vetores" << endl;
	cout << "[5] Procurar o Max e Min" << endl;
	cout << "[6] Sair" << endl;
	cout << "=======================================" << endl;
	cin >> resposta;
	switch(resposta){
	case 1:
		preencheTad(&t,re,tamV);
		cout << "Informe um valor: " << endl;
		cin >> v;
		tempo = 0;
		tempo = clock();
		retorno = pesquisaSequencial(&t,v);
		p.setTempoGastoPesquisaS((clock() - tempo)/(double)CLOCKS_PER_SEC);	
		if(v == t.elementos[retorno].chave){
			cout << "Valor encontrado na posicão " << retorno << endl;
		}else{
			cout << "Valor não encontrado" << endl;
		}

		FILE *a;
		a = fopen("arquivoDados.txt","a");
			fprintf(a,"%s\n","============================================================================");
			fprintf(a,"%s\n\n","              Dado referente ao tempo gasto pela pesquisa sequêncial");
			fprintf(a,"%s","                     Tempo Gasto: ");
			fprintf(a,"%f\n",p.getTempoGastoPesquisaS());
			fprintf(a,"%s\n\n","============================================================================");
		fclose(a);
		break;
	case 2:
		inicializar(&t,tamV);
		preencheTadOrdenado(&t,re,tamV);
		cout << "Informe um valor: " << endl;
		cin >> v;
		tempo = 0;
		tempo = clock();
		retorno = pesquisaBinaria(&t,v);
		p.setTempoGastoPesquisaB((clock() - tempo)/(double)CLOCKS_PER_SEC);	
		if(v == t.elementos[retorno].chave){
			cout << "Valor encontrado na posicao " << retorno << endl;
		}else{
			cout << "Valor não encontrado" << endl;
		}

		FILE *b;
		b = fopen("arquivoDados.txt","a");
			fprintf(b,"%s\n","============================================================================");
			fprintf(b,"%s\n\n","              Dado referente ao tempo gasto pela pesquisa binária");
			fprintf(b,"%s","                    Tempo Gasto: ");
			fprintf(b,"%f\n",p.getTempoGastoPesquisaB());
			fprintf(b,"%s\n\n","============================================================================");
		fclose(b);
		break;
	case 3:
		char *palavra;
		char line[50];
		int valor;
		FILE *ba;
		ba = fopen("vetorCriado.txt","r");

		while(!feof(ba)){
			fscanf(ba,"%d",&valor);
			insertTree(&arv,valor);
		}

		cout << "Informe um valor: " << endl;
		cin >> v;
		tempo = 0;
		tempo = clock();
		if(isInTree(arv,v)){

		p.setTempoGastoArvoreBinaria((clock() - tempo)/(double)CLOCKS_PER_SEC);	
			cout << "Valor encontrado  "<< endl;
		}else{
			cout << "Valor não encontrado" << endl;
		}

fclose(ba);

FILE *pa;
	pa = fopen("arquivoDados.txt","a");
	fprintf(pa,"%s\n","============================================================================");
	fprintf(pa,"%s\n\n","            Dados referente ao tempo gasto para busca árvore binária");

	fprintf(pa,"%s","                    Tempo Gasto árvore Binária: ");
	fprintf(pa,"%f\n",p.getTempoGastoArvoreBinaria());
	fprintf(pa,"%s\n","============================================================================-");

fclose(pa);
		//showTree(arv);
		break;
	case 4:
	i = 0;
	FILE *x;
	int tipo;
	cout << "Informe o tipo de arquivo acessar" << endl;
	cout << "[1] Vetor aleatório" << endl;
	cout << "[2] Vetor crescente" << endl;
	cout << "[3] Vetor vetor decrescente" << endl;
	cin >> tipo;

if(tipo == 1 ){
	x = fopen("vetorCriado.txt","r");
}else if(tipo == 2){
		x = fopen("vetorOrdenado.txt","r");
}else if(tipo == 3){
		x = fopen("vetorDecrescente.txt","r");
}
	while(!feof(x)){
		fscanf(x,"%d",&valor);
		vetorSelection[i] = valor;
		vetorInsertion[i] = valor;
		vetorBubble[i] = valor;
		vetorMerge[i] = valor;
		vetorShell[i] = valor;
		vetorHeap[i] = valor;
		vetorQuick[i] = valor;
		i++;
	}

	fclose(x);

	tempo = 0;
	tempo = clock();
	p.selectionSort(vetorSelection,tamV);
	p.setTempoGastoSelection((clock() - tempo)/(double)CLOCKS_PER_SEC);

	tempo = 0;
	tempo = clock();
	p.bubbleSort(vetorBubble,tamV);
	p.setTempoGastoBubble((clock() - tempo)/(double)CLOCKS_PER_SEC);
	tempo = 0;
	tempo = clock();
	p.insertionSort(vetorInsertion,tamV);
	p.setTempoGastoInsertion((clock() - tempo)/(double)CLOCKS_PER_SEC);

	tempo = 0;
	tempo = clock();
	p.shellSort(vetorShell,tamV);
	p.setTempoGastoShell((clock() - tempo)/(double)CLOCKS_PER_SEC);

	tempo = 0;
	tempo = clock();
	p.mergeSort(vetorMerge,1,tamV);
	p.setTempoGastoMerge((clock() - tempo)/(double)CLOCKS_PER_SEC);	
	tempo = 0;
	tempo = clock();
	p.heapSort(vetorHeap,tamV);
	p.setTempoGastoHeap((clock() - tempo)/(double)CLOCKS_PER_SEC);	
	tempo = 0;
	tempo = clock();
	p.quickSort(vetorQuick,1,tamV);
	p.setTempoGastoQuick((clock() - tempo)/(double)CLOCKS_PER_SEC);

FILE *y;
y = fopen("arquivoDados.txt","a");
	fprintf(y,"%s\n","============================================================================");
	fprintf(y,"%s\n\n","                Dados referente ao tempo gasto para ordenação");
	fprintf(y,"%s","                    Tempo Gasto Insertion Sort: ");
	fprintf(y,"%f\n",p.getTempoGastoInsertion());
	fprintf(y,"%s","                    Tempo Gasto Selection Sort: ");
	fprintf(y,"%f\n",p.getTempoGastoSelection());
	fprintf(y,"%s","                    Tempo Gasto Shell Sort: ");
	fprintf(y,"%f\n",p.getTempoGastoShell());
	fprintf(y,"%s","                    Tempo Gasto Merge Sort: ");
	fprintf(y,"%f\n",p.getTempoGastoMerge());
	fprintf(y,"%s","                    Tempo Gasto Quick Sort: ");
	fprintf(y,"%f\n",p.getTempoGastoQuick());				
	fprintf(y,"%s","                    Tempo Gasto Heap Sort: ");
	fprintf(y,"%f\n",p.getTempoGastoHeap());	
	fprintf(y,"%s","                    Tempo Gasto Bubble Sort: ");
	fprintf(y,"%f\n",p.getTempoGastoBubble());	
	fprintf(y,"%s\n\n","============================================================================");
fclose(y);
	break;
	
	case 5:
	preencheTad(&t,re,tamV);
	float aux1,aux2,aux3,aux4;
	tempo = 0;
	tempo = clock();
	retorno = procuraMax(&t,tamV);
	aux1 = ((clock() - tempo)/(double)CLOCKS_PER_SEC); 
	
	tempo = 0;
	tempo = clock();
	procuraMinMax1(&t,tamV);
	aux2 = ((clock() - tempo)/(double)CLOCKS_PER_SEC);

	tempo = 0;
	tempo = clock();
	procuraMinMax2(&t,tamV);
	aux3 = ((clock() - tempo)/(double)CLOCKS_PER_SEC);	

	tempo = 0;
	tempo = clock();
	procuraMinMax3(&t,tamV);
	aux4 = ((clock() - tempo)/(double)CLOCKS_PER_SEC);

	FILE *p;
	p = fopen("arquivoDados.txt","a");
	fprintf(p,"%s\n","============================================================================");
	fprintf(p,"%s\n\n","                  Dados referente ao tempo gasto para busca");

	fprintf(p,"%s","                    Tempo Gasto procuraMax: ");
	fprintf(p,"%f\n",aux1);
	fprintf(p,"%s\n","----------------------------------------------------------------------------");
	
	fprintf(p,"%s","                    Tempo Gasto procuraMinMax1: ");
	fprintf(p,"%f\n",aux2);
	
	fprintf(p,"%s\n","----------------------------------------------------------------------------");
	fprintf(p,"%s","                    Tempo Gasto procuraMinMax2: ");
	fprintf(p,"%f\n",aux3);
;
	fprintf(p,"%s\n","----------------------------------------------------------------------------");
	fprintf(p,"%s","                    Tempo Gasto procuraMinMax3: ");
	fprintf(p,"%f\n",aux4);
	fprintf(p,"%s\n\n","==========================================================================");
	fclose(p);
	break;
	case 6:
		cout << "Saindo..." << endl;
	break;
	
}
}while(resposta != 6);
FILE * an;
an = fopen("arquivoDados.txt","r");
size_t len= 255; // valor arbitrário
char *linha= (char*)malloc(len);
		while (getline(&linha, &len, an) > 0) {
    		printf("%s", linha);
  		}
cout << "Criar outro caso de uso?" << endl;
cin >> respostaP;

}while(respostaP != 0 );
return 0;
}


