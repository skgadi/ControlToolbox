const int ledPin = 13; // the pin that the LED is attached toint incomingByte;      // a variable to read incoming serial data intoint AI0P = 0;int AI0N = 1;int AI1P = 2;int AI1N = 3;int AI2P = 4;int AI2N = 5;int Val0 = 0;int Val1 = 0;int Val2 = 0;String AnalogRead;int AnalogReadVal;int AO0P = 5;int AO0N = 6;byte AORead[2] = {0,0};void setup() {  // initialize serial communication:  Serial.begin(115200);}void loop() {  // see if there's incoming serial data:  if (Serial.available() > 0) {    Val0 = analogRead(AI0P) - analogRead(AI0N);    Val1 = analogRead(AI1P) - analogRead(AI1N);    Val2 = analogRead(AI2P) - analogRead(AI2N);    /*Val0 = 2;    Serial.print(char((Val0 & 0xff)));    Serial.print(char(((Val0>>8) & 0xff)));    Serial.print(char((Val1 & 0xff)));    Serial.print(char(((Val1>>8) & 0xff)));    Serial.print(char((Val2 & 0xff)));    Serial.print(char(((Val2>>8) & 0xff)));*/    Serial.print(Val0);    Serial.print(";");    Serial.print(Val1);    Serial.print(";");    Serial.print(Val2);    Serial.print("E");    /*Serial.println(char(AORead[0]));    Serial.println(char(AORead[1]));*/    Serial.readBytes(AORead, 10);    if (AORead[0]) {      analogWrite(AO0P, 0);      analogWrite(AO0N, AORead[1]);    } else {      analogWrite(AO0P, AORead[1]);            analogWrite(AO0N, 0);    }    /*AnalogReadVal = AORead[1]*256 + AORead[0];    if (AnalogReadVal<0) {      analogWrite(AO0P, 0);      analogWrite(AO0N, AnalogReadVal);    } else {      analogWrite(AO0P, AnalogReadVal);            analogWrite(AO0N, 0);    }*/  }}