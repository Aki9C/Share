const int Star_BottomPin=12;
const int Stop_BottomPin=13;
void setup(){
    pinMode(Star_BottomPin,INPUT_PULLUP);
    pinMode(Stop_BottomPin,INPUT_PULLUP);
    pinMode(10,OUTPUT);
    for (int i=2;i<=9;i+=1)
    {
        pinMode(i,OUTPUT);
    }
    Serial.begin(9600);
}
void loop(){
    int k=20;
    int d=500;
    if(digitalRead(Star_BottomPin)==LOW){
        delay(80);
        if(digitalRead(Star_BottomPin)==LOW){
            leq(d);
        }
        else {
           lrand(d);
        }
    }
    if(digitalRead(Stop_BottomPin)==LOW){
        delay(80);
        if(digitalRead(Stop_BottomPin)==LOW){
            unsigned long tm=millis()/1000;
            fade(k);
            Serial.println(tm);
        }
        else{
            leq(d);
        }
    }
}
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
void fade(int t){
    int i=2;
    while(t!=0&&i<=9){
            digitalWrite(i,HIGH);
            digitalWrite(10,HIGH);
            delay(10000/t);
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
    delay(10000);
    lrand(500);
}