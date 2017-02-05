import processing.serial.*;
Serial port;

PFont f;
boolean e =true;
boolean g=false;
boolean h=false;
boolean old_h=false;
boolean p=false;
boolean q=false;
boolean old_p=false;
boolean old_q=false;
int c =0;
float x;
float y;
float z;
float a;
int b;
int i;
int [] d=new int[5];
float t;
float s;
int l;
int k;
String []n={"0","1","2","3","4","5","6","7","8","9"};
String []m={"0","1","2","3","4","5","6","7","8","9"};


void setup(){
  port = new Serial(this, "COM3", 9600);

size(1000,600);
background(255);
smooth();
f=loadFont("Consolas-BoldItalic-48.vlw");
textFont(f,48);
x=200;y=0;z=590;t=0;s=1;l=0;k=0;

fill(0);
text(m[l],5,40);
fill(0);
text(n[k],28,40);
fill(255,127,0);
text("HIT",60,40);

for (i = 1; i < 6; i++){
  a=random(2);
  b=int(a); 
 d[i-1]=b; 
if (b==0){
  fill(238,118,33);
  ellipse(-100+200*i,300,50,50);
   }else if(b==1){
  fill(0,0,255);
  rect(-125+i*200,275,50,50);
}
}
}


void draw(){

x=x+3*s;
y=y+3*s;
z=z-3*s;
t=t+4.25*s;
fill(0);
text("Time:",0,450);
fill(0,0,255);
rect(75,450,t,25);

if (mousePressed){
  h=true;
if(mouseButton==LEFT){
  p=true;}
  if(mouseButton==RIGHT){
  q=true;}
}else{h=false;p=false;q=false;}


if (mousePressed&&(c<5)&&((!old_p&&p)||(!old_q&&q))){

  if ((mouseButton==LEFT&&d[c]==0)||(mouseButton==RIGHT&&d[c]==1)){
    fill(0,205,0);
    rect(c*200,0,200,600);
    port.write(1);
  }else if((mouseButton==LEFT&&d[c]==1)||(mouseButton==RIGHT&&d[c]==0)){
    e=false;
    port.write(0);
  }
  port.clear();
  c=c+1;
  if (c==5&&e){
    g=true;}
 
}

old_h=h;old_p=p;old_q=q;
if (!e||x>800){//lose
  e=false;
  fill(255,0,0);
  rect(0,0,1000,600);
  fill(0);
  text("fail",x,y);
  text("Press any key to return!",0,500);
    fill(0);
  text(m[l],5,40);
  fill(0);
  text(n[k],28,40);
  fill(0);
  text("HIT",60,40);
  
  
  if (keyPressed){
  x=200;y=0;z=590;c=0;t=0;s=1;e=true;l=0;k=0;
  fill(255,255,255);
  rect(0,0,1000,600);
  for (i = 1; i < 6; i++){
  a=random(2);
  b=int(a); 
 d[i-1]=b; 
  if (b==0){
  fill(238,118,33);
  ellipse(-100+200*i,300,50,50);
   }else if(b==1){
  fill(0,0,255);
    rect(-125+i*200,275,50,50);}}
      fill(0);
  text(m[l],5,40);
  fill(0);
  text(n[k],28,40);
  fill(255,127,0);
  text("HIT",60,40);
}
}


//if(e&&c>4){//win

//  fill(0,205,0);
//  rect(0,0,1000,600);
//  fill(0);
//  text("win",x,z);}
  
if (g&&e){
  x=200;y=0;z=590;c=0;t=0;g=false;k=k+1;
  
  if(s<2){
  s=s+0.1;}
  
  
  if (k==10){
  l=l+1;
  k=k-10;
}
  fill(255,255,255);
  rect(0,0,1000,600);
  fill(0);
  text(m[l],5,40);
  fill(0);
  text(n[k],28,40);
  fill(255,127,0);
  text("HIT",60,40);
 
  for (i = 1; i < 6; i++){
  a=random(2);
  b=int(a); 
 d[i-1]=b; 
if (b==0){
  fill(238,118,33);
  ellipse(-100+200*i,300,50,50);
   }else if(b==1){
  fill(0,0,255);
    rect(-125+i*200,275,50,50);}}
}
  
  
}

