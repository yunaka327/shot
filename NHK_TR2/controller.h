#ifndef BTD_H
#define BTD_H
#include<HardwareSerial.h>
#include<Arduino.h>
//#include<string>
#define MYRX PA10
#define MYTX PA9
HardwareSerial mySerial(MYRX,MYTX);
class Btd{
    public:
        Btd();
        int i;
        unsigned char c[8];
        unsigned long chksum;
        int Left_x;
        int Left_y;
        int Right_x;         
        int Right_y;
        
        void Task();
        bool getButtonPress(String name);
        bool Check(int c,int num);
};
Btd::Btd(){
    c[0]=0x80;
    
}
bool Btd::Check(int c,int num){
    
    if((c&num)==num)return true;
    else return false;
    
}
bool Btd::getButtonPress(String name){
    bool rep;
    if(name=="CROSS") rep=this->Check(c[2],0x20);
    else if(name=="CIRCLE") rep=this->Check(c[2],0x40);
    else if(name=="TRIANGLE") rep=this->Check(c[2],0x10);
    else if(name=="SQUARE") rep=this->Check(c[1],0x01);
    else if(name=="UP") rep=this->Check(c[2],0x01);
    else if(name=="DOWN") rep=this->Check(c[2],0x02);
    else if(name=="RIGHT") rep=this->Check(c[2],0x04);
    else if(name=="LEFT") rep=this->Check(c[2],0x08);
    else if(name=="L1") rep=this->Check(c[1],0x02);
    else if(name=="L2") rep=this->Check(c[1],0x04);
    else if(name=="R1") rep=this->Check(c[1],0x08);
    else if(name=="R2") rep=this->Check(c[1],0x10);
    else rep=false; 
    return rep;
}
void Btd::Task(){
    if(mySerial.available()>=8){
        if(mySerial.read()==0x80){
            for(chksum=c[0],i=1;i<8;i++){
                c[i]=mySerial.read();
                if(i<7)chksum+=c[i];
            }
            //if(c[7]!=(chksum & 0x7F))throw "check sum EROOR";
            
            String leftstickx=String(c[3],DEC);
            String leftsticky=String(c[4],DEC);
            String rightstickx=String(c[5],DEC);
            String rightsticky=String(c[6],DEC);
            Left_x=leftstickx.toInt();
            Left_y=leftsticky.toInt();
            Right_x=rightsticky.toInt();
            Right_y=rightsticky.toInt();
           
            /*
            #ifdef DEBUG
                Serial.println("left_x: "leftstickx);
                Serial.println("left_y: "leftsticky);
                Serial.println("right_x: "rightstickx);
                Serial.println("right_y: "rightsticky);
            #endif
            */
        }
    }
}
#endif
