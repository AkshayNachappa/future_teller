//library for keypad
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = 
{
     {'1','2','3'},
     {'4','5','6'},
     {'7','8','9'},
     {'*','0','#'}
};

byte rowPins[ROWS] = {13, 12, 14, 27}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {26, 25, 33}; //connect to the column pinouts of the keypad
// defining pins ,keypad and variables
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
String x[99][2];
const int ledpin = 2;
const int ledpin2=23;
const int freq= 5000;
const int ledChannel=0;
const int ledChannel2=1;
const int resolution= 8;
const int trigPin = 4;
const int echoPin = 5;
long duration;
int distance;
int z,c,v,b,n,m,l,k,j,i;
char key;

void setup() {
  // put your setup code here, to run once:

Serial.begin(300);
delay(300);
//for random consecutive numbers 
randomSeed(analogRead(0));



// for PWM of motor 
 ledcSetup(ledChannel,freq,resolution);
 ledcAttachPin(ledpin,ledChannel);
 ledcSetup(ledChannel2,freq,resolution);
 ledcAttachPin(ledpin2,ledChannel2);
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);

}

void loop() 
{ 
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;//
  // main code
  
  // source array or database 
  String x[99][2] = 
{
     {"getting married"},// denied from
     {"singing in bathroom"},
     {"having children"},
     {"entering Wankhede stadium"},
     {"entering bars"},
     {"bathing"},
     {"supporting your favourite IPL team"},
     {"stalking"},
     {"playing PUBG"},
     {"bunking any class"},//Q1 end
     {"vaishnavi upahar"},// honeymoon
     {"paris"},
     {"ooty"},
     {"indian railway"},
     {"mars"},
     {"moon"},
     {"pakistan"},
     {"backseat of dancing car "},
     {"public washroom"},
     {"ERROR:404 - you'll die single"},//Q2 end
     {"carving your lover's name on wall"},//arrested for
     {"puncturing your teacher's car"},
     {"being quiet sitting in the last bench"},
     {"kicking your friend's ass"},
     {"watching GOT sitting inside a bush"},
     {"telling Ee Sala Cup Namde"},
     {"peeing in the pool"},
     {"not wearing ID card to college"},
     {"complimenting your best friend"},
     {"not taking bath for a week"},//q3 end
     {"constipation"},// die coz of
     {"drooling"},
     {"falling from a bungee jump"},
     {"uncontrollable laughter"},
     {"loose motion"},
     {"excessive farting"},
     {"drowning in a comod"},
     {"falling from a giant wheel"},
     {"rabies"},
     {"HIV-AIDS"},//q4 end
     {"getting avg within 2 internals"},// famous for
     {"strip dancing"},
     {"getting highest package in campus placement"},
     {"stinky feet"},
     {"bargaining in malls"},
     {"flirting"},
     {"writing notes in engineering"},
     {"farting in public"},
     {"back answering the teacher"},
     {"answering in class being a last bencher"},// q5 end
     {"peeing in pool"},// embarrased in public
     {"not having zipped your pant"},
     {"singing wrong lyrics loudly"},
     {"getting your proposal rejected"},
     {"getting caught while stealing from beggar's bowl "},
     {"digging nose"},
     {"farting "},
     {"wearing T-shirt inside out"},
     {"towel slipping"},// q6 end
     {"your best friend's fiance"},// marry your
     {"your ex"},
     {"your college crush"},
     {"your teacher"},
     {"sexiest person alive"},
     {"~namgella yaar beeltare "},
     {"your best friend's ex"},
     {"your childhood best friend"},
     {"the person wearing black top right now"},
     {"the person right behind you"},// q7 end
     {"2 rupees change"},// kill your best friend for
     {" not returning pen"},
     {"getting into a relationship"},
     {"dating your ex"},
     {"having another secretive best friend"},
     {"not liking dinchak pooja"},
     {"lying about not studying"},
     {"scoring more than you"},
     {"stealing the last piece of your pizza"},
     {"fun ;-; coz i'm bored"},//q8 end
     {"Nithyananda swamy"},// past life
     {"principal of NIE"},
     {"high profile gangster"},                
     {"skunk"},
     {"humble politician"},
     {"superstar"},
     {"belly dancer"},
     {"mermaid"},
     {"martian"},
     {"IIT topper"}// q9 end
           
     
};
     // distance from ultrasonic 
if (distance<20) 
 {
  
  delay(1000);
  for(i=0;i<=255;i++)
  { //PWM for motors
    ledcWrite(ledChannel,i);
    ledcWrite(ledChannel2,i);
    delay(64);
  }
  //digitalWrite(2,HIGH);
  // displayed questions
  Serial.println("In the future");
  Serial.println("1 - you'll be denied from...");
  Serial.println("2 - your honeymoon destination will be....");
  Serial.println("3 - you will be arrested for....");
  Serial.println("4 - you'll die because of...");
  Serial.println("5 - you'll be popular for....");
  Serial.println("6 - you'll be embarrassed in public for....");
  Serial.println("7 - you'll be married to....");
  Serial.println("8 - you'll kill your best friend for....");
  //Serial.println("......................................");
  Serial.println("9 - In your next life you'll be....");
  Serial.println("PRESS THE KEY WITHIN 5 SECS FOR ACCURATE RESULTS");
 

  
// if(key= NO_KEY)
//  {
//    Serial.println("press a key");
//  }
  while(key== NO_KEY)
    {
      key = keypad.getKey();
    }
    
    ledcWrite(ledChannel,100);
    ledcWrite(ledChannel2,0);     
    delay(3000);
        
   ledcWrite(ledChannel2,100);
   ledcWrite(ledChannel,0);
   delay(3000);
   ledcWrite(ledChannel2,0);
   ledcWrite(ledChannel,0);    
       
  Serial.print("You have pressed ");
  Serial.print(key);
   delay(3000);
   Serial.println("");
   
   Serial.println("Analyzing.");
   for(int q=1;q<8;q++)
   {
    Serial.print(".");
     ledcWrite(ledChannel,255);
    ledcWrite(ledChannel2,0);
    delay(250);
    ledcWrite(ledChannel2,255);
    ledcWrite(ledChannel,0);
    delay(250);
   }
   Serial.println("");
   ledcWrite(ledChannel2,255);
   ledcWrite(ledChannel,255);
  Serial.println("Looking into your future.");
  for(int w=1;w<4;w++)
   {
    Serial.print(".");
    delay(500);
   }
    
   // random answer generation 

   if (key=='1')
   {
    Serial.println("you'll be denied from ");
    z=random(0,10);
    delay(50);
    Serial.println(x[z][0]);
   }
   if (key=='2')
   {
    Serial.println("your honeymoon destination will be ");
    c=random(10,20);
    delay(50);
    Serial.println(x[c][0]);
   }
   if (key=='3')
   {
    Serial.println("you will be arrested for ");
    v=random(20,30);
    delay(50);
    Serial.println(x[v][0]);
   }
   if (key=='4')
   {
    Serial.println("you'll die because of ");
    j=random(30,40);
    delay(50);
    Serial.println(x[j][0]);
   }
   if (key=='5')
   {
    Serial.println("you'll be popular for ");
    b=random(40,50);
    delay(50);
    Serial.println(x[b][0]);
   } 
   if (key=='6')
   {
    Serial.println("you'll be embarrassed in public because ");
    n=random(50,60);
    delay(50);
    Serial.println(x[n][0]);
   }  
   if (key=='7')
   {
    Serial.println("you'll be married to ");
    m=random(60,70);
    delay(50);
    Serial.println(x[m][0]);
   } 
   if (key=='8')
   {
    Serial.println("you'll kill your best friend for ");
    l=random(70,80);
    delay(50);
    Serial.println(x[l][0]);
   }
   if (key=='9')
   {
    Serial.println("In your next life you'll be ");
    k=random(80,90);
    delay(50);
    Serial.println(x[k][0]);
   }
   
delay(5000);
Serial.println();
Serial.println();
   

}
}









   
