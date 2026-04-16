 <p align = "center">
    <img src="https://readme-typing-svg.herokuapp.com/?font=Fira+Code&size=50&pause=1000&color=00F7FF&center=true&vCenter=true&width=2000&lines=Resta+Um" />

 </p>

# ♟️ Resta Um

<div align="center">

![Badge Linguagem](https://img.shields.io/badge/Linguagem-C%2FC%2B%2B-blue?style=for-the-badge&logo=c%2B%2B)
![Badge Biblioteca](https://img.shields.io/badge/Biblioteca-Raylib-red?style=for-the-badge)
![Badge Plataforma](https://img.shields.io/badge/Plataforma-Windows-lightgrey?style=for-the-badge&logo=windows)
![Badge Status](https://img.shields.io/badge/Status-Concluído-brightgreen?style=for-the-badge)

> **Um clássico puzzle de tabuleiro reimaginado em C/C++ com gráficos 2D usando a Raylib.**

</div>

---

## 📸 Screenshots

<div align="center">

<!-- ===== COLOQUE AQUI A IMAGEM DA TELA INICIAL DO JOGO ===== -->
> 📷 *[Imagem — Tela Inicial / Menu]*

---

<!-- ===== COLOQUE AQUI A IMAGEM DO TABULEIRO DURANTE O JOGO ===== -->
> 📷 *[Imagem — assets/meio.pgm]*

---

<!-- ===== COLOQUE AQUI A IMAGEM DA TELA DE VITÓRIA OU GAME OVER ===== -->
> 📷 *[Imagem — Tela de Fim de Jogo / Recorde]*

</div>

---

## 🎯 Sobre o Jogo

**Resta Um** (também conhecido como *Peg Solitaire*) é um puzzle de tabuleiro solo onde o objetivo é eliminar o máximo de peças possível saltando uma sobre a outra — semelhante às capturas do jogo de damas.

- 🟤 O tabuleiro começa cheio de peças, com **apenas um buraco no centro**
- ♟️ Um movimento válido consiste em **saltar uma peça sobre outra adjacente** para uma casa vazia, removendo a peça saltada
- 🏆 O objetivo final é **restar apenas uma peça** no centro do tabuleiro

---

## ✨ Funcionalidades

- 🎮 Interface gráfica com **Raylib**
- 🖱️ Controle por **mouse** (clique para selecionar e mover peças)
- 🏅 Sistema de **recordes** salvo em arquivo (`recordes.txt`)
- 🔄 Opção de **reiniciar** a partida
- 📐 Arquitetura separada em **frontend** e **backend**

---

## 🗂️ Estrutura do Projeto

```
RestaUm/
│
├── main.cpp           # Ponto de entrada do programa
├── front.cpp          # Lógica de renderização (Raylib)
├── back.cpp           # Lógica do jogo (regras, movimentos)
├── dec_front.h        # Declarações do frontend
├── dec_back.h         # Declarações do backend
├── JButton.h          # Componente de botão customizado
├── recordes.txt       # Arquivo de recordes salvos
└── RestaUm.exe        # Executável compilado (Windows)
```

---

## 🚀 Como Executar

### ▶️ Executável direto (Windows)

Basta rodar o arquivo:
```
RestaUm.exe
```

### 🔧 Compilando do zero

**Pré-requisitos:**
- Compilador `g++` (MinGW recomendado no Windows)
- Biblioteca [Raylib](https://www.raylib.com/) instalada

**Comando de compilação:**
```bash
g++ main.cpp front.cpp back.cpp -o RestaUm -lraylib -lopengl32 -lgdi32 -lwinmm
```

---


## 🏆 Sistema de Recordes

O jogo salva automaticamente os melhores resultados no arquivo `recordes.txt`.

## 🛠️ Tecnologias Utilizadas

| Tecnologia | Uso |
|------------|-----|
| **C / C++** | Lógica principal do jogo |
| **Raylib** | Renderização gráfica 2D |
| **MinGW / g++** | Compilação no Windows |

---
 
## 🚀 Como Executar
 
### ▶️ Executável direto (Windows)
 
Basta rodar o arquivo:
```
RestaUm.exe
```
 
### 🔧 Compilando do zero
 
**Pré-requisitos:**
- Compilador `g++` (MinGW recomendado no Windows)
- Biblioteca [Raylib](https://www.raylib.com/) instalada
**Comando de compilação:**
```bash
g++ main.cpp front.cpp back.cpp -o RestaUm -lraylib -lopengl32 -lgdi32 -lwinmm
```
 
---
 
## 🕹️ Como Jogar
 
<!-- ===== COLOQUE AQUI UM GIF OU IMAGEM MOSTRANDO O GAMEPLAY ===== -->
> 📷 *[GIF ou Imagem — Demonstração do Gameplay]*
 
1. **Clique** em uma peça para selecioná-la (ela ficará destacada)
2. **Clique** na casa de destino (deve ser um salto válido sobre outra peça)
3. A peça do meio é **removida automaticamente**
4. Repita até não haver mais movimentos possíveis
5. Quando **sobrar uma peça**, Vitória!
---
 
## 🏆 Sistema de Recordes
 
O jogo salva automaticamente os melhores resultados no arquivo `recordes.txt`.
 
| 🥇 Posição | 👤 Jogador | ⏱️ Tempo          |
|:-----------:|:----------:|:-----------------:|
| 1º          | A          |       0:30        |
| 2º          | B          |       0:40        |
| 3º          | C          |       1:12        |
 
---
 
## 🛠️ Tecnologias Utilizadas
 
| Tecnologia | Uso |
|------------|-----|
| **C / C++** | Lógica principal do jogo |
| **Raylib** | Renderização gráfica 2D |
| **MinGW / g++** | Compilação no Windows |
 
---
 
 
## 👥 Equipe
 
Projeto desenvolvido em grupo acadêmico por:
 
| Integrante | GitHub |
|------------|--------|
| Nome 1 | [@username1](https://github.com/username1) |
| Nome 2 | [@username2](https://github.com/username2) |
| Nome 3 | [@username3](https://github.com/username3) |
| Nome 4 | [@username4](https://github.com/username4) |
 
<!-- ===== SUBSTITUA OS comentários acima pelos nomes e @ do GitHub de cada integrante ===== -->

## 📄 Licença

Este projeto está sob a licença **MIT**. Consulte o arquivo `LICENSE` para mais detalhes.

---

<div align="center">

Feito com ☕ e muito C++

</div>
