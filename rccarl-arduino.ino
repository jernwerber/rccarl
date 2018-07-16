#define MPIN1A 6
#define MPIN1B 5
#define MPIN2A 9
#define MPIN2B 10

#define UBPIN0 2
#define UBPIN1 3
#define UBPIN2 4

void _motorSetup(){
  pinMode(MPIN1A, OUTPUT);
  pinMode(MPIN1B, OUTPUT);
  pinMode(MPIN2A, OUTPUT);
  pinMode(MPIN2B, OUTPUT);
}

void setup() {
  Serial.begin(115200);
  
  _motorSetup();
  pinMode(UBPIN0,INPUT);
  pinMode(UBPIN1,INPUT);
  pinMode(UBPIN2,INPUT);
  
}

void forward(int t){
  digitalWrite(MPIN1A, HIGH);
  digitalWrite(MPIN1B, LOW);

  digitalWrite(MPIN2A, HIGH);
  digitalWrite(MPIN2B, LOW);
  delay(t);
}

void right(int t) {
  digitalWrite(MPIN1A, HIGH);
  digitalWrite(MPIN1B, LOW);

  digitalWrite(MPIN2A, LOW);
  digitalWrite(MPIN2B, LOW);
  delay(t);
}

void left(int t) {
  digitalWrite(MPIN1A, LOW);
  digitalWrite(MPIN1B, LOW);

  digitalWrite(MPIN2A, HIGH);
  digitalWrite(MPIN2B, LOW);
  delay(t);
}

void halt(){
  digitalWrite(MPIN1A, LOW);
  digitalWrite(MPIN1B, HIGH);

  digitalWrite(MPIN2A, LOW);
  digitalWrite(MPIN2B, HIGH);

  delay(20);

  digitalWrite(MPIN1A, LOW);
  digitalWrite(MPIN1B, LOW);

  digitalWrite(MPIN2A, LOW);
  digitalWrite(MPIN2B, LOW);
}

void reverse(int t) {
  digitalWrite(MPIN1A, LOW);
  digitalWrite(MPIN1B, HIGH);

  digitalWrite(MPIN2A, LOW);
  digitalWrite(MPIN2B, HIGH);
}

void coast() {
  digitalWrite(MPIN1A, LOW);
  digitalWrite(MPIN1B, LOW);

  digitalWrite(MPIN2A, LOW);
  digitalWrite(MPIN2B, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  String instruction = "";

  if (digitalRead(UBPIN0)){
    instruction += "1";
  }
  else {
    instruction +="0";
  }

  if (digitalRead(UBPIN1)){
    instruction += "1";
  }
  else {
    instruction +="0";
  }

  if (digitalRead(UBPIN2)){
    instruction += "1";
  }
  else {
    instruction +="0";
  }

  Serial.print(instruction+"\n");
  
  
  if (instruction == "100"){
      forward(100);
  }
  else if (instruction == "110"){
      left(100);
  }
  else if (instruction == "101"){
      right(100);
  }
  else if (instruction == "010"){
      reverse(100);
  }
  else {
      coast();
  }
}
