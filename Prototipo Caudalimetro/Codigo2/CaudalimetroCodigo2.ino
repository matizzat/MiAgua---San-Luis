volatile double caudal = 0; // caudal en litros
unsigned long int tiempo = 0; //variable auxiliar para imprimir cada 1 segundo

void setup()
{
  Serial.begin(9600);  //Inicializamos la comunicación serial

  //El caudalimetro lo tenemos en el pin 2, le corresponde la interrupcion 0
  attachInterrupt(0, pulsos, RISING);  //DIGITAL Pin 2: Interrupt 0
}
void loop()
{
  if ((millis() - tiempo) >= 1000) { //imprimimos los valores cada 1 segundo
    Serial.print("Caudal: ");
    Serial.print(caudal * 1000); //multiplicamos por 1000 para pasarlo a mililitros
    Serial.println(" ml");
    tiempo = millis();
  }
}

void pulsos()   //Medimos la cantidad de pulsos
{
  caudal += 1.0 / 5880.0;
}
