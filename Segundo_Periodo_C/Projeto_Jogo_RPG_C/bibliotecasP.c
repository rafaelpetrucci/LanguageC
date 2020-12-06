#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>
#include <time.h>

// Variáveis globais
int life = 100;
int vidaBase = 50;
int vida = 50; //personagem
int level = 1;
int xp = 100;
int danoBasePersonagem = 5;
int danoBaseMonstro;
int boss = 0;

void historia(){
    if(boss == 0){
        batalha1();
    }
    else if(boss == 1){
        batalha2();
    }
    else if(boss == 2){
        batalha3();
    }
    else{
        fimJogo();
    }
}

void menu(){
    imprimirMenu();
    int escolha;
    printf("                            1 -> Iniciar Jogo\n");
    printf("                            2 -> Resumo\n");
    printf("                            3 -> Creditos\n");
    printf("                            4 -> Sair do Jogo\n\n");
    printf("                            -> ");
    scanf("%d", &escolha);
    opcoes(escolha);
}

void menuSecundario(){
    imprimirMenu();
    int escolha;
    printf("                            1 -> Continuar História\n");
    printf("                            2 -> Treinamento\n");
    printf("                            3 -> Casa\n");
    printf("                            4 -> Voltar ao Menu Principal (Reseta o jogo)\n\n");
    printf("                            -> ");
    scanf("%d", &escolha);
    opcoesSecundario(escolha);
}

void opcoesSecundario(int opcao){
    int continuar = 1;
    int verdadeiro = 0;
    if(opcao == 1){
        clear();
        historia();
    }else if(opcao == 2){
        clear();
        treinamento();
    }else if(opcao == 3){
        clear();
        casa();
    }
    else if(opcao == 4){
        clear();
        main();
    }
    else{
        clear();
        menuSecundario();
    }
}


void opcoes(int opcao){
    int continuar = 1;
    if(opcao == 4){
        exit(0);
    }
    else if(opcao == 2){
        clear();
        resumo();
    }else if(opcao == 3){
        clear();
        creditos();
    }else if(opcao == 1){ //First
        do{
            clear();
            introducao();
            dragaoInicio();
            continuar = introducao2();
        }while(continuar != 0);
        clear();
    }
    else{
        menu();
    }
}

void resumo(){
    char text[] = "O clube dos Garanhoes foi formado no ano de 1980 por um grupo de 3 adolescentes,Fabrício, Arthur, Rafael, onde na escola se teve a ideia de formar este grupo para combater o mau a fora, na hora, não passava de 3 adolescentes com sonhos estranhos, mau sabiam que iam se tornar o clube de maior reputação em Tyrondir..";
    charPorChar(text);
    printf("\n\n");
    imprimirLogo();
}

void treinamento(){
    for(int i = 0; i < 10; i++){
        imprimirTreinamento1();
        sleep(1);
        clear();
        imprimirTreinamento2();
        sleep(1);
        clear();
    }
    xp = 0;
    verificaLevel();
    sleep(3);
    clear();
    menuSecundario();
}

void casa(){
    for (int i = 0; i < 5; i++){
        imprimirCasa1();
        sleep(1);
        clear();
        imprimirCasa2();
        sleep(1);
        clear();
        imprimirCasa3();
        sleep(1);
        clear();
        imprimirCasa4();
        sleep(1);
        clear();
    }
    vida = vidaBase;
    verificaLevel();
    sleep(3);
    clear();
    menuSecundario();
}

void imprimirTreinamento1(){
    printf("                    \n");
    printf("           ___      \n");
    printf("      /   /^-^\\     \n");
    printf("   O / <=========>  \n");
    printf("  /|/     |_|      \n");
    printf("  \ |      |_|      \n");
    printf("   /\\     |_|      \n");
    printf("  /  \\    | |      \n");
}

void imprimirTreinamento2(){
    printf("                    \n");
    printf("           ___      \n");
    printf("          /0~0\\     \n");
    printf("   O    <========>  \n");
    printf("  /|\______*\\_\\     \n");
    printf("  \ |      *|_|     \n");
    printf("   /\\      |_|     \n");
    printf("  /  \\    /_/      \n");
}

void imprimirCasa1(){
    printf("                            \n");
    printf("                            \n");
    printf("                            \n");
    printf("             __ z           \n");
    printf("     _______|  |____        \n");
    printf("    / / / / / / / / /\\      \n");
    printf("   / / / / / / / / /  \\     \n");
    printf("  / / / / / / / / /    \\    \n");
    printf(" /_/_/_/_/_/_/_/_/______\\   \n");
    printf("  |   _____        ___ |    \n");
    printf("  |  |__|__|       |  ||    \n");
    printf("  |  |__|__|       |* ||    \n");
    printf("  |________________|__||    \n");
}

void imprimirCasa2(){
    printf("                            \n");
    printf("                            \n");
    printf("                 z          \n");
    printf("             __ z           \n");
    printf("     _______|  |____        \n");
    printf("    / / / / / / / / /\\      \n");
    printf("   / / / / / / / / /  \\     \n");
    printf("  / / / / / / / / /    \\    \n");
    printf(" /_/_/_/_/_/_/_/_/______\\   \n");
    printf("  |   _____        ___ |    \n");
    printf("  |  |__|__|       |  ||    \n");
    printf("  |  |__|__|       |* ||    \n");
    printf("  |________________|__||    \n");
}

void imprimirCasa3(){
    printf("                            \n");
    printf("                  Z         \n");
    printf("                 z          \n");
    printf("             __ z           \n");
    printf("     _______|  |____        \n");
    printf("    / / / / / / / / /\\      \n");
    printf("   / / / / / / / / /  \\     \n");
    printf("  / / / / / / / / /    \\    \n");
    printf(" /_/_/_/_/_/_/_/_/______\\   \n");
    printf("  |   _____        ___ |    \n");
    printf("  |  |__|__|       |  ||    \n");
    printf("  |  |__|__|       |* ||    \n");
    printf("  |________________|__||    \n");
}

void imprimirCasa4(){
    printf("                   Z        \n");
    printf("                  Z         \n");
    printf("                 z          \n");
    printf("             __ z           \n");
    printf("     _______|  |____        \n");
    printf("    / / / / / / / / /\\      \n");
    printf("   / / / / / / / / /  \\     \n");
    printf("  / / / / / / / / /    \\    \n");
    printf(" /_/_/_/_/_/_/_/_/______\\   \n");
    printf("  |   _____        ___ |    \n");
    printf("  |  |__|__|       |  ||    \n");
    printf("  |  |__|__|       |* ||    \n");
    printf("  |________________|__||    \n");
}


void creditos(){
    int voltar;
    printf(".   ║\.\n");
    printf("    ║▒\.            ---------------------------------- \n");
    printf("    ║▒▒                         GRUPO\n");
    printf("    ║░▒ ║           ----------------------------------\n");
    printf("    ║░▒║\n");
    printf("    ║░▒ ║                      .Fabrício Moura\n");
    printf("    ║░▒║                       .Arthur Amaral\n");
    printf("    ║░▒║                       .Rafael Petrucci\n");
    printf("    ║░▒ ║\n");
    printf("    ║░▒║\n");
    printf("    ║░▒ ║\n");
    printf("    ║░▒║\n");
    printf("▓▓▓▓▓▓▓\n");
    printf("     ]█▓[\n");
    printf("     ]█▓[\n");
    printf("     ]█▓[\n");
    printf("\n");
    printf("\n");
    printf("                                0 -> Voltar\n");
    printf("                                  -> ");
    scanf("%d",&voltar);
    if(voltar == 0){
        clear();
        main();
    }
}

void imprimirMenu(){
    printf("─▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄                                    ─▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄ \n");
    printf("█░░░█░░░░░░░░░░▄▄░██░█-----------------------------------█░░░█░░░░░░░░░░▄▄░██░█\n");
    printf("█░▀▀█▀▀░▄▀░▄▀░░▀▀░▄▄░█         Clube dos Garanhoes       █░▀▀█▀▀░▄▀░▄▀░░▀▀░▄▄░█\n");
    printf("█░░░▀░░░▄▄▄▄▄░░██░▀▀░█-----------------------------------█░░░▀░░░▄▄▄▄▄░░██░▀▀░█\n");
    printf("─▀▄▄▄▄▄▀─────▀▄▄▄▄▄▄▀                                    ─▀▄▄▄▄▄▀─────▀▄▄▄▄▄▄▀\n\n");

}

void imprimirLogo(){
    int voltar;
    printf("                            ░░░░░▄▄▀▀▀▀▀▀▀▀▀▄▄░░░░░\n");
    printf("                            ░░░░█░░░░░░░░░░░░░█░░░░\n");
    printf("                            ░░░█░░░░░░░░░░▄▄▄░░█░░░\n");
    printf("                            ░░░█░░▄▄▄░░▄░░███░░█░░░\n");
    printf("                            ░░░▄█░▄░░░▀▀▀░░░▄░█▄░░░\n");
    printf("                            ░░░█░░▀█▀█▀█▀█▀█▀░░█░░░\n");
    printf("                            ░░░█░░░░░░░░░░▄▄▄░░█░░░\n");
    printf("                            ░▄█░█▀▀█▀▀▀█▀▀▀█▀▀█░█▄░\n");
    printf("                            ▄▀░▄▄▀▄▄▀▀▀▄▀▀▀▄▄▀▄▄░▀▄\n");
    printf("                             █░░░░▀▄░█▄░░░▄█░▄▀░░░░█\n");
    printf("                            ░▀▄▄░█░░█▄▄▄▄▄█░░█░▄▄▀░\n");
    printf("                            ░░░▀██▄▄███████▄▄██▀░░░\n");
    printf("                            ░░░████████▀████████░░░\n");
    printf("                            ░░▄▄█▀▀▀▀█░░░█▀▀▀▀█▄▄░░\n");
    printf("                            ░░▀▄▄▄▄▄▀▀░░░▀▀▄▄▄▄▄▀░\n");
    printf("\n");
    printf("                                0 -> Voltar\n");
    printf("                                  -> ");
    scanf("%d",&voltar);
    if(voltar == 0){
        clear();
        main();
    }
}

void dragaoInicio(){
    printf("                                             __----~~~~~~~~~~~------___\n");
    printf("                                  .  .   ~~//====......          __--~ ~~\n");
    printf("                  -.            \_|//     |||\\  ~~~~~~::::... /~\n");
    printf("               ___-==_       _-~o~  \/    |||  \\            _/~~-\n");
    printf("       __---~~~.==~||\=_    -_--~/_-~|-   |\\   \\        _/~\n");
    printf("   _-~~     .=~    |  \\-_    '-~7  /-   /  ||    \      /\n");
    printf(" .~       .~       |   \\ -_    /  /-   /   ||      \   /\n");
    printf("/  ____  /         |     \\ ~-_/  /|- _/   .||       \ /\n");
    printf("|~~    ~~|--~~~~--_ \     ~==-/   | \~--===~~        .\"\n");
    printf("         '         ~-|      /|    |-~\~~       __--~~\n");
    printf("                     |-~~-_/ |    |   ~\_   _-~            /\"\n");
    printf("                          /  \     \__   \/~                \__\n");
    printf("                      _--~ _/ | .-~~____--~-/                  ~~==.\n");
    printf("                     ((->/~   '.|||' -_|    ~~-/ ,              . _||\n");
    printf("                                -_     ~\      ~~---l__i__i__i--~~_/\n");
    printf("                                _-~-__   ~)  \--______________--~~\n");
    printf("                              //.-~~~-~_--~- |-------~~~~~~~~\n");
    printf("                                     //.-~~~--\"\n");
    sleep(2);
}

void dragaoMob(){
    printf("                              ______________   \n");
    printf("                        ,===:'.,            `-._  \n");
    printf("                             `:.`---.__         `-._              \n");
    printf("                               `:.     `--.         `.            \n");
    printf("                                 \\.        `.         `.           \n");
    printf("                         (,,(,    \\.         `.   ____,-`.,  \n");
    printf("                      (,'     `/   \\.   ,--.___`.'  \n");
    printf("                  ,  ,'  ,--.  `,   \\.;'\n");
    printf("                   `{D, {    \\  :    \;\n");
    printf("       O             V,,'    /  /    //\n");
    printf("      /|/D           j;;    /  ,' ,-//.    ,---.      ,        Habilidades:\n");
    printf("     / |             \\;'   /    ,'  _  \\__/  _  \\   ,'/    1 -> Golpe de Furia\n");
    printf("      /\\                   \\       / \\      / \\   \\/ /     2 -> Bola de Fogo\n");
    printf("     / /                    `.___,'   `.__,'   `.__,'      3 -> Dash\n");
    printf("\n--------------------------------------------------------------------------------\n");
    printf("\n");
}

void dragaoMob2(){
    printf("                                             _,,,.._       ,_\n");
    printf("                                          .gMMMMMMMMMp,_    `\\n");
    printf("                                                        .dMMP'       ``^YMb..dP\n");
    printf("                                      dMMP'\n");
    printf("                                      MMM:\n");
    printf("                                      YMMb.\n");
    printf("                                       YMMMb.\n");
    printf("                                        `YMM/|Mb.  ,__\n");
    printf("                                     _,,-~`--..-~-'_,/`--,,,____\n");
    printf("                                 `\,_,/',_.-~_..-~/' ,/---~~~""""\n");
    printf("                            _,_,,,\q\q/'    \,,-~'_,/`````-,7.\n");
    printf("                          `@v@`\\,,,,__"   "\,,-~~""__/` "",,/MMMMb.\n");
    printf("                            `--''_..-~~\   \,-~~""  `\_,/ `^YMMMMMb..\n");
    printf("                             ,|``-~~--./_,,_  _,,-~~'/_      `YMMMMMMMb.\n");
    printf("                           ,/  `\,_,,/`\    `\,___,,,/M/'      `YMMMMMMMb\n");
    printf("                                       ;  _,,/__...|MMM/         YMMMMMMMb\n");
    printf("                                        .' /'      dMMM\         !MMMMMMMMb\n");
    printf("                                     ,-'.-'""~~~--/M|M' \        !MMMMMMMMM\n");
    printf("                                   ,/ .|...._____/MMM\   b       gMMMMMMMMM\n");
    printf("                                ,'/'\/          dMMP/'   M.     ,MMMMMMMMMP\n");
    printf("                               / `\;/~~~~----...MP'     ,MMb..,dMMMMMMMMM'\n");
    printf("                              / ,_  |          _/      dMMMMMMMMMMMMMMMMB\n");
    printf("                              \  |\,\,,,,___ _/    _,dMMMMMMMMMMMP""emmmb,\n");
    printf("                               `.\  gY.     /      7MMMMMMMMMMP""emmMMMMM\n");
    printf("                                  .dMMMb,-..|       `.~~""""```|""dMMMMP'MMP'\n");
    printf(" O                                .MMMMP^""""/ .7 ,  _  \,""----""`""YMMP'MM;\n");
    printf("/|/D                            _dMMMP'   ,' / | |\ \\  }          PM^M^b\n");
    printf("/|                            _,' _,  \_.._`./  } ; \ \``'      __,'_` _  `._\n");
    printf("/\                        ,-~/'./'| 7`,,__,}`   ``   ``        // _/`| 7``-._`}\n");
    printf("/ /                    |_,}__{  {,/'   ``                    `\{_  {,/'   ``\n");
    printf("\n\n\n");
    printf("\n--------------------------------------------------------------------------------\n");
    printf("1 -> Golpe de Furia\n");
    printf("2 -> Bola de Fogo\n");
    printf("3 -> Dash\n");
    printf("\n--------------------------------------------------------------------------------\n");
}

void dragaoMob3(){
    printf("                                              ==(W{==========-      /===-     \n");
    printf("                                                 ||  (.--.)         /===-_---~\n");
    printf("                                                 | \_,|**|,__      |===-~___  \n");
    printf("                                    -==\\        `\ ' `--'   ),    `//~\\   ~~\n");
    printf("                                 ______-==|        /`\_. .__/\ \    | |  \\   \n");
    printf("                           __--~~~  ,-/-==\\      (   | .  |~~~~|   | |   `\  \n");
    printf("                        _-~       /'    |  \\     )__/==0==-\<>/   / /      \ \n");
    printf("                      .'        /       |   \\      /~\_v_/~~\/  /' /         \n");
    printf("                     /  ____  /         |    \`\.__/-~~   \  |_/'  /          \n");
    printf("                    /-'~    ~~~~~---__  |     ~-/~         ( )   /'        _--\n");
    printf("                                      \_|      /        _) | ;  ),   __--~~   \n");
    printf("                                        '~~--_/      _-~/- |/ \   '-~ \       \n");
    printf("                                       {\__--_/}    / \\_>-|)<__\      \      \n");
    printf("                                       /'   (_/  _-~  | |__>--<__|      |     \n");
    printf("                                      |   _/) )-~     | |__>--<__|      |     \n");
    printf("                                      / /~ ,_/       / /__>---<__/      |     \n");
    printf("                                     o-o _//        /-~_>---<__-~      /      \n");
    printf("                                     (^(~          /~_>---<__-      _-~       \n");
    printf("                                    ,/|           /__>--<__/     _-~          \n");
    printf("                                 ,//('(          |__>--<__|     /             \n");
    printf("                                 ( ( '))         |__>--<__|    |              \n");
    printf("                             `-)) )) (           |__>--<__|    |              \n");
    printf("                             ,/,'//( (            \__>--<__\    \            /\n");
    printf("     _  /                   ,( ( ((, ))             ~-__>--<_~-_  ~--____---~'\n");
    printf("    |O|/                `~/  )` ) ,/|                 ~-_~>--<_/-__       __-~\n");
    printf("   _/|/               ._-~//( )/ )) `                    ~~-'_/_/ /~~~~~~~__- \n");
    printf("  <V>|                 ;'( ')/ ,)(                              ~~~~~~~~~~    \n");
    printf("    /\\                 ' ') '( (/                                            \n");
    printf("   /_/_                  '   '  `                                             \n");
    printf("\n\n");
    printf("\n--------------------------------------------------------------------------------\n");
    printf("1 -> Golpe de Furia\n");
    printf("2 -> Bola de Fogo\n");
    printf("3 -> Dash\n");
    printf("\n--------------------------------------------------------------------------------\n");
}


void introducao(){
    char text[] = "Campanha onde o Clube dos Garanhões são contratados para uma simples escolta de um comerciante, saindo da fronteira de Deheon e indo para Cosamhir, capital de Tyrondir. Mas no caminho ficam presos numa cidade sendo atacada por dragões da Aliança Negra que conseguiram furar o bloqueio do Exército do Reinado. Mas a verdade é bem pior e eles acabam descobrindo um grande plano da Aliança Negra para invadir Dozza por passagens subterrâneas. Cabe aos clube dos garanhões fazer algo para que a AN não realize seu plano.";
    charPorChar(text);
    printf("\n\n\n");
}

int introducao2(){
    int continuar;
    printf("\n\n");
    char text[] = "Depois de escoltarem o comerciante, o Clube dos Garanhões procuram um lugar para dormir na cidade quando se deparam com uma criatura estranha, algo não estava certo...";
    charPorChar(text);
    printf("\n\n\n                             0 -> Continuar\n");
    printf("                               -> ");
    scanf("%d", &continuar);
    return continuar;
}

void historico(int *valor, int tamanho){
    for(int i = 0; i < tamanho; i = i + 3){
        if(valor[i] == 1){
            printf("Golpe de Furia -     Dano %d     XXXXXXXXXXX     O Dragao lhe deu %d de Dano\n", valor[i + 1], valor[i + 2]);
        }else if(valor[i] == 2){
            printf("Bola de Fogo   -     Dano %d     XXXXXXXXXXX     O Dragao lhe deu %d de Dano\n", valor[i + 1], valor[i + 2]);
        }else if(valor[i] == 3){
            printf("Dash           -     Dano %d     XXXXXXXXXXX     O Dragao lhe deu %d de Dano\n", valor[i + 1], valor[i + 2]);
        }
    }
}

void escolhaSkill(int indice, int *array){
    int skill, dano, danoMonstro;
    printf("Escolha a habilidade-> ");
    scanf("%d", &skill);
    srand(time(NULL));
    danoMonstro = (rand() % 10) + danoBaseMonstro;
    if(skill == 1){
        dano = (danoBasePersonagem + 20) - (rand() % 10);
        life = life - dano;
        vida = vida - danoMonstro;
        array[indice] = 1;
        array[indice + 1] = dano;
        array[indice + 2] = danoMonstro;
        indice = indice + 3;
    }else if(skill == 2){
        dano = (danoBasePersonagem + 15) - (rand() % 8);
        life = life - dano;
        vida = vida - danoMonstro;
        array[indice] = 2;
        array[indice + 1] = dano;
        array[indice + 2] = danoMonstro;
        indice = indice + 3;
    }else if(skill == 3){
        dano = (danoBasePersonagem + 10) - (rand() % 10);
        life = life - dano;
        vida = vida - danoMonstro;
        array[indice] = 3;
        array[indice + 1] = dano;
        array[indice + 2] = danoMonstro;
        indice = indice + 3;
    }
}

void verificaLevel(){
    if(xp <= 0){
        level++;
        xp = 100 * level;
        vidaBase = vidaBase + 25;
        vida = vidaBase;
        danoBasePersonagem = danoBasePersonagem + 15;
    }
    printf("\n----------------------------------   Status   ----------------------------------\n");
    printf("\n--------------------------------------------------------------------------------\n");
    printf("Vida: %d\nLevel: %d\nDano: %d\n\n", vida, level, danoBasePersonagem);
    sleep(3);
}

void batalha1(){
    int array[40];
    life = 90;
    int indice = 0;
    danoBaseMonstro = 2;
    while (life > 0){
        printf("                        PrEpArE-sE pArA bAtAlHa!!!                      \n\n");
        dragaoMob();
        printf("HP PERSONAGEM: %d                                        HP BOSS: %d", vida, life);
        printf("\n");
        printf("\n--------------------------------------------------------------------------------\n");
        if(indice > 0){
            printf("--- Histórico de Batalha ---\n\n");
            historico(&array, indice);
        }
        printf("\n--------------------------------------------------------------------------------\n");
        escolhaSkill(indice, &array);
        if (vida <= 0){
            gameOver();
            return 0;
        }
        indice = indice + 3;
        clear();
    }
    xp = xp - 100;
    dragaoMob();
    vitoria();
    boss++;
    verificaLevel();
    char text[] = "Parabens! Você passou pelo primeiro monstro, agora faltam 2, sua jornada ainda não terminou!";
    charPorChar(text);
    sleep(3);
    clear();
    menuSecundario();
}

void batalha2(){
    int array[40];
    life = 250;
    int indice = 0;
    danoBaseMonstro = 10;
    while (life > 0){
        printf("                        PrEpArE-sE pArA bAtAlHa!!!                      \n\n");
        dragaoMob2();
        printf("HP PERSONAGEM: %d                                        HP BOSS: %d", vida, life);
        printf("\n");
        printf("\n--------------------------------------------------------------------------------\n");
        if(indice > 0){
            printf("--- Histórico de Batalha ---\n\n");
            historico(&array, indice);
        }
        printf("\n--------------------------------------------------------------------------------\n");
        escolhaSkill(indice, &array);
        if (vida <= 0){
            gameOver();
            return 0;
        }
        indice = indice + 3;
        clear();
    }
    xp = xp - 200;
    dragaoMob2();
    vitoria();
    boss++;
    verificaLevel();
    char text[] = "Muito bem! agora você tem acesso a sala do boss final, acho melhor dar uma treinada antes..";
    charPorChar(text);
    sleep(3);
    clear();
    menuSecundario();
}

void batalha3(){
    textoFinal();
    int array[40];
    life = 400;
    int indice = 0;
    danoBaseMonstro = 15;
    while (life > 0){
        printf("                        PrEpArE-sE pArA bAtAlHa!!!                      \n\n");
        dragaoMob3();
        printf("HP PERSONAGEM: %d                                        HP BOSS: %d", vida, life);
        printf("\n");
        printf("\n--------------------------------------------------------------------------------\n");
        if(indice > 0){
            printf("--- Histórico de Batalha ---\n\n");
            historico(&array, indice);
        }
        printf("\n--------------------------------------------------------------------------------\n");
        escolhaSkill(indice, &array);
        if (vida <= 0){
            gameOver();
            return 0;
        }
        indice = indice + 3;
        clear();
    }
    xp = xp - 200;
    dragaoMob3();
    vitoria();
    boss++;
    verificaLevel();
    char text[] = "Muito bem! agora você tem acesso a sala do boss final, acho melhor dar uma treinada antes..";
    charPorChar(text);
    sleep(3);
    clear();
    fimJogo();
}

void vitoria(){
    life = 0;
    printf("HP PERSONAGEM: %d                                        HP BOSS: %d", vida, life);
    printf("\n");
    printf("\n--------------------------------------------------------------------------------\n");
    printf("-------------------------- O nosso heroi saiu vitorioso ------------------------\n");
    printf("--------------------------------------------------------------------------------\n");
}

void gameOver(){
    clear();
    printf("\n");
    printf("\n--------------------------------------------------------------------------------\n");
    printf("---------------------------------- Game Over -----------------------------------\n");
    printf("--------------------------------- Você Morreu ----------------------------------\n");
    printf("\n--------------------------------------------------------------------------------\n");
    sleep(3);
    clear();
    reseta();
    main();
    historia();
}
void reseta(){
     life = 100;
     vidaBase = 50;
     vida = 50; //personagem
     level = 1;
     xp = 100;
     danoBasePersonagem = 5;
     danoBaseMonstro;
     boss = 0;
}

void textoFinal(){
    char text[] = "Se você chegou até aqui, parabens, mas Tyrondir ainda precisa ser liberada, você treinou bastante para chegar aqui, mas não ache que vai ser fácil, a Aliança Negra é muito poderosa..";
    charPorChar(text);
    sleep(3);
    clear();
}

void caracteres(){
    for(int i = 0; i< 8000000; i++);
}

void charPorChar(char *text){
    int tamanho = strlen(text);
    for(int i = 0; i < tamanho; i++) {
        caracteres();
        putchar(text[i]);
        fflush(stdout);
    }
    sleep(2);
}

void fimJogo(){
    clear();
    char text[] = "PARABENS, VOCÊ FOI ESSENCIAL PARA ESTA VITÓRIA!\nTyrondir agradece a sua ajuda...";
    charPorChar(text);
    printf("\n\n\n");

    char text1[] = "Para você comprar a versão oficial, acesse www.clubedosgaranhoes.com.br";
    charPorChar(text1);
    printf("\n\n");
    sleep(1);
    creditos();

}

void clear(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}
