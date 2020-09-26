#include "MenuLog.h"
#include "../tools/Constantes.h"

MenuLog::MenuLog(){
    this->actual = MENU_VALIDAR_1;
}

MenuLog::~MenuLog() {
}

void MenuLog::configurar(int caso, std::string valor){
    if(caso == MENU_VALIDAR_1) {
        if (valor == BACKSPACE) {
            setUsuario(getUsuario(), true);

        } else {
            if(strlen(getUsuario()) == MAX_LEN_USUARIO)
                return;

            setUsuario(getUsuario() + valor, false);
        }

    }

    else if(caso == MENU_VALIDAR_2){
        if(valor == BACKSPACE){
            setPass(getPass(), true);

        } else{
            if(strlen(getPass()) == MAX_LEN_PASS)
                return;

            setPass(getPass() + valor, false);
        }

    }
}

int MenuLog::actualizar(){
    Uint8* keystates = const_cast<Uint8 *>(SDL_GetKeyboardState(NULL));

    if( keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_TAB]) {
        keystates[SDL_SCANCODE_DOWN] = false;
        keystates[SDL_SCANCODE_TAB] = false;
        if (this->actual == MENU_VALIDAR_ULT ){
            this->actual = MENU_VALIDAR_1;

        } else{
            this->actual += 1;
        }
    }

    else if( keystates[SDL_SCANCODE_UP] ){
        keystates[SDL_SCANCODE_UP] = false;
        if (this->actual == MENU_VALIDAR_1 ){
            this->actual = MENU_VALIDAR_ULT;

        } else{
            this->actual -= 1;
        }
    }

    else if( keystates[SDL_SCANCODE_RETURN] && this->actual == MENU_VALIDAR_ULT){
        keystates[SDL_SCANCODE_RETURN] = false;
        this->actual = MENU_INICIAR;
    }

    else if(keystates[SDL_SCANCODE_ESCAPE]){
        keystates[SDL_SCANCODE_ESCAPE] = false;
        this->actual = MENU_SALIR;
    }

    else if(keystates[SDL_SCANCODE_0]){
        keystates[SDL_SCANCODE_0] = false;
        configurar(this->actual, "0");

    } else if(keystates[SDL_SCANCODE_1]){
        keystates[SDL_SCANCODE_1] = false;
        configurar(this->actual, "1");

    } else if(keystates[SDL_SCANCODE_2]){
        keystates[SDL_SCANCODE_2] = false;
        configurar(this->actual, "2");

    } else if(keystates[SDL_SCANCODE_3]){
        keystates[SDL_SCANCODE_3] = false;
        configurar(this->actual, "3");

    } else if(keystates[SDL_SCANCODE_4]){
        keystates[SDL_SCANCODE_4] = false;
        configurar(this->actual, "4");

    } else if(keystates[SDL_SCANCODE_5]){
        keystates[SDL_SCANCODE_5] = false;
        configurar(this->actual, "5");

    } else if(keystates[SDL_SCANCODE_6]){
        keystates[SDL_SCANCODE_6] = false;
        configurar(this->actual, "6");

    } else if(keystates[SDL_SCANCODE_7]){
        keystates[SDL_SCANCODE_7] = false;
        configurar(this->actual, "7");

    } else if(keystates[SDL_SCANCODE_8]){
        keystates[SDL_SCANCODE_8] = false;
        configurar(this->actual, "8");

    } else if(keystates[SDL_SCANCODE_9]){
        keystates[SDL_SCANCODE_9] = false;
        configurar(this->actual, "9");

    } else if(keystates[SDL_SCANCODE_BACKSPACE]) {
        keystates[SDL_SCANCODE_BACKSPACE] = false;
        configurar(this->actual, BACKSPACE);
    }

    else if((keystates[SDL_SCANCODE_A]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_A] = false;
        configurar(this->actual, "a");

    } else if((keystates[SDL_SCANCODE_B]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_B] = false;
        configurar(this->actual, "b");

    } else if((keystates[SDL_SCANCODE_C]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_C] = false;
        configurar(this->actual, "c");

    } else if((keystates[SDL_SCANCODE_D]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_D] = false;
        configurar(this->actual, "d");

    } else if((keystates[SDL_SCANCODE_E]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_E] = false;
        configurar(this->actual, "e");

    } else if((keystates[SDL_SCANCODE_F]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_F] = false;
        configurar(this->actual, "f");

    } else if((keystates[SDL_SCANCODE_G]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_G] = false;
        configurar(this->actual, "g");

    } else if((keystates[SDL_SCANCODE_H]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_H] = false;
        configurar(this->actual, "h");

    } else if((keystates[SDL_SCANCODE_I]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_I] = false;
        configurar(this->actual, "i");

    } else if((keystates[SDL_SCANCODE_J]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_J] = false;
        configurar(this->actual, "j");

    } else if((keystates[SDL_SCANCODE_K]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_K] = false;
        configurar(this->actual, "k");

    } else if((keystates[SDL_SCANCODE_L]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_L] = false;
        configurar(this->actual, "l");

    } else if((keystates[SDL_SCANCODE_M]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_M] = false;
        configurar(this->actual, "m");

    } else if((keystates[SDL_SCANCODE_N]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_N] = false;
        configurar(this->actual, "n");

    } else if((keystates[SDL_SCANCODE_O]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_O] = false;
        configurar(this->actual, "o");

    } else if((keystates[SDL_SCANCODE_P]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_P] = false;
        configurar(this->actual, "p");

    } else if((keystates[SDL_SCANCODE_Q]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_Q] = false;
        configurar(this->actual, "q");

    } else if((keystates[SDL_SCANCODE_R]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_R] = false;
        configurar(this->actual, "r");

    } else if((keystates[SDL_SCANCODE_S]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_S] = false;
        configurar(this->actual, "s");

    } else if((keystates[SDL_SCANCODE_T]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_T] = false;
        configurar(this->actual, "t");

    } else if((keystates[SDL_SCANCODE_U]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_U] = false;
        configurar(this->actual, "u");

    } else if((keystates[SDL_SCANCODE_V]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_V] = false;
        configurar(this->actual, "v");

    } else if((keystates[SDL_SCANCODE_W]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_W] = false;
        configurar(this->actual, "w");

    } else if((keystates[SDL_SCANCODE_X]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_X] = false;
        configurar(this->actual, "x");

    } else if((keystates[SDL_SCANCODE_Y]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_Y] = false;
        configurar(this->actual, "y");

    } else if((keystates[SDL_SCANCODE_Z]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_Z] = false;
        configurar(this->actual, "z");
    }
    else if(keystates[SDL_SCANCODE_A] &&
            ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_A] = false;
        configurar(this->actual, "A");

    } else if(keystates[SDL_SCANCODE_B] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_B] = false;
        configurar(this->actual, "B");

    } else if(keystates[SDL_SCANCODE_C] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_C] = false;
        configurar(this->actual, "C");

    } else if(keystates[SDL_SCANCODE_D] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_D] = false;
        configurar(this->actual, "D");

    } else if(keystates[SDL_SCANCODE_E] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_E] = false;
        configurar(this->actual, "E");

    } else if(keystates[SDL_SCANCODE_F] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_F] = false;
        configurar(this->actual, "F");

    } else if(keystates[SDL_SCANCODE_G] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_G] = false;
        configurar(this->actual, "G");

    } else if(keystates[SDL_SCANCODE_H] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_H] = false;
        configurar(this->actual, "H");

    } else if(keystates[SDL_SCANCODE_I] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_I] = false;
        configurar(this->actual, "I");

    } else if(keystates[SDL_SCANCODE_J] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_J] = false;
        configurar(this->actual, "J");

    } else if(keystates[SDL_SCANCODE_K] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_K] = false;
        configurar(this->actual, "K");

    } else if(keystates[SDL_SCANCODE_L] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_L] = false;
        configurar(this->actual, "L");

    } else if(keystates[SDL_SCANCODE_M] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_M] = false;
        configurar(this->actual, "M");

    } else if(keystates[SDL_SCANCODE_N] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_N] = false;
        configurar(this->actual, "N");

    } else if(keystates[SDL_SCANCODE_O] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_O] = false;
        configurar(this->actual, "O");

    } else if(keystates[SDL_SCANCODE_P] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_P] = false;
        configurar(this->actual, "P");

    } else if(keystates[SDL_SCANCODE_Q] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_Q] = false;
        configurar(this->actual, "Q");

    } else if(keystates[SDL_SCANCODE_R] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_R] = false;
        configurar(this->actual, "R");

    } else if(keystates[SDL_SCANCODE_S] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_S] = false;
        configurar(this->actual, "S");

    } else if(keystates[SDL_SCANCODE_T] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_T] = false;
        configurar(this->actual, "T");

    } else if(keystates[SDL_SCANCODE_U] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_U] = false;
        configurar(this->actual, "U");

    } else if(keystates[SDL_SCANCODE_V] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_V] = false;
        configurar(this->actual, "V");

    } else if(keystates[SDL_SCANCODE_W] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_W] = false;
        configurar(this->actual, "W");

    } else if(keystates[SDL_SCANCODE_X] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_X] = false;
        configurar(this->actual, "X");

    } else if(keystates[SDL_SCANCODE_Y] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_Y] = false;
        configurar(this->actual, "Y");

    } else if(keystates[SDL_SCANCODE_Z] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_Z] = false;
        configurar(this->actual, "Z");
    }

    return this->actual;
}

bool MenuLog::estaActivo() {
    return !( (this->actual == MENU_INICIAR) ||
              (this->actual == MENU_SALIR)
            );
}

bool MenuLog::estaIniciado(){
    return this->actual == MENU_INICIAR;
}

void MenuLog::reestablecer() {
    this->actual = MENU_VALIDAR_1;
}

bool MenuLog::estaCancelado(SDL_Event *evento) {
    return (evento->type == SDL_QUIT || (this->actual == MENU_SALIR));
}