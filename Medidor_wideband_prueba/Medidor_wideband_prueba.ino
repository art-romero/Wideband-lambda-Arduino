//     EARChile    Cristhian Romero Veliz  romeroveliz@gmail.com   
//            +56958592938


// Medidor AFR y LAMBDA tomando la señal de 0 a 5 Volts de un reloj Wideband

//usamos entrada A0 para medir voltaje de 0-5V esta señal se conecta desde el reloj de WideBand
#include <LiquidCrystal_I2C.h> // Libreria LCD_I2C

LiquidCrystal_I2C lcd(0x27,16,2); // si no te sale con esta direccion  puedes usar (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2) 
float lectura = 0;
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("==> EARChile <=="); 
  lcd.setCursor (2,1);
  lcd.print("AFR / LAMBDA");
  delay(4000);



  Serial.begin(9600);
}

void loop() {
 int valor = analogRead(A0);
 lectura = (valor * 5.0)/1024.0;
 Serial.println(lectura);
 
 
 Serial.print(" AIR/FUEL:  ");
  // se puede hacer una lista mayor de parametros de lectura para hacer una lectrua mas exacta 
 // es importante saber que no todos los relojes de wideband tiene la misma calibracion de voltaje v/s AFR , para ello hay que revisar la tabla de cada fabricante

  if (lectura <5.00  && lectura >= 4.84  ){
  Serial.println("MEZCLA MUY POBRE   19.98   ");
   lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("> AFR :<"); 
  lcd.setCursor (11,0);
  lcd.print(" 19.98");
    
 lcd.setCursor(0,1);
  lcd.print(">LAMBDA:<"); 
  lcd.setCursor (11,1);
  lcd.print(" 1.365");
  
  // lcd.setCursor (7,1);
 // lcd.print(lectura);
 }
 else if (lectura <4.85  && lectura >=4.67){
  Serial.println("MEZCLA MUY POBRE    19.66 ");
   lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("> AFR :<"); 
  lcd.setCursor (11,0);
  lcd.print(" 19.66");
    
 lcd.setCursor(0,1);
  lcd.print(">LAMBDA:<"); 
  lcd.setCursor (11,1);
  lcd.print(" 1.343");
  
  // lcd.setCursor (7,1);
 // lcd.print(lectura);
 }
 else if (lectura <4.68 && lectura >= 4.05){
  Serial.println("MEZCLA MUY POBRE   19.36  ");
   lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("> AFR :<"); 
  lcd.setCursor (11,0);
  lcd.print(" 19.36");
    
 lcd.setCursor(0,1);
  lcd.print(">LAMBDA:<"); 
  lcd.setCursor (11,1);
  lcd.print(" 1.322");
 }
 else if (lectura <4.06 && lectura >=3.58){
  Serial.println("MEZCLA MUY POBRE   18.10  ");
   lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("> AFR :<"); 
  lcd.setCursor (11,0);
  lcd.print(" 18.10");
    
 lcd.setCursor(0,1);
  lcd.print(">LAMBDA:<"); 
  lcd.setCursor (11,1);
  lcd.print(" 1.236");

 }
 else if (lectura <3.59  && lectura >=3.27){
  Serial.println("MEZCLA MUY POBRE    17.18  ");
   lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("> AFR :<"); 
  lcd.setCursor (11,0);
  lcd.print(" 17.18");
    
 lcd.setCursor(0,1);
  lcd.print(">LAMBDA:<"); 
  lcd.setCursor (11,1);
  lcd.print(" 1.173");
 }
 else if (lectura <3.28 && lectura >= 2.95){
 Serial.println("MEZCLA  POBRE      16.54 ");
   lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("> AFR :<"); 
  lcd.setCursor (11,0);
  lcd.print(" 16.54");
    
 lcd.setCursor(0,1);
  lcd.print(">LAMBDA:<"); 
  lcd.setCursor (11,1);
  lcd.print(" 1.130");
 }
 else if (lectura <2.96 && lectura >=2.80){
   Serial.println("MEZCLA  POBRE     15.92  ");
   lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("> AFR :<"); 
  lcd.setCursor (11,0);
  lcd.print(" 15.92");
    
 lcd.setCursor(0,1);
  lcd.print(">LAMBDA:<"); 
  lcd.setCursor (11,1);
  lcd.print(" 1.087");
 }
 
 else if (lectura <2.81 && lectura >=2.49){
   Serial.println("MEZCLA  POBRE     15.62  ");
   lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("> AFR :<"); 
  lcd.setCursor (11,0);
  lcd.print(" 15.62");
    
 lcd.setCursor(0,1);
  lcd.print(">LAMBDA:<"); 
  lcd.setCursor (11,1);
  lcd.print(" 1.067");
 }
 else if (lectura <2.50 && lectura >=2.33){
   Serial.println("MEZCLA  OK        15.00  ");
   lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("> AFR :<"); 
  lcd.setCursor (11,0);
  lcd.print(" 15.00");
    
 lcd.setCursor(0,1);
  lcd.print(">LAMBDA:<"); 
  lcd.setCursor (11,1);
  lcd.print(" 1.025");
 }
 else if (lectura <2.34 && lectura >=2.174){
   Serial.println("MEZCLA  OK        14.68  ");
   lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("> AFR :<"); 
  lcd.setCursor (11,0);
  lcd.print(" 14.68");
    
 lcd.setCursor(0,1);
  lcd.print(">LAMBDA:<"); 
  lcd.setCursor (11,1);
  lcd.print(" 1.003");
 }
 else if (lectura <2.18 && lectura >=2.02){
   Serial.println("MEZCLA  OK        14.36 ");
   lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("> AFR :<"); 
  lcd.setCursor (11,0);
  lcd.print(" 14.36");
    
 lcd.setCursor(0,1);
  lcd.print(">LAMBDA:<"); 
  lcd.setCursor (11,1);
  lcd.print(" 0.981");
 }
 else if (lectura <2.03 && lectura >=1.87){
   Serial.println("MEZCLA  OK        14.06  ");
   lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("> AFR :<"); 
  lcd.setCursor (11,0);
  lcd.print(" 14.06");
    
 lcd.setCursor(0,1);
  lcd.print(">LAMBDA:<"); 
  lcd.setCursor (11,1);
  lcd.print(" 0.960");
 }
 else if (lectura <1.87 && lectura >=1.71){
   Serial.println("MEZCLA  OK        13.74  ");
   lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("> AFR :<"); 
  lcd.setCursor (11,0);
  lcd.print(" 13.74");
    
 lcd.setCursor(0,1);
  lcd.print(">LAMBDA:<"); 
  lcd.setCursor (11,1);
  lcd.print(" 0.939");
 }
 else if (lectura <1.72 && lectura >=1.56){
   Serial.println("MEZCLA  OK        13.44");
   lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("> AFR :<"); 
  lcd.setCursor (11,0);
  lcd.print(" 13.44");
    
 lcd.setCursor(0,1);
  lcd.print(">LAMBDA:<"); 
  lcd.setCursor (11,1);
  lcd.print(" 0.918");
 }
 
 else if (lectura <1.56 && lectura >=1.39){
   Serial.println("MEZCLA  RICA      13.12 ");
   lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("> AFR :<"); 
  lcd.setCursor (11,0);
  lcd.print(" 13.12");
   
 lcd.setCursor(0,1);
  lcd.print(">LAMBDA:<"); 
  lcd.setCursor (11,1);
  lcd.print(" 0.896");
 }
 
 else if (lectura <1.40 && lectura >=1.24){
   Serial.println("MEZCLA  RICA      12.80 ");
   lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("> AFR :<"); 
  lcd.setCursor (11,0);
  lcd.print(" 12.80");
    
 lcd.setCursor(0,1);
  lcd.print(">LAMBDA:<"); 
  lcd.setCursor (11,1);
  lcd.print(" 0.874");
 }
 
 else if (lectura <1.25 && lectura >=1.08){
   Serial.println("MEZCLA  RICA      12.50  ");
   lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("> AFR :<"); 
  lcd.setCursor (11,0);
  lcd.print(" 12.50");
    
 lcd.setCursor(0,1);
  lcd.print(">LAMBDA:<"); 
  lcd.setCursor (11,1);
  lcd.print(" 0.854");
 }
 
 else if (lectura <1.09 && lectura >=0.93){
   Serial.println("MEZCLA  RICA      12.18  ");
   lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("> AFR :<"); 
  lcd.setCursor (11,0);
  lcd.print(" 12.18");
    
 lcd.setCursor(0,1);
  lcd.print(">LAMBDA:<"); 
  lcd.setCursor (11,1);
  lcd.print(" 0.832");
 }
 
 else if (lectura <0.94 && lectura >=0.77){
   Serial.println("MEZCLA  RICA      11.88  ");
   lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("> AFR :<"); 
  lcd.setCursor (11,0);
  lcd.print(" 11.88");
    
 lcd.setCursor(0,1);
  lcd.print(">LAMBDA:<"); 
  lcd.setCursor (11,1);
  lcd.print(" 0.811");
 }
 
 else if (lectura <0.78 && lectura >=0.61){
   Serial.println("MEZCLA  RICA      11.55  ");
   lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("> AFR :<"); 
  lcd.setCursor (11,0);
  lcd.print(" 11.55");
    
 lcd.setCursor(0,1);
  lcd.print(">LAMBDA:<"); 
  lcd.setCursor (11,1);
  lcd.print(" 0.790");
 }
  
 else if (lectura <0.62 && lectura >=0.46){
   Serial.println("MEZCLA  RICA      11.24  ");
   lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("> AFR :<"); 
  lcd.setCursor (11,0);
  lcd.print(" 11.24");
    
 lcd.setCursor(0,1);
  lcd.print(">LAMBDA:<"); 
  lcd.setCursor (11,1);
  lcd.print(" 0.768");
 }
  
 else if (lectura <0.47 && lectura >=0.30){
   Serial.println("MEZCLA MUY RICA   10.94  ");
   lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("> AFR :<"); 
  lcd.setCursor (11,0);
  lcd.print(" 10.94");
    
 lcd.setCursor(0,1);
  lcd.print(">LAMBDA:<"); 
  lcd.setCursor (11,1);
  lcd.print(" 0.747");
 }
  
 else if (lectura <0.31 && lectura >=0.15){
   Serial.println("MEZCLA MUY RICA   10.62  ");
   lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("> AFR :<"); 
  lcd.setCursor (11,0);
  lcd.print(" 10.62");
   
 lcd.setCursor(0,1);
  lcd.print(">LAMBDA:<"); 
  lcd.setCursor (11,1);
  lcd.print(" 0.725");
 }
  
 else if (lectura <0.16 && lectura >=0.00){
   Serial.println("MEZCLA MUY RICA   10.32  ");
   lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("> AFR :<"); 
  lcd.setCursor (11,0);
  lcd.print(" 10.32");
    
 lcd.setCursor(0,1);
  lcd.print(">LAMBDA:<"); 
  lcd.setCursor (11,1);
  lcd.print(" 0.705");
 }
 delay(500);
 
}
