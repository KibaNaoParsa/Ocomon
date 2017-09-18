#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <locale.h>
#include <exception>


using namespace std;

char enter;

int contest = 4;

int contesp = 4;

struct ocomon {
    int dp, atk, cod, odx;
    float def;
    string nome, atk1, atk2, atk3, atk4;
    int ppa1, ppa2, ppa3, ppa4;
    int finalidade;
};

void Pause (float delay1) {
   if (delay1<0.001) return;
   float inst1=0, inst2=0;
   inst1 = (float)clock()/(float)CLOCKS_PER_SEC;
   while (inst2-inst1<delay1) inst2 = (float)clock()/(float)CLOCKS_PER_SEC;
   return;
}

void Lifebar(ocomon a[4], int ativo1) {
    if (a[ativo1].dp <= 0) {
        cout << "|          |";
    }
    if ((a[ativo1].dp > 0) && (a[ativo1].dp <= 400)) {
        cout << "|-         |";
    }
    if ((a[ativo1].dp > 400) && (a[ativo1].dp <= 800)) {
        cout << "|--         |";
    }
    if ((a[ativo1].dp > 800) && (a[ativo1].dp <= 1200)) {
        cout << "|---        |";
    }
    if ((a[ativo1].dp > 1200) && (a[ativo1].dp <= 1600)) {
        cout << "|----       |";
    }
    if ((a[ativo1].dp > 1600) && (a[ativo1].dp <= 2000)) {
        cout << "|-----      |";
    }
    if ((a[ativo1].dp > 2000) && (a[ativo1].dp <= 2400)) {
        cout << "|------     |";
    }
    if ((a[ativo1].dp > 2400) && (a[ativo1].dp <= 2800)) {
        cout << "|-------    |";
    }
    if ((a[ativo1].dp > 2800) && (a[ativo1].dp <= 3200)) {
        cout << "|--------   |";
    }
    if ((a[ativo1].dp > 3200) && (a[ativo1].dp <= 3600)) {
        cout << "|---------  |";
    }
    if ((a[ativo1].dp > 3600) && (a[ativo1].dp < 4000)) {
        cout << "|---------- |";
    }
    if (a[ativo1].dp >= 4000) {
        cout << "|-----------|";
    }
}

int Evasao (ocomon a[4], int ativo2) {
    float def = a[ativo2].def;
    float ev = def/1000;
    ev = ev*10;
    int vfc = rand()%100;
    vfc++;
    if (vfc <= ev) {
        return 1;
    } else {
        return 0;
    }
}

int MiniMenu() {
    cout << "=======================================================================" << endl;
    cout << " 1. Ataques                                            2. Estatísticas" << endl;
    cout << " 3. Trocar Ocomon                                      4. Sair        " << endl;
	cout << "=======================================================================" << endl;
    int minimenu;
    cin >> minimenu;
    if ((minimenu < 1) || (minimenu > 4)) {
        throw out_of_range("Índice inválido");
    } else {
        return minimenu;
    }
}

void InterfaceI(ocomon a[4], ocomon b[4], int ativo1, int ativo2) {
		cout << b[ativo2].nome << "\nDP: ";
		Lifebar(b, ativo2);
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "                                                    " << a[ativo1].nome << "\n                                                    DP: ";
		Lifebar(a, ativo1);
		cout << endl;
}

void InterfaceII(ocomon a[4], ocomon b[4], int ativo1, int ativo2) {
		cout << a[ativo1].nome << "\nDP: ";
		Lifebar(a, ativo1);
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "                                                    " << b[ativo2].nome << "\n                                                    DP: ";
		Lifebar(b, ativo2);
		cout << endl;
}

int TrocaI(ocomon a[4], ocomon b[4], int ativo1, int ativo2) {
    InterfaceI(a, b, ativo1, ativo2);
    cout << "=======================================================================" << endl;
    cout << " Ocobola, vai!" << endl;
    cout << "" << endl;
	cout << "=======================================================================" << endl;
    enter = getch();
    system("cls");
    InterfaceI(a, b, ativo1, ativo2);
    cout << "=======================================================================" << endl;
    cout << " " << a[ativo1].nome << ", eu escolho você." << endl;
    cout << "" << endl;
	cout << "=======================================================================" << endl;
    enter = getch();
}

void Creditos () {
    cout << "Desenvolvedora: Darth Weider Padawan's Creations." << endl;
    cout << "Distribuidora: CristhSoft Corporation LTDA." << endl;
    cout << endl;
    cout << "Desenvolvedores: Elyas Correa Nogueira." << endl;
    cout << "                 Luiz Henrique Silvério de Souza." << endl;
    cout << "                 Matheus Amâncio Ferreira." << endl;
    cout << endl;
    cout << "Contribuidores:  Agnaldo Alessandro da Silva Júnior." << endl;
    cout << "                 João Paulo Paiva Lima." << endl;
    cout << "                 João Victor Teófilo Salgado." << endl;
    cout << "                 Matheus José Françoso Goulart." << endl;
    cout << "                 Wagner Aristides Machado da Silva Pereira Júnior." << endl;
    cout << endl;
    cout << "© 2016 DW Padawan's Creations. Todos os direitos reservados." << endl;
    enter = getch();
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
	srand(unsigned(time(NULL)));
	float delay1 = 0.5;
	int menu, sltm, turno = 1, menujogo, menuatk, veratk = 1, fatk, danoatk, verfim = 0, atkal, finaljogo = 0;
    int ativo1 = 0, ativo2 = 0, i;
    int ocobox = rand()%6;
    ocobox++;
    int det, det2;
    int varev, som;
    string atkfinal;
    ocomon est[4];
    ocomon esp[4];
    // Determinando atributos dos Ocomons;
    est[0].cod = 1;
    est[0].nome = "PAULO GUINA";
    est[0].atk = 730;
    est[0].def = 720;
    est[0].dp = 4000;
    est[0].atk1 = "OcoMaker";
    est[0].atk2 = "Suquinho Trap";
    est[0].atk3 = "Instrumento de Trabalho";
    est[0].atk4 = "Salame Attack";
    est[0].ppa1 = 30;
    est[0].ppa2 = 20;
    est[0].ppa3 = 15;
    est[0].ppa4 = 25;
    est[0].finalidade = 0;
    est[1].cod = 2;
    est[1].nome = "CRISTHIAN COUGO";
    est[1].atk = 800;
    est[1].def = 775;
    est[1].dp = 4000;
    est[1].atk1 = "Couve Cutter";
    est[1].atk2 = "Hole Breaker";
    est[1].atk3 = "Pig Killer";
    est[1].atk4 = "Extreme Sarrator";
    est[1].ppa1 = 25;
    est[1].ppa2 = 20;
    est[1].ppa3 = 10;
    est[1].ppa4 = 20;
    est[1].finalidade = 0;
    est[2].nome = "KAUAN DESU";
    est[2].cod = 3;
    est[2].atk = 690;
    est[2].def = 730;
    est[2].dp = 4000;
    est[2].atk1 = "???";
    est[2].atk2 = "Storm of Peças";
    est[2].atk3 = "Relax Time";
    est[2].atk4 = "Mechanical Relax";
    est[2].ppa1 = 20;
    est[2].ppa2 = 15;
    est[2].ppa3 = 10;
    est[2].ppa4 = 10;
    est[2].finalidade = 0;
    est[3].odx = 4;
    est[3].nome = "SANTIAGO THE RAPER";
    est[3].cod = 4;
    est[3].atk = 980;
    est[3].def = 900;
    est[3].dp = 4000;
    est[3].atk1 = "Black Hole";
    est[3].atk2 = "Rape Father";
    est[3].atk3 = "Pyscho Smile";
    est[3].atk4 = "Hole Smasher";
    est[3].ppa1 = 20;
    est[3].ppa2 = 15;
    est[3].ppa3 = 10;
    est[3].ppa4 = 10;
    est[3].finalidade = 0;
    esp[0].cod = 1;
    esp[0].odx = 7;
    esp[0].nome = "JAÍLSON MENDES";
    esp[0].atk = 970;
    esp[0].def = 905;
    esp[0].dp = 4000;
    esp[0].atk1 = "Macho Attack";
    esp[0].atk2 = "Peça Strike";
    esp[0].atk3 = "Relaxo";
    esp[0].atk4 = "Delícia Rampage";
    esp[0].ppa1 = 30;
    esp[0].ppa2 = 20;
    esp[0].ppa3 = 5;
    esp[0].ppa4 = 15;
    esp[0].finalidade = 1;
    esp[1].odx = 8;
    esp[1].cod = 2;
    esp[1].nome = "WAGNER MACHADO";
    esp[1].atk = 820;
    esp[1].def = 715;
    esp[1].dp = 4000;
    esp[1].atk1 = "Jewish Gas";
    esp[1].atk2 = "Jewish Anxiety Attack";
    esp[1].atk3 = "Jewish Concentration";
    esp[1].atk4 = "Jew-Ken-Do";
    esp[1].ppa1 = 30;
    esp[1].ppa2 = 20;
    esp[1].ppa3 = 15;
    esp[1].ppa4 = 15;
    esp[1].finalidade = 1;
    esp[2].cod = 3;
    esp[2].odx = 9;
    esp[2].nome = "JOÃO VICTOR";
    esp[2].atk = 680;
    esp[2].def = 740;
    esp[2].dp = 4000;
    esp[2].atk1 = "???";
    esp[2].atk2 = "???";
    esp[2].atk3 = "Rexona Pipe";
    esp[2].atk4 = "Sarrada Inversa";
    esp[2].ppa1 = 30;
    esp[2].ppa2 = 20;
    esp[2].ppa3 = 10;
    esp[2].ppa4 = 10;
    esp[2].finalidade = 2;
    esp[3].cod = 4;
    esp[3].odx = 10;
    esp[3].nome = "LUAN REIS";
    esp[3].atk = 730;
    esp[3].def = 690;
    esp[3].dp = 4000;
    esp[3].atk1 = "???";
    esp[3].atk2 = "Repetentality";
    esp[3].atk3 = "Restart's Album";
    esp[3].atk4 = "Pulso Slicer";
    esp[3].ppa1 = 35;
    esp[3].ppa2 = 25;
    esp[3].ppa3 = 10;
    esp[3].ppa4 = 1;
    esp[3].finalidade = 2;
    // Menu principal do jogo;
    for (int k = 0; k < 6; k++) {
        if (k == 0 || k == 3) {
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "LOADING ." << endl;
            Pause(delay1);
        }
        if (k == 1 || k == 4) {
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "LOADING .." << endl;
            Pause(delay1);
        }
        if (k == 2 || k == 5) {
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "LOADING ..." << endl;
            Pause(delay1);
        }
        system("cls");
    }
    cout << "CristhSoft Corporation LTDA" << endl;
    cout << "          & " << endl;
    cout << "Darth Weider Padawan's Creations" << endl;
    cout << endl;
    cout << "Orgulhosamente apresentam: " << endl;
	enter = getch();
	system("cls");
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "                        OCOMON: MACHOS AND URSOS" << endl;
    enter = getch();
    system("cls");
    int a;
    PlaySound(TEXT("PDF.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    cout << "                        OCOMON: MACHOS AND URSOS" << endl;
    cout << endl;
    cout << "O que você deseja fazer?" << endl;
    cout << endl;
    cout << "1. Jogar (Single Player).\n2. Jogar (Multiplayer).\n3. Ocodex.\n4. Créditos.\n5. Sair." << endl;
    cout << endl;
    cout << "Versão Early Beta 1.2.2." << endl;
    cout << "© 2016 DW Padawan's Creations. Todos os direitos reservados." << endl;
    cin >> menu;
    system("cls");

    switch (menu) {
		case 1:
			// Seleção de times para um jogo single-player;
			cout << "Escolha o time:\n1. Estupradores.\n2. Estuprados." << endl;
			cin >> sltm;
			system("cls");
			PlaySound(NULL, 0, 0);
			if (sltm == 1) {
				// Utilizado em caso de time 1;
				do {
					// Repetição do procedimento de jogo;
					if (turno == 1) {
                        finaljogo = 0;
						// Utilizado em caso de turno do jogador;
						InterfaceI(est, esp, ativo1, ativo2);
						cout << "=======================================================================" << endl;
						cout << " 1. Ataques                                            2. Estatísticas" << endl;
						cout << " 3. Trocar Ocomon                                      4. Sair        " << endl;
						cout << "=======================================================================" << endl;
						cin >> menujogo;
						// Seleção da ação da rodada;
						system("cls");
						switch (menujogo) {
							case 1:
								// Amostra dos ataques;
								do {
									InterfaceI(est, esp, ativo1, ativo2);
									cout << "=======================================================================" << endl;
									cout << " 1. " << est[ativo1].atk1 << " <" << est[ativo1].ppa1 << ">" << endl;
									cout << " 2. " << est[ativo1].atk2 << " <" << est[ativo1].ppa2 << ">" << endl;
									cout << " 3. " << est[ativo1].atk3 << " <" << est[ativo1].ppa3 << ">" << endl;
									cout << " 4. " << est[ativo1].atk4 << " <" << est[ativo1].ppa4 << ">" << endl;
									cout << "=======================================================================" << endl;
									cin >> menuatk;
									// A função irá determinar a evasão do oponente e armazenar em uma variável
									varev = Evasao(esp, ativo2);
									switch (menuatk) {
										// Sorteio do dano/benefício do ataque;
										case 1:
											if (est[ativo1].ppa1 > 0) {
												est[ativo1].ppa1--;
												veratk = 1;
												atkfinal = est[ativo1].atk1;
												fatk = rand()%5;
												fatk += 1;
												switch (fatk) {
													case 1:
														danoatk = est[ativo1].atk*0.35;
													break;
													case 2:
														danoatk = est[ativo1].atk*0.4;
													break;
													case 3:
														danoatk = est[ativo1].atk*0.5;
													break;
													case 4:
														danoatk = est[ativo1].atk*0.55;
													break;
													case 5:
														danoatk = est[ativo1].atk*0.7;
													break;
												}
												// Se o oponente não evadir, tomará o dano do ataque
												if (varev == 0) {
                                                    esp[ativo2].dp -= danoatk;
												}
												// Concretização do ataque;
												if (esp[ativo2].dp <= 0) {
													esp[ativo2].dp = 0;
												}
											} else {
												system("cls");
												// Se o número de execuções do ataque já estiver no limite, o jogador repetirá a jogada
												veratk = 0;
											    cout << "Não é possível realizar o ataque. " << endl;
												enter = getch();
												system("cls");
											}
										break;
										case 2:
											if (est[ativo1].ppa2 > 0) {
												est[ativo1].ppa2--;
												veratk = 1;
												atkfinal = est[ativo1].atk2;
												fatk = rand()%5;
												fatk += 1;
												switch (fatk) {
													case 1:
														danoatk = est[ativo1].atk*0.2;
													break;
													case 2:
														danoatk = est[ativo1].atk*0.4;
													break;
													case 3:
														danoatk = est[ativo1].atk*0.5;
													break;
													case 4:
														danoatk = est[ativo1].atk*0.6;
													break;
													case 5:
														danoatk = est[ativo1].atk*0.8;
													break;
												}
												// Se o oponente não evadir, tomará o dano do ataque
												if (varev == 0) {
                                                    esp[ativo2].dp -= danoatk;
												}
												if (esp[ativo2].dp <= 0) {
													esp[ativo2].dp = 0;
												}
											} else {
												system("cls");
												veratk = 0;
											    cout << "Não é possível realizar o ataque. " << endl;
												enter = getch();
												system("cls");
											}
										break;
										case 3:
											if (est[ativo1].ppa3 > 0) {
												est[ativo1].ppa3--;
												veratk = 1;
												atkfinal = est[ativo1].atk3;
												fatk = rand()%5;
												fatk += 1;
												switch (fatk) {
													case 1:
														est[ativo1].atk *= 1.05;
													break;
													case 2:
														est[ativo1].atk *= 1.1;
													break;
													case 3:
														est[ativo1].atk *= 1.15;
													break;
													case 4:
														est[ativo1].atk *= 1.2;
													break;
													case 5:
														est[ativo1].atk *= 1.25;
													break;
												}
											} else {
												system("cls");
												veratk = 0;
											    cout << "Não é possível realizar o ataque. " << endl;
												enter = getch();
												system("cls");
											}
										break;
										case 4:
											if (est[ativo1].ppa4 > 0) {
												est[ativo1].ppa4--;
												veratk = 1;
												atkfinal = est[ativo1].atk4;
												fatk = rand()%5;
												fatk += 1;
												switch (fatk) {
													case 1:
														danoatk = est[ativo1].atk*0.25;
													break;
													case 2:
														danoatk = est[ativo1].atk*0.4;
													break;
													case 3:
														danoatk = est[ativo1].atk*0.5;
													break;
													case 4:
														danoatk = est[ativo1].atk*0.75;
													break;
													case 5:
														danoatk = est[ativo1].atk*1;
													break;
												}
												// Se o oponente não evadir, tomará o dano do ataque
												if (varev == 0) {
                                                    esp[ativo2].dp -= danoatk;
												}
												if (esp[ativo2].dp <= 0) {
													esp[ativo2].dp = 0;
												}
											} else {
												system("cls");
												veratk = 0;
											    cout << "Não é possível realizar o ataque. " << endl;
												enter = getch();
												system("cls");
											}
										break;
										default:
											return 0;
										break;
									}
                                // Esse laço estará sendo executado enquanto o jogador não escolher um ataque válido
								} while (veratk == 0);
								system("cls");
								InterfaceI(est, esp, ativo1, ativo2);
								// Final da fase de ataque;
								cout << "=======================================================================" << endl;
								cout << " " << est[ativo1].nome << " usou " << atkfinal << "." << endl;
								cout << "                                                                " << endl;
								cout << "=======================================================================" << endl;
								if (menuatk != 3 && varev == 0) {
                                    // Esse 'if' será executado para determinar o som
                                    som = rand()%2;
                                    if (som == 0) PlaySound(TEXT("AUD2.wav"), NULL, SND_FILENAME | SND_ASYNC);
                                    if (som == 1) PlaySound(TEXT("AUD3.wav"), NULL, SND_FILENAME | SND_ASYNC);
								}
								enter = getch();
								if (menuatk != 3) {
                                    PlaySound(NULL, 0, 0);
								}
								system("cls");
								InterfaceI(est, esp, ativo1, ativo2);
								if (menuatk != 3 && menujogo == 1 && varev == 0) {
									// Frase relacionada ao dano do ataque;
									switch (fatk) {
										case 1:
											cout << "=======================================================================" << endl;
											cout << " Não causou muito dano." << endl;
											cout << "                                                                " << endl;
											cout << "=======================================================================" << endl;
										break;
										case 2:
											cout << "=======================================================================" << endl;
											cout << " O ataque teve efeito fraco." << endl;
											cout << "                                                                " << endl;
											cout << "=======================================================================" << endl;
										break;
										case 3:
											cout << "=======================================================================" << endl;
											cout << " O ataque teve efeito médio." << endl;
											cout << "                                                                " << endl;
											cout << "=======================================================================" << endl;
										break;
										case 4:
											cout << "=======================================================================" << endl;
											cout << " O ataque foi forte." << endl;
											cout << "                                                                " << endl;
											cout << "=======================================================================" << endl;
										break;
										case 5:
											cout << "=======================================================================" << endl;
											cout << " Foi super efetivo." << endl;
											cout << "                                                                " << endl;
											cout << "=======================================================================" << endl;
										break;
									}
								} else if (varev == 0) {
                                    // Se 'varev' = 0, logo o ataque será um benefício
                                    cout << "=======================================================================" << endl;
									cout << " O ataque de "<< est[ativo1].nome << " aumentou." << endl;
									cout << "                                                                " << endl;
									cout << "=======================================================================" << endl;
								}
								if ((menuatk != 3) && (menujogo == 1) && (varev == 1)) {
                                    // O 'if' da evasão será executado se um ataque tiver sido realizado
                                    PlaySound(TEXT("EVS1.wav"), NULL, SND_FILENAME | SND_ASYNC);
                                    cout << "=======================================================================" << endl;
									cout << " " << esp[ativo2].nome << " evadiu o ataque." << endl;
									cout << "                                                                " << endl;
									cout << "=======================================================================" << endl;
								}
								// O turno passa para o oponente
								turno = 0;
								enter = getch();
								PlaySound(NULL, 0, 0);
							break;
							case 2:
								// Utilizada caso o jogador queira ver estatísticas;
								for (i = 0; i <= 3; i++) {
									cout << est[i].nome << "\nATK: " << est[i].atk << "\nDEF: " << est[i].def << "\nDP: " << est[i].dp << endl;
									cout << endl;
								}
								enter = getch();
							break;
							case 3:
								// Utilizada caso o jogador queira trocar o Ocomon;
								do {
									for (i = 0; i <= 3; i++) {
										cout << est[i].cod << ". " << est[i].nome << "\nATK: " << est[i].atk << "\nDEF: " << est[i].def << "\nDP: " << est[i].dp << endl;
										cout << endl;
                                    }
									cin >> ativo1;
									if ((ativo1 > i) || (ativo1 < 0)) return 0;
                                    // Essa atribuição é utilizada para adequar a variável ao 'cod'
                                    ativo1 -= 1;
									if (est[ativo1].dp <= 0) {
                                        // Se o personagem escolhido não possuir DPs, o jogador deverá escolher outro
										cout << "Inválido. Esse personagem não possui DPs." << endl;
										enter = getch();
										system("cls");
									}
								} while (est[ativo1].dp <= 0);
								// Em caso de troca, o turno também passa
								turno = 0;
								system("cls");
								TrocaI(est, esp, ativo1, ativo2);
								enter = getch();
								system("cls");
							break;
							default:
								cout << "Volte sempre." << endl;
								return 0;
							break;
						}
						system("cls");
						// Verificação: Algum Ocomon foi derrotado?;
						if (est[ativo1].dp <= 0 || esp[ativo2].dp <= 0) {
							if (est[ativo1].dp <= 0) {
								// finaljogo receberá 1 caso o time 1 tenha perdido um Ocomon
								finaljogo = 1;
								est[ativo1].dp = 0;
								// A variável 'contest' perde um para indicar um Ocomon fora de combate
								contest--;
								det = ativo1;
								// Caso sim, uma variável armazena o nome do derrotado;
								if (contest > 0) {
									// O jogador escolhe um Ocomon substituto;
									do {
										for (i = 0; i <= 1; i++) {
											cout << est[i].cod << ". " << est[i].nome << "\nATK: " << est[i].atk << "\nDEF: " << est[i].def << "\nDP: " << est[i].dp << endl;
											cout << endl;
										}
										cin >> ativo1;
										if ((ativo1 > i) || (ativo1 < 0)) return 0;
										ativo1 -= 1;
										if (est[ativo1].dp <= 0) {
											cout << "Inválido. Esse personagem não possui DPs." << endl;
											enter = getch();
											system("cls");
										}
									} while (est[ativo1].dp <= 0);
								} else {
									// Se não houver Ocomon para combater, a variável 'verfim' mostrará que o jogo acabou
									verfim = 1;
								}
							}
							if (esp[ativo2].dp <= 0) {
								// Mesmo para o adversário, mas a escolha é randômica;
								finaljogo = 2;
								esp[ativo2].dp = 0;
								contesp--;
								det = ativo2;
								if (contesp > 0) {
									do {





                                       ativo2 = rand()%4;






									} while (esp[ativo2].dp <= 0);
								} else {
									verfim = 1;
								}
							}
							// Interface após a derrota de um Ocomon;
							if (finaljogo == 1) {
								InterfaceI(est, esp, ativo1, ativo2);
								cout << "=======================================================================" << endl;
								cout << " " << est[det].nome << " is dead." << endl;
								cout << "                                                                " << endl;
								cout << "=======================================================================" << endl;
							}
							if (finaljogo == 2) {
                                InterfaceI(est, esp, ativo1, ativo2);
								cout << "=======================================================================" << endl;
								cout << " " << esp[det].nome << " is dead." << endl;
								cout << "                                                                " << endl;
								cout << "=======================================================================" << endl;
							}
							// O 'getch' só será executado se houver um Ocomon derrotado
							if ((finaljogo == 1) || (finaljogo == 2)) enter = getch();
							system("cls");
						}
				    }
				    if (turno == 0 && verfim != 1) {
						finaljogo = 0;
						// Turno do oponente;
						InterfaceI(est, esp, ativo1, ativo2);
						cout << "=======================================================================" << endl;
						cout << " Agora é a vez de " << esp[ativo2].nome << "." << endl;
						cout << "                                                                " << endl;
						cout << "=======================================================================" << endl;
						enter = getch();
						atkal = rand()%4;
						atkal += 1;
						system("cls");
						varev = Evasao(est, ativo1);
						// Um ataque randômico é realizado pelo adversário;
						switch (atkal) {
							case 1:
								esp[ativo2].ppa1--;
								veratk = 1;
								atkfinal = esp[ativo2].atk1;
								fatk = rand()%5;
								fatk += 1;
								switch (fatk) {
									case 1:
										danoatk = esp[ativo2].atk*0.35;
									break;
									case 2:
										danoatk = esp[ativo2].atk*0.4;
									break;
									case 3:
										danoatk = esp[ativo2].atk*0.5;
									break;
									case 4:
										danoatk = esp[ativo2].atk*0.55;
									break;
									case 5:
										danoatk = esp[ativo2].atk*0.7;
									break;
								}
								if (varev == 0) {
                                    est[ativo1].dp -= danoatk;
								}
								if (est[ativo1].dp <= 0) {
									est[ativo1].dp = 0;
								}
							break;
							case 2:
								esp[ativo2].ppa2--;
								veratk = 1;
								atkfinal = esp[ativo2].atk2;
								fatk = rand()%5;
								fatk += 1;
								switch (fatk) {
									case 1:
										danoatk = esp[ativo2].atk*0.2;
									break;
									case 2:
										danoatk = esp[ativo2].atk*0.4;
									break;
									case 3:
										danoatk = esp[ativo2].atk*0.5;
									break;
									case 4:
										danoatk = esp[ativo2].atk*0.6;
									break;
									case 5:
										danoatk = esp[ativo2].atk*0.8;
									break;
								}
								if (varev == 0) {
                                    est[ativo1].dp -= danoatk;
								}
								if (est[ativo1].dp <= 0) {
									est[ativo1].dp = 0;
								}
							break;
							case 3:
								if (esp[ativo2].finalidade == 1) {
                                    esp[ativo2].ppa3--;
                                    veratk = 1;
                                    atkfinal = esp[ativo2].atk3;
                                    fatk = rand()%5;
                                    fatk += 1;
                                    switch (fatk) {
                                        case 1:
                                            esp[ativo2].dp *= 1.05;
                                        break;
                                        case 2:
                                            esp[ativo2].dp *= 1.1;
                                        break;
                                        case 3:
                                            esp[ativo2].dp *= 1.15;
                                        break;
                                        case 4:
                                            esp[ativo2].dp *= 1.2;
                                        break;
                                        case 5:
                                            esp[ativo2].dp *= 1.25;
                                        break;
                                    }
								}
								if (esp[ativo2].finalidade == 2) {
                                    esp[ativo2].ppa3--;
                                    veratk = 1;
                                    atkfinal = esp[ativo2].atk3;
                                    fatk = rand()%5;
                                    fatk += 1;
                                    switch (fatk) {
                                        case 1:
                                            esp[ativo2].def *= 1.05;
                                        break;
                                        case 2:
                                            esp[ativo2].def *= 1.1;
                                        break;
                                        case 3:
                                            esp[ativo2].def *= 1.15;
                                        break;
                                        case 4:
                                            esp[ativo2].def *= 1.2;
                                        break;
                                        case 5:
                                            esp[ativo2].def *= 1.25;
                                        break;
                                    }
								}
                            break;
							case 4:
								if (esp[ativo2].cod != 4) {
                                    esp[ativo2].ppa4--;
                                    veratk = 1;
                                    atkfinal = esp[ativo2].atk4;
                                    fatk = rand()%5;
                                    fatk += 1;
                                    switch (fatk) {
                                        case 1:
                                            danoatk = esp[ativo2].atk*0.25;
                                        break;
                                        case 2:
                                            danoatk = esp[ativo2].atk*0.4;
                                        break;
                                        case 3:
                                            danoatk = esp[ativo2].atk*0.5;
                                        break;
                                        case 4:
                                            danoatk = esp[ativo2].atk*0.75;
                                        break;
                                        case 5:
                                            danoatk = esp[ativo2].atk*1;
                                        break;
                                    }
								} else {
                                    // Se for o ataque 'Pulso Slicer', esses comandos irão zerar a vida dos dois competidores
                                    esp[ativo2].dp = 0;
                                    atkfinal = esp[ativo2].atk4;
                                    fatk = 5;
                                    est[ativo1].dp = 0;
                                    varev = 0;
                                    det2 = ativo2;
								}
                                if ((varev == 0) && (est[ativo1].dp != 0)) {
                                    est[ativo1].dp -= danoatk;
                                }
                                if (est[ativo1].dp <= 0) {
                                    est[ativo1].dp = 0;
                                }
							break;
						}
						InterfaceI(est, esp, ativo1, ativo2);
						cout << "=======================================================================" << endl;
						cout << " " << esp[ativo2].nome << " usou " << atkfinal << "." << endl;
						cout << "                                                                " << endl;
						cout << "=======================================================================" << endl;
						if (atkal != 3 && varev == 0) {
                            som = rand()%2;
                            if (som == 0) PlaySound(TEXT("AUD1.wav"), NULL, SND_FILENAME | SND_ASYNC);
                            if (som == 1) PlaySound(TEXT("AUD4.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        }
                        enter = getch();
                        if (atkal != 3 ) {
                            PlaySound(NULL, 0, 0);
                        }
                        system("cls");
						InterfaceI(est, esp, ativo1, ativo2);
						if (atkal != 3 && varev == 0) {
							switch (fatk) {
								case 1:
									cout << "=======================================================================" << endl;
									cout << " Não causou muito dano." << endl;
									cout << "                                                                " << endl;
									cout << "=======================================================================" << endl;
								break;
								case 2:
									cout << "=======================================================================" << endl;
									cout << " O ataque teve efeito fraco." << endl;
									cout << "                                                                " << endl;
									cout << "=======================================================================" << endl;
								break;
								case 3:
									cout << "=======================================================================" << endl;
									cout << " O ataque teve efeito médio." << endl;
									cout << "                                                                " << endl;
									cout << "=======================================================================" << endl;
								break;
								case 4:
									cout << "=======================================================================" << endl;
									cout << " O ataque foi forte." << endl;
									cout << "                                                                " << endl;
									cout << "=======================================================================" << endl;
								break;
								case 5:
									cout << "=======================================================================" << endl;
									cout << " Foi super efetivo." << endl;
									cout << "                                                                " << endl;
									cout << "=======================================================================" << endl;
								break;
							}
						} else if (varev == 0){
                            if (esp[ativo2].finalidade == 1) {
                                cout << "=======================================================================" << endl;
                                cout << " Os Delícia Points de "<< esp[ativo2].nome << " aumentaram." << endl;
                                cout << "                                                                " << endl;
                                cout << "=======================================================================" << endl;
                            }
                            if (esp[ativo2].finalidade == 2) {
                                cout << "=======================================================================" << endl;
                                cout << " A defesa de "<< esp[ativo2].nome << " aumentou." << endl;
                                cout << "                                                                " << endl;
                                cout << "=======================================================================" << endl;
                            }
						}
						if ((atkal != 3) && (varev == 1)) {
                            PlaySound(TEXT("EVS1.wav"), NULL, SND_FILENAME | SND_ASYNC);
                            cout << "=======================================================================" << endl;
                            cout << " " << est[ativo1].nome << " evadiu o ataque." << endl;
                            cout << "                                                                " << endl;
                            cout << "=======================================================================" << endl;
                        }
                        // O turno voltará para o jogador
                        turno = 1;
						enter = getch();
						system("cls");
						PlaySound(NULL, 0, 0);
						if (est[ativo1].dp <= 0 || esp[ativo2].dp <= 0) {
							if (est[ativo1].dp <= 0) {
								if (det2 != 0) finaljogo = 1;
								est[ativo1].dp = 0;
								contest--;
								det = ativo1;
								if (contest > 0) {
									do {
										for (i = 0; i <= 3; i++) {
											cout << est[i].cod << ". " << est[i].nome << "\nATK: " << est[i].atk << "\nDEF: " << est[i].def << "\nDP: " << est[i].dp << endl;
											cout << endl;
										}
										cin >> ativo1;
										if ((ativo1 > i) || (ativo1 < 0)) return 0;
										ativo1--;
										if (est[ativo1].dp <= 0) {
											cout << "Inválido. Esse personagem não possui DPs." << endl;
											enter = getch();
											system("cls");
										}
										if ((contest > i) || (contest < 0)) return 0;
									} while (est[ativo1].dp <= 0);
								} else {
									verfim = 1;
								}
								system("cls");
							}
							if (esp[ativo2].dp <= 0) {
                                if (det2 != 0) finaljogo = 2;
								esp[ativo2].dp = 0;
								contesp--;
								det = ativo2;
								if (contesp > 0) {
									do {
										ativo2 = rand()%4;
									} while (esp[ativo2].dp <= 0);
								} else {
									verfim = 1;
								}
                            }
                        }
                        if (finaljogo == 1) {
                            if ((est[ativo1].dp != 0) && (esp[ativo2].dp != 0)) {
                                InterfaceI(est, esp, ativo1, ativo2);
                                PlaySound(TEXT("DRT1.wav"), NULL, SND_FILENAME | SND_ASYNC);
                                cout << "=======================================================================" << endl;
                                cout << " " << est[det].nome << " is dead." << endl;
                                cout << "                                                                " << endl;
                                cout << "=======================================================================" << endl;
                            }
                        }
                        if (finaljogo == 2) {
                            if ((est[ativo1].dp != 0) && (esp[ativo2].dp != 0)) {
                                InterfaceI(est, esp, ativo1, ativo2);
                                PlaySound(TEXT("DRT1.wav"), NULL, SND_FILENAME | SND_ASYNC);
                                cout << "=======================================================================" << endl;
                                cout << " " << esp[det].nome << " is dead." << endl;
                                cout << "                                                                " << endl;
                                cout << "=======================================================================" << endl;
                            }
                        }
                        if ((est[ativo1].dp == 0) && (esp[ativo2].dp == 0)) {
                            InterfaceI(est, esp, ativo1, ativo2);
                            PlaySound(TEXT("DRT1.wav"), NULL, SND_FILENAME | SND_ASYNC);
                            cout << "=======================================================================" << endl;
                            cout << " " << est[det].nome << " is dead." << endl;
                            cout << "                                                                " << endl;
                            cout << "=======================================================================" << endl;
                            enter = getch();
                            system("cls");
                            InterfaceI(est, esp, ativo1, ativo2);
                            cout << "=======================================================================" << endl;
                            cout << " " << esp[det2].nome << " is dead." << endl;
                            cout << "                                                                " << endl;
                            cout << "=======================================================================" << endl;
                        }
                        if ((finaljogo == 1) || (finaljogo == 2) || (det2 == 1)) enter = getch();
                        // Para garantir o 'if' anterior, a variável 'det2' será zerada agora
                        det2 = 0;
                        system("cls");
                    }
				} while (verfim == 0);
				if ((verfim == 1) && (contest == 0) && (contesp != 0)) {
					cout << "Você perdeu." << endl;
					enter = getch();
					system("cls");
					Creditos();
					return 0;
				}
				if ((verfim == 1) && (contesp == 0) && (contest != 0)) {
					cout << "Você venceu." << endl;
					enter = getch();
                    system("cls");
					Creditos();
					return 0;
				}
				if ((verfim == 1) && (contesp == 0) && (contest == 0)) {
					cout << "Empate." << endl;
					enter = getch();
					system("cls");
					Creditos();
					return 0;
				}
			}
			if (sltm == 2) {
				do {
					if (turno == 1) {
						InterfaceII(est, esp, ativo1, ativo2);
						cout << "=======================================================================" << endl;
						cout << " 1. Ataques                                            2. Estatísticas" << endl;
						cout << " 3. Trocar Ocomon                                      4. Sair" << endl;
						cout << "=======================================================================" << endl;
						cin >> menujogo;
						system("cls");
						switch (menujogo) {
							case 1:
								InterfaceII(est, esp, ativo1, ativo2);
								cout << "=======================================================================" << endl;
								cout << " 1. " << esp[ativo2].atk1 << " <" << esp[ativo2].ppa1 << ">" << endl;
								cout << " 2. " << esp[ativo2].atk2 << " <" << esp[ativo2].ppa2 << ">" << endl;
								cout << " 3. " << esp[ativo2].atk3 << " <" << esp[ativo2].ppa3 << ">" << endl;
								cout << " 4. " << esp[ativo2].atk4 << " <" << esp[ativo2].ppa4 << ">" << endl;
								cout << "=======================================================================" << endl;
								do {
									cin >> menuatk;
									varev = Evasao(est, ativo1);
									switch (menuatk) {
										case 1:
											if (esp[ativo2].ppa1 > 0) {
												esp[ativo2].ppa1--;
												veratk = 1;
												atkfinal = esp[ativo2].atk1;
												fatk = rand()%5;
												fatk += 1;
												switch (fatk) {
													case 1:
														danoatk = esp[ativo2].atk*0.35;
													break;
													case 2:
														danoatk = esp[ativo2].atk*0.4;
													break;
													case 3:
														danoatk = esp[ativo2].atk*0.5;
													break;
													case 4:
														danoatk = esp[ativo2].atk*0.55;
													break;
													case 5:
														danoatk = esp[ativo2].atk*0.7;
													break;
												}
												if (varev == 0) {
                                                    est[ativo1].dp -= danoatk;
												}
												if (est[ativo1].dp <= 0) {
													est[ativo1].dp = 0;
												}
											} else {
												system("cls");
												veratk = 0;
											    cout << "Não é possível realizar o ataque. " << endl;
												enter = getch();
												system("cls");
											}
										break;
										case 2:
											if (esp[ativo2].ppa2 > 0) {
												esp[ativo2].ppa2--;
												veratk = 1;
												atkfinal = esp[ativo2].atk2;
												fatk = rand()%5;
												fatk += 1;
												switch (fatk) {
													case 1:
														danoatk = esp[ativo2].atk*0.2;
													break;
													case 2:
														danoatk = esp[ativo2].atk*0.4;
													break;
													case 3:
														danoatk = esp[ativo2].atk*0.5;
													break;
													case 4:
														danoatk = esp[ativo2].atk*0.6;
													break;
													case 5:
														danoatk = esp[ativo2].atk*0.8;
													break;
												}
												if (varev == 0) {
                                                    est[ativo1].dp -= danoatk;
												}
												if (est[ativo1].dp <= 0) {
													est[ativo1].dp = 0;
												}
											} else {
												system("cls");
												veratk = 0;
											    cout << "Não é possível realizar o ataque. " << endl;
												enter = getch();
												system("cls");
											}
										break;
										case 3:
											if (esp[ativo2].ppa3 > 0) {
												if (esp[ativo2].finalidade == 1) {
                                                    esp[ativo2].ppa3--;
                                                    veratk = 1;
                                                    atkfinal = esp[ativo2].atk3;
                                                    fatk = rand()%5;
                                                    fatk += 1;
                                                    switch (fatk) {
                                                        case 1:
                                                            esp[ativo2].dp *= 1.05;
                                                        break;
                                                        case 2:
                                                            esp[ativo2].dp *= 1.1;
                                                        break;
                                                        case 3:
                                                            esp[ativo2].dp *= 1.15;
                                                        break;
                                                        case 4:
                                                            esp[ativo2].dp *= 1.2;
                                                        break;
                                                        case 5:
                                                            esp[ativo2].dp *= 1.25;
                                                        break;
                                                    }
												}
												if (esp[ativo2].finalidade == 2) {
                                                    esp[ativo2].ppa3--;
                                                    veratk = 1;
                                                    atkfinal = esp[ativo2].atk3;
                                                    fatk = rand()%5;
                                                    fatk += 1;
                                                    switch (fatk) {
                                                        case 1:
                                                            esp[ativo2].def *= 1.05;
                                                        break;
                                                        case 2:
                                                            esp[ativo2].def *= 1.1;
                                                        break;
                                                        case 3:
                                                            esp[ativo2].def *= 1.15;
                                                        break;
                                                        case 4:
                                                            esp[ativo2].def *= 1.2;
                                                        break;
                                                        case 5:
                                                            esp[ativo2].def *= 1.25;
                                                        break;
                                                    }
												}
											} else {
												system("cls");
												veratk = 0;
											    cout << "Não é possível realizar o ataque. " << endl;
												enter = getch();
												system("cls");
											}
										break;
										case 4:
											if (esp[ativo2].ppa4 > 0) {
												if (esp[ativo2].cod != 4) {
                                                    esp[ativo2].ppa4--;
                                                    veratk = 1;
                                                    atkfinal = esp[ativo2].atk4;
                                                    fatk = rand()%5;
                                                    fatk += 1;
                                                    switch (fatk) {
                                                        case 1:
                                                            danoatk = esp[ativo2].atk*0.25;
                                                        break;
                                                        case 2:
                                                            danoatk = esp[ativo2].atk*0.4;
                                                        break;
                                                        case 3:
                                                            danoatk = esp[ativo2].atk*0.5;
                                                        break;
                                                        case 4:
                                                            danoatk = esp[ativo2].atk*0.75;
                                                        break;
                                                        case 5:
                                                            danoatk = esp[ativo2].atk*1;
                                                        break;
                                                    }
                                                } else {
                                                    esp[ativo2].dp = 0;
                                                    fatk = 5;
                                                    est[ativo1].dp = 0;
                                                    varev = 0;
                                                    det2 = ativo2;
                                                }
                                                if ((varev == 0) && (est[ativo1].dp != 0)) {
                                                    est[ativo1].dp -= danoatk;
                                                }
												if (est[ativo1].dp <= 0) {
													est[ativo1].dp = 0;
												}
											} else {
												system("cls");
												veratk = 0;
											    cout << "Não é possível realizar o ataque. " << endl;
												enter = getch();
												system("cls");
											}
										break;
									}
								} while (veratk == 0);
								system("cls");
								InterfaceII(est, esp, ativo1, ativo2);
								cout << "=======================================================================" << endl;
								cout << " " << esp[ativo2].nome << " usou " << atkfinal << "." << endl;
								cout << "                                                                " << endl;
								cout << "=======================================================================" << endl;
								if (menuatk != 3 && menujogo == 1 && varev == 0) {
                                    som = rand()%2;
                                    if (som == 0) PlaySound(TEXT("AUD1.wav"), NULL, SND_FILENAME | SND_ASYNC);
                                    if (som == 1) PlaySound(TEXT("AUD4.wav"), NULL, SND_FILENAME | SND_ASYNC);
								}
								enter = getch();
								if (menuatk != 3) {
                                    PlaySound(NULL, 0, 0);
								}
								system("cls");
								InterfaceII(est, esp, ativo1, ativo2);
								if ((menuatk != 3) && (menujogo == 1) && (varev == 0)) {
									switch (fatk) {
										case 1:
											cout << "=======================================================================" << endl;
											cout << " Não causou muito dano." << endl;
											cout << "                                                                " << endl;
											cout << "=======================================================================" << endl;
										break;
										case 2:
											cout << "=======================================================================" << endl;
											cout << " O ataque teve efeito fraco." << endl;
											cout << "                                                                " << endl;
											cout << "=======================================================================" << endl;
										break;
										case 3:
											cout << "=======================================================================" << endl;
											cout << " O ataque teve efeito médio." << endl;
											cout << "                                                                " << endl;
											cout << "=======================================================================" << endl;
										break;
										case 4:
											cout << "=======================================================================" << endl;
											cout << " O ataque foi forte." << endl;
											cout << "                                                                " << endl;
											cout << "=======================================================================" << endl;
										break;
										case 5:
											cout << "=======================================================================" << endl;
											cout << " Foi super efetivo." << endl;
											cout << "                                                                " << endl;
											cout << "=======================================================================" << endl;
										break;
									}
								} else if (varev == 0) {
                                            if (esp[ativo2].finalidade == 1) {
                                                cout << "=======================================================================" << endl;
                                                cout << " Os Delícia Points de "<< esp[ativo2].nome << " aumentaram." << endl;
                                                cout << "                                                                " << endl;
                                                cout << "=======================================================================" << endl;
                                            }
                                            if (esp[ativo2].finalidade == 2) {
                                                cout << "=======================================================================" << endl;
                                                cout << " A defesa de "<< esp[ativo2].nome << " aumentou." << endl;
                                                cout << "                                                                " << endl;
                                                cout << "=======================================================================" << endl;
                                            }
								}
								if ((menuatk != 3) && (menujogo == 1) && (varev == 1)) {
                                    PlaySound(TEXT("EVS1.wav"), NULL, SND_FILENAME | SND_ASYNC);
                                    cout << "=======================================================================" << endl;
                                    cout << " " << est[ativo1].nome << " evadiu o ataque." << endl;
                                    cout << "                                                                " << endl;
                                    cout << "=======================================================================" << endl;
                                }
								turno = 0;
								enter = getch();
							break;
							case 2:
								for (i = 0; i <= 3; i++) {
									cout << esp[i].nome << "\nATK: " << esp[i].atk << "\nDEF: " << esp[i].def << "\nDP: " << esp[i].dp << endl;
									cout << endl;
								}
								enter = getch();
							break;
							case 3:
								// Utilizada caso o jogador queira trocar o Ocomon;
								do {
									for (i = 0; i <= 3; i++) {
										cout << esp[i].cod << ". " << esp[i].nome << "\nATK: " << esp[i].atk << "\nDEF: " << esp[i].def << "\nDP: " << esp[i].dp << endl;
										cout << endl;
									}
									cin >> ativo2;
									if ((ativo2 > i) || (ativo2 < 0)) return 0;
									ativo2 -= 1;
									if (esp[ativo2].dp <= 0) {
										cout << "Inválido. Esse personagem não possui DPs." << endl;
										enter = getch();
										system("cls");
									}
								} while (esp[ativo2].dp <= 0);
								turno = 0;
								system("cls");
								TrocaI(esp, est, ativo2, ativo1);
								enter = getch();
								system("cls");
							break;
							case 4:
								cout << "Volte sempre." << endl;
								return 0;
							break;
							default:
								cout << "Inválido." << endl;
								return 0;
							break;
						}
						system("cls");
						// Verificação: Algum Ocomon foi derrotado?;
						if (est[ativo1].dp <= 0 || esp[ativo2].dp <= 0) {
							if (esp[ativo2].dp <= 0) {
								if (det2 != 0) finaljogo = 2;
								esp[ativo2].dp = 0;
								contesp--;
								det = ativo2;
								// Caso sim, uma variável armazena o nome do derrotado;
								if (contesp > 0) {
									// O jogador escolhe um Ocomon substituto;
									do {
										for (i = 0; i <= 3; i++) {
											cout << esp[i].cod << ". " << esp[i].nome << "\nATK: " << esp[i].atk << "\nDEF: " << esp[i].def << "\nDP: " << esp[i].dp << endl;
											cout << endl;
										}
										cin >> ativo2;
										ativo2 -= 1;
										if (esp[ativo2].dp <= 0) {
											cout << "Inválido. Esse personagem não possui DPs." << endl;
											enter = getch();
											system("cls");
										}
									} while (esp[ativo2].dp <= 0);
								} else {
									verfim = 1;
								}
							}
							if (est[ativo1].dp <= 0) {
								// Mesmo para o adversário, mas a escolha é randômica;
								if (det2 != 0) finaljogo = 1;
								est[ativo1].dp = 0;
								contest--;
								det = ativo1;
								if (contest > 0) {
									do {
										ativo1 = rand()%4;
									} while (est[ativo1].dp <= 0);
								} else {
									verfim = 1;
								}
							}
							system("cls");
							InterfaceII(est, esp, ativo1, ativo2);
							// Interface após a derrota de um Ocomon;
							if (finaljogo == 1) {
                                if ((est[ativo1].dp != 0) && (esp[ativo2].dp != 0)) {
                                    PlaySound(TEXT("DRT1.wav"), NULL, SND_FILENAME | SND_ASYNC);
                                    cout << "=======================================================================" << endl;
                                    cout << " " << est[det].nome << " is dead." << endl;
                                    cout << "                                                                " << endl;
                                    cout << "=======================================================================" << endl;
                                }
                            }
                            if (finaljogo == 2) {
                                if ((est[ativo1].dp != 0) && (esp[ativo2].dp != 0)) {
                                    PlaySound(TEXT("DRT1.wav"), NULL, SND_FILENAME | SND_ASYNC);
                                    cout << "=======================================================================" << endl;
                                    cout << " " << esp[det].nome << " is dead." << endl;
                                    cout << "                                                                " << endl;
                                    cout << "=======================================================================" << endl;
                                }
                            }
                            if ((est[ativo1].dp != 0) && (esp[ativo2].dp != 0)) {
                                PlaySound(TEXT("DRT1.wav"), NULL, SND_FILENAME | SND_ASYNC);
                                cout << "=======================================================================" << endl;
                                cout << " " << est[det].nome << " is dead." << endl;
                                cout << "                                                                " << endl;
                                cout << "=======================================================================" << endl;
                                enter = getch();
                                system("cls");
                                InterfaceI(est, esp, ativo1, ativo2);
                                cout << "=======================================================================" << endl;
                                cout << " " << esp[det2].nome << " is dead." << endl;
                                cout << "                                                                " << endl;
                                cout << "=======================================================================" << endl;
                                det2 = 0;
                            }
							enter = getch();
							system("cls");
						}
						system("cls");
				    }
				    if (turno == 0 && verfim != 1) {
						InterfaceII(est, esp, ativo1, ativo2);
						cout << "=======================================================================" << endl;
						cout << " Agora é a vez de " << est[ativo1].nome << "." << endl;
						cout << "                                                                " << endl;
						cout << "=======================================================================" << endl;
						enter = getch();
						atkal = rand()%4;
						atkal += 1;
						Evasao(esp, ativo2);
						system("cls");
						switch (atkal) {
							case 1:
								veratk = 1;
								atkfinal = est[ativo1].atk1;
								fatk = rand()%5;
								fatk += 1;
								switch (fatk) {
									case 1:
										danoatk = est[ativo1].atk*0.35;
									break;
									case 2:
										danoatk = est[ativo1].atk*0.4;
									break;
									case 3:
										danoatk = est[ativo1].atk*0.5;
									break;
									case 4:
										danoatk = est[ativo1].atk*0.55;
									break;
									case 5:
										danoatk = est[ativo1].atk*0.7;
									break;
								}
								if (varev == 0) {
                                    esp[ativo2].dp -= danoatk;
								}
								if (esp[ativo2].dp <= 0) {
									esp[ativo2].dp = 0;
								}
							break;
							case 2:
								veratk = 1;
								atkfinal = est[ativo1].atk2;
								fatk = rand()%5;
								fatk += 1;
								switch (fatk) {
									case 1:
										danoatk = est[ativo1].atk*0.2;
									break;
									case 2:
										danoatk = est[ativo1].atk*0.4;
									break;
									case 3:
										danoatk = est[ativo1].atk*0.5;
									break;
									case 4:
										danoatk = est[ativo1].atk*0.6;
									break;
									case 5:
										danoatk = est[ativo1].atk*0.8;
									break;
								}
								if (varev == 0) {
                                    esp[ativo2].dp -= danoatk;
								}
								if (esp[ativo2].dp <= 0) {
									esp[ativo2].dp = 0;
								}
							break;
							case 3:
								veratk = 1;
								atkfinal = est[ativo1].atk3;
								fatk = rand()%5;
								fatk += 1;
								switch (fatk) {
									case 1:
										est[ativo1].atk *= 1.05;
									break;
									case 2:
										est[ativo1].atk *= 1.1;
									break;
									case 3:
										est[ativo1].atk *= 1.15;
									break;
									case 4:
										est[ativo1].atk *= 1.2;
									break;
									case 5:
										est[ativo1].atk *= 1.25;
									break;
								}
							break;
							case 4:
								veratk = 1;
								atkfinal = est[ativo1].atk4;
								fatk = rand()%5;
								fatk += 1;
								switch (fatk) {
									case 1:
										danoatk = est[ativo1].atk*0.25;
									break;
									case 2:
										danoatk = est[ativo1].atk*0.4;
									break;
									case 3:
										danoatk = est[ativo1].atk*0.5;
									break;
									case 4:
										danoatk = est[ativo1].atk*0.75;
									break;
									case 5:
										danoatk = est[ativo1].atk*1;
									break;
								}
								if (varev == 0) {
                                    esp[ativo2].dp -= danoatk;
								}
								if (esp[ativo2].dp <= 0) {
									esp[ativo2].dp = 0;
								}
							break;
							default:
								return 0;
							break;
						}
						InterfaceII(est, esp, ativo1, ativo2);
						cout << "=======================================================================" << endl;
						cout << " " << est[ativo1].nome << " usou " << atkfinal << "." << endl;
						cout << "                                                                " << endl;
						cout << "=======================================================================" << endl;
						if (atkal != 3 && varev == 0) {
                            som = rand()%2;
                            if (som == 0) PlaySound(TEXT("AUD2.wav"), NULL, SND_FILENAME | SND_ASYNC);
                            if (som == 1) PlaySound(TEXT("AUD3.wav"), NULL, SND_FILENAME | SND_ASYNC);
						}
                        enter = getch();
                        if (atkal != 3) {
                            PlaySound(NULL, 0, 0);
                        }
						system("cls");
						InterfaceII(est, esp, ativo1, ativo2);
						if (atkal != 3 && varev == 0) {
							switch (fatk) {
								case 1:
									cout << "=======================================================================" << endl;
									cout << " Não causou muito dano." << endl;
									cout << "                                                                " << endl;
									cout << "=======================================================================" << endl;
								break;
								case 2:
									cout << "=======================================================================" << endl;
									cout << " O ataque teve efeito fraco." << endl;
									cout << "                                                                " << endl;
									cout << "=======================================================================" << endl;
								break;
								case 3:
									cout << "=======================================================================" << endl;
									cout << " O ataque teve efeito médio." << endl;
									cout << "                                                                " << endl;
									cout << "=======================================================================" << endl;
								break;
								case 4:
									cout << "=======================================================================" << endl;
									cout << " O ataque foi forte." << endl;
									cout << "                                                                " << endl;
									cout << "=======================================================================" << endl;
								break;
								case 5:
									cout << "=======================================================================" << endl;
									cout << " Foi super efetivo." << endl;
									cout << "                                                                " << endl;
									cout << "=======================================================================" << endl;
								break;
							}
						} else if (varev == 0) {
							cout << "=======================================================================" << endl;
							cout << " O ataque de "<< est[ativo1].nome << " aumentou." << endl;
							cout << "                                                                " << endl;
							cout << "=======================================================================" << endl;
						}
						if (atkal != 3 && varev == 1) {
                            PlaySound(TEXT("EVS1.wav"), NULL, SND_FILENAME | SND_ASYNC);
                            cout << "=======================================================================" << endl;
                            cout << " " << esp[ativo2].nome << " evadiu o ataque." << endl;
                            cout << "                                                                " << endl;
                            cout << "=======================================================================" << endl;
                        }
						turno = 1;
						enter = getch();
						system("cls");
						PlaySound(NULL, 0, 0);
						if (est[ativo1].dp <= 0 || esp[ativo2].dp <= 0) {
							if (esp[ativo2].dp <= 0) {
								finaljogo = 2;
								esp[ativo2].dp = 0;
								contesp--;
								det = ativo2;
								if (contesp > 0) {
									do {
										for (i = 0; i <= 3; i++) {
											cout << esp[i].cod << ". " << esp[i].nome << "\nATK: " << esp[i].atk << "\nDEF: " << esp[i].def << "\nDP: " << esp[i].dp << endl;
											cout << endl;
										}
										cin >> ativo2;
										if ((ativo2 > i) || (ativo2 < 0)) return 0;
										ativo2--;
										if (esp[ativo2].dp <= 0) {
											cout << "Inválido. Esse personagem não possui DPs." << endl;
											enter = getch();
											system("cls");
										}
									} while (esp[ativo2].dp <= 0);
								} else {
									verfim = 1;
								}
							}
							if (est[ativo1].dp <= 0) {
								finaljogo = 1;
								est[ativo1].dp = 0;
								contest--;
								det = ativo1;
								if (contest > 0) {
									do {
										ativo1 = rand()%4;
									} while (est[ativo1].dp <= 0);
								} else {
									verfim = 1;
								}
							}
							system("cls");
							InterfaceII(est, esp, ativo1, ativo2);
							if (finaljogo == 1) {
								cout << "=======================================================================" << endl;
								cout << " " << est[det].nome << " is dead." << endl;
								cout << "                                                                " << endl;
								cout << "=======================================================================" << endl;
							}
							if (finaljogo == 2) {
                                PlaySound(TEXT("DRT1.wav"), NULL, SND_FILENAME | SND_ASYNC);
								cout << "=======================================================================" << endl;
								cout << " " << esp[det].nome << " is dead." << endl;
								cout << "                                                                " << endl;
								cout << "=======================================================================" << endl;
							}
							enter = getch();
							system("cls");
						}
					}
				} while (verfim == 0);
				PlaySound (NULL, 0, 0);
				if ((verfim == 1) && (contesp == 0)) {
					cout << "Você perdeu." << endl;
					return 0;
				}
				if ((verfim == 1) && (contest == 0)) {
					cout << "Você venceu." << endl;
					return 0;
				}
			}
		break;
		case 2:
			system("cls");
			cout << "Recurso não disponível na versão Early Beta do jogo." << endl;
			return 0;
		break;
		case 3:
			system("cls");
			cout << "Seja bem-vindo ao Ocodex." << endl;
			cout << endl;
			for (int ocodex = 0; ocodex <= 3; ocodex++) {
                cout << "0" << est[ocodex].cod << ". " << est[ocodex].nome << endl;
			}
			cout << "05. ???"<< endl;
			cout << "06. ???"<< endl;
			cout << "07. ???"<< endl;
			for (int ocodex = 0; ocodex <= 3; ocodex++) {
                if (7+esp[ocodex].cod < 10) cout << "0" << 7+esp[ocodex].cod << ". " << esp[ocodex].nome << endl;
                if (7+esp[ocodex].cod >= 10) cout << 7+esp[ocodex].cod << ". " << esp[ocodex].nome << endl;
			}
			cout << "12. ???"<< endl;
			cout << "13. ???"<< endl;
			cout << "14. ???"<< endl;
            enter = getch();
			return 0;
		break;
		case 4:
			system("cls");
			Creditos();
			return 0;
		break;
		case 5:
			system("cls");
			cout << "Volte sempre." << endl;
			return 0;
		break;
		default:
			return 0;
		break;
    }
	return 0;
}
