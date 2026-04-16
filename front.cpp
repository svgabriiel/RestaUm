#include "dec_back.h"
#include "dec_front.h"


float startTime = 0.0f;
float timeElapsed;
int minutos;
int segundos;
char textoTimer[50];
int restaPart;

Part tabuleiro[TAM][TAM];

int i_atual = 0, j_atual = 0;
int aux_ci, aux_cj;
int clique_atual = CLIQUE_PRIMEIRO;

bool jaSalvou = false; 

bool temaAtual = true;
Color corBotao = BROWN;
Color corFundo = BEIGE;
Color corPeca  = DARKBROWN;
Color corTabu  = BROWN;
Color corTabuF = DARKBROWN;
Color corTime  = BLACK;
Color corERRO  = WHITE;

Rectangle borda;

bool trocarTema(void)
{
    temaAtual = !temaAtual;

    if (temaAtual)
    {
        corFundo = BEIGE;
        corPeca  = DARKBROWN;
        corBotao = BROWN;
        corTabu  = BROWN;
        corTabuF = DARKBROWN;
        corTime  = BLACK;
        corERRO  = WHITE;
    }
    else
    {
        corFundo = BLACK;
        corPeca  = PURPLE;
        corBotao = DARKPURPLE;
        corTabu  = DARKPURPLE;
        corTabuF = PURPLE;
        corTime  = GOLD;
        corERRO  = RED;
    }

    return temaAtual;
}

void imprimeTabuleiro(Part tabuleiro[TAM][TAM], int i_aux, int j_aux, int clique_atual)
{
    DrawRectangleRec(fundoMaior, corTabuF);
    DrawRectangleRec(fundoMenor, corTabu);

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (tabuleiro[i][j].state == N_EXIST)
                continue;

            Color cor = (tabuleiro[i][j].state == VAZIO) ? LIGHTGRAY : corPeca;
            DrawCircleV(tabuleiro[i][j].pos, raio, cor);

            for (float o = 0.2; o < 3; o++)
                DrawCircleLinesV(tabuleiro[i][j].pos, raio + o, BLACK);

            if (jogadaValida(tabuleiro))
            {
                if(clique_atual==CLIQUE_SEGUNDO)
                    for(float c = 0.2; c<4;c++){
                        DrawCircleLinesV(tabuleiro[aux_ci][aux_cj].pos, raio + c, GOLD);
                    }

                int movimento = calculeMovimento(i_atual, j_atual, i_aux, j_aux);
                if (movimento == MOVIMENTO_VALIDO && tabuleiro[i_aux][j_aux].state == VAZIO)
                {
                    for (float i = 0.2; i < 4; i++)
                        DrawCircleLinesV(tabuleiro[i_aux][j_aux].pos, raio + i, GREEN);
                }

                if (i == i_aux && j == j_aux)
                {
                    bool Mov = jogadaValida(tabuleiro, i, j);
                    Color Cor = Mov ? GREEN : RED;
                    if (clique_atual == CLIQUE_SEGUNDO)
                        Cor = RED;
                    for (float k = 0.5; k < 4; k++)
                        DrawCircleLinesV(tabuleiro[i][j].pos, raio + k, Cor);
                }
            }
        }
    }
}

bool locateButton(Rectangle button)
{
    Vector2 mouse = GetMousePosition();
    return (mouse.x > button.x && mouse.x < button.x + button.width &&
            mouse.y > button.y && mouse.y < button.y + button.height);
}

Rectangle expandRectangle(Rectangle button, float border_size)
{
    Rectangle expanded = button;
    expanded.x = button.x - border_size;
    expanded.y = button.y - border_size;
    expanded.width = button.width + border_size * 2;
    expanded.height = button.height + border_size * 2;
    return expanded;
}

void Emblema(void)
{
    DrawText("Resta Um", inicioX - 60, inicioY, 100, corPeca);
    if (locateButton(startButton))
    {
        borda = expandRectangle(startButton, 4);
        DrawRectangleRec(borda, GREEN);
    }
    DrawRectangleRec(startButton, corBotao);
    DrawText("START", screenWidth / 2 - 43, screenHeight / 2 + 70, 25, BLACK);
}

void Titulo(void)
{
    int size =15;
    DrawText("----- RESTA UM -----", screenWidth / 3, 50, 30, corPeca);

    if (locateButton(resetButton))
    {
        // size++;
        borda = expandRectangle(resetButton, size);
        DrawRectangleRec(borda, GREEN);
        size++;
    }

    if (locateButton(themeButton))
    {
        // size--;
        borda = expandRectangle(themeButton, size);
        DrawRectangleRec(borda, GREEN);
        size--;
    }

    DisplayTimer();

    if (!jogadaValida(tabuleiro))
    {
        if (restaPart == 1)
        {   
            salvarRecorde();
            if(!DisplayTimer())
            DrawText("!!! VITORIA !!!", 100, 50, 30, RED);
        }
        else
        {
            DrawText("FIM DE JOGO", screenWidth / 3 + 30, 2, 40, RED);
            DrawText(TextFormat("Restaram: %d", restaPart), 25, 70, 30, corPeca);
        }
    }
    else jaSalvou= false; // add

    DrawRectangleRec(resetButton, corBotao);
    DrawRectangleRec(themeButton, corBotao);
    DrawText("RESET", 835, 615, 20, BLACK);
    DrawText("TEMA", 45, 615, 20, BLACK);
}


int DisplayTimer(void)
{
    int mim, seg;

    timeElapsed = GetTime() - startTime;
    bool valida = jogadaValida(tabuleiro);

    if (valida) {
        mim = (int)timeElapsed / 60;
        seg = (int)timeElapsed % 60;
    }

    int exibMin = valida ? mim : (int)timeElapsed / 60;
    int exibSeg = valida ? seg : (int)timeElapsed % 60;

    sprintf(textoTimer, "Tempo: %02d:%02d", exibMin, exibSeg);
    DrawText(textoTimer, 675, 20, 25, corTime);

    if (valida && ((int)timeElapsed & 1))
        return 1;

    return 0;
}

void salvarRecorde(void)//add
{
     
    if (jaSalvou) return;

    Recorde temp[MAX_RECORDES];
    int qtd = carrega_recordes(temp);
    if (qtd >= MAX_RECORDES) return;

    char proxLetra = 'A' + qtd;
    salvarRecorde(proxLetra, timeElapsed);
    jaSalvou = true;
}
