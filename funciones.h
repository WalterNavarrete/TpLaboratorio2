typedef struct {

    char nombre[50];
    int dni;
    int edad;
    int estado;

}EPersona;

void setearEstado(EPersona arrayPersonas[],int arrayLenght,int valor);
int BuscarLugarLibre(EPersona arrayPersona[],int arrayLenght);
int BuscarPersonaPorDni(EPersona arrayPersona[],int arrayLenght,int dni);

void Graficar(EPersona arrayPersona[],int arrayLenght);
int BuscoMayorRango(int hasta18,int de19a35,int mayorDe35);
void MuestroGrafico(int mayor,int hasta18, int de19a35, int mayorDe35);

