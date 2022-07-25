#include "Dxlib.h"
#include "sleep.h"


void Sleep_Initialize(){
	sleepImage = LoadGraph("images/Player_Sleep.png");
}

void Sleep_Finalize() {
	DeleteGraph(sleepImage);
}

void Sleep_Update() {

}

void Sleep_Draw() {

}