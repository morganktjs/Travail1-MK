#include "screen.h"

/* ---------------------------------------------------------------------------*/
/* Fonction qui sert à effacer l'écran en utilisant la couleur du dernier     */
/* TextBackground effectué. Replace le curseur en haut à gauche               */
/* ---------------------------------------------------------------------------*/
void ClrScr()
{
	CONSOLE_SCREEN_BUFFER_INFO ScreenInfo;
	HANDLE ScreenHandle;
	COORD Home={0,0};
	DWORD N=0;
	ScreenHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//pour avoir de l'information sur la fenêtre (ses dimensions)
	GetConsoleScreenBufferInfo(ScreenHandle,&ScreenInfo); 
	//efface les caractères de l'écran
	FillConsoleOutputCharacter(ScreenHandle,' ',ScreenInfo.dwSize.X * ScreenInfo.dwSize.Y,Home,&N);
	//remplit l'écran avec la couleur du dernier TextBackground
	FillConsoleOutputAttribute(ScreenHandle,ScreenInfo.wAttributes,ScreenInfo.dwSize.X * ScreenInfo.dwSize.Y,Home,&N);
	Gotoxy(0,0);
}

/* ---------------------------------------------------------------------------*/
/* Fonction qui sert à effacer la ligne sur laquelle le curseur est placé     */
/* L'effacement se produit à partir de la position du curseur jusqu'à la fin de la ligne*/
/* La couleur utilisée est celle du dernier TextBackground effectué           */
/* ---------------------------------------------------------------------------*/
void ClrEol()
{
	CONSOLE_SCREEN_BUFFER_INFO ScreenInfo;
	HANDLE ScreenHandle;
	COORD Home={0,0};
	COORD Pos={0,0};
	DWORD N=0;
	ScreenHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//pour avoir de l'information sur la fenêtre (positions actuelles du curseur)
	GetConsoleScreenBufferInfo(ScreenHandle,&ScreenInfo); 
	Home = ScreenInfo.dwCursorPosition;
	Pos.X = 80 - ScreenInfo.dwCursorPosition.X;
	//efface les caractères à partir de la position du curseur jusqu'à la fin de la ligne
	FillConsoleOutputCharacter(ScreenHandle,' ',Pos.X,Home,&N);
	//remplit avec la couleur du dernier TextBackGround
	FillConsoleOutputAttribute(ScreenHandle,ScreenInfo.wAttributes,Pos.X,Home,&N);
}

/* ---------------------------------------------------------------------------*/
/* Fonction qui sert à effacer l'écran à partir de la position du curseur    */
/* jusqu'à la fin de l'écran en utilisant la couleur du dernier TextBackGround effectué */
/* Le curseur est replacé en haut à gauche                                    */
/* ---------------------------------------------------------------------------*/
void ClrEoscr()
{
	CONSOLE_SCREEN_BUFFER_INFO ScreenInfo;
	HANDLE ScreenHandle;
	COORD Home;
	LPDWORD N=0;
	ScreenHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//pour avoir de l'information sur la fenêtre (positions actuelles du curseur et dimensions de l'écran)
	GetConsoleScreenBufferInfo(ScreenHandle,&ScreenInfo); 
	Home = ScreenInfo.dwCursorPosition;
	//efface à partir de la position du curseur jusqu'à la fin de l'écran
	FillConsoleOutputCharacter(ScreenHandle,' ',ScreenInfo.dwSize.X * ScreenInfo.dwSize.Y,Home,N);
	//remplit avec la couleur du dernier TextBackground
	FillConsoleOutputAttribute(ScreenHandle,ScreenInfo.wAttributes,ScreenInfo.dwSize.X * ScreenInfo.dwSize.Y,Home,N);
	Gotoxy(0,0);
}

/* ---------------------------------------------------------------------------*/
/* Fonction qui place le curseur aux positions spécifiées                     */
/* InX et InY: positions en X et en Y où il faut placer le curseur            */
/* ---------------------------------------------------------------------------*/
void Gotoxy(int InX, int InY)
{
	CONSOLE_SCREEN_BUFFER_INFO ScreenInfo;
	HANDLE ScreenHandle;
	ScreenHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//il faut indiquer à quelles positions le curseur doit se placer
	ScreenInfo.dwCursorPosition.X = InX;
	ScreenInfo.dwCursorPosition.Y = InY;
	//place le curseur à l'endroit indiqué
	SetConsoleCursorPosition(ScreenHandle,ScreenInfo.dwCursorPosition);
}

/* ---------------------------------------------------------------------------*/
/* Fonction qui modifie la couleur du prochain texte à afficher               */
/* InFontcolor : couleur désirée pour le texte                                  */
/* ---------------------------------------------------------------------------*/
void TextColor(int InFontcolor)
{
   HANDLE  ScreenHandle;
   CONSOLE_SCREEN_BUFFER_INFO ScreenInfo;
   int Color;
   ScreenHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   //pour connaitre les couleurs actuelles
   GetConsoleScreenBufferInfo(ScreenHandle,&ScreenInfo); 
   //les instructions suivantes servent à modifier la couleur du texte sans modifier la couleur de fond
   Color = ScreenInfo.wAttributes & 112; 
   Color = Color | InFontcolor; 
   //modifie la couleur d'affichage et de fond des prochaines instructions
   SetConsoleTextAttribute(ScreenHandle,Color);
}

/* ---------------------------------------------------------------------------*/
/* Fonction qui modifie la couleur de fond du prochain texte à afficher       */
/* InBackground: couleur à utiliser pour le fond                              */
/* ---------------------------------------------------------------------------*/
void TextBackground(int InBackground)
{
   HANDLE  ScreenHandle;
   CONSOLE_SCREEN_BUFFER_INFO ScreenInfo;
   int Color;
   ScreenHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   //pour connaitre les couleurs actuelles
   GetConsoleScreenBufferInfo(ScreenHandle,&ScreenInfo); 
   //les instructions suivantes servent à modifier la couleur de fond tout en gardant la couleur de texte actuelle 
   Color = ScreenInfo.wAttributes & 15; 
   InBackground = InBackground << 4;  //il faut placer la couleur aux bits 5-6-7
   Color = Color | InBackground; 
   //modifie la couleur d'affichage et de fond des prochaines instructions
   SetConsoleTextAttribute(ScreenHandle,Color);
}