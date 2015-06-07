#define ledAzul     4 
#define ledVerde    5
#define ledVermelho 3
#define echoPin     9
#define trigPin     8
#define toni        A5
#define pwm         A0

unsigned long duracao, inicio; 
int musica = 1,
    distancia;

void beep (unsigned char toni, int frequencyInHertz, long timeInMilliseconds){ 
    digitalWrite(ledVermelho, LOW);  
    int x;   
    long delayAmount = (long)(1000000/frequencyInHertz);
    long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
    for (x=0;x<loopTime;x++)   {    
        digitalWrite(toni,HIGH);
        delayMicroseconds(delayAmount);
        digitalWrite(toni,LOW);
        delayMicroseconds(delayAmount);
    }    
    digitalWrite(ledVermelho, HIGH);
    delay(20);
} 

void toque(int toni, int melodia, float duracao, float pausa, int *pisco){
    int intensidade = map(melodia, 0, 1020, 0, 255);
    tone(toni, melodia, duracao);

    if(*pisco == 0){
      *pisco = 1;
      analogWrite(ledVermelho, intensidade);
      analogWrite(ledVerde, 0);
      analogWrite(ledAzul, 0);
    }else if(*pisco == 1){
      *pisco = 2;
      analogWrite(ledVerde, intensidade);
      analogWrite(ledVermelho, 0);
      analogWrite(ledAzul, 0);
    }else if(*pisco == 2){
      *pisco = 0;
      analogWrite(ledAzul, intensidade);
      analogWrite(ledVerde, 0);
      analogWrite(ledVermelho, 0);
    }
    delay(pausa);
    analogWrite(ledVerde, 0);
    analogWrite(ledVermelho, 0);
    analogWrite(ledAzul, 0);
}

void marchaImperial(){
    digitalWrite(ledAzul, HIGH);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledVermelho, HIGH);

    beep(toni, 440, 500); 
    beep(toni, 440, 500);     
    beep(toni, 440, 500); 
    beep(toni, 349, 350); 
    beep(toni, 523, 150);
    beep(toni, 440, 500);
    beep(toni, 349, 350);
    beep(toni, 523, 150);
    beep(toni, 440, 1000);
    beep(toni, 659, 500);
    beep(toni, 659, 500);
    beep(toni, 659, 500);    
    beep(toni, 698, 350); 
    beep(toni, 523, 150);
    beep(toni, 415, 500);
    beep(toni, 349, 350);
    beep(toni, 523, 150);
    beep(toni, 440, 1000);
    beep(toni, 880, 500);
    beep(toni, 440, 350); 
    beep(toni, 440, 150);
    beep(toni, 880, 500);
    beep(toni, 830, 250); 
    beep(toni, 784, 250);
    beep(toni, 740, 125);
    beep(toni, 698, 125);    
    beep(toni, 740, 250);
    delay(250);
    beep(toni, 455, 250);    
    beep(toni, 622, 500);  
    beep(toni, 587, 250);  
    beep(toni, 554, 250);  
    beep(toni, 523, 125);  
    beep(toni, 466, 125);  
    beep(toni, 523, 250);      
    delay(250);
    beep(toni, 349, 125);  
    beep(toni, 415, 500);  
    beep(toni, 349, 375);  
    beep(toni, 440, 125); 
    beep(toni, 523, 500); 
    beep(toni, 440, 375);  
    beep(toni, 523, 125); 
    beep(toni, 659, 1000); 
    beep(toni, 880, 500);
    beep(toni, 440, 350); 
    beep(toni, 440, 150);
    beep(toni, 880, 500);
    beep(toni, 830, 250); 
    beep(toni, 784, 250);
    beep(toni, 740, 125);
    beep(toni, 698, 125);    
    beep(toni, 740, 250);
    delay(250);
    beep(toni, 455, 250);    
    beep(toni, 622, 500);  
    beep(toni, 587, 250);  
    beep(toni, 554, 250);  
    beep(toni, 523, 125);  
    beep(toni, 466, 125);  
    beep(toni, 523, 250);      
    delay(250);
    beep(toni, 349, 250);  
    beep(toni, 415, 500);  
    beep(toni, 349, 375);  
    beep(toni, 523, 125); 
    beep(toni, 440, 500);            
    beep(toni, 349, 375);            
    beep(toni, 261, 125);            
    beep(toni, 440, 1000);       
}

void musicaMario(){
  int pisco = 0;
  toque(toni,660,100,150,&pisco);
  toque(toni,660,100,300,&pisco);
  toque(toni,660,100,300,&pisco);
  toque(toni,510,100,100,&pisco);
  toque(toni,660,100,300,&pisco);
  toque(toni,770,100,550,&pisco);
  toque(toni,380,100,575,&pisco);
  toque(toni,510,100,450,&pisco);
  toque(toni,380,100,400,&pisco);
  toque(toni,320,100,500,&pisco);
  toque(toni,440,100,300,&pisco);
  toque(toni,480,80,330,&pisco);
  toque(toni,450,100,150,&pisco);
  toque(toni,430,100,300,&pisco);
  toque(toni,380,100,200,&pisco);
  toque(toni,660,80,200,&pisco);
  toque(toni,760,50,150,&pisco);
  toque(toni,860,100,300,&pisco);
  toque(toni,700,80,150,&pisco);
  toque(toni,760,50,350,&pisco);
  toque(toni,660,80,300,&pisco);
  toque(toni,520,80,150,&pisco);
  toque(toni,580,80,150,&pisco);
  toque(toni,480,80,500,&pisco);
  toque(toni,510,100,450,&pisco);
  toque(toni,380,100,400,&pisco);
  toque(toni,320,100,500,&pisco);
  toque(toni,440,100,300,&pisco);
  toque(toni,480,80,330,&pisco);
  toque(toni,450,100,150,&pisco);
  toque(toni,430,100,300,&pisco);
  toque(toni,380,100,200,&pisco);
  toque(toni,660,80,200,&pisco);
  toque(toni,760,50,150,&pisco);
  toque(toni,860,100,300,&pisco);
  toque(toni,700,80,150,&pisco);
  toque(toni,760,50,350,&pisco);
  toque(toni,660,80,300,&pisco);
  toque(toni,520,80,150,&pisco);
  toque(toni,580,80,150,&pisco);
  toque(toni,480,80,500,&pisco);
  toque(toni,500,100,300,&pisco);
  toque(toni,760,100,100,&pisco);
  toque(toni,720,100,150,&pisco);
  toque(toni,680,100,150,&pisco);
  toque(toni,620,150,300,&pisco);
  toque(toni,650,150,300,&pisco);
  toque(toni,380,100,150,&pisco);
  toque(toni,430,100,150,&pisco);
  toque(toni,500,100,300,&pisco);
  toque(toni,430,100,150,&pisco);
  toque(toni,500,100,100,&pisco);
  toque(toni,570,100,220,&pisco);
  toque(toni,500,100,300,&pisco);
  toque(toni,760,100,100,&pisco);
  toque(toni,720,100,150,&pisco);
  toque(toni,680,100,150,&pisco);
  toque(toni,620,150,300,&pisco);
  toque(toni,650,200,300,&pisco);
  toque(toni,1020,80,300,&pisco);
  toque(toni,1020,80,150,&pisco);
  toque(toni,1020,80,300,&pisco);
  toque(toni,380,100,300,&pisco);
  toque(toni,500,100,300,&pisco);
  toque(toni,760,100,100,&pisco);
  toque(toni,720,100,150,&pisco);
  toque(toni,680,100,150,&pisco);
  toque(toni,620,150,300,&pisco);
  toque(toni,650,150,300,&pisco);
  toque(toni,380,100,150,&pisco);
  toque(toni,430,100,150,&pisco);
  toque(toni,500,100,300,&pisco);
  toque(toni,430,100,150,&pisco);
  toque(toni,500,100,100,&pisco);
  toque(toni,570,100,420,&pisco);
  toque(toni,585,100,450,&pisco);
  toque(toni,550,100,420,&pisco);
  toque(toni,500,100,360,&pisco);
  toque(toni,380,100,300,&pisco);
  toque(toni,500,100,300,&pisco);
  toque(toni,500,100,150,&pisco);
  toque(toni,500,100,300,&pisco);
  toque(toni,500,100,300,&pisco);
  toque(toni,760,100,100,&pisco);
  toque(toni,720,100,150,&pisco);
  toque(toni,680,100,150,&pisco);
  toque(toni,620,150,300,&pisco);
  toque(toni,650,150,300,&pisco);
  toque(toni,380,100,150,&pisco);
  toque(toni,430,100,150,&pisco);
  toque(toni,500,100,300,&pisco);
  toque(toni,430,100,150,&pisco);
  toque(toni,500,100,100,&pisco);
  toque(toni,570,100,220,&pisco);
  toque(toni,500,100,300,&pisco);
  toque(toni,760,100,100,&pisco);
  toque(toni,720,100,150,&pisco);
  toque(toni,680,100,150,&pisco);
  toque(toni,620,150,300,&pisco);
  toque(toni,650,200,300,&pisco);
  toque(toni,1020,80,300,&pisco);
  toque(toni,1020,80,150,&pisco);
  toque(toni,1020,80,300,&pisco);
  toque(toni,380,100,300,&pisco);
  toque(toni,500,100,300,&pisco);
  toque(toni,760,100,100,&pisco);
  toque(toni,720,100,150,&pisco);
  toque(toni,680,100,150,&pisco);
  toque(toni,620,150,300,&pisco);
  toque(toni,650,150,300,&pisco);
  toque(toni,380,100,150,&pisco);
  toque(toni,430,100,150,&pisco);
  toque(toni,500,100,300,&pisco);
  toque(toni,430,100,150,&pisco);
  toque(toni,500,100,100,&pisco);
  toque(toni,570,100,420,&pisco);
  toque(toni,585,100,450,&pisco);
  toque(toni,550,100,420,&pisco);
  toque(toni,500,100,360,&pisco);
  toque(toni,380,100,300,&pisco);
  toque(toni,500,100,300,&pisco);
  toque(toni,500,100,150,&pisco);
  toque(toni,500,100,300,&pisco);
  toque(toni,500,60,150,&pisco);
  toque(toni,500,80,300,&pisco);
  toque(toni,500,60,350,&pisco);
  toque(toni,500,80,150,&pisco);
  toque(toni,580,80,350,&pisco);
  toque(toni,660,80,150,&pisco);
  toque(toni,500,80,300,&pisco);
  toque(toni,430,80,150,&pisco);
  toque(toni,380,80,600,&pisco);
  toque(toni,500,60,150,&pisco);
  toque(toni,500,80,300,&pisco);
  toque(toni,500,60,350,&pisco);
  toque(toni,500,80,150,&pisco);
  toque(toni,580,80,150,&pisco);
  toque(toni,660,80,550,&pisco);
  toque(toni,870,80,325,&pisco);
  toque(toni,760,80,600,&pisco);
  toque(toni,500,60,150,&pisco);
  toque(toni,500,80,300,&pisco);
  toque(toni,500,60,350,&pisco);
  toque(toni,500,80,150,&pisco);
  toque(toni,580,80,350,&pisco);
  toque(toni,660,80,150,&pisco);
  toque(toni,500,80,300,&pisco);
  toque(toni,430,80,150,&pisco);
  toque(toni,380,80,600,&pisco);
  toque(toni,660,100,150,&pisco);
  toque(toni,660,100,300,&pisco);
  toque(toni,660,100,300,&pisco);
  toque(toni,510,100,100,&pisco);
  toque(toni,660,100,300,&pisco);
  toque(toni,770,100,550,&pisco);
  toque(toni,380,100,575,&pisco);
  noTone(toni);
}

void musicaTetris(){
  int pisco = 0;
  toque(toni,659,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,494,125,162.5,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,587,125,162.5,&pisco);
  toque(toni,659,62.5,81.25,&pisco);
  toque(toni,587,62.5,81.25,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,494,125,162.5,&pisco);
  toque(toni,440,125,162.5,&pisco);
  toque(toni,220,125,162.5,&pisco);
  toque(toni,440,125,162.5,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,659,125,162.5,&pisco);
  toque(toni,220,125,162.5,&pisco);
  toque(toni,587,125,162.5,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,494,125,162.5,&pisco);
  toque(toni,330,125,162.5,&pisco);
  toque(toni,392,125,162.5,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,587,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,659,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,220,125,162.5,&pisco);
  toque(toni,440,125,162.5,&pisco);
  toque(toni,220,125,162.5,&pisco);
  toque(toni,440,125,162.5,&pisco);
  toque(toni,220,125,162.5,&pisco);
  toque(toni,123,125,162.5,&pisco);
  toque(toni,131,125,162.5,&pisco);
  toque(toni,147,125,162.5,&pisco);
  toque(toni,587,250,325,&pisco);
  toque(toni,698,125,162.5,&pisco);
  toque(toni,880,125,162.5,&pisco);
  toque(toni,523,62.5,81.25,&pisco);
  toque(toni,523,62.5,81.25,&pisco);
  toque(toni,784,125,162.5,&pisco);
  toque(toni,698,125,162.5,&pisco);
  toque(toni,659,125,162.5,&pisco);
  toque(toni,131,125,162.5,&pisco);
  toque(toni,0,125,162.5,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,659,125,162.5,&pisco);
  toque(toni,440,62.5,81.25,&pisco);
  toque(toni,392,62.5,81.25,&pisco);
  toque(toni,587,125,162.5,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,494,125,162.5,&pisco);
  toque(toni,330,125,162.5,&pisco);
  toque(toni,494,125,162.5,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,587,125,162.5,&pisco);
  toque(toni,392,125,162.5,&pisco);
  toque(toni,659,125,162.5,&pisco);
  toque(toni,392,125,162.5,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,330,125,162.5,&pisco);
  toque(toni,440,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,440,250,325,&pisco);
  toque(toni,0,250,325,&pisco);
  toque(toni,659,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,494,125,162.5,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,587,125,162.5,&pisco);
  toque(toni,659,62.5,81.25,&pisco);
  toque(toni,587,62.5,81.25,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,494,125,162.5,&pisco);
  toque(toni,440,125,162.5,&pisco);
  toque(toni,220,125,162.5,&pisco);
  toque(toni,440,125,162.5,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,659,125,162.5,&pisco);
  toque(toni,220,125,162.5,&pisco);
  toque(toni,587,125,162.5,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,494,125,162.5,&pisco);
  toque(toni,330,125,162.5,&pisco);
  toque(toni,392,125,162.5,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,587,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,659,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,220,125,162.5,&pisco);
  toque(toni,440,125,162.5,&pisco);
  toque(toni,220,125,162.5,&pisco);
  toque(toni,440,125,162.5,&pisco);
  toque(toni,220,125,162.5,&pisco);
  toque(toni,123,125,162.5,&pisco);
  toque(toni,131,125,162.5,&pisco);
  toque(toni,147,125,162.5,&pisco);
  toque(toni,587,250,325,&pisco);
  toque(toni,698,125,162.5,&pisco);
  toque(toni,880,125,162.5,&pisco);
  toque(toni,523,62.5,81.25,&pisco);
  toque(toni,523,62.5,81.25,&pisco);
  toque(toni,784,125,162.5,&pisco);
  toque(toni,698,125,162.5,&pisco);
  toque(toni,659,125,162.5,&pisco);
  toque(toni,131,125,162.5,&pisco);
  toque(toni,0,125,162.5,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,659,125,162.5,&pisco);
  toque(toni,440,62.5,81.25,&pisco);
  toque(toni,392,62.5,81.25,&pisco);
  toque(toni,587,125,162.5,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,494,125,162.5,&pisco);
  toque(toni,330,125,162.5,&pisco);
  toque(toni,494,125,162.5,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,587,125,162.5,&pisco);
  toque(toni,392,125,162.5,&pisco);
  toque(toni,659,125,162.5,&pisco);
  toque(toni,392,125,162.5,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,330,125,162.5,&pisco);
  toque(toni,440,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,440,250,325,&pisco);
  toque(toni,0,250,325,&pisco);
  toque(toni,330,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,110,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,262,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,110,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,294,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,104,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,247,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,104,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,262,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,110,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,220,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,110,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,208,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,104,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,247,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,104,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,330,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,110,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,262,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,110,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,294,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,104,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,247,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,104,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,262,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,330,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,440,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,110,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,415,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,104,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,104,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,104,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,659,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,494,125,162.5,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,587,125,162.5,&pisco);
  toque(toni,659,62.5,81.25,&pisco);
  toque(toni,587,62.5,81.25,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,494,125,162.5,&pisco);
  toque(toni,440,125,162.5,&pisco);
  toque(toni,220,125,162.5,&pisco);
  toque(toni,440,125,162.5,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,659,125,162.5,&pisco);
  toque(toni,220,125,162.5,&pisco);
  toque(toni,587,125,162.5,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,494,125,162.5,&pisco);
  toque(toni,330,125,162.5,&pisco);
  toque(toni,392,125,162.5,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,587,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,659,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,220,125,162.5,&pisco);
  toque(toni,440,125,162.5,&pisco);
  toque(toni,220,125,162.5,&pisco);
  toque(toni,440,125,162.5,&pisco);
  toque(toni,220,125,162.5,&pisco);
  toque(toni,123,125,162.5,&pisco);
  toque(toni,131,125,162.5,&pisco);
  toque(toni,147,125,162.5,&pisco);
  toque(toni,587,250,325,&pisco);
  toque(toni,698,125,162.5,&pisco);
  toque(toni,880,125,162.5,&pisco);
  toque(toni,523,62.5,81.25,&pisco);
  toque(toni,523,62.5,81.25,&pisco);
  toque(toni,784,125,162.5,&pisco);
  toque(toni,698,125,162.5,&pisco);
  toque(toni,659,125,162.5,&pisco);
  toque(toni,131,125,162.5,&pisco);
  toque(toni,0,125,162.5,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,659,125,162.5,&pisco);
  toque(toni,440,62.5,81.25,&pisco);
  toque(toni,392,62.5,81.25,&pisco);
  toque(toni,587,125,162.5,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,494,125,162.5,&pisco);
  toque(toni,330,125,162.5,&pisco);
  toque(toni,494,125,162.5,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,587,125,162.5,&pisco);
  toque(toni,392,125,162.5,&pisco);
  toque(toni,659,125,162.5,&pisco);
  toque(toni,392,125,162.5,&pisco);
  toque(toni,523,125,162.5,&pisco);
  toque(toni,330,125,162.5,&pisco);
  toque(toni,440,125,162.5,&pisco);
  toque(toni,165,125,162.5,&pisco);
  toque(toni,440,250,325,&pisco);
  toque(toni,0,250,325,&pisco);
  noTone(toni);
}

void piscaLeds(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duracao   = pulseIn(echoPin, HIGH);
  distancia = microsecondsToCentimeters(duracao);

  Serial.print("Distancia em cm: ");
  Serial.print(distancia);
  delay(100);
  
  //potenciometro  
  int value = analogRead(pwm);
  value = map(value,0,1023,0,255);
  analogWrite(ledVermelho, value);

  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledAzul, HIGH);


   if(distancia <= 5){ // && value < 16
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, LOW);

    if((inicio == 0 && millis() > 3000) || (millis() - inicio) > 20000){
      delay(500);
      
      switch(musica){
        case 1:
          marchaImperial();
          musica = 2;
        break;
        case 2:
          musicaMario();
          musica = 3;
        break;
        case 3:
          musicaTetris();
          musica = 1;
        break;
      }
      
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledAzul, LOW); 
      delay(1000);
      inicio = millis();
      inicio = (inicio < 0)?inicio* -1:inicio;
    }
  }else if(distancia <= 10){    //  && value > 16             
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledVerde, HIGH);                   
    digitalWrite(ledAzul, HIGH);
  }else if(distancia <= 30){  // && value > 16    
    digitalWrite(ledVerde, LOW);                   
    digitalWrite(ledAzul, HIGH);
  }else if(distancia <= 50){  // && value > 16                                
    digitalWrite(ledAzul, LOW);
    digitalWrite(ledVerde, HIGH);                                 
  }else if(distancia <= 60){
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, HIGH); 
  }else{
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, LOW); 
  }

  Serial.print("| actual: ");
  Serial.print(millis());

  Serial.print("| inicio: ");
  Serial.print(inicio);

  Serial.print("| potenciometro: ");
  Serial.println(value);
  delay(100);
}

void setup(){
  Serial.begin(9600);   
  pinMode(echoPin, INPUT);  
  pinMode(trigPin, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(toni, OUTPUT);
}

long microsecondsToCentimeters(long microseconds){
  /* A velocidade do som é 340 m/s ou 29 microssegundos por centímetro.
   A rajada sonora vai e volta, portanto, para achar a distância até o objeto, tomamos metade da distância de viagem. */
  return microseconds / 29 / 2;
}

void loop(){
  piscaLeds();
}
