#include <Wire.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  Serial1.begin(9600);//com3
  Serial1.println("Iniciamos con la medicion de temperatura"); 
  mlx.begin(); 
  Serial.begin(9600);//com5
  pinMode(42, OUTPUT);
  pinMode(44, OUTPUT);
}

void loop() {
  Serial1.print("Ambiente : "); Serial1.print(mlx.readAmbientTempC()); 
  Serial1.print("*C\   Persona : "); Serial1.print(mlx.readObjectTempC()); Serial1.println("*C");
  Serial1.println();
  delay(1000);
  if(Serial.available()){
    switch(Serial.read()){
      case 'n': digitalWrite(42, HIGH);
                digitalWrite(44, LOW);
        break;
      case 's': digitalWrite(44, HIGH);
                digitalWrite(42, LOW);
        break;
      default: break;    
      }
  }
}
