#include <Pimote.h>

Pimote socket(0, 1, 2, 3, 4, 5);

void setup()
{
}

void loop()
{
  socket.On(0);
  delay(500);

  socket.Off(0);
  delay(500);

}
