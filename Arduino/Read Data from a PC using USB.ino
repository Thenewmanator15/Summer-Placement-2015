
int incomingByte = 0;   // for incoming serial data
int led = 8;
void setup(){
Serial.begin(9600); // // opens serial port, sets data rate to 9600 bps
pinMode(led, OUTPUT);
}
void loop(){ 

while(Serial.available()<=0);
// read the incoming byte:
incomingByte = Serial.read();//not using this
if(incomingByte >150){
//Serial.println(incomingByte);
digitalWrite(led, HIGH); }
else{digitalWrite(led, LOW);}


}
