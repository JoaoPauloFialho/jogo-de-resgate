# Jogo de resgate c++ Linux (ainda em desenvolvimento)
### Se na sua máquina Linux não tiver o mpg321 (software livre utilizado para reprodução de mp3 via terminal) o instale
```shell
sudo apt update
sudo apt install mpg321
```
### Depois de instalado o mpg321 para jogar o jogo primeiro o compile executando no terminal o código (Linux)
```shell
g++ -o jogo -I include src/*cpp
```

### E depois execute o arquivo compilado
```shell
./jogo
```

### Se você quiser rodar o projeto no Windows será preciso mudar algumas coisinhas no projeto
#### Mude o paramêtro de system()
```c++
//mude esse comando 
system("clear");
//para esse
system("cls");
```
#### A classe Sound não funciona em Windows então exclua a sua implementação e o seu header e remova as sua instâncias na classe Fase

# Estrutura do projeto (arquivos e pastas)
<div>
<img src="https://github.com/JoaoPauloFialho/imagens/blob/main/Captura%20de%20tela%20de%202023-06-14%2015-59-08.png" alt="arquivos" align="left" width="250rem" height="180rem"/>
<p>O projeto é organizado pelas pastas</p>
<p>include -> arquivos .h com os headers (arquivos de declaração das classes e constantes)</p>
<p>sounds -> arquivo com os sons .mp3 utilizados pelo jogo</p>
<p>sprites -> sprites das entidades do jogo</p>
<p>src -> arquivos .cpp com a implementação dos métodos das classes</p>
<div/>

# Estrutura do projeto (principais classes)

### Classe Game
#### A classe Game é a classe mais importante do jogo, ela é responsável por controlar as fases ou seja, controlar o jogo em si

### Classe Fase
#### A classe Fase é a mais complexa classe do jogo e nela existe as operações para que o jogo funcione basicamente

### Classe ObjetoDoJogo
#### Classe responsável por encapsular as informações das entidades do jogo e controla-las

### Classe SpriteAnimado
#### Classe responsável por ler e salvar os sprites utilizados pelas entidades do jogo e controlar suas animações

# Configuração dos Sprites das entidades
#### Os sprites de cada entidade são criados em arquivo .txt único, por isso, devem seguir a risca a a configuração demonstrada a seguir
![imagem explicativa de como os sprites devem ser configurados](https://github.com/JoaoPauloFialho/imagens/blob/main/helicoptero.png)
#### Cada sprite deverá ser digitado no arquivo .txt, quando chegar ao final de cada sprite escreva uma linha com a seguinte string "proxsprite", você pode desenhar quantos sprites quiser, desde que siga a risca essa  configuração de digitar "proxsprite" sempre que quiser digitar outro sprite. Ao final, quando tiver digitado todos os sprites na ultima linha do arquivo .txt escreva a linha "fimsprite"

#### Depois é só instanciar a classe e passar o caminho do arquivo .txt dos sprites no construtor da entidade em questão

```c++
Helicoptero hel("sprites/helicoptero.txt",0 , 0);
```

#### OBS** Não faça sprites com largura e alturas diferentes, além de não ficar agradável aos olhos pode acabar gerando bugs, cheque no arquivo txt se cada sprite tem altura (quantidade de linhas) e largura (quantidade de caracteres em cada linha) iguais

#### OBS** Lembre de checar no arquivo de constantes no namespace jogo a altura e largura dos sprites da Base e Helicoptero, é muito importante isso para que o joyo funcione corretamente

