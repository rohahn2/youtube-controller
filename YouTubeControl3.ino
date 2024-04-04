//   Youtube control to pause, jumpback and play the video stream with foot controled pushbuttons
//   Designed to to used while holding a guitar learning music on Youtube.  
//   Hardware is a Teensy 2.0 processor connected to 4 push buttons. The buttons are:
//         Bten   or reverse the video 10 seconds
//         Bfive   or reverse the video 5 seconds
//         PAUSE  pause the video
//         Ften  Forwared the video 10 seconds
//  How about we add a 5th button Alt +(Tab) to switch between apps. browser to MS Word and back
//   These pushbutton switches short the Teensy pins to ground (active low signals).

#include <Keyboard.h>

    const int led = LED_BUILTIN;   // I used the LED on the Teensy as a good debug tool.
    int Bten = 5;      // Pin 5   the back ten seconds button
    int Bfive = 6;     // Pin 6   the back 5 seconds button
    int pause = 7;     // Pin 7   pause button
    int Ften = 8;      // Pin 8   Forward ten seconds
    int alt_tab = 9;       // Pin 9   Alt +Tab  will switch between windows apps
    
void setup() {
    
pinMode(Bten, INPUT_PULLUP);     //configure the pushbutton switch inputs with pull-ups. Normally high then active low
pinMode(Bfive, INPUT_PULLUP);
pinMode(pause, INPUT_PULLUP);
pinMode(Ften, INPUT_PULLUP);
pinMode(alt_tab, INPUT_PULLUP);

  Keyboard.begin();   //  Keyboard library
}

  void loop() 
  {
//---------------------REWIND 10 SECONDS----------------------------------------
      if(digitalRead(Bten)==LOW)     //if the button is pressed
      {
       digitalWrite(led, HIGH);     // Turn on the LED when button is pushed
       Keyboard.write('j');     //Send the message lower case j = go back ten seconds
       delay(500);              // This 1/2 second delay prevents multiple button pushes
       }
//----------------------REWIND 5 SECONDS------------------------------------------
      if(digitalRead(Bfive)==LOW)     //if the button is pressed
      {
       digitalWrite(led, HIGH);

       //  all this just to send a left arrow key which = go back five seconds.
       //  https://www.pjrc.com/teensy/td_keyboard.html
       
       Keyboard.set_key1(KEY_LEFT);
       Keyboard.send_now();
       // release all the keys at the end
       Keyboard.set_key1(0);
       Keyboard.send_now();
       delay(500);
       }
//------------------------PAUSE----------------------------------------------------
      if(digitalRead(pause)==LOW)     //if the button is pressed
      {
       digitalWrite(led, HIGH);
       Keyboard.write('k');     //Send the message lower case k = pause
       delay(500);
       }
//------------------------FORWARE 10 SECONDS----------------------------------------
      if(digitalRead(Ften)==LOW)     //if the button is pressed
      {
       digitalWrite(led, HIGH);
       Keyboard.write('l');     //Send the message lower case l = go forward 10 seconds
       delay(500);
       }
//------------------------Alt + Tab----------------------------------------
      if(digitalRead(alt_tab)==LOW)     //if the button is pressed
      {
       digitalWrite(led, HIGH);
       Keyboard.set_modifier(MODIFIERKEY_ALT);    //Set the Alt modifier
       Keyboard.send_now();                       //Send the alt modifier
       Keyboard.press(KEY_TAB);                   // Send the TAB key
       Keyboard.release(KEY_TAB);                 //quite sending tab key
       Keyboard.set_modifier(0);                  //Turn off the modifier key
       Keyboard.send_now();                       //send that 
       delay(500);
       }
//---------------------------------------------------------------------------      
       
       else
       {
        digitalWrite(led, LOW);
        }
  }
//the end-------------------------------------------------------------------------------

//------------------The Following is a list of possible Youtube keyboard shortcuts
//Toggle play/pause the video      k or Spacebar 
//Go back 5 seconds     Left arrow  
//Go back 10 seconds     j  
//Go forward 5 seconds      Right arrow
//Go forward 10 seconds     l 
//Skip to a particular section of the video (e.g., 5 goes to the video midpoint)  Numbers 1-9 (not the keypad numbers)
//Restart video    0 (not the keypad number)  
//Go to Full Screen mode     f 
//Exit Full Screen mode      Escape 
//Go to beginning of video    Home
//Go to end of video     End
//Increase volume 5%        Up arrow
//Decrease volume 5%       Down arrow          
//Increase speed        Shift+> (may not work in all browsers)   
//Decrease speed        Shift+< (may not work in all browsers)       
//Move forward 1 frame when video is paused   .   (period)  
//Move backward 1 frame when video is paused     ,   (comma)  
//Mute/unmute video    m 
//Turn captions on/off    c 
//Cycle through options for caption background color   b    
//Move to the previous video in a playlist      Shift+p 
//Move to the next video in a playlist      Shift+n 
