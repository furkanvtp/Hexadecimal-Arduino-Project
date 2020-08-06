#include <IRremote.h>  
int a1 = 10; int a2 = 6;
int b1 = 9;  int b2 = 5;
int c1 = 2;  int c2 = A4;
int d1 = 3;  int d2 = A3;
int e1 = 4;  int e2 = A2;
int f1 = 13; int f2 = 7;
int g1 = 12; int g2 = 8;
int dp1 =A1; int dp2 =A5;
                     //Simülasyon başlatıldıktan sonra 
int i=0;             //ögrencino girilir ve ardından 
int ogrencino[10];   //FUNC/STOP tusuna basarak sonuc alınır
String ilkhex;
String sonhex;

IRrecv irrecv(11); //kizilsensordengelen degerleri oku

decode_results results; //kizilsensör okuduğu değerleri 
                       //results değişkenine tanımlıyoruz
#define guc 0xFD00FF  
#define dur 0xFD40BF                  
#define buton0 0xFD30CF    
#define buton1 0xFD08F7                      
#define buton2 0xFD8877             
#define buton3 0xFD48B7                     
#define buton4 0xFD28D7            
#define buton5 0xFDA857              
#define buton6 0xFD6897             
#define buton7 0xFD18E7               
#define buton8 0xFD9867          
#define buton9 0xFD58A7    

void setup(){
    pinMode(a1, OUTPUT);
    pinMode(b1, OUTPUT);
    pinMode(c1, OUTPUT);
    pinMode(d1, OUTPUT);
    pinMode(e1, OUTPUT);
    pinMode(f1, OUTPUT);
    pinMode(g1, OUTPUT);
    pinMode(dp1,OUTPUT);
    pinMode(a2, OUTPUT);
    pinMode(b2, OUTPUT);
    pinMode(c2, OUTPUT);
    pinMode(d2, OUTPUT);
    pinMode(e2, OUTPUT);
    pinMode(f2, OUTPUT);
    pinMode(g2, OUTPUT);
    pinMode(dp2,OUTPUT);

 irrecv.enableIRIn();  // kızıl ötesi başlatılıyor.
  
    digitalWrite(a1,HIGH);
    digitalWrite(b1,HIGH);
    digitalWrite(c1,HIGH);
    digitalWrite(d1,HIGH);
    digitalWrite(e1,HIGH);
    digitalWrite(f1,HIGH);
    digitalWrite(g1,HIGH);
    digitalWrite(dp1,HIGH);
    digitalWrite(a2,HIGH);
    digitalWrite(b2,HIGH);
    digitalWrite(c2,HIGH);
    digitalWrite(d2,HIGH);
    digitalWrite(e2,HIGH);
    digitalWrite(f2,HIGH);
    digitalWrite(g2,HIGH);
    digitalWrite(dp2,HIGH);
}

void loop(){
  
  if(irrecv.decode(&results)){

    switch(results.value){
      
      case buton0:            
   	  	ogrencino[i]=0;	//buton 0 a basılırsa ogrencino nun i. 
      	i++;         //elemanını 0 a esitler ve i'yi 1 arttırır.
        irrecv.resume();
      break;
      
      case buton1:
  	  	ogrencino[i]=1;
      	i++;
        irrecv.resume();
      break;
      
      case buton2:
   	  	ogrencino[i]=2;
      	i++;
        irrecv.resume();
      break;
      
      case buton3:
      	ogrencino[i]=3;
      	i++;
        irrecv.resume();
      break;
 
      case buton4:
      	ogrencino[i]=4;
      	i++;
        irrecv.resume();
      break;
      
      case buton5:
      	ogrencino[i]=5;
      	i++;
        irrecv.resume();
      break;
    
      case buton6:
      	ogrencino[i]=6;
      	i++;
        irrecv.resume();
      break;
   
      case buton7:
      	ogrencino[i]=7;
      	i++;
        irrecv.resume();
      break;
      
      case buton8:
      	ogrencino[i]=8;
      	i++;
        irrecv.resume();
      break;
      
      case buton9:
      	ogrencino[i]=9;
      	i++;
        irrecv.resume();
      break;
    
      case dur:
      	int ilkiki=(ogrencino[0]*10 + ogrencino[1]); //ogrencino nun ilk 2 
        int soniki=(ogrencino[i-2]*10 + ogrencino[i-1]); //son 2hanesini aldı
        ilkhex=hexcevirici(ilkiki); //ilk 2 ve son 2 hanenin hexadecimal karsılıgını 
        sonhex=hexcevirici(soniki); // bulmak icin ilgili fonksiyona gönderdi
      	
     if(ilkhex[0]=='0') //7 segmentli displayde sayı ve harfleri
       sifir();         //yakmak icin fonksiyonları cagırdık
     else if(ilkhex[0]=='1')
       bir();
     else if(ilkhex[0]=='2')
       iki();
     else if(ilkhex[0]=='3')
       uc();
     else if(ilkhex[0]=='4')
       dort();
     else if(ilkhex[0]=='5')
       bes();
     else if(ilkhex[0]=='6')
       alti();
     else if(ilkhex[0]=='7')
       yedi();
     else if(ilkhex[0]=='8')
       sekiz();
     else if(ilkhex[0]=='9')
       dokuz();
     else if(ilkhex[0]=='a')
       aharfi();
     else if(ilkhex[0]=='b')
       bharfi();
     else if(ilkhex[0]=='c')
       charfi();
     else if(ilkhex[0]=='d')
       dharfi();
     else if(ilkhex[0]=='e')
       eharfi();
     else if(ilkhex[0]=='f')
       fharfi();
          
     if(ilkhex[1]=='0') //2.ekranda yanacak degerler icin ayrı
       sifir2();        //fonksiyonlar yapıldı
     else if(ilkhex[1]=='1')
       bir2();            
     else if(ilkhex[1]=='2')
       iki2();
     else if(ilkhex[1]=='3')
       uc2();
     else if(ilkhex[1]=='4')
       dort2();
     else if(ilkhex[1]=='5')
       bes2();
     else if(ilkhex[1]=='6')
       alti2();
     else if(ilkhex[1]=='7')
       yedi2();
     else if(ilkhex[1]=='8')
       sekiz2();
     else if(ilkhex[1]=='9')
       dokuz2();
     else if(ilkhex[1]=='a')
       aharfi2();
     else if(ilkhex[1]=='b')
       bharfi2();
     else if(ilkhex[1]=='c')
       charfi2();
     else if(ilkhex[1]=='d')
       dharfi2();
     else if(ilkhex[1]=='e')
       eharfi2();
     else if(ilkhex[1]=='f')
       fharfi2();
       
        delay(1000); //ilk 2 hanenin hexadecimal degerini  
        //yaktıktan sonra ekranları söndürdük
        digitalWrite(a1,HIGH);
        digitalWrite(b1,HIGH);
        digitalWrite(c1,HIGH);
        digitalWrite(d1,HIGH);
        digitalWrite(e1,HIGH);
        digitalWrite(f1,HIGH);
        digitalWrite(g1,HIGH);
        digitalWrite(dp1,HIGH);
        digitalWrite(a2,HIGH);
        digitalWrite(b2,HIGH);
        digitalWrite(c2,HIGH);
        digitalWrite(d2,HIGH);
        digitalWrite(e2,HIGH);
        digitalWrite(f2,HIGH);
        digitalWrite(g2,HIGH);
        digitalWrite(dp2,HIGH);
          
        delay(500);
     //simdide son 2 hanenin hexadecimal degerini yakıyoruz
     if(sonhex[0]=='0')
       sifir();
     else if(sonhex[0]=='1')
       bir();
     else if(sonhex[0]=='2')
       iki();
     else if(sonhex[0]=='3')
       uc();
     else if(sonhex[0]=='4')
       dort();
     else if(sonhex[0]=='5')
       bes();
     else if(sonhex[0]=='6')
       alti();
     else if(sonhex[0]=='7')
       yedi();
     else if(sonhex[0]=='8')
       sekiz();
     else if(sonhex[0]=='9')
       dokuz();
     else if(sonhex[0]=='a')
       aharfi();
     else if(sonhex[0]=='b')
       bharfi();
     else if(sonhex[0]=='c')
       charfi();
     else if(sonhex[0]=='d')
       dharfi();
     else if(sonhex[0]=='e')
       eharfi();
     else if(sonhex[0]=='f')
       fharfi();
      
     if(sonhex[1]=='0')
       sifir2();
     else if(sonhex[1]=='1')
       bir2();
     else if(sonhex[1]=='2')
       iki2();
     else if(sonhex[1]=='3')
       uc2();
     else if(sonhex[1]=='4')
       dort2();
     else if(sonhex[1]=='5')
       bes2();
     else if(sonhex[1]=='6')
       alti2();
     else if(sonhex[1]=='7')
       yedi2();
     else if(sonhex[1]=='8')
       sekiz2();
     else if(sonhex[1]=='9')
       dokuz2();
     else if(sonhex[1]=='a')
       aharfi2();
     else if(sonhex[1]=='b')
       bharfi2();
     else if(sonhex[1]=='c')
       charfi2();
     else if(sonhex[1]=='d')
       dharfi2();
     else if(sonhex[1]=='e')
       eharfi2();
     else if(sonhex[1]=='f')
       fharfi2();
        
     delay(3000); 
    }
  }
} //sayılar ve harflerin yanmasını saglayan fonksiyonlar
    void sifir(){           
    digitalWrite(a1, 0);
    digitalWrite(b1, 0);
    digitalWrite(c1, 0);
    digitalWrite(d1, 0);
    digitalWrite(e1, 0);
    digitalWrite(f1, 0);
    digitalWrite(g1, 1);
    digitalWrite(dp1, 1);
    }
    void bir(){
    digitalWrite(a1, 1);
    digitalWrite(b1, 0);
    digitalWrite(c1, 0);
    digitalWrite(d1, 1);
    digitalWrite(e1, 1);
    digitalWrite(f1, 1);
    digitalWrite(g1, 1);
    digitalWrite(dp1, 1);
    }
    void iki(){
    digitalWrite(a1, 0);
    digitalWrite(b1, 0);
    digitalWrite(c1, 1);
    digitalWrite(d1, 0);
    digitalWrite(e1, 0);
    digitalWrite(f1, 1);
    digitalWrite(g1, 0);
    digitalWrite(dp1, 1);
    }
    void uc(){
    digitalWrite(a1, 0);
    digitalWrite(b1, 0);
    digitalWrite(c1, 0);
    digitalWrite(d1, 0);
    digitalWrite(e1, 1);
    digitalWrite(f1, 1);
    digitalWrite(g1, 0);
    digitalWrite(dp1, 1);
    }   
    void dort(){
    digitalWrite(a1, 1);
    digitalWrite(b1, 0);
    digitalWrite(c1, 0);
    digitalWrite(d1, 1);
    digitalWrite(e1, 1);
    digitalWrite(f1, 0);
    digitalWrite(g1, 0);
    digitalWrite(dp1, 1);
    }   
    void bes(){
    digitalWrite(a1, 0);
    digitalWrite(b1, 1);
    digitalWrite(c1, 0);
    digitalWrite(d1, 0);
    digitalWrite(e1, 1);
    digitalWrite(f1, 0);
    digitalWrite(g1, 0);
    digitalWrite(dp1, 1);
    }   
    void alti(){
    digitalWrite(a1, 0);
    digitalWrite(b1, 1);
    digitalWrite(c1, 0);
    digitalWrite(d1, 0);
    digitalWrite(e1, 0);
    digitalWrite(f1, 0);
    digitalWrite(g1, 0);
    digitalWrite(dp1, 1);
    }   
    void yedi(){
    digitalWrite(a1, 0);
    digitalWrite(b1, 0);
    digitalWrite(c1, 0);
    digitalWrite(d1, 1);
    digitalWrite(e1, 1);
    digitalWrite(f1, 1);
    digitalWrite(g1, 1);
    digitalWrite(dp1, 1);
    }   
    void sekiz(){
    digitalWrite(a1, 0);
    digitalWrite(b1, 0);
    digitalWrite(c1, 0);
    digitalWrite(d1, 0);
    digitalWrite(e1, 0);
    digitalWrite(f1, 0);
    digitalWrite(g1, 0);
    digitalWrite(dp1, 1);
    }   
    void dokuz(){
    digitalWrite(a1, 0);
    digitalWrite(b1, 0);
    digitalWrite(c1, 0);
    digitalWrite(d1, 0);
    digitalWrite(e1, 1);
    digitalWrite(f1, 0);
    digitalWrite(g1, 0);
    digitalWrite(dp1, 1);
    }  
    void aharfi(){
    digitalWrite(a1, 0);
    digitalWrite(b1, 0);
    digitalWrite(c1, 0);
    digitalWrite(d1, 1);
    digitalWrite(e1, 0);
    digitalWrite(f1, 0);
    digitalWrite(g1, 0);
    digitalWrite(dp1, 1);
    } 
    void bharfi(){
    digitalWrite(a1, 0);
    digitalWrite(b1, 0);
    digitalWrite(c1, 0);
    digitalWrite(d1, 0);
    digitalWrite(e1, 0);
    digitalWrite(f1, 0);
    digitalWrite(g1, 0);
    digitalWrite(dp1, 1);
    } 
    void charfi(){
    digitalWrite(a1, 0);
    digitalWrite(b1, 1);
    digitalWrite(c1, 1);
    digitalWrite(d1, 0);
    digitalWrite(e1, 0);
    digitalWrite(f1, 0);
    digitalWrite(g1, 1);
    digitalWrite(dp1, 1);
    } 
    void dharfi(){
    digitalWrite(a1, 1);
    digitalWrite(b1, 0);
    digitalWrite(c1, 0);
    digitalWrite(d1, 0);
    digitalWrite(e1, 0);
    digitalWrite(f1, 1);
    digitalWrite(g1, 0);
    digitalWrite(dp1, 1);
    } 
    void eharfi(){
    digitalWrite(a1, 0);
    digitalWrite(b1, 1);
    digitalWrite(c1, 1);
    digitalWrite(d1, 0);
    digitalWrite(e1, 0);
    digitalWrite(f1, 0);
    digitalWrite(g1, 0);
    digitalWrite(dp1, 1);
    } 
    void fharfi(){
    digitalWrite(a1, 0);
    digitalWrite(b1, 1);
    digitalWrite(c1, 1);
    digitalWrite(d1, 1);
    digitalWrite(e1, 0);
    digitalWrite(f1, 0);
    digitalWrite(g1, 0);
    digitalWrite(dp1, 1);
    }  
    void sifir2(){  //2. ekranın yanmasını saglayan fonksiyonlar
    digitalWrite(a2, 0);
    digitalWrite(b2, 0);
    digitalWrite(c2, 0);
    digitalWrite(d2, 0);
    digitalWrite(e2, 0);
    digitalWrite(f2, 0);
    digitalWrite(g2, 1);
    digitalWrite(dp2, 1);
    }
    void bir2(){
    digitalWrite(a2, 1);
    digitalWrite(b2, 0);
    digitalWrite(c2, 0);
    digitalWrite(d2, 1);
    digitalWrite(e2, 1);
    digitalWrite(f2, 1);
    digitalWrite(g2, 1);
    digitalWrite(dp2, 1);
    }
    void iki2(){
    digitalWrite(a2, 0);
    digitalWrite(b2, 0);
    digitalWrite(c2, 1);
    digitalWrite(d2, 0);
    digitalWrite(e2, 0);
    digitalWrite(f2, 1);
    digitalWrite(g2, 0);
    digitalWrite(dp2, 1);
    }
    void uc2(){
    digitalWrite(a2, 0);
    digitalWrite(b2, 0);
    digitalWrite(c2, 0);
    digitalWrite(d2, 0);
    digitalWrite(e2, 1);
    digitalWrite(f2, 1);
    digitalWrite(g2, 0);
    digitalWrite(dp2, 1);
    }   
    void dort2(){
    digitalWrite(a2, 1);
    digitalWrite(b2, 0);
    digitalWrite(c2, 0);
    digitalWrite(d2, 1);
    digitalWrite(e2, 1);
    digitalWrite(f2, 0);
    digitalWrite(g2, 0);
    digitalWrite(dp2, 1);
    }   
    void bes2(){
    digitalWrite(a2, 0);
    digitalWrite(b2, 1);
    digitalWrite(c2, 0);
    digitalWrite(d2, 0);
    digitalWrite(e2, 1);
    digitalWrite(f2, 0);
    digitalWrite(g2, 0);
    digitalWrite(dp2, 1);
    }   
    void alti2(){
    digitalWrite(a2, 0);
    digitalWrite(b2, 1);
    digitalWrite(c2, 0);
    digitalWrite(d2, 0);
    digitalWrite(e2, 0);
    digitalWrite(f2, 0);
    digitalWrite(g2, 0);
    digitalWrite(dp2, 1);
    }   
    void yedi2(){
    digitalWrite(a2, 0);
    digitalWrite(b2, 0);
    digitalWrite(c2, 0);
    digitalWrite(d2, 1);
    digitalWrite(e2, 1);
    digitalWrite(f2, 1);
    digitalWrite(g2, 1);
    digitalWrite(dp2, 1);
    }   
    void sekiz2(){
    digitalWrite(a2, 0);
    digitalWrite(b2, 0);
    digitalWrite(c2, 0);
    digitalWrite(d2, 0);
    digitalWrite(e2, 0);
    digitalWrite(f2, 0);
    digitalWrite(g2, 0);
    digitalWrite(dp2, 1);
    }   
    void dokuz2(){
    digitalWrite(a2, 0);
    digitalWrite(b2, 0);
    digitalWrite(c2, 0);
    digitalWrite(d2, 0);
    digitalWrite(e2, 1);
    digitalWrite(f2, 0);
    digitalWrite(g2, 0);
    digitalWrite(dp2, 1);
    }  
    void aharfi2(){
    digitalWrite(a2, 0);
    digitalWrite(b2, 0);
    digitalWrite(c2, 0);
    digitalWrite(d2, 1);
    digitalWrite(e2, 0);
    digitalWrite(f2, 0);
    digitalWrite(g2, 0);
    digitalWrite(dp2, 1);
    } 
    void bharfi2(){
    digitalWrite(a2, 0);
    digitalWrite(b2, 0);
    digitalWrite(c2, 0);
    digitalWrite(d2, 0);
    digitalWrite(e2, 0);
    digitalWrite(f2, 0);
    digitalWrite(g2, 0);
    digitalWrite(dp2, 1);
    } 
    void charfi2(){
    digitalWrite(a2, 0);
    digitalWrite(b2, 1);
    digitalWrite(c2, 1);
    digitalWrite(d2, 0);
    digitalWrite(e2, 0);
    digitalWrite(f2, 0);
    digitalWrite(g2, 1);
    digitalWrite(dp2, 1);
    } 
    void dharfi2(){
    digitalWrite(a2, 1);
    digitalWrite(b2, 0);
    digitalWrite(c2, 0);
    digitalWrite(d2, 0);
    digitalWrite(e2, 0);
    digitalWrite(f2, 1);
    digitalWrite(g2, 0);
    digitalWrite(dp2, 1);
    } 
    void eharfi2(){
    digitalWrite(a2, 0);
    digitalWrite(b2, 1);
    digitalWrite(c2, 1);
    digitalWrite(d2, 0);
    digitalWrite(e2, 0);
    digitalWrite(f2, 0);
    digitalWrite(g2, 0);
    digitalWrite(dp2, 1);
    } 
    void fharfi2(){
    digitalWrite(a2, 0);
    digitalWrite(b2, 1);
    digitalWrite(c2, 1);
    digitalWrite(d2, 1);
    digitalWrite(e2, 0);
    digitalWrite(f2, 0);
    digitalWrite(g2, 0);
    digitalWrite(dp2, 1);
    } 

String hexcevirici(int number){ //hexadecimale ceviren fonk.

  char hexstr[2],harf;
  int bolum,kalan;
    
  kalan=number%16; 
  bolum=number/16;
    
  if(kalan>9){  //sayının 16'ya bölümünden kalan 9 dan büyükse
                //hexadecimal degeri harflere esit oluyor
    if(kalan==10){
        harf='a';}
    else if(kalan==11){
        harf='b';}
    else if(kalan==12){
        harf='c';}
    else if(kalan==13){
        harf='d';}
    else if(kalan==14){
        harf='e';}
    else if(kalan==15){
        harf='f';}
    
    bolum= bolum + '0'; //int degeri char a dönüstürüyor    
    hexstr[0] = bolum ;
    hexstr[1] = harf ;
}            //sayının 16'ya bölümünden kalan 9 dan küçükse 
  else{      //hexadecimal deger sayının kendisine esit olur  
    kalan= kalan + '0'; //int degeri char a dönüstürüyor 
    bolum= bolum + '0'; //int degeri char a dönüstürüyor 
    hexstr[0] = bolum ;
    hexstr[1] = kalan ;}
  return hexstr ;
}
