#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
boolean gg=true;
int a_data = 0; // 创建变量用于储存在串行端口收到的值
int ledPin = 13;//设定一个LED插口，用于检测收到的值
int fmq=8;
int n=0;
int thisNote=0;
int lastdata=0;
int melody[] = {NOTE_G5,NOTE_C6,NOTE_C6,NOTE_C6,NOTE_C6,NOTE_G5,NOTE_A5,NOTE_B5,NOTE_C6,NOTE_C6,
0,NOTE_E6,NOTE_C6,NOTE_D6,NOTE_E6,NOTE_G6,NOTE_G6,NOTE_G6,NOTE_E6,NOTE_E6,NOTE_C6,NOTE_E6,
NOTE_G6,NOTE_E6,NOTE_D6,NOTE_D6,NOTE_A6,NOTE_G6,NOTE_D6,NOTE_E6,NOTE_G6,NOTE_E6,NOTE_G6,NOTE_E6,NOTE_D6,
NOTE_E6,NOTE_C6,NOTE_D6,NOTE_E6,0,NOTE_G6,NOTE_A5,NOTE_C6,NOTE_C6,NOTE_E6,NOTE_E6,NOTE_G6,NOTE_G6,
NOTE_D6,NOTE_D6,NOTE_D6,NOTE_A5,NOTE_A5,NOTE_D6,NOTE_G5,NOTE_C6,NOTE_C6,NOTE_E6,NOTE_E6,NOTE_G6,NOTE_G6,
NOTE_C6,NOTE_E6,NOTE_G6,NOTE_G6,NOTE_A6,NOTE_G6,NOTE_E6,NOTE_C6,NOTE_G6,NOTE_G6,NOTE_G6,
NOTE_E6,0,NOTE_E6,0,NOTE_G5,NOTE_C6,NOTE_E5,NOTE_C6,NOTE_G6,NOTE_G6,NOTE_G6,NOTE_E6,0,NOTE_C6,0,NOTE_G5,NOTE_C6,NOTE_G5,NOTE_C6,NOTE_G5,NOTE_C6,NOTE_C6,0};
int noteDurations[] = {6,2,2,4,12,6,12,12,3,3,6,6,6,12,12,4,12,3,4,12,4,12,4,12,3,1.5,
3,3,3,3,6,3,6,6,12,12,4,12,3,3,4,12,6,6,4,12,4,12,6,6,6,4,12,2,6,2,6,2,6,1.5,1.5,4,12,
4,12,3,3,4,12,6,6,6,6,6,6,6,3,3,4,12,6,6,6,6,6,6,6,3,3,3,3,3,3,3,3};

void setup() {
  Serial.begin(9600);//定义数据传输率为9600比特
  pinMode(ledPin, OUTPUT);//定义13号插口为输出模式  
//  pinMode(8,OUTPUT);

//  for (int thisNote = 0; thisNote < 95;thisNote++){
//
//     // to calculate the note duration, take one second 
//     // divided by the note type.
//     int noteDuration = 1000/noteDurations[thisNote];
//     tone(8, melody[thisNote],noteDuration);
//
//     // to distinguish the notes, set a minimum time between them.
//     // the note's duration + 30% seems to work well:
//     int pauseBetweenNotes = noteDuration * 1.30;
//     delay(pauseBetweenNotes);
//     // stop the tone playing:
//     noTone(8);
// 
//  }
}
void loop() {  
 
  if (Serial.available() > 0) {// 在收到数据后再做出处理:   
  
 
  if (gg){
  if (thisNote==95){thisNote=0;};
  thisNote=thisNote+1;

     // to calculate the note duration, take one second 
     // divided by the note type.
     int noteDuration = 1000/noteDurations[thisNote];
    tone(fmq, melody[thisNote],noteDuration);

     // to distinguish the notes, set a minimum time between them.
     // the note's duration + 30% seems to work well:
     int pauseBetweenNotes = noteDuration * 1.30;
     delay(pauseBetweenNotes);
     // stop the tone playing:
     noTone(fmq);
  }
  
    a_data = Serial.read(); // 将收到的值储存在变量中
    if(a_data){//如果收到“1”（a_data为真），点亮LED，否则熄灭
      digitalWrite(ledPin, HIGH);
    }
    else{
      digitalWrite(ledPin, LOW);
      gg=false;thisNote=0;
    }
    if (lastdata==0&&a_data==1){gg=true;}
    lastdata=a_data;
  }
}
