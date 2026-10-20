
# lib_estat
## Introdução
A biblioteca `lib_estat` é uma biblioteca em C criada para facilitar o cálculo de variáveis aleatórias e seus modelos de probabilidade, como o modelo de Poisson, o modelo Binomial, o modelo Uniforme e o modelo Geométrico. Além dos modelos, a biblioteca também calcula as estatísticas provenientes de cada modelo. A biblioteca contém 15 funções públicas, as quais estão distribuídas em 4 módulos.
 
A biblioteca contém, embutida em sua compilação, a opção de compilá-la estaticamente ou dinamicamente. Para a biblioteca estática, cria-se `libestat.a`; para a biblioteca dinâmica, `libestat.so`.
 
## Módulos
| Módulo | Funções |
|--------|---------|
| `esperanca` | `esperanca_binomial`, `esperanca_geometrica`, `esperanca_uniforme`, `esperanca_poisson` |
| `variancia_modelos` | `variancia_binomial`, `variancia_geometrica`, `variancia_uniforme`, `variancia_poisson` |
| `distribuicoes` | `probabilidade_binomial`, `probabilidade_geometrica`, `probabilidade_poisson`, `densidade_uniforme` |
| `correlacao` | `covariancia`, `correlacao`, `coeficiente_linear_regressao` |
 
## Pré-requisitos
Para compilar e utilizar a biblioteca, é necessário ter os seguintes pré-requisitos:
- Sistema operacional Linux
- Make
- Compilador `gcc`
- Doxygen para documentação (opcional)
- GDB (opcional)
## Estrutura
```text
./
├── Doxyfile (arquivo de configuração do Doxygen)
├── Makefile (instruções do Make)
├── README.md (documentação de como usar a biblioteca e suas funções)
├── app/ (contém a aplicação cliente, que demonstra a utilização da biblioteca)
│   └── main.c
├── bin/ (onde ficam os executáveis gerados, como os testes e a aplicação)
│   └── .gitkeep
├── build/ (contém arquivos intermediários de compilação, como os .o (arquivos objeto))
│   └── .gitkeep
├── docs/ (onde ficam a documentação e a saída do Doxygen)
│   ├── .gitkeep
│   └── relatorio/
│       └── relatorio.tex
├── include/ (contém as assinaturas e interfaces da biblioteca)
│   ├── correlacao.h
│   ├── distribuicoes.h
│   ├── erros.h
│   ├── esperanca.h
│   └── variancia_modelos.h
├── lib/ (após a compilação, onde ficam as bibliotecas estática .a e dinâmica .so)
│   └── .gitkeep
├── src/ (contém a implementação das funções da biblioteca)
│   ├── correlacao.c
│   ├── distribuicoes.c
│   ├── esperanca.c
│   └── variancia_modelos.c
└── tests/ (onde ficam os testes da biblioteca)
    ├── test_correlacao.c
    ├── test_distribuicoes.c
    ├── test_esperanca.c
    └── test_variancia_modelos.c
```
 
## Convenção de erro
| Código | Valor | Quando ocorre |
|--------|-------|---------------|
| `ESTAT_OK` | 0 | Quando não há nenhum erro |
| `ESTAT_ERRO_N_INVALIDO` | 1 | Quando o tamanho da amostra (ou o número de ensaios) é inválido (valores menores que 1) |
| `ESTAT_ERRO_TAMANHOS_DIFERENTES` | 2 | Reservado, mas nenhuma função o utiliza |
| `ESTAT_ERRO_DIVISAO_ZERO` | 3 | Quando ocorre uma divisão por zero, como `p` igual a 0 em `variancia_geometrica` |
| `ESTAT_ERRO_PARAMETRO_INVALIDO` | 4 | Quando o parâmetro utilizado não é válido, como `p` fora do intervalo [0,1], `a >= b` na distribuição uniforme, `lambda` negativo e array `NULL` na correlação |
 
Utiliza-se o ponteiro `erro` para atribuir o código de retorno de cada função. Caso a função tenha sucesso, `*erro` é igual a `ESTAT_OK`. Em caso de erro, a função retorna 0.0, e deve-se checar `*erro` para que se veja o motivo. O ponteiro nunca pode ser `NULL`, exceto nas funções do módulo `correlacao`, que aceitam `NULL` (nesse caso, nenhum código de erro é armazenado).
 
## Exemplos de Uso
 
Exemplo de programa que calcula a variância binomial.
 
```c
#include <stdio.h>
#include "variancia_modelos.h"
#include "erros.h"
 
int main(void)
{
    int erro;
    double resultado;
 
    /* Caso válido */
    resultado = variancia_binomial(10,0.5, &erro);
    if (erro == ESTAT_OK) {
        printf("passou = %f\n", resultado);
    } else {
        printf("erro: %d\n", erro);
    }
 
    /* Caso inválido */
    resultado = variancia_binomial(0, 0.5, &erro);
    if (erro == ESTAT_OK) {
        printf("passou = %f\n", resultado);
    } else {
        printf("erro: %d\n", erro);
    }
 
    return 0;
}
```
 
Para compilar e executar o exemplo (salvo como `exemplo.c`), a partir da raiz do projeto e depois de rodar `make`:
 
```bash
gcc -Iinclude exemplo.c lib/libestat.a -lm -o exemplo
./exemplo
```
 
Saída esperada:
 
```text
passou = 2.500000
erro: 1
```
 
O valor `1` da segunda linha corresponde a `ESTAT_ERRO_N_INVALIDO`, pois a segunda chamada usa `n = 0`.
 
## Compilação
 
Utiliza-se o comando `make` para executar o alvo padrão do Makefile (`all`), que compila as duas bibliotecas.
 
```bash
make
```
 
As bibliotecas são guardadas na pasta `lib/` e os arquivos intermediários ficam em `build/` (os da versão dinâmica, em `build/pic/`). Os executáveis, guardados em `bin/`, só são gerados pelos alvos de teste e de aplicação descritos abaixo.
 
A biblioteca dinâmica é compilada com `-fPIC` (código independente de posição), pois uma biblioteca compartilhada pode ser carregada em endereços diferentes da memória e ser usada por vários programas ao mesmo tempo.
 
O comando `make clean` apaga os arquivos gerados: os objetos (`*.o`) de `build/` e `build/pic/`, as bibliotecas (`*.a` e `*.so`) de `lib/` e os executáveis de `bin/` (`test_*`, `dyn_test_*`, `app` e `app_dyn`).
 
## Alvos do Makefile
 
| Alvo | O que faz | O que gera |
|------|-----------|------------|
| `all` | Compila as bibliotecas estática e dinâmica. | `lib/libestat.a` e `lib/libestat.so` |
| `test` | Compila os testes com a biblioteca estática e executa todos, mas para no primeiro que falhar. | `bin/test_*` |
| `test-dyn` | Compila os testes com a biblioteca dinâmica e executa todos com `LD_LIBRARY_PATH=lib`. | `bin/dyn_test_*` |
| `app` | Compila a aplicação cliente com a biblioteca estática (não a executa). | `bin/app` |
| `app-dyn` | Compila a aplicação cliente com a biblioteca dinâmica (não a executa). | `bin/app_dyn` |
| `clean` | Apaga os arquivos gerados em `build/`, `lib/` e `bin/`. | Nada |
| `run` | Compila e executa a aplicação com a biblioteca estática. | `bin/app` |
| `run-dyn` | Compila e executa a aplicação com a biblioteca dinâmica, usando `LD_LIBRARY_PATH=lib`. | `bin/app_dyn` |
| `install` | Copia as bibliotecas e os cabeçalhos para o prefixo `PREFIX`. | `$(PREFIX)/lib` e `$(PREFIX)/include` |
 
## Execução
 
Os alvos `app` e `app-dyn` apenas compilam a aplicação cliente. Para executá-la, rode o executável gerado.
 
Versão estática:
 
```bash
make app
./bin/app
```
 
Ela não precisa de configuração adicional, pois a biblioteca já está incorporada ao executável.
 
Versão dinâmica:
 
```bash
make app-dyn
LD_LIBRARY_PATH=lib ./bin/app_dyn
```
 
Essa versão depende da `libestat.so` em tempo de execução. Como a pasta `lib/` não está entre os diretórios padrão do sistema, sem a variável `LD_LIBRARY_PATH=lib` o carregador dinâmico não encontra a biblioteca e o programa falha com `error while loading shared libraries: libestat.so: cannot open shared object file`. É possível conferir isso com `ldd bin/app_dyn`.
 
A parte dinâmica foi validada apenas no Linux (com o `ldd`) e não foi testada no Mac.
 
## Testes
 
Utiliza-se o comando abaixo para executar todos os testes com a biblioteca estática.
 
```bash
make test
```
 
Cada teste imprime uma linha com o seu nome ao passar (no módulo `correlacao`, é impressa uma linha por grupo de testes: covariância, correlação e regressão). Caso algum teste falhe, o `assert` aborta o programa com uma mensagem de `Assertion failed` (o texto exato varia conforme o sistema) e o `make` interrompe a execução.
 
| Arquivo de teste | Módulo |
|------------------|--------|
| `tests/test_esperanca.c` | `esperanca` |
| `tests/test_variancia_modelos.c` | `variancia_modelos` |
| `tests/test_distribuicoes.c` | `distribuicoes` |
| `tests/test_correlacao.c` | `correlacao` |
 
O comando que roda os testes com a biblioteca dinâmica (validado apenas no Linux) é:
 
```bash
make test-dyn
```
 
## Uso em outro programa
 
Para compilar um programa próprio com a biblioteca, o usuário deve informar ao compilador as seguintes flags:
 
- `-I` diz onde estão os headers (`include/`).
- `-L` diz em que pasta ficam as bibliotecas (`lib/`).
- `-l` escolhe a biblioteca pelo nome (`estat`, sem o prefixo `lib` e sem a extensão).
- `-lm` liga a biblioteca matemática do C.
Com a biblioteca estática (caminho direto para o arquivo `.a`):
 
```bash
gcc -Iinclude programa.c lib/libestat.a -lm -o programa
```
 
Com a biblioteca dinâmica:
 
```bash
gcc -Iinclude programa.c -Llib -lestat -lm -o programa
```
 
No Linux, quando as duas versões existem em `lib/`, o `-lestat` escolhe a dinâmica.
 
Para rodar o programa gerado na versão dinâmica, é necessário informar onde está a biblioteca:
 
```bash
LD_LIBRARY_PATH=lib ./programa
```
 
## Instalação

O alvo `install` copia `libestat.a` e `libestat.so` para `$(PREFIX)/lib` e os cabeçalhos de `include/` para `$(PREFIX)/include`. O prefixo pode ser alterado, então a instalação não exige privilégios de administrador:

```bash
make install PREFIX=$HOME/.local
```

Para compilar um programa com a biblioteca instalada:

```bash
gcc -I$HOME/.local/include programa.c -L$HOME/.local/lib -lestat -lm -o programa
LD_LIBRARY_PATH=$HOME/.local/lib ./programa
```

O `LD_LIBRARY_PATH` é necessário porque, com `-lestat`, o linker escolhe a biblioteca dinâmica quando as duas existem na mesma pasta.

## Documentação com Doxygen
 
O Doxygen gera páginas HTML a partir dos comentários dos headers em `include/`, e este README é usado como página principal.
 
```bash
doxygen Doxyfile
```
 
Depois, o usuário abre o arquivo `docs/html/index.html` no navegador.
 
Em cada uma das 15 funções estão documentados os campos `@brief`, `@param`, `@return` e `@note`.
 
A pasta `docs/html/` está no `.gitignore` e não vai para o repositório. Por isso, cada usuário deve gerar a sua própria documentação.
 
 

