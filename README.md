# Jogo de resgate c++ (ainda em desenvolvimento)
### Para jogar o jogo primeiro o compile executando no terminal o código (Linux)
```shell
g++ -o jogo -I include src/*cpp
```

### E depois execute o arquivo compilado
```shell
./jogo
```

# Estrutura do projeto (arquivos e pastas)
<div>
<img src="https://github.com/JoaoPauloFialho/imagens/blob/main/pastas.png" alt="arquivos" align="left" width="230rem"/>
<p>O projeto é organizado pelas pastas</p>
<p>include -> arquivos .h com os headers (arquivos de declaração das classes e constantes)</p>
<p>sprites -> sprites das entidades do jogo</p>
<p>src -> arquivos .cpp com a implementação dos métodos das classes</p>
<div/>

# Estrutura do projeto (principais classes)

### Classe Game
#### a classe Game é a principal classe do jogo e nela existe as operações para que o jogo funcione basicamente

### Classe ObjetoDoJogo
#### classe responsável por encapsular as informações das entidades do jogo e controla-las

### Classe SpriteAnimado
#### classe responsável por ler e salvar os sprites utilizados pelas entidades do jogo

# Configuração dos Sprites das entidades
#### Os sprites das entidades são criados em arquivos .txt e devem seguir um formato padrão
![imagem explicativa de como os sprites devem ser configurados](https://github.com/JoaoPauloFialho/imagens/blob/main/helicoptero.png)
#### Cada sprite deverá ser digitado no arquivo .txt, quando chegar ao final de cada sprite escreva uma linha com a seguinte string "proxsprite", você pode desenhar quantos sprites quiser, desde que siga a risca essa  configuração de digitar "proxsprite" sempre que quiser digitar outro sprite. Ao final, quando tiver digitado todos os sprites na ultima linha do arquivo .txt escreva a linha "fimsprite"

#### Depois é só instanciar a classe e passar o caminho do arquivo .txt dos sprites no construtor da entidade em questão

```c++
Helicoptero hel("sprites/helicoptero.txt",0 , 0);
```

#### OBS** Não faça sprites com largura e alturas diferentes, além de não ficar agradável aos olhos pode acabar gerando bugs, cheque no arquivo txt se cada sprite tem altura (quantidade de linhas) e largura (quantidade de caracteres em cada linha) iguais

#### OBS** O sprite que representa a base deve possuir 2 de altura, para evitar erros

