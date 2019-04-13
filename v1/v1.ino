const int upPin = 7;
const int downPin = 8;
const int enterPin = 9;
const int deletePin = 10;
const int sendPin = 11;

const int numWords = 10;
const int wordLength = 20;

int words[numWords][wordLength];
char characters[27] = {' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int currWord = 0;
int currWordChar = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(upPin, INPUT);
  pinMode(downPin, INPUT);
  pinMode(enterPin, INPUT);
  pinMode(deletePin, INPUT);
  pinMode(sendPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  printCurrentPassword();
  if(digitalRead(upPin) == HIGH){
    words[currWord][currWordChar] = words[currWord][currWordChar] + 1 % sizeof(characters);
  }
  if(digitalRead(downPin) == HIGH){
    words[currWord][currWordChar] = words[currWord][currWordChar] - 1 % sizeof(characters);
  }
  if(digitalRead(enterPin) == HIGH){
    currWordChar = currWordChar + 1 % numWords;
  }
  if(digitalRead(deletePin) == HIGH){
    currWordChar = currWordChar - 1 % numWords;
  }
  if(digitalRead(sendPin) == HIGH){
    sendCurrWordToComputer();
  }
}

void printCurrentPassword(){
  //This will send the currently selected word to the screen.
}

void sendCurrWordToComputer(){
  for(int i = 0; i < wordLength; i++){
    Keyboard.print(words[currWord][currWordChar]);
  }
}
