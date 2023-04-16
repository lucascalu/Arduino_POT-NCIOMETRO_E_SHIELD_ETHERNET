#include <ETHER_28J60.h>
#include <etherShield.h>


//Define o MAC da placa de rede. Nao eh necessario alterar
static uint8_t mac[6] = {0x54, 0x55, 0x58, 0x10, 0x00, 0x24};
//Define o endereco IP da sua placa
static uint8_t ip[4] = {169, 254, 59, 36};
 
static uint16_t port = 80; 
 
ETHER_28J60 e;
 
int pin = 1; // Pino analogico para ligacao do Sensor
int tempc = 0; // Variavel que armazena a temperatura em Celsius
// Variáveis para temperatura máxima e mínima
int maxtemp = -100,mintemp = 100; 
int i;
 
void setup()
{ 
  //Inicializa a placa com as configuracoes fornecidas
  e.setup(mac, ip, port);
}
 
void loop()
{
  //Calcula o valor da temperatura
  tempc = ( 5.0 * analogRead(pin) * 100.0) / 1024.0;
 
  //Armazena a temperatura máxima na variavel maxtemp
  if(tempc > maxtemp) {maxtemp = tempc;} 
  //Armazena a temperatura máxima na variavel mintemp
  if(tempc < mintemp) {mintemp = tempc;} 
 
  if (e.serviceRequest())
  {
    e.print("<H1>Lucas S Calu - Teste ENC28J60</H1><br/>");
    e.print("<b>Valor potenciometro porta analogica 5 : ");
    e.print(analogRead(A5));
    e.print("<br/><br/>");
    e.print("Valor temperatura : ");
    e.print(tempc);
    e.print("&deg<br/><br/>");
    e.print("Temperatura minima : ");
    e.print(mintemp);
    e.print("&deg<br/>");
    e.print("Temperatura maxima : ");
    e.print(maxtemp);
    e.print("&deg<b/>");
    e.respond();
  }
  delay(100);
}
