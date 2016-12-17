/*
The script is based of the https://github.com/MiniGirlGeek/energenie-demo python script to 
control the pimote https://energenie4u.co.uk/index.php/catalogue/product/ENER002-2PI using
Raspberry pi. More information on http://www.jdohnalek.com/

EXAMPLES:

# turn a plug socket on and off by number
switch_on(1)
switch_off(1)

switch_on(3)
switch_off(3)

# turn all plug sockets on and off
switch_on(0)
switch_off(0)

# turn some plug sockets on, then turn them off after 10 seconds
switch_on(1)
switch_on(4)
sleep(10)
switch_off(1)
switch_off(4)
*/


// VARIABLES ------------------------------

int gpio17 = 0; // Encoded Signal D0
int gpio22 = 1; // Encoder Signal D1
int gpio23 = 2; // Encoder Signal D2
int gpio27 = 3; // Encoder Signal D3

int gpio24 = 4; // MODSEL mode select signal (OOK/FSK)
int gpio25 = 5; // CE modular enable (Output ON/OFF)

// Socket     all      1       2      3       4
char* on[] ={"1011", "1111", "1110","1101", "1100"};
char* off[]={"0011", "0111", "0110","0101", "0100"};

// Initialize the Pimote pins
void setupPimotePins(){
  int pin[] = {gpio17, gpio22, gpio23, gpio27, gpio24, gpio25};
  for(int i=0; i<6; i++){ pinMode(pin[i], OUTPUT);  }
  for(i=0; i<6; i++){ pinMode(pin[i], LOW); }
  delay(500);
}

// Handle Energenie Pimote socket state
// @param socket, int: socket to address
// @param on_or_off, char[]: series of bits to address socket
void state(int socket, char* on_or_off[]){
  int pin[] = {gpio27, gpio23, gpio22, gpio17};
  for(i=0; i<4; i++){
    digitalWrite(pin[i], LOW);
    if(on_or_off[socket][i] - '0' == 1 ){
      digitalWrite(pin[i], HIGH);
    }   
  }
  delay(100);
  digitalWrite(gpio25, HIGH);
  delay(250);
  digitalWrite(gpio25, LOW);
}

// Turn socket on method
// @param socket, int: socket to switch
void switch_on(int socket){
  state(socket, on);
}

// Turn socket on method
// @param socket, int: socket to switch
void switch_off(int socket){
  state(socket, off);
}


// BEGIN

void setup(){
  setupPimotePins();
}

void loop(){
  
  switch_on(0);
  delay(5000);
  
  switch_off(0);
  delay(5000);
}
