

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    inputString.trim();
    //Serial.print(inputString);

    if(inputString=="Led_0_OFF"){
      digitalWrite(2, LOW);
      Serial.print("LED0 OFF\n");             //Send to java 9 characters. \n is an escape sequence, counts as a character
    }
    
    else if(inputString=="Led_0__ON"){
      digitalWrite(2, HIGH);
      Serial.print("LED0  ON\n");
    }

    else if(inputString=="Led_1_OFF"){
      digitalWrite(3, LOW);
      Serial.print("LED1 OFF\n");
    }
    else if(inputString=="Led_1__ON"){
      digitalWrite(3, HIGH);
      Serial.print("LED1  ON\n");
    }

    else if(inputString=="Led_2_OFF"){
      digitalWrite(4, LOW);
      Serial.print("LED2 OFF\n");
    }
    else if(inputString=="Led_2__ON"){
      digitalWrite(4, HIGH);
      Serial.print("LED2  ON\n");
    }

    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}


void serialEvent() {
  while (Serial.available()) {          //received from java
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
      break;
    }
  }
}
