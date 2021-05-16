
#include"controller.h"
#include<Motor.h>
#include<Arduino.h>
#include<Servo.h>
#define DEBUG // Srial.printを有効にする時コメント化解除

Btd btd;
//Motor mo0(PB6,PC7);
//Motor mo1(PA5,PA8);
//Motor mo2(PB10,PB4);
//Motor mo3(PB5,PB3);
//Omni omni(170,mo0,mo1,mo2,mo3);
double theta(double x_,double y_){
    //double x=(x_-64)*4;
    //double y=-1*(y_-64)*4;
    float rad=atan2(y_,x_);
    float deg=rad/PI*180;
    return deg;
}

#define outputA D11
#define outputB D12
#define Hand1 D3
#define Hand2 D5
#define Rotate1 D13
#define Rotate2 D9
#define Step1 D6
//#define Step2 D7

void Motor(int a, int b)
{
  if(a)
  {
    digitalWrite(b,HIGH);
  }
  else
  {
    digitalWrite(b,LOW);
  }
}

void hand(int a, int b)
{
    Motor(a,Hand1);
    Motor(b,Hand2);
}

void rotate(int a, int b)
{
    Motor(a,Rotate1);
    Motor(b,Rotate2);
}

/*void Step(int a, int b)
{
    Motor(a,Step1);
    Motor(b,Step2);
}*/

/*void encoder()
{
    aState = digitalRead(outputA); // Reads the "current" state of the outputA
    // If the previous and the current state of the outputA are different, that means a Pulse has occured
    if (aState != aLastState){     
    // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
        if (digitalRead(outputB) != aState) 
        { 
            counter ++;
        }
        else 
        {
           counter --;
        }
        Serial.print("Position: ");
        Serial.println(counter);
    } 
    aLastState = aState; // Updates the previous state of the outputA with the current state
}*/

void setup(){
    pinMode(outputA,INPUT);
    pinMode(outputB,INPUT);
    pinMode(Hand1,OUTPUT);
    pinMode(Hand2,OUTPUT);
    pinMode(Rotate1,OUTPUT);
    pinMode(Rotate2,OUTPUT);
    pinMode(Step1,OUTPUT);
    //pinMode(Step2,OUTPUT);
    
    mySerial.begin(2400);
    Serial.begin(9600);
    
}
void loop(){
    btd.Task();
    
    int v;
    int x=(btd.Left_x-64)*4;
    int y=-1*(btd.Left_y-64)*4;
    /*
    Serial.print("x:");
    Serial.println(x);
    Serial.print("y:");
    Serial.println(y);
    */
    //double deg=theta(x,y);
    //Serial.println(deg);
   // delay(500);
    
    //Serial.println(theta(x,y));
    
    /*if(theta(x,y)>=60&&theta(x,y)<=120){
       v = sqrt(x*x+y*y);        //front;
       // Serial.println("f");
      //  Serial.println(y);
       
       omni.move(0,v,0);
        
        //omni.move(0,y,0);
       //Serial.print("front");  
         
        #ifdef DEBUG 
        Serial.print("front");  
        Serial.print("y :");
        Serial.println(y);
        delay(1000);
        #endif
        
    }
    else if(theta(x,y)>=-120&&theta(x,y)<=-60){
       v = -sqrt(x*x+y*y);
        //back;
       omni.move(0,v,0);
        
        #ifdef DEBUG 
        Serial.print("y :");
        Serial.println(y);
        delay(1000);
        Serial.print("back");
        #endif
    }
    else if((theta(x,y)>=-30&&theta(x,y)<0)||(theta(x,y)>0&&theta(x,y)<=30)){
       v = sqrt(x*x+y*y);
        //right;
      omni.move(v,0,0);
        /*
         omni.move(x,0,0)
        */
      /*#ifdef DEBUG 
        Serial.print("x :");
        Serial.println(x);
        delay(1000);
        Serial.print("right");
        #endif
    }
    
    else if((theta(x,y)<=180&&theta(x,y)>=150)||(theta(x,y)>=-180&&theta(x,y)<=-150)){
        //left;
         v = -sqrt(x*x+y*y);
         omni.move(v,0,0);
         
        //Serial.print("left");
    
        #ifdef DEBUG 
         Serial.print("left");
        Serial.print("x :");
        Serial.println(x);
        delay(1000);
        #endif
    }*/
    //else{
        if(btd.getButtonPress("CIRCLE")){//上下運動
            Serial.print(F("\r\nCIRCLE: "));
            //Step(1,0)
            Motor(1,Step1);
        }
        else if(btd.getButtonPress("SQUARE")){
    
        //button
        }
        else if(btd.getButtonPress("CROSS")){
        //button
        }
        else if(btd.getButtonPress("TRIANGLE")){
        //button
        }
    
        else if(btd.getButtonPress("UP")){//マジックハンドを伸ばす
          Serial.print(F("\r\nUP: "));
          hand(1,0);
        //button
        }
    
        else if(btd.getButtonPress("DOWN")){//マジックハンドを縮める
          Serial.print(F("\r\nDOWN: "));
          hand(0,1);
        //button
        }
    
        else if(btd.getButtonPress("LEFT")){//機構を傾ける
          Serial.print(F("\r\nLEFT: "));
          rotate(1,0);
        //button
        }

        else if(btd.getButtonPress("RIGHT")){//機構を元に戻す
          Serial.print(F("\r\nRIGHT: "));
          rotate(0,1);
        //button
        }

        else if(btd.getButtonPress("L1")){
        //button
        }

        else if(btd.getButtonPress("L2")){
        //button
        }

        else if(btd.getButtonPress("R2")){
        //button
        }

        else if(btd.getButtonPress("R1")){
        //button
        }
        else {//何もしない
          Serial.print(F("\r\nSTOP: "));
          hand(0,0);
          rotate(0,0);
          //Step(0,0);
            //omni.move(0,0,0);
       // 
        }
    
      }
