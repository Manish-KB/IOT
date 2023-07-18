#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

  #include <WiFiClientSecure.h>
  #include <UniversalTelegramBot.h>
  #include <ArduinoJson.h>


#ifndef STASSID
#define STASSID "ACT_TPlink_2.4GHz"
#define STAPSK  "deveduk6"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

//////////////////////////////////////////////////////////
#define BOTtoken "5402135498:AAFnrCsWVTowQfxTTYzpWD5NijhjPZV1i_g"  // your Bot Token (Get from Botfather)
  
  // Use @myidbot to find out the chat ID of an individual or a group
  // Also note that you need to click "start" on a bot before it can
  // message you
  #define CHAT_ID "1510589294"
  
  X509List cert(TELEGRAM_CERTIFICATE_ROOT);
  WiFiClientSecure client;
  UniversalTelegramBot bot(BOTtoken, client);
  const int buzz=13;
  const int trigPin = 4;
  const int echoPin = 14;
  int d=200;
   String myString;
  int botRequestDelay = 1000;
  unsigned long lastTimeBotRan;
  int n=50;
  int freq=300;
  int cnt1=5;
  int cnt2=5;
  long duration; // variable for the duration of sound wave travel
  int distance;
  // Indicates when motion is detected
  int mode=0;
  
//////////////////////////////////////////////////////////
void setup() {
  
//////////////////////////////////////////////////////////
 pinMode( buzz ,OUTPUT);
digitalWrite(buzz, HIGH);   
          delay(100);                       
          digitalWrite(buzz, LOW);    
          

    
    Serial.begin(9600);
    configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
    client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org
  
   
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); 
  

    // Attempt to connect to Wifi network:
    Serial.print("Connecting Wifi: ");
    Serial.println(ssid);
  
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
  
    while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(500);
    }
  
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  pinMode( buzz ,OUTPUT);
digitalWrite(buzz, HIGH);   
          delay(500);                       
          digitalWrite(buzz, LOW);    
          
    bot.sendMessage(CHAT_ID, "Device has started", "");
/////////////////////////////////////////////////////////
  Serial.println("Booting");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }

  // Port defaults to 8266
  // ArduinoOTA.setPort(8266);

  // Hostname defaults to esp8266-[ChipID]
  // ArduinoOTA.setHostname("myesp8266");

  // No authentication by default
  // ArduinoOTA.setPassword("admin");

  // Password can be set with it's md5 value as well
  // MD5(admin) = 21232f297a57a5a743894a0e4a801fc3,.
  // ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3");

  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) {
      type = "sketch";
    } else { // U_FS
      type = "filesystem";
    }

    // NOTE: if updating FS this would be the place to unmount FS using FS.end()
    Serial.println("Start updating " + type);
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) {
      Serial.println("Auth Failed");
    } else if (error == OTA_BEGIN_ERROR) {
      Serial.println("Begin Failed");
    } else if (error == OTA_CONNECT_ERROR) {
      Serial.println("Connect Failed");
    } else if (error == OTA_RECEIVE_ERROR) {
      Serial.println("Receive Failed");
    } else if (error == OTA_END_ERROR) {
      Serial.println("End Failed");
    }
  });
  ArduinoOTA.begin();
  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
 pinMode( buzz ,OUTPUT);
digitalWrite(buzz, HIGH);   
          delay(100);                       
          digitalWrite(buzz, LOW);   
  /////////////////////////////////////////
   #define BOTtoken "5402135498:AAFnrCsWVTowQfxTTYzpWD5NijhjPZV1i_g"  // your Bot Token (Get from Botfather)
  
  // Use @myidbot to find out the chat ID of an individual or a group
  // Also note that you need to click "start" on a bot before it can
  // message you
  #define CHAT_ID "1510589294"
  
  X509List cert(TELEGRAM_CERTIFICATE_ROOT);
  WiFiClientSecure client;
  UniversalTelegramBot bot(BOTtoken, client);
  const int buzz=13;
  const int trigPin = 4;
  const int echoPin = 14;
  int d=200;
   String myString;
  int botRequestDelay = 1000;
  unsigned long lastTimeBotRan;
  int n=150;
  int freq=300;
  int cnt1=5;
  int cnt2=5;
  long duration; // variable for the duration of sound wave travel
  int distance;
  // Indicates when motion is detected
  int mode=0;
  
}

bool ota_flag=true;
uint16_t time_elapsed =0;

void loop() {
  if(ota_flag){
    digitalWrite(buzz, HIGH);   
          delay(100);                       
          digitalWrite(buzz, LOW);
    while(time_elapsed<15000){
  ArduinoOTA.handle();
  time_elapsed=millis();
  delay(10);
    }
    ota_flag=false;
  }

////////////////////////////////////////////////////////////////////////
for(int j=0;j<freq;j++){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
    Serial.println(distance);
   if(distance<n && distance>0)
   { 
    if(mode==0){
    Serial.println("Motion Detected");
 
  myString ="Motion Detected at: "+ String(distance)+"cm";
        bot.sendMessage(CHAT_ID,myString,"");
    }
    else if(mode==11){
      if(cnt1!=0){
for(int j=0;j<40;j++){      
          tone(buzz,1000);
delay(80);
noTone(buzz);
delay(80);  
          }
      }
      if(cnt1>0){cnt1--;}
       Serial.println("Motion Detected");
  myString ="Motion Detected at: "+ String(distance)+"cm";
        bot.sendMessage(CHAT_ID,myString,"");
    }
else if(mode==12){
  if(cnt2!=0){
for(int i=0;i<20;i++){
          digitalWrite(buzz, HIGH);   
          delay(100);                       
          digitalWrite(buzz, LOW);    
          delay(100);
  }
  }
  if(cnt2>0){cnt2--;}
       Serial.println("Motion Detected");
  myString ="Motion Detected at: "+ String(distance)+"cm";
        bot.sendMessage(CHAT_ID,myString,"");
    }
   }
    }
  
  
   int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
   while(numNewMessages) {
        Serial.println("got response");
        handleNewMessages(numNewMessages);
        numNewMessages = bot.getUpdates(bot.last_message_received + 1);
      }
  
  }
   void handleNewMessages(int numNewMessages) {
    Serial.println("handleNewMessages");
    Serial.println(String(numNewMessages));
  
    for (int i=0; i<numNewMessages; i++) {
      // Chat id of the requester
      String chat_id = String(bot.messages[i].chat_id);
      String group_id="-692249623";
      Serial.println(chat_id);
//      if (chat_id != CHAT_ID){
//        bot.sendMessage(chat_id, "Unauthorized user", "");
//        continue;
//      }
//      

   String text = bot.messages[i].text;
    Serial.println(text);
    if (text == "/start") {
        String welcome = "Welcome to motion detector\n" ;
        welcome += "Use the following commands to control the device.\n\n";
         welcome += "/start  to get the list of commands \n";
          welcome += "/update to update the code \n";
        welcome += "/distance  to get distance in cm\n";
        welcome += "/changeX  to change minimum distance to X (X=50/100/150/200)\n";
         welcome += "/n  to request current Minimum distance \n";
         welcome += "/f  to request current frequency \n";
        welcome += "/frequencyX  to change frequency to X (X=50/100/500/1000)\n";
        welcome += "/alarm  to play simple alarm\n";
           welcome += "/danger  to play big alarm\n";
           welcome += "/aX  to change alarm delay to X (X=100/300/700/1000)\n";
        welcome += "/mode11 to change to Night Mode 1\n";
        welcome += "/mode12 to change to Night Mode 2\n";
                welcome += "/mode0 to change to Day Mode 2\n";
           welcome += "/m to display current mode\n";
                welcome += "/default to restore to defaults \n";
        bot.sendMessage(chat_id, welcome, "");
      }
      else if (text == "/distance") {
      myString = String(distance);
        bot.sendMessage(chat_id,myString,"");
       
      }
      
     else if (text == "/change50") {
      n=50;
        String msg="Minimum distance changed to 50";
        Serial.println(msg);
        bot.sendMessage(chat_id,msg, "");   
  
     }
     else if (text == "/change100") {
      n=100;
        String msg="Minimum distance changed to 100";
        Serial.println(msg);
        bot.sendMessage(chat_id,msg, "");
  
     }
     else if (text == "/change150") {
      n=150;
        String msg="Minimum distance changed to 150";
        Serial.println(msg);
        bot.sendMessage(chat_id,msg, "");
  
     }
    else if (text == "/change200") {
      n=200;
        String msg="Minimum distance changed to 200";
        Serial.println(msg);
        bot.sendMessage(chat_id,msg, "");
  
     }
    else if (text == "/n") { 
        String m= String(n);
          bot.sendMessage(chat_id,m, "");
        }
           else if (text == "/frequency50"){
          freq= 50;
          String msg="Frequency changed to 50";
          bot.sendMessage(chat_id,msg, "");
         }
 else if (text == "/frequency100"){
          freq= 100;
          String msg="Frequency changed to 100";
          bot.sendMessage(chat_id,msg, "");
         }
          else if (text == "/frequency500"){
          freq= 500;
          String msg="Frequency changed to 500";
          bot.sendMessage(chat_id,msg, "");
         }
          else if (text == "/frequency1000"){
          freq= 1000;
          String msg="Frequency changed to 1000";
          bot.sendMessage(chat_id,msg, "");
         }
         else if(text=="/default")
         {
          n=150;
          freq=300;
          d=200;
           mode=0;
           cnt1=cnt2=5;
          bot.sendMessage(chat_id,"Defaults restored Min distance=150cm freq=300 buzz delay=200ms Mode=0 cnt=5", "");
         }
        
else if (text == "/f") { 
        String fr= String(freq);
          bot.sendMessage(chat_id,fr, "");
        }
        else if(text=="/alarm"){
           bot.sendMessage(chat_id,"Playing alarm(s)", "");
           
 for(int i=0;i<10;i++){
          digitalWrite(buzz, HIGH);   
          delay(d);                       
          digitalWrite(buzz, LOW);    
          delay(d);
  }
        
        }
         else if (text =="/danger")
{
   bot.sendMessage(chat_id,"Playing alarm(d)", "");
for(int j=0;j<20;j++){      
          tone(buzz,1000);
delay(80);
noTone(buzz);
delay(80);  
          }
}
else if (text =="/a100")
{
d=100;
 bot.sendMessage(chat_id,"Alarm delay set to 100ms", "");
}
else if (text =="/a300")
{
d=300;
 bot.sendMessage(chat_id,"Alarm delay set to 300ms", "");
}
else if (text =="/a700")
{
d=700;
 bot.sendMessage(chat_id,"Alarm delay set to 700ms", "");
}
else if (text =="/a1000")
{
d=1000;
 bot.sendMessage(chat_id,"Alarm delay set to 1000ms", "");
}
        
         else if(text=="/video")
         {
          bot.sendMessage(chat_id,"Video Call Feature to be available soon..Till then use Skype", "");
   
         }
         else if (text == "/mode11"){
          mode=11;
          bot.sendMessage(chat_id,"Mode set to Night Mode 1");
         }
         else if (text == "/mode12"){
          mode=12;
          bot.sendMessage(chat_id,"Mode set to Night Mode 2");
         }
         else if (text == "/mode0"){
          mode=0;
          bot.sendMessage(chat_id,"Mode set to Day Mode 0");
         }
         else if(text=="/m")
         {
          String m="Mode"+String(mode);
          bot.sendMessage(chat_id,m);
         }

         else if(text=="/update")
         {
          bot.sendMessage(chat_id,"Checking for Updates");
          time_elapsed=0;
           while(time_elapsed<60000){
  ArduinoOTA.handle();
  time_elapsed=millis();
  delay(10);
    }
     bot.sendMessage(chat_id,"No Updates Found");
         }
        else
        bot.sendMessage(chat_id,"Invalid Command", "");
    }
  
  
    }
   

////////////////////////////////////////////////////////////////////////  
