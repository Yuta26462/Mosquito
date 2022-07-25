#include"Dxlib.h"
#include"sleep.h"

void Sleep_Initialize() {
	ImageSleep = LoadGraph("images/Player_Sleep");
}

void Sleep_Finalize() {
	DeleteGraph(ImageSleep);
}

void Sleep_Update() {

}

void Sleep_Draw() {

}