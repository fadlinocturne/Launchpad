void ledon(int r,int c){
  pinMode(c+15,OUTPUT);
  digitalWrite(c+15,HIGH);
  if(r==4){
  pinMode(r+10,OUTPUT);
  digitalWrite(r+10,LOW);
  }else{
  pinMode(r,OUTPUT);
  digitalWrite(r,LOW);
  }
}

void ledoff(int r,int c){
  pinMode(c+15,INPUT);
  digitalWrite(c+15,LOW);
  if(r==4){
  pinMode(r+10,INPUT);
  digitalWrite(r+10,LOW);
  }else{
  pinMode(r,INPUT);
  digitalWrite(r,LOW);
  }
}

void mode1(){
   int i,j;
    for(i=0;i<=4;i++){
    for(j=0;j<=4;j++){
    ledon(i,j);
    delay(40);
    ledoff(i,j);
    }
  }

   for(i=4;i>=0;i--){
    for(j=4;j>=0;j--){
    ledon(i,j);
    delay(40);
    ledoff(i,j);
    }
  }

  for(i=0;i<=4;i++){
    for(j=0;j<=4;j++){
    ledon(j,i);
    delay(5);
    ledoff(j,i);
    }
  }

   for(i=4;i>=0;i--){
    for(j=4;j>=0;j--){
    ledon(j,i);
    delay(5);
    ledoff(j,i);
    }
  }
}


void mode2(){   
  int i,j;
    for(i=0;i<=4;i++){
    for(j=0;j<=4;j++){
    ledon(i,j);
    }
    
    delay(100);
    ledoff(i,j);
  }

   for(i=4;i>=0;i--){
    for(j=4;j>=0;j--){
    ledon(i,j);
    }
    
    delay(100);
    ledoff(i,j);
  }

  for(i=0;i<=4;i++){
    for(j=0;j<=4;j++){
    ledon(j,i);
    }
    
    delay(100);
    ledoff(j,i);
  }

   for(i=4;i>=0;i--){
    for(j=4;j>=0;j--){
    ledon(j,i);
    }
    
    delay(100);
    ledoff(j,i);
  }
}

void setup() {
}

void loop() {
//ledon(0,0);
mode1();
mode2();
// ledon(1,1);
// ledoff(1,1);
// ledon(1,3);
// ledoff(1,3);
// ledon(3,0);
// ledoff(3,0);
// ledon(3,1);
// ledoff(3,1);
// ledon(3,2);
// ledoff(3,2);
// ledon(3,3);
// ledoff(3,3);
// ledon(3,4);
// ledoff(3,4);
//  ledon(4,1);
// ledoff(4,1);
//  ledon(4,2);
// ledoff(4,2);
//  ledon(4,3);
// ledoff(4,3);



   //ledoff(i,j);
//  }
//ledon(0,0);
//ledon(1,0);
//ledon(2,0);
//ledon(3,0);
//ledon(4,0);
//delay(100);
//ledoff(0,0);
//ledoff(1,0);
//ledoff(2,0);
//ledoff(3,0);
//ledoff(4,0);
//delay(100);
//ledon(0,1);
//ledon(1,1);
//ledon(2,1);
//ledon(3,1);
//ledon(4,1);
//delay(100);
//ledoff(0,1);
//ledoff(1,1);
//ledoff(2,1);
//ledoff(3,1);
//ledoff(4,1);
//delay(100);
//ledon(0,2);
//ledon(1,2);
//ledon(2,2);
//ledon(3,2);
//ledon(4,2);
//delay(100);
//ledoff(0,2);
//ledoff(1,2);
//ledoff(2,2);
//ledoff(3,2);
//ledoff(4,2);
//delay(100);
//ledon(0,3);
//ledon(1,3);
//ledon(2,3);
//ledon(3,3);
//ledon(4,3);
//delay(100);
//ledoff(0,3);
//ledoff(1,3);
//ledoff(2,3);
//ledoff(3,3);
//ledoff(4,3);
//delay(100);
//ledon(0,4);
//ledon(1,4);
//ledon(2,4);
//ledon(3,4);
//ledon(4,4);
//delay(100);
//ledoff(0,4);
//ledoff(1,4);
//ledoff(2,4);
//ledoff(3,4);
//ledoff(4,4);
//delay(100);
//ledoff(0,0);
//ledoff(1,0);
//ledoff(2,0);
//ledoff(3,0);
//ledoff(4,0);
//ledoff(0,1);
//ledoff(1,1);
//ledoff(2,1);
//ledoff(3,1);
//ledoff(4,1);
//ledoff(0,2);
//ledoff(1,2);
//ledoff(2,2);
//ledoff(3,2);
//ledoff(4,2);
//ledoff(0,3);
//ledoff(1,3);
//ledoff(2,3);
//ledoff(3,3);
//ledoff(4,3);
//ledoff(0,4);
//ledoff(1,4);
//ledoff(2,4);
//ledoff(3,4);
//ledoff(4,4);
//delay(50);



}
