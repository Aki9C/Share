const int Star_BottomPin=12;
const int Stop_BottomPin=13;
void lrand(int i);
void leq(int i);
void fade(int i);
void setup(){
    pinMode(Star_BottomPin,INPUT_PULLUP);
    pinMode(Stop_BottomPin,INPUT_PULLUP);
    pinMode(10,OUTPUT);
    for (int i=2;i<=9;i+=1)
    {
        pinMode(i,OUTPUT);
    }
    Serial.begin(9600);//串口监视器初期化
}
void loop(){
    int k=20;//倒计时参数初期化
    int d=500;//设置led抖动消除时间
    if(digitalRead(Star_BottomPin)==LOW&&digitalRead(Stop_BottomPin)==HIGH){ 
        delay(80);//设置按钮抖动消除时间
        if(digitalRead(Star_BottomPin)==LOW){
            leq(d);//star按钮被按下时执行的操作
        }
        else {
           lrand(d);//没被按下时执行的操作
        }
    }
    if(digitalRead(Stop_BottomPin)==LOW&&digitalRead(Star_BottomPin)==LOW){
        delay(80);//设置按钮抖动消除时间
        if(digitalRead(Stop_BottomPin)==LOW){
            unsigned long tm=millis()/1000;//从按下stop按钮开始计时
            fade(k);
            Serial.println(tm);//输出计时
        }
        else{
            leq(d);
        }
    }
}
//顺序亮灭灯
void leq(int d){
    for(int i=2;i<=9;i+=1){
        digitalWrite(i,HIGH);
        digitalWrite(10,HIGH);
        delay(d);
        digitalWrite(i,LOW);
        digitalWrite(10,LOW);
        delay(d);
    }
}
//随机亮灭灯
void lrand(int d){
    int r;
    for(int i=0;i<8;i+=1){
        r=random(2,10);
        digitalWrite(r,HIGH);
        digitalWrite(10,HIGH);
        delay(d);
        digitalWrite(r,LOW);
        digitalWrite(10,LOW);
        delay(d);
    }
}
//led亮度和蜂鸣器衰减
void fade(int t){
    int i=2;
    while(t!=0&&i<=9){
        digitalWrite(i,HIGH);
        digitalWrite(10,HIGH);
        delay(1000/t);
        digitalWrite(i,LOW);
        digitalWrite(10,LOW);
        t-=1;
        i+=1;
        if(i==10){
            i=2;
        }
    }
    digitalWrite(i,LOW);
    digitalWrite(10,LOW);
    delay(1000);
    lrand(500);
}
