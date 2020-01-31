/*  Proje Adı: Discovery
 *  Kategori: İnovasyon
 *  Kod Yazarı:Süleyman Kaan Çakmak 
 *  Proje yapım :2019-2020 Alanya
 *  Proje Sahipleri:Uğur Ata Gök, Süleyman Kaan Çakmak
 *  Proje Danışmanı: İsmet Çüçen
 *  Okul: TED Alanya Koleji
██████╗░██╗░██████╗░█████╗░░█████╗░██╗░░░██╗███████╗██████╗░██╗░░░██╗
██╔══██╗██║██╔════╝██╔══██╗██╔══██╗██║░░░██║██╔════╝██╔══██╗╚██╗░██╔╝
██║░░██║██║╚█████╗░██║░░╚═╝██║░░██║╚██╗░██╔╝█████╗░░██████╔╝░╚████╔╝░
██║░░██║██║░╚═══██╗██║░░██╗██║░░██║░╚████╔╝░██╔══╝░░██╔══██╗░░╚██╔╝░░
██████╔╝██║██████╔╝╚█████╔╝╚█████╔╝░░╚██╔╝░░███████╗██║░░██║░░░██║░░░
╚═════╝░╚═╝╚═════╝░░╚════╝░░╚════╝░░░░╚═╝░░░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░

██████╗░██╗░░░░░██╗░░░██╗███████╗████████╗░█████╗░░█████╗░████████╗██╗░░██╗
██╔══██╗██║░░░░░██║░░░██║██╔════╝╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝██║░░██║
██████╦╝██║░░░░░██║░░░██║█████╗░░░░░██║░░░██║░░██║██║░░██║░░░██║░░░███████║
██╔══██╗██║░░░░░██║░░░██║██╔══╝░░░░░██║░░░██║░░██║██║░░██║░░░██║░░░██╔══██║
██████╦╝███████╗╚██████╔╝███████╗░░░██║░░░╚█████╔╝╚█████╔╝░░░██║░░░██║░░██║
╚═════╝░╚══════╝░╚═════╝░╚══════╝░░░╚═╝░░░░╚════╝░░╚════╝░░░░╚═╝░░░╚═╝░░╚═╝
                        ██
██╗░░██╗███████╗░██████╗██╗███████╗  ██████╗░░█████╗░██████╗░░█████╗░████████╗██╗░░░██╗
██║░██╔╝██╔════╝██╔════╝██║██╔════╝  ██╔══██╗██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝██║░░░██║
█████═╝░█████╗░░╚█████╗░██║█████╗░░  ██████╔╝██║░░██║██████╦╝██║░░██║░░░██║░░░██║░░░██║
██╔═██╗░██╔══╝░░░╚═══██╗██║██╔══╝░░  ██╔══██╗██║░░██║██╔══██╗██║░░██║░░░██║░░░██║░░░██║
██║░╚██╗███████╗██████╔╝██║██║░░░░░  ██║░░██║╚█████╔╝██████╦╝╚█████╔╝░░░██║░░░╚██████╔╝
╚═╝░░╚═╝╚══════╝╚═██══╝░╚═╝╚═╝░░░░░  ╚═╝░░╚═╝░╚════╝░╚═════╝░░╚════╝░░░░╚═╝░░░░╚═════╝░
 */
const int motorA1  = 2;  //Sol Motoru Burada tanımlıyoruz
const int motorB1  = 3;  //Sağ Motoru Burada tanımlıyoruz
int i = 0; //Herhangi bir değişken
int a;//Herhangi bir değişken
int j = 0; //Herhangi bir değişken
int state; //Durumu belirtir
int vSpeed = 255;
void setup() {
  pinMode(motorA1, OUTPUT);//Sol Motorun Pin durumunu burada atıyoruz.
  pinMode(motorB1, OUTPUT);//Sağ Motorun Pin durumunu burada atıyoruz.
  pinMode(12, OUTPUT);//Buzzerın Pin durumunu burada atıyoruz. 
  pinMode(7, OUTPUT); //Sol Ledin Pin durumunu burada atıyoruz.
  pinMode(6, OUTPUT);//Sağ Ledin Pin durumunu burada atıyoruz.
  Serial.begin(9600);//Seri haberleşme portunun baud rateini burada ayarlıyoruz
}

void loop() {
  //Gelen veriyi 'state' değişkenine kaydet
    if(Serial.available() > 0){     
      state = Serial.read();   
    }
    if (state == '0'){
      vSpeed=0;}
  
    else if (state == '1'){
      vSpeed=100;}
  
    else if (state == '2'){
      vSpeed=180;}
  
    else if (state == '3'){
      vSpeed=200;}
  
    else if (state == '4'){
      vSpeed=255;}
  /*İleri
  Gelen veri 'F' ise araba ileri gider.*/
    if (state == 'F') {
      analogWrite(motorA1, vSpeed); 
        analogWrite(motorB1, vSpeed);    
    }
  /*İleri Sol
  Gelen veri 'G' ise araba ileri sol(çapraz) gider.*/
    else if (state == 'G') {
      analogWrite(motorA1,vSpeed ); 
        analogWrite(motorB1, 100);   
    }
  /**İleri Sağ
  Gelen veri 'I' ise araba ileri sağ(çapraz) gider.*/
    else if (state == 'I') {
        analogWrite(motorA1, 100);  
        analogWrite(motorB1, vSpeed);      
    }
  /*Geri
  Gelen veri 'B' ise araba geri gider.*/
    else if (state == 'B') {
      analogWrite(motorA1, 0);   
        analogWrite(motorB1, 0);   
    }
  /*Geri Sol
  Gelen veri 'H' ise araba geri sol(çapraz) gider*/
    else if (state == 'H') {
      analogWrite(motorA1, 0);  
        analogWrite(motorB1, 0);
    }
  /*Geri Sağ
  Gelen veri 'J' ise araba geri sağ(çapraz) gider*/
    else if (state == 'J') {
      analogWrite(motorA1, 0);   
        analogWrite(motorB1, 0);   
    }
  /*Sol
  Gelen veri 'L' ise araba sola gider.*/
    else if (state == 'L') {
      analogWrite(motorA1, vSpeed);    
        analogWrite(motorB1, 0);
    }
  /*Sağ
  Gelen veri 'R' ise araba sağa gider*/
    else if (state == 'R') {
      analogWrite(motorA1, 0);   
        analogWrite(motorB1, vSpeed);        
    }
  
  /*Dur
  Gelen veri 'S' ise arabayı durdurur.*/
    else if (state == 'S'){
        analogWrite(motorA1, 0);  
        analogWrite(motorB1, 0);  
    }
//Gelen veri 'W' ise arabanın ön farları yanar. 
else if (a == 'W') {
digitalWrite(6 , HIGH);
}
//Gelen veri 'w' ise arabanın ön farları söner. 
else if (a == 'w') {
digitalWrite(6, LOW);
}
//Gelen veri 'V' ise araba korna çalar. 
else if (a == 'V') {
digitalWrite(12, HIGH);
}
//Gelen veri 'v' ise araba korna susar. 
else if (a == 'v') {
digitalWrite(12, LOW);
}
//Gelen veri 'U' ise arabanın arka farları yanar 
else if (a == 'U') {
digitalWrite(7, HIGH);
}
//Gelen veri 'u' ise arabanın arka farları söner
else if (a == 'u') {
digitalWrite(7 , LOW );

}
}
