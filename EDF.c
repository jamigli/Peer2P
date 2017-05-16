#include "PeerUDP.h"

int main(){

    char msj[30];

    createSocket(8080);
    
    run();

     pid_t pid;
     int x,y;
     
     for(x=1;x<=3;x++)
     {
      
      pid=fork(); 
      if(pid)
      {
        msj[0] = 'a' + rand() % (('z' - 'a')+1);
        msj[1] = 'a' + rand() % (('z' - 'a')+1);
        sendToMessage(msj,"localhost",8080);       sleep(2);
        printf("Mensaje enviado: %s\n", msj);
      }

      else
      {
         msj[0] = 'a' + rand() % (('z' - 'a')+1);
        msj[1] = 'a' + rand() % (('z' - 'a')+1);
        sendToMessage(msj,"localhost",8080);
        printf("Mensaje enviado: %s\n", msj);
       sleep(2);
       for(y=1;y<=2;y++)
       {
        pid=fork();
         if(pid)
         {
             msj[0] = 'a' + rand() % (('z' - 'a')+1);
            msj[1] = 'a' + rand() % (('z' - 'a')+1);
              sendToMessage(msj,"localhost",8080);
              printf("Mensaje enviado: %s\n", msj);
              sleep(2);
         }
         else
         {
            msj[0] = 'a' + rand() % (('z' - 'a')+1);
              msj[1] = 'a' + rand() % (('z' - 'a')+1);
            sendToMessage(msj,"localhost",8080);
            printf("Mensaje enviado: %s\n", msj);
          sleep(2);
          exit(0);
         }
       }
       exit(0);
      }
  
 }

    return 0;

}