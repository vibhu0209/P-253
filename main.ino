#include<ezButton.h>

const int button1 = 4;
const int button2 = 22;
int count = 0;

ezButton push_button1(button1);
ezButton push_button2(button2);


void setup()
{
  Serial.begin(9600);
  push_button1.setDebounceTime(50);
  push_button2.setDebounceTime(50);
}

void loop()
{
  push_button1.loop();
  push_button2.loop();
  
  if (push_button1.isPressed())
  {
    count++;
    Serial.print("Number : ");
    Serial.println(count);
  }

  else if (push_button2.isPressed())
  {
    Serial.print("Table of ");
    Serial.println(count);
    for (int i = 1; i <= 10; i++)
    {
      Serial.print(count);
      Serial.print('*');
      Serial.print(i);
      Serial.print('\t');
      Serial.print('=');
      Serial.print('\t');
      Serial.println(count*i);
    }

    // reset the variable
    count = 0;
  }
 
}
