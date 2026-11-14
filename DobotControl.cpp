#include "DobotControl.h"
#include "Dobot.h"

extern Dobot dobot;

void StartQueueDobot(){
    byte startQueue[] ={170, 170, 2, 240, 1, 15};
    dobot.commandFrame(startQueue);
}

void StopQueueDobot(){
    byte stopQueue[] ={170, 170, 2, 241,1, 14};
    dobot.commandFrame(stopQueue);
}

void ClearQueueDobot(){
    byte clearQueue[] ={170, 170, 2, 245, 1, 10};
    dobot.commandFrame(clearQueue);
}

void HomingDobot() {
    byte homing[] = {170, 170, 6, 31, 1, 0, 0, 0, 0, 224};
    dobot.commandFrame(homing);
}

void SuckOnDobot(){
    byte suckon[] ={170, 170, 4, 62, 1, 1, 1, 191};
    dobot.commandFrame(suckon);
}

void SuckOffDobot(){
    byte suckoff[] ={170, 170, 4, 62, 1, 1, 0, 192};
    dobot.commandFrame(suckoff);
}

void LoadingAreaDobot (){
    byte loadingarea[] ={
        170, 170,           //Header
        19,                 //Length
        84,                 //ID (Checksum = 84)
        3,                  //Ctrl (Checksum = 87)
        1,                  //Mode (Checksum = 88)
        57,209,101,67,      //X (Checksum = 522)
        83,178,14,192,      //Y (Checksum = 989)
        162,162,67,194,     //Z (Checksum = 1574)
        0,0,0,0,            //R (Checksum = 1574)
        218};               //Checksum (1574 mod 256
                            //256 x 6 = 1536
                            //Checksum = 1574 - 1536 = 38)
                            //256 - 38 = 218
    dobot.commandFrame(loadingarea);
}

void LoadingAreaUpDobot (){
    byte loadingareaup[] ={
        170, 170,           //Header
        19,                 //Length
        84,                 //ID (Checksum = 84)
        3,                  //Ctrl (Checksum = 87)
        1,                  //Mode (Checksum = 88)
        57,209,101,67,      //X (Checksum = 522)
        83,178,14,192,      //Y (Checksum = 989)
        118,184,78,66,     //Z (Checksum = 1435)
        0,0,0,0,            //R (Checksum = 1435)
        101};               //Checksum (1435 mod 256
                            //256 x 5 = 1280
                            //Checksum = 1435 - 1280 = 155)
                            //256 - 155 = 101
    dobot.commandFrame(loadingareaup);
}

void StorageBay1Dobot (){
    byte storagebay1[] ={
        170, 170,           //Header
        19,                 //Length
        84,                 //ID (Checksum = 84)
        3,                  //Ctrl (Checksum = 87)
        1,                  //Mode (Checksum = 88)
        3,68,113,194,      //X (Checksum = 466)
        120,55,122,67,      //Y (Checksum = 830)
        0,135,63,194,     //Z (Checksum = 1222)
        0,0,0,0,            //R (Checksum = 1222)
        58};                //Checksum (1222 mod 256
                            //256 x 4 = 1024
                            //Checksum = 1222 - 1024 = 198)
                            //256 - 198 = 58
    dobot.commandFrame(storagebay1);
}

void StorageBay1UpDobot (){
    byte storagebay1up[] ={
        170, 170,           //Header
        19,                 //Length
        84,                 //ID (Checksum = 84)
        3,                  //Ctrl (Checksum = 87)
        1,                  //Mode (Checksum = 88)
        3,68,113,194,      //X (Checksum = 466)
        120,55,122,67,      //Y (Checksum = 830)
        118,184,78,66,     //Z (Checksum = 1276)
        0,0,0,0,            //R (Checksum = 1276)
        4};                //Checksum (1276 mod 256
                            //256 x 4 = 1024
                            //Checksum = 1276 - 1024 = 252)
                            //256 - 252 = 4
    dobot.commandFrame(storagebay1up);
}

void StorageBay1Stack2Dobot(){
    byte storagebaystack2[] ={
        170, 170,           //Header
        19,                 //Length
        84,                 //ID (Checksum = 84)
        3,                  //Ctrl (Checksum = 87)
        1,                  //Mode (Checksum = 88)
        3,68,113,194,      //X (Checksum = 466)
        120,55,122,67,      //Y (Checksum = 830)
        40,57,183,193,     //Z (Checksum = 1303)
        0,0,0,0,            //R (Checksum = 1303)
        233};               //Checksum (1303 mod 256
                            //256 x 4 = 1024
                            //Checksum = 1303 - 1024 = 279)
                            //256 - 279 = -23 (wrap around to 233)
    dobot.commandFrame(storagebaystack2);
}

void StorageBay1Stack3Dobot(){
    byte storagebaystack3[] ={
        170, 170,           //Header
        19,                 //Length
        84,                 //ID (Checksum = 84)
        3,                  //Ctrl (Checksum = 87)
        1,                  //Mode (Checksum = 88)
        3,68,113,194,      //X (Checksum = 466)
        120,55,122,67,      //Y (Checksum = 830)
        0,54,137,64,        //Z (Checksum = 1085
        0,0,0,0,            //R (Checksum = 1085
        195};          //Checksum (1085 mod 256
                            //256 x 4 = 1024
                            //Checksum = 1085 - 1024 = 61)
                            //256 - 61 = 195 (wrap around to 168)
    dobot.commandFrame(storagebaystack3);
}
void StorageBay2Dobot (){
    byte storagebay2[] ={
        170, 170,           //Header
        19,                 //Length
        84,                 //ID (Checksum = 84)
        3,                  //Ctrl (Checksum = 87)
        1,                  //Mode (Checksum = 88)
        146,19,146,65,      //X (Checksum = 464)
        93,32,120,67,      //Y (Checksum = 776)
        20,98,67,194,     //Z (Checksum = 1155)
        0,0,0,0,            //R (Checksum = 1155)
        125};               //Checksum (1155 mod 256
                            //256 x 4 = 1024
                            //Checksum = 1155 - 1024 = 131)
                            //256 - 131 = 125
    dobot.commandFrame(storagebay2);
}

void StorageBay2UpDobot (){
    byte storagebay2up[] ={
        170, 170,           //Header
        19,                 //Length
        84,                 //ID (Checksum = 84)
        3,                  //Ctrl (Checksum = 87)
        1,                  //Mode (Checksum = 88)
        146,19,146,65,      //X (Checksum = 464)
        93,32,120,67,      //Y (Checksum = 776)
        118,184,78,66,     //Z (Checksum = 1222)
        0,0,0,0,            //R (Checksum = 1222)
        58};                //Checksum (1222 mod 256
                            //256 x 4 = 1024
                            //Checksum = 1222 - 1024 = 198)
                            //256 - 198 = 58
    dobot.commandFrame(storagebay2up);
}

void StorageBay2Stack2Dobot (){
    byte storagebay2stack2[] ={
        170, 170,           //Header
        19,                 //Length
        84,                 //ID (Checksum = 84)
        3,                  //Ctrl (Checksum = 87)
        1,                  //Mode (Checksum = 88)
        146,19,146,65,      //X (Checksum = 464)
        93,32,120,67,      //Y (Checksum = 776)
        40,57,183,193,     //Z (Checksum = 1249)
        0,0,0,0,            //R (Checksum = 1249)
        31};                //Checksum (1249 mod 256
                            //256 x 4 = 1024
                            //Checksum = 1249 - 1024 = 225)
                            //256 - 225 = 31
    dobot.commandFrame(storagebay2stack2);
}

void StorageBay2Stack3Dobot (){
    byte storagebay2stack3[] ={
        170, 170,           //Header
        19,                 //Length
        84,                 //ID (Checksum = 84)
        3,                  //Ctrl (Checksum = 87)
        1,                  //Mode (Checksum = 88)
        146,19,146,65,      //X (Checksum = 464)
        93,32,120,67,      //Y (Checksum = 776)
        0,54,137,64,        //Z (Checksum = 1031)
        0,0,0,0,            //R (Checksum = 1031)
        249};               //Checksum (1031 mod 256
                            //256 x 4 = 1024
                            //Checksum = 1031 - 1024 = 7)
                            //256 - 7 = 249
    dobot.commandFrame(storagebay2stack3);
}

void StorageBay3Dobot (){
    byte storagebay3[] ={
        170, 170,           //Header
        19,                 //Length
        84,                 //ID (Checksum = 84)
        3,                  //Ctrl (Checksum = 87)
        1,                  //Mode (Checksum = 88)
        67,243,194,66,      //X (Checksum = 658)
        202,49,118,67,      //Y (Checksum = 1094)
        194,71,71,194,     //Z (Checksum = 1624)
        0,0,0,0,            //R (Checksum = 1624)
        168};               //Checksum (1624 mod 256
                            //256 x 6 = 1536
                            //Checksum = 1624 - 1536 = 88)
                            //256 - 88 = 168
    dobot.commandFrame(storagebay3);
}

void StorageBay3UpDobot (){
    byte storagebay3up[] ={
        170, 170,           //Header
        19,                 //Length
        84,                 //ID (Checksum = 84)
        3,                  //Ctrl (Checksum = 87)
        1,                  //Mode (Checksum = 88)
        67,243,194,66,      //X (Checksum = 658)
        202,49,118,67,      //Y (Checksum = 1094)
        118,184,78,66,     //Z (Checksum = 1540)
        0,0,0,0,            //R (Checksum = 1540)
        252};               //Checksum (1540 mod 256
                            //256 x 6 = 1536
                            //Checksum = 1540 - 1536 = 4)
                            //256 - 4 = 252
    dobot.commandFrame(storagebay3up);
}

void StorageBay3Stack2Dobot (){
    byte storagebay3stack2[] ={
        170, 170,           //Header
        19,                 //Length
        84,                 //ID (Checksum = 84)
        3,                  //Ctrl (Checksum = 87)
        1,                  //Mode (Checksum = 88)
        67,243,194,66,      //X (Checksum = 658)
        202,49,118,67,      //Y (Checksum = 1094)
        40,57,183,193,     //Z (Checksum = 1567)
        0,0,0,0,            //R (Checksum = 1567)
        225};               //Checksum (1567 mod 256
                            //256 x 6 = 1536
                            //Checksum = 1567 - 1536 = 31)
                            //256 - 31 = 225
    dobot.commandFrame(storagebay3stack2);
}

void StorageBay3Stack3Dobot (){
    byte storagebay3stack3[] ={
        170, 170,           //Header
        19,                 //Length
        84,                 //ID (Checksum = 84)
        3,                  //Ctrl (Checksum = 87)
        1,                  //Mode (Checksum = 88)
        67,243,194,66,      //X (Checksum = 658)
        202,49,118,67,      //Y (Checksum = 1094)
        0,54,137,64,        //Z (Checksum = 1349)
        0,0,0,0,            //R (Checksum = 1349)
        187};               //Checksum (1349 mod 256
                            //256 x 5 = 1280
                            //Checksum = 1349 - 1280 = 69)
                            //256 - 69 = 187
    dobot.commandFrame(storagebay3stack3);
}

/* Update with correct values for the colour sensor position once known
void ColourSensorPositionDobot(){}
    byte coloursensorposition[] ={
        170, 170,           //Header
        19,                 //Length
        84,                 //ID (Checksum = 84)
        3,                  //Ctrl (Checksum = 87)
        1,                  //Mode (Checksum = 88)
        67,243,194,66,      //X (Checksum = 658)
        202,49,118,67,      //Y (Checksum = 1094)
        0,54,137,64,        //Z (Checksum = 1349)
        0,0,0,0,            //R (Checksum = 1349)
        187};               //Checksum (1349 mod 256
                            //256 x 5 = 1280
                            //Checksum = 1349 - 1280 = 69)
                            //256 - 69 = 187
    dobot.commandFrame(coloursensorposition);
}
*/