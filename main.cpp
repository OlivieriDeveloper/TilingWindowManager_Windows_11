#include <Windows.h>
#include <iostream>

// Definizione degli indirizzi dei tasti
#define VK_T 0x54
#define VK_F 0x46

// Definizione di costanti
#define PADDING 10
#define INTER_WINDOWS 10

// Definizione di variabili per il controllo dell'ancoraggio
bool isOnLeft = false;
bool isOnRight = false;

// Funzione per ridimensionare una finestra attiva
void TileActiveWindow() {
    // Ottenere l'handle della finestra attiva
    HWND activeWindow = GetForegroundWindow();

    // Ottenere le dimensioni dello schermo
    RECT screenRect;
    GetWindowRect(GetDesktopWindow(), &screenRect);

    // Definire le dimensioni e la posizione della finestra tiling
    int width = screenRect.right - (PADDING*2); // Dividi la larghezza dello schermo per 2
    int height = screenRect.bottom - (PADDING*2); // Dividi l'altezza dello schermo per 2
    int x = PADDING; // Posizione x della finestra
    int y = PADDING; // Posizione y della finestra

    // Ridimensionare e spostare la finestra attiva
    SetWindowPos(activeWindow, HWND_TOP, x, y, width, height, SWP_SHOWWINDOW);
}

// Funzione per impostare come flottante una finestra attiva
void FloatToCenterActiveWindow() {
    // Ottenere l'handle della finestra attiva
    HWND activeWindow = GetForegroundWindow();

    // Ottenere le dimensioni dello schermo
    RECT screenRect;
    GetWindowRect(GetDesktopWindow(), &screenRect);

    // Definire le dimensioni e la posizione della finestra tiling
    int width = screenRect.right/3*2; // Dividi la larghezza dello schermo per 2
    int height = screenRect.bottom/3*2; // Dividi l'altezza dello schermo per 2
    int x = screenRect.right/2-screenRect.right/6*2; // Posizione x della finestra
    int y = screenRect.bottom/2-screenRect.bottom/6*2; // Posizione y della finestra

    // Ridimensionare e spostare la finestra attiva
    SetWindowPos(activeWindow, HWND_TOP, x, y, width, height, SWP_SHOWWINDOW);
}



// Funzione per spostare a sinistra una finestra attiva
void MoveLeftActiveWindow() {
    // Ottenere l'handle della finestra attiva
    HWND activeWindow = GetForegroundWindow();

    // Ottenere le dimensioni dello schermo
    RECT screenRect;
    GetWindowRect(GetDesktopWindow(), &screenRect);

    // Definire le dimensioni e la posizione della finestra tiling
    int width = screenRect.right / 2 - (PADDING) - INTER_WINDOWS / 2; // Dividi la larghezza dello schermo per 2
    int height = screenRect.bottom - (PADDING*2); // Dividi l'altezza dello schermo per 2
    int x = PADDING; // Posizione x della finestra
    int y = PADDING; // Posizione y della finestra

    // Ridimensionare e spostare la finestra attiva
    SetWindowPos(activeWindow, HWND_TOP, x, y, width, height, SWP_SHOWWINDOW);
}

// Funzione per spostare a destra una finestra attiva
void MoveRightActiveWindow() {
    // Ottenere l'handle della finestra attiva
    HWND activeWindow = GetForegroundWindow();

    // Ottenere le dimensioni dello schermo
    RECT screenRect;
    GetWindowRect(GetDesktopWindow(), &screenRect);

    // Definire le dimensioni e la posizione della finestra tiling
    int width = screenRect.right / 2 - (PADDING); // Dividi la larghezza dello schermo per 2
    int height = screenRect.bottom - (PADDING*2); // Dividi l'altezza dello schermo per 2
    int x = screenRect.right /2 + INTER_WINDOWS / 2; // Posizione x della finestra
    int y = PADDING; // Posizione y della finestra

    // Ridimensionare e spostare la finestra attiva
    SetWindowPos(activeWindow, HWND_TOP, x, y, width, height, SWP_SHOWWINDOW);
}

// Funzione per spostare in alto una finestra attiva
void MoveTopActiveWindow(std::string position="top") {
    // Ottenere l'handle della finestra attiva
    HWND activeWindow = GetForegroundWindow();

    // Ottenere le dimensioni dello schermo
    RECT screenRect;
    GetWindowRect(GetDesktopWindow(), &screenRect);
    if(position == "top"){
        // Definire le dimensioni e la posizione della finestra tiling
        int width = screenRect.right - (PADDING*2); // Dividi la larghezza dello schermo per 2
        int height = screenRect.bottom / 2 - (PADDING); // Dividi l'altezza dello schermo per 2
        int x = PADDING; // Posizione x della finestra
        int y = PADDING; // Posizione y della finestra

        // Ridimensionare e spostare la finestra attiva
        SetWindowPos(activeWindow, HWND_TOP, x, y, width, height, SWP_SHOWWINDOW);
    } else if (position == "top-left") {
        // Definire le dimensioni e la posizione della finestra tiling
        int width = screenRect.right / 2 - (PADDING); // Dividi la larghezza dello schermo per 2
        int height = screenRect.bottom / 2 - (PADDING); // Dividi l'altezza dello schermo per 2
        int x = PADDING; // Posizione x della finestra
        int y = PADDING; // Posizione y della finestra

        // Ridimensionare e spostare la finestra attiva
        SetWindowPos(activeWindow, HWND_TOP, x, y, width, height, SWP_SHOWWINDOW);
    } else if (position == "top-right") {
        // Definire le dimensioni e la posizione della finestra tiling
        int width = screenRect.right / 2 - (PADDING); // Dividi la larghezza dello schermo per 2
        int height = screenRect.bottom / 2 - (PADDING); // Dividi l'altezza dello schermo per 2
        int x = screenRect.right /2 + INTER_WINDOWS / 2; // Posizione x della finestra
        int y = PADDING; // Posizione y della finestra

        // Ridimensionare e spostare la finestra attiva
        SetWindowPos(activeWindow, HWND_TOP, x, y, width, height, SWP_SHOWWINDOW);
    } else {
        std::cout << "error: position not valid\n";
    }
}

// Funzione per spostare in basso una finestra attiva
void MoveBottomActiveWindow(std::string position="bottom") {
    // Ottenere l'handle della finestra attiva
    HWND activeWindow = GetForegroundWindow();

    // Ottenere le dimensioni dello schermo
    RECT screenRect;
    GetWindowRect(GetDesktopWindow(), &screenRect);
    if(position == "bottom"){
        // Definire le dimensioni e la posizione della finestra tiling
        int width = screenRect.right - (PADDING*2); // Dividi la larghezza dello schermo per 2
        int height = screenRect.bottom / 2 - (PADDING); // Dividi l'altezza dello schermo per 2
        int x = PADDING; // Posizione x della finestra
        int y = screenRect.bottom/2 + INTER_WINDOWS/2; // Posizione y della finestra

        // Ridimensionare e spostare la finestra attiva
        SetWindowPos(activeWindow, HWND_TOP, x, y, width, height, SWP_SHOWWINDOW);
    } else if (position == "bottom-left") {
        // Definire le dimensioni e la posizione della finestra tiling
        int width = screenRect.right / 2 - (PADDING); // Dividi la larghezza dello schermo per 2
        int height = screenRect.bottom / 2 - (PADDING); // Dividi l'altezza dello schermo per 2
        int x = PADDING; // Posizione x della finestra
        int y = screenRect.bottom/2 + INTER_WINDOWS/2; // Posizione y della finestra

        // Ridimensionare e spostare la finestra attiva
        SetWindowPos(activeWindow, HWND_TOP, x, y, width, height, SWP_SHOWWINDOW);
    } else if (position == "bottom-right") {
        // Definire le dimensioni e la posizione della finestra tiling
        int width = screenRect.right / 2 - (PADDING); // Dividi la larghezza dello schermo per 2
        int height = screenRect.bottom / 2 - (PADDING); // Dividi l'altezza dello schermo per 2
        int x = screenRect.right /2 + INTER_WINDOWS / 2; // Posizione x della finestra
        int y = screenRect.bottom/2 + INTER_WINDOWS/2; // Posizione y della finestra

        // Ridimensionare e spostare la finestra attiva
        SetWindowPos(activeWindow, HWND_TOP, x, y, width, height, SWP_SHOWWINDOW);
    } else {
        std::cout << "error: position not valid\n";
    }
}

// Funzione per gestire gli eventi della combinazione di tasti
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        KBDLLHOOKSTRUCT* kbs = (KBDLLHOOKSTRUCT*)lParam;
        if (wParam == WM_KEYDOWN) {
            // CTRL + ALT + T
            if (kbs->vkCode == VK_T && GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_MENU)) {
                TileActiveWindow(); // Se CTRL + ALT + T sono premuti, esegui la funzione di tiling
                isOnLeft = false;
                isOnRight= false;
            }
            // CTRL + ALT + Freccia Sinistra
            else if (kbs->vkCode == VK_LEFT && GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_MENU)) {
                if(!isOnLeft){
                    MoveLeftActiveWindow(); // Se CTRL + ALT + Freccia Sinistra sono premuti, esegui la funzione di spostamento verso sinistra
                    isOnLeft = true;
                    isOnRight= false;
                } else {
                    MoveLeftActiveWindow(); // Se CTRL + ALT + Freccia Sinistra sono premuti, esegui la funzione di spostamento verso sinistra
                }
            }
            // CTRL + ALT + Freccia Destra
            else if (kbs->vkCode == VK_RIGHT && GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_MENU)) {
                if(!isOnRight){
                    MoveRightActiveWindow(); // Se CTRL + ALT + Freccia Destra sono premuti, esegui la funzione di spostamento verso sinistra
                    isOnLeft = false;
                    isOnRight= true;
                } else {
                    MoveRightActiveWindow(); // Se CTRL + ALT + Freccia Destra sono premuti, esegui la funzione di spostamento verso sinistra
                }
            }

            // CTRL + ALT + F
            else if (kbs->vkCode == VK_F && GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_MENU)) {
                FloatToCenterActiveWindow(); // Se CTRL + ALT + F sono premuti, esegui la funzione di spostamento verso sinistra
                isOnLeft = false;
                isOnRight= false;
            }

            // CTRL + ALT + Freccia Su
            else if (kbs->vkCode == VK_UP && GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_MENU)) {
                if(isOnLeft){
                    MoveTopActiveWindow("top-left"); // Se CTRL + ALT + Freccia Su sono premuti, e la finestra è già a sinistra esegui la funzione di spostamento verso in alto a sinstra
                } else if(!isOnLeft && !isOnRight){
                    MoveTopActiveWindow("top"); // Se CTRL + ALT + Freccia Su sono premuti, e la finestra è già a sinistra esegui la funzione di spostamento verso l'alto
                } else if(isOnRight){
                    MoveTopActiveWindow("top-right"); // Se CTRL + ALT + Freccia Su sono premuti, e la finestra è già a sinistra esegui la funzione di spostamento verso in alto a sinstra
                }
            }

            // CTRL + ALT + Freccia Giu
            else if (kbs->vkCode == VK_DOWN && GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_MENU)) {
                if(isOnLeft){
                    MoveBottomActiveWindow("bottom-left"); // Se CTRL + ALT + Freccia Su sono premuti, e la finestra è già a sinistra esegui la funzione di spostamento verso in alto a sinstra
                } else if(!isOnLeft && !isOnRight){
                    MoveBottomActiveWindow("bottom"); // Se CTRL + ALT + Freccia Su sono premuti, e la finestra è già a sinistra esegui la funzione di spostamento verso l'alto
                } else if(isOnRight){
                    MoveBottomActiveWindow("bottom-right"); // Se CTRL + ALT + Freccia Su sono premuti, e la finestra è già a sinistra esegui la funzione di spostamento verso in alto a sinstra
                }
            }
        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int main() {
    // Installare il hook per intercettare gli eventi della tastiera
    HHOOK hook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);

    // Ciclo per mantenere in esecuzione il programma
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Rimuovere il hook quando il programma termina
    UnhookWindowsHookEx(hook);

    return 0;
}
