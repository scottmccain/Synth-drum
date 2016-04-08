#include <arduino.h>

#include "editor.h"
#include "player.h"

extern PanelScanner theScanner;
extern Player       thePlayer;

// constructor...
Editor::Editor()
{
}

void Editor::receiveKey(uint32_t keynum, bool pressed)
{
#if 1
  Serial.print("Ed Key: ");
  Serial.print(keynum, HEX);
  Serial.print(" ");
  Serial.println(pressed);
#endif

  if (keynum == 0x17) 
  {
    if(pressed )
    {
      // start/stop key
      if(thePlayer.isPlaying())
      {
        thePlayer.stop();
        theScanner.clearLED(0x17);
      }
      else
      {
        thePlayer.start();
        theScanner.setLED(0x17);
      }
    }
  }
#if 1
  else// other, unmapped keys, just show they work.
  {
    if(pressed)
    {
      theScanner.setLED(keynum);
    }
    else
    {
      theScanner.clearLED(keynum);
    }
  }
#endif  
}
