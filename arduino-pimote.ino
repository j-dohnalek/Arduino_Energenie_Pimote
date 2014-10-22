/*
The script is based of the https://github.com/MiniGirlGeek/energenie-demo python script to 
control the pimote https://energenie4u.co.uk/index.php/catalogue/product/ENER002-2PI using
Raspberry pi. More information on http://www.badcompanyx.eu/

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

void setupPimotePins()
{
  // Select the pins used for the encoder K0-K3 data inputs
  pinMode(gpio17, OUTPUT);
  pinMode(gpio22, OUTPUT);
  pinMode(gpio23, OUTPUT);
  pinMode(gpio27, OUTPUT);
  
  // Select the signal used to select ASK/FSK
  pinMode(gpio24, OUTPUT);
  // Select the signal used to enable/disable the modulator
  pinMode(gpio25, OUTPUT);
  
  // Disable the modulator by setting CE pin lo
  digitalWrite(gpio25, LOW);
  
  // Set the modulator to ASK for On Off Keying
  // by setting MODSEL pin lo
  digitalWrite(gpio24, LOW);
  
  // Initialise K0-K3 inputs of the encoder to 0000
  digitalWrite(gpio17, LOW);
  digitalWrite(gpio22, LOW);
  digitalWrite(gpio23, LOW);
  digitalWrite(gpio27, LOW);
  
  // Give a short delay after setup
  delay(500); 
}

void state(int state, char* on_or_off[])
{
    digitalWrite(gpio27, LOW);
    digitalWrite(gpio23, LOW);
    digitalWrite(gpio22, LOW);
    digitalWrite(gpio17, LOW);
    
    if(on_or_off[state][0] - '0' == 1 )
      digitalWrite(gpio27, HIGH);
    
    if(on_or_off[state][1] - '0' == 1 )
      digitalWrite(gpio23, HIGH);
    
        
    if(on_or_off[state][2] - '0' == 1 )
      digitalWrite(gpio22, HIGH);

        
    if(on_or_off[state][3] - '0' == 1 )
      digitalWrite(gpio17, HIGH);
    
    delay(100);
    digitalWrite(gpio25, HIGH);
    delay(250);
    digitalWrite(gpio25, LOW);
}


void switch_on(int socket)
{
  state(socket, on);
}


void switch_off(int socket)
{
  state(socket, off);
}


// BEGIN +++++++++++


void setup(){
  setupPimotePins();
}


void loop(){
  
  switch_on(0);
  delay(5000);
  
  switch_off(0);
  delay(5000);
}
